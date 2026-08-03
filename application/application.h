#pragma once
#include <string>
#include <utility>
#include <vector>

#include "../scene/scene.h"

class Application {
private:
	bool m_isRunning{ false };
	Scene m_currentScene;

public:

	[[nodiscard]] bool getAppState() const { return m_isRunning; };
	void setAppState(const bool gameState) { m_isRunning = gameState; };

	Scene& getScene() { return m_currentScene; }
	void setScene(Scene scene) { m_currentScene = std::move(scene); }

	void start();
	void stop();
	void update();

	void processInput(std::string_view input);

	std::string receiveInput();


};
