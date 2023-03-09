#version 400 core
out vec4 FragColor;

in vec4 vertexPositions;

void main()
{
	FragColor = vertexPositions;
}