#ifndef SHADERS_H
#define SHADERS_H

//////////////////////////////////////////////////
//				NORMAL SHADER                   //
//////////////////////////////////////////////////
static const char* NormalVertexShader = 
	"#version 330 \n"
	"layout(location = 0) in vec2 point;"
	"layout(location = 1) in vec2 pointUV;"
	"uniform vec2 displacement;"
	"uniform vec2 scale;"
	"out vec2 UV;"
	"void main()"
	"{"
	"	vec2 coordinate = point * scale + displacement;"
	"	gl_Position = vec4(coordinate, 0, 1);"
	"	UV = pointUV;"
	"}";


static const char* NormalFragmentShader = 
	"#version 330 \n"
	"in vec2 UV;"
	"out vec4 color;"
	"uniform sampler2D sampler;"
	"void main()"
	"{"
	"	vec4 testColor = texture(sampler, UV).rgba;"
	"	if(testColor.a < .5) discard;"
	"	color = testColor;"
	"}";
//////////////////////////////////////////////////
#endif