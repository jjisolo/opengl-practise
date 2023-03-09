#version 400 core
out vec4 FragColor;

in vec4 vertexPositions;
in vec2 textureCoordinates;

uniform sampler2D ourTexture;

void main()
{
	FragColor = texture(ourTexture, textureCoordinates);
}