#include "TestScene.h"

//#include <GameEngine/Exception.h>

TestScene::TestScene()
{
	

}

TestScene::~TestScene()
{
	//clean up shaders
	//glDetachShader(prgramId, vertexShaderID);
	//glDeleteShader(vertexShaderID);
	//glDetachShader(prgramId, fragmentShaderID);
	//glDeleteShader(fragmentShaderID);
	//clean up SDL
	/*SDL_DestroyWindow(m_Window);
	SDL_Quit();*/
}

void TestScene::OnInitalise()
{
	const GLfloat positions[] =
	{
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	vertexShaderSrc =
		"attribute vec3 in_Position;"\
		"uniform mat4 in_Model; "\
		""\
		"void main()"\
		"{"\
		"	gl_Position = in_Model * vec4(in_Position, 1.0);"\
		"}"\
		"";

	fragmentShaderSrc =
		"void main()"\
		"{"\
		"	gl_FragColor = vec4(0, 0, 1, 1);"\
		"}"\
		"";

	//calls glewInit, and checks if it was successful
	//if not will through a exeption.
	_context = GameEngine::Context::initialize();
	//create shader
	_shader = _context->createShader();
	//create buffer
	_buffer = _context->createBuffer();
	//create mesh
	_mesh = _context->createMesh();

	//set shaders
	//_shader->setSource(vertexShaderSrc, fragmentShaderSrc);
	//_shader->loadShaderFile("vertexShader.txt", "fragmentShader.txt");

	//_mesh->loadMesh("resources/rend/samples/graveyard/graveyard.obj");

	_buffer->add(rend::vec3(positions[0],positions[1], positions[2]));
	_buffer->add(rend::vec3(positions[3], positions[4], positions[5]));
	_buffer->add(rend::vec3(positions[6], positions[7], positions[8]));

}

void TestScene::SetMesh(std::shared_ptr<Mesh> _mesh)
{

	this->_mesh = _mesh->_internal;
	//_shader->setMesh(_mesh);
}

void TestScene::OnDraw()
{
	//might need to check this
	std::shared_ptr<Transform> _trans = getEntity()->getComponent<Transform>();

	//_trans->GetPosition();
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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glUseProgram(prgramId);
		//glUseProgram(_shader->ProgramID());
		//glBindVertexArray(vaoID);

		//glDrawArrays(GL_TRIANGLES, 0, 3);
		_shader->setUniform("in_Model", rend::mat4(1.0f));
		//_shader->setUniform("in_Model", _trans->GetModel());
		_shader->setAttribute("in_Position", _buffer);

		_shader->setMesh(_mesh);
		_shader->render();

		//glBindVertexArray(0);
		//glUseProgram(0);

		

	//}

	//onTicks();
}


