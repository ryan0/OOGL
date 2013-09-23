#ifndef SHADERS_H
#define SHADERS_H

//////////////////////////////////////////////////
//				NORMAL SHADER                   //
//////////////////////////////////////////////////
static const char* NormalVertexShader = 
	"#version 330 \n"
	"layout(location = 0) in vec2 point;"
	"layout(location = 1) in vec2 pointUV;"
	"out vec2 UV;"
	"void main()"
	"{"
	"	gl_Position = vec4(point, 0, 1);"
	"	UV = pointUV;"
	"}";


static const char* NormalFragmentShader = 
	"#version 330 \n"
	"in vec2 UV;"
	"out vec4 color;"
	"uniform sampler2D sampler;"
	"void main()"
	"{"
	"	color = texture(sampler, UV).rgba;"
	"}";
//////////////////////////////////////////////////
#endif
