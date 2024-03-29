#ifndef LOAD_SHADERS
#define LOAD_SHADERS

typedef struct _ShaderInfo {
  GLenum Type;
	GLchar const * Source;
} ShaderInfo;

void PrintShaderErrorLog(GLuint shader)
{
	GLint maxLength = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

	GLchar* shaderErrorLog = (GLchar*)malloc(sizeof(GLchar) * (maxLength + 1));

	glGetShaderInfoLog(shader, maxLength, &maxLength, shaderErrorLog);
	shaderErrorLog[maxLength] = '\0';
	printf(shaderErrorLog);

	free(shaderErrorLog);
}

GLuint CreateShader(ShaderInfo const * shaderInfo)
{
	GLuint shader = glCreateShader(shaderInfo->Type);
	glShaderSource(shader, 1, (const GLchar**)(&shaderInfo->Source), 0);
	glCompileShader(shader);

	GLint isCompiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
	if(isCompiled == 0) {
		PrintShaderErrorLog(shader);
		return 0;
	}

	return shader;
}

GLuint LoadShaders(ShaderInfo const * shaderInfo)
{
	GLchar const * vertexSource =
		"#if __VERSION__ >= 140\r\n\
in vec4  vPosition;\r\n\
#else\r\n\
attribute vec4 vPosition;\r\n\
#endif\r\n\
\r\n\
void main()\r\n\
{\r\n\
    gl_Position = vPosition;\r\n\
}\r\n\
";
	ShaderInfo vertexShaderInfo = { GL_VERTEX_SHADER, vertexSource };
	GLuint vertexShader = CreateShader(&vertexShaderInfo);
	if(vertexShader == 0) {
		return 0;
	}

	GLchar const * fragmentSource =
		"#if __VERSION__ >= 140\r\n\
out vec4 fColor;\r\n\
#endif\r\n\
\r\n\
void main()\r\n\
{\r\n\
#if __VERSION__ >= 140\r\n\
    fColor = vec4(0.0, 0.0, 0.0, 1.0);\r\n\
#else\r\n\
    gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);\r\n\
#endif\r\n\
}\r\n\
";
	ShaderInfo fragmentShaderInfo = { GL_FRAGMENT_SHADER, fragmentSource };
	GLuint fragmentShader = CreateShader(&fragmentShaderInfo);
	if(fragmentShader == 0) {
		return 0;
	}

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);

	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	GLint isLinked = 0;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &isLinked);
	if(isLinked == 0)
	{
		GLint maxLength = 0;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);
		GLchar * shaderProgramInfoLog = (GLchar*)malloc(sizeof(GLchar) * (maxLength+1));
		glGetProgramInfoLog(shaderProgram, maxLength, &maxLength,
			shaderProgramInfoLog);
		shaderProgramInfoLog[maxLength] = '\0';
		printf(shaderProgramInfoLog);
		free(shaderProgramInfoLog);
		return 0;
	}

	glUseProgram(shaderProgram);

	return shaderProgram;
}

#endif
