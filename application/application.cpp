#include "application.h"
#include <string_view>
#include <iostream>
#include <optional>
#include <chrono>

#include <GLFW/glfw3.h>

void Application::start() {

	if (!getWindow().create()) {
		std::cout << "Couldnt create window" << std::endl;
	}

	using clock = std::chrono::steady_clock;
	m_lastTime = clock::now();

	getScene().init();

	Input input;
	Application::setInputSys(input);

	std::vector<float> triVerts{
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.0f, 0.5f
	};

	std::vector<float> recVerts {
		-0.5f,  0.5f,  // top-left
		 0.5f,  0.5f,  // top-right
		 0.5f, -0.5f,  // bottom-right
		-0.5f, -0.5f
	};

	const Mesh triMesh(triVerts);
	int triangleID = getScene().addMesh(triMesh);

	const Mesh recMesh(recVerts);
	int redID = getScene().addMesh(recMesh);

	getScene().createEntity("Danny", redID);
	getScene().createEntity("Enemy", triangleID);

	Application::setAppState(true);

	while (!getWindow().shouldClose())
	{
		Application::update();
		getWindow().update();
	}


}

void Application::update() {

	// Delta Time
	using clock = std::chrono::steady_clock;




	// ref to scene / input
	Scene& scene = getScene();
	Input& input = getInputSys();

	// Update Delta Time
	auto currentTime = clock::now();
	float deltaTime = std::chrono::duration<float>(currentTime - m_lastTime).count();
	m_lastTime = currentTime;
	
	if (deltaTime > 0.05f) deltaTime = 0.05f;
	
	Entity& entToUpdate = scene.getEntityByID(1);
	entToUpdate.setVelocityX(1);

	//auto inputResult = input.getInput();
	
	//if (inputResult.action == Input::QUIT) {
	//	std::cout << "Exiting" << std::endl;
	//	Application::stop();
	//}
	//
	//Entity& entToUpdate = scene.getEntityByID(1);
	//
	//if (inputResult.action == Input::MOVE) {
	//	if (inputResult.direction == Input::NORTH) {
	//		std::cout << "North" << std::endl;
	//		entToUpdate.setVelocityY(100);
	//	}
	//	if (inputResult.direction == Input::SOUTH) {
	//		std::cout << "South" << std::endl;
	//		entToUpdate.setVelocityY(-100);
	//	}
	//	if (inputResult.direction == Input::EAST) {
	//		std::cout << "East" << std::endl;
	//		entToUpdate.setVelocityX(100);
	//	}
	//	if (inputResult.direction == Input::WEST) {
	//		std::cout << "West" << std::endl;
	//		entToUpdate.setVelocityX(-100);
	//	}
	//	if (inputResult.action == NULL || inputResult.direction) {
	//		entToUpdate.setVelocityX(0);
	//		entToUpdate.setVelocityY(0);
	//	}
	//}
	
	scene.Update(deltaTime);
	scene.Render();
	

}

void Application::stop() {
	Application::setAppState(false);
}