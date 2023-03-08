#include "shader_manager.hpp"

Shader::Shader(const std::string& vertexShaderPath,const std::string& fragmentShaderPath)
{
	// Load shaders from the file
	std::string   vShaderSource;
	std::string   fShaderSource;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(vertexShaderPath);
		vShaderFile.open(fragmentShaderPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();		
       
        vShaderFile.close();
        fShaderFile.close();
       
        vShaderSource   = vShaderStream.str();
        fShaderSource = fShaderStream.str();	

	}
	catch(std::ifstream::failure e)
    {
        std::cout << "Cannot read shader files" << std::endl;
    }

    const char* vShaderCode = vShaderSource.c_str();
    const char* fShaderCode = fShaderSource.c_str();

    // Compile shaders
    GLint  success;
    char   infoLog[512];

    // Compile vertex shader
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success) {
    	glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    	std::cerr << "Compilation of the vertex shader has failed!\n";
    }

    // Compile fragment shader
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success) {
    	glGetShaderInfoLog(fragment, 512, NULL, infoLog);
    	std::cerr << "Compilation of the fragment shader has failed!\n";
    }

    // Create shader program
    m_ProgramID = glCreateProgram();
    glAttachShader(m_ProgramID, vertex);
    glAttachShader(m_ProgramID, fragment);
    glLinkProgram(m_ProgramID);

    glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &success);
	if(!success)
	{
    	glGetProgramInfoLog(ID, 512, NULL, infoLog);
    	std::cout << "Shader linking failed!\n" << infoLog << std::endl;
	}
  
	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::execute() 
{
	glUseProgram(m_ProgramID);
}

void Shader::setBoolean(const std::string& uniformTag, GLboolean value) const
{
	glUniform1i(glGetUniformLocation(m_ProgramID, uniformTag.c_str()), static_cast<int>(value));
}

void Shader::setInteger(const std::string& uniformTag, GLint value) const
{
	glUniform1i(glGetUniformLocation(m_ProgramID, uniformTag.c_str()), value);
}

void Shader::setFloat(const std::string& uniformTag, GLfloat value) const
{
	glUniform1i(glGetUniformLocation(m_ProgramID, uniformTag.c_str()), value);
}