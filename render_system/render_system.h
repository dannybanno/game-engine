#include <glad/gl.h>
#include <array>
#include <fstream>
#include <sstream>
#include <string>


class renderSystem {

private:
	std::array<std::pair<float, float>, 3> m_vertices{
		{
			{-0.5f, -0.5f}, 
			{ 0.5f, -0.5f}, 
			{ 0.0f,  0.5f}  
		}
	};


	GLuint m_vbo;
	GLuint m_vao;
	GLuint m_shaderProgram;
	GLuint m_entityPosLocation;

public:

	void init() {

		glGenVertexArrays(1, &m_vao);
		glGenBuffers(1, &m_vbo);

		glBindVertexArray(m_vao);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(m_vertices),
			m_vertices.data(),
			GL_STATIC_DRAW
		);

		glVertexAttribPointer(
			0, // index -> location = 0. 
			2, // 2 components -> x, y
			GL_FLOAT, // component type
			GL_FALSE, // normalise?
			2 * sizeof(float), // bytes from pos to next
			(void*)0
		);
		glEnableVertexAttribArray(0);

		std::ifstream file("../shaders/triangle.vert");

		if (!file.is_open()) {
			std::cout << "FAILED TO OPEN VERTEX SHADER\n";
		}

		std::stringstream buffer;
		buffer << file.rdbuf();

		std::string vertexShaderSource = buffer.str();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		const char* vertexShaderSourcePointer = vertexShaderSource.c_str();

		glShaderSource(vertexShader, 1, &vertexShaderSourcePointer, nullptr);

		glCompileShader(vertexShader);

		int success;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success) {
			std::cout << "VERTEX SHADER FAILED\n";
		}

		std::ifstream fragFile("../shaders/triangle.frag");

		if (!fragFile.is_open()) {
			std::cout << "FAILED TO OPEN FRAGMENT SHADER\n";
		}

		std::stringstream fragBuffer;
		fragBuffer << fragFile.rdbuf();

		std::string fragmentShaderSource = fragBuffer.str();

		const char* fragmentShaderSourcePointer = fragmentShaderSource.c_str();

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(
			fragmentShader,
			1,
			&fragmentShaderSourcePointer,
			nullptr
		);

		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success) {
			std::cout << "FRAGMENT SHADER FAILED\n";
		}

		m_shaderProgram = glCreateProgram();

		glAttachShader(m_shaderProgram, vertexShader);
		glAttachShader(m_shaderProgram, fragmentShader);

		glLinkProgram(m_shaderProgram);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		m_entityPosLocation = glGetUniformLocation(m_shaderProgram, "entityPos");

	}

	void render(const std::vector<Entity>& entityList){

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(m_shaderProgram);

		glBindVertexArray(m_vao);

		for (const Entity& entity : entityList) {
			double x = entity.getTransformX();
			double y = entity.getTransformX();

			glUniform2f(m_entityPosLocation, x, y);

			glDrawArrays(GL_TRIANGLES, 0, 3);
		}

	}

};