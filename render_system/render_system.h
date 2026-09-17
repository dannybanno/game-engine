#include <glad/gl.h>
#include <array>
#include <fstream>
#include <sstream>
#include <string>


class renderSystem {

private:
	GLuint m_shaderProgram{};
	GLuint m_entityPosLocation{};

	meshManager m_meshManager;

public:

	void init() {



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

	void render(const std::vector<Entity>& entityList, meshManager& meshManager){

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(m_shaderProgram);

		for (const auto& entity : entityList) {

			double x = entity.getTransform().getTransformX();
			double y = entity.getTransform().getTransformY();

			const renderMesh& renderMesh = meshManager.getRenderMesh(entity.getMeshID());

			glBindVertexArray(renderMesh.getVAO());

			glUniform2f(m_entityPosLocation, x, y);

			glDrawArrays(GL_TRIANGLES, 0, renderMesh.getVertexCount());
		}

	}

};