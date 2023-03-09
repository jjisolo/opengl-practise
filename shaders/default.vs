#version 400 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTextCoord;

uniform float horizontalOffset;

out vec4 vertexPositions;
out vec2 textureCoordinates;

void main()
{
	gl_Position        = vec4(aPos.x + horizontalOffset, aPos.y, aPos.z, 1.0);
	vertexPositions    = gl_Position;
	textureCoordinates = aTextCoord;
}