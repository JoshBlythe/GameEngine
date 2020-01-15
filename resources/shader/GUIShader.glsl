#ifdef VERTEX

attribute vec2 a_Position;

uniform mat4 u_Projection;
uniform mat4 u_Model;

void main()
{

gl_Position = u_Projection * u_Model * vec4(a_Position, 0, 1);

}

#endif
#ifdef FRAGMENT

void main()
{

 gl_FragColor = vec4(1, 0, 0, 1);

}
#endif