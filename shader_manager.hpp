#pragma once

#include "glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class ShaderManager
{
public:
	
	Shader(const std::string& vertexShaderPath,const std::string& fragmentShaderPath);

public:
	
	// Get the shader program ID
	inline GLuint getProgramID() const { return m_ProgramID; }

	// Activate the shader
	void ececute();

	// Uniform functions
	void setBoolean(const std::string& uniformTag, GLboolean value) const;

	void setInteger(const std::string& uniformTag, GLint     value) const;

	void setFloat  (const std::string& uniformTag, GLfloat   value) const;

private:
	// Shader program ID
	GLuint m_ProgramID;
}


