#include "TestScene.h"

//#include <GameEngine/Exception.h>

TestScene::TestScene()
{
	const GLfloat positions[] =
	{
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	const GLchar *vertexShaderSrc =
		"attribute vec3 in_Position;"\
		""\
		"void main()"\
		"{"\
		"	uniform mat4 in_model;"\
		"	gl_Position = vec4(in_Position *in_model, 1.0);"\
		"}"\
		"";

	const GLchar *fragmentShaderSrc =
		"void main()"\
		"{"\
		"	gl_FragColor = vec4(0, 0, 1, 1);"\
		"}"\
		"";

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw Exception("SDL_Init Error: ");
	}

	//create window
	m_Window = SDL_CreateWindow("Game Engine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		600, 400, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(m_Window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw Exception("Glew Init Error: ");
	}

	//below stuff will adventually need to me 
		//for now get the shader working ignore the VAOID

	//set position of VBO
	positionVboId = 0;
	
	//Creates a VBO on the GPU and binds it to position 1
	glGenBuffers(1, &positionVboId);

	if (!positionVboId)
	{
		throw Exception("position VBO ID Genbuffer Error: Cannot bind to CPU. ");
	}

	glBindBuffer(GL_ARRAY_BUFFER, positionVboId);

	//upload a copy of data from memory to the created VBO 
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions),
		positions, GL_STATIC_DRAW);

	//reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//initalising the vao
	vaoID = 0;
	//create new VAO on GPU and bind it
	glGenVertexArrays(1, &vaoID);

	if (!vaoID)
	{
		throw Exception("VAO ID Genbuffer Error: Cannot bind to CPU. ");
	}

	glBindVertexArray(vaoID);

	//bind the position VBO, then assign it to a position 0 on the bound VAO and flag it for use
	glBindBuffer(GL_ARRAY_BUFFER, positionVboId);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(0);
	
	//reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glEnableVertexAttribArray(0);

	//vertex shader
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShaderID);
	
	GLint success = 0;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

	//check for success if not throw exeption
	if (!success)
	{
		throw Exception("Reset State Vertex shader, Success Error! ");
	}

	//fragment shader
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fragmentShaderID);
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw Exception("Reset State Fragment shader, Success Error! ");
	}

	//program
	prgramId = glCreateProgram();
	glAttachShader(prgramId, vertexShaderID);
	glAttachShader(prgramId, fragmentShaderID);
	glBindAttribLocation(prgramId, 0, "in_Position");

	if (glGetError() != GL_NO_ERROR)
	{
		throw Exception("Program Error: glGetError is not Equal to No Error. ");
	}

	glLinkProgram(prgramId);
	glGetProgramiv(prgramId, GL_LINK_STATUS, &success);

	if (!success)
	{
		throw Exception("Program, Success Error! ");
	}

}

TestScene::~TestScene()
{
	//clean up shaders
	glDetachShader(prgramId, vertexShaderID);
	glDeleteShader(vertexShaderID);
	glDetachShader(prgramId, fragmentShaderID);
	glDeleteShader(fragmentShaderID);
	//clean up SDL
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

void TestScene::OnDraw()
{
	//might need to check this
	std::shared_ptr<Entity> ent = getEntity()->getCore()->addEntity();
	//bool m_systemLoop = true;

	//while (m_systemLoop)
	//{
		SDL_Event m_event = { 0 };

		while (SDL_PollEvent(&m_event))
		{
			if (m_event.type == SDL_QUIT)
			{
				//m_systemLoop = false;
			}
		}

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(prgramId);
		glBindVertexArray(vaoID);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);

		SDL_GL_SwapWindow(m_Window);

	//}

	//onTicks();
}
