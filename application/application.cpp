#include "application.h"
#include "../scene/scene.h"
#include <string_view>
#include <iostream>
#include "../entity/entity.h"
#include <optional>

void Application::start() {
	Application::setAppState(true);

	Scene currentScene;

	Application::setScene(currentScene);

	Application::update();
}

std::string receiveInput() {
	std::string userInput{};
	std::cin >> userInput;
	return userInput;
}



void Application::processInput(std::string_view input) {
	
}

void Application::update() {


	Scene& scene = getScene();

	scene.createEntity("Danny");
	scene.createEntity("2");
	Entity test = scene.getEntityByID(2);
	std::cout << scene.getEntityByID(1).getEntityName() << std::endl;
	std::cout << test.getEntityName() << std::endl;
	std::cout << scene.getEntityByID(3).getEntityName() << std::endl;

	while (Application::getAppState()) {



		std::string userInput;
		std::cin >> userInput;

		processInput(userInput);

		scene.Update();
	}

}

void Application::stop() {
	Application::setAppState(false);
}