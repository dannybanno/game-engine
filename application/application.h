#pragma once
#include <string>
#include <utility>
#include <vector>

#include "../scene/scene.h"
#include "../input/input.h"
#include "../window/window.h"


class Application {
private:
	bool m_isRunning{ false };
	Scene m_currentScene;
	Input m_currentInput;

	window m_window;

public:

	[[nodiscard]] bool getAppState() const { return m_isRunning; };
	void setAppState(const bool gameState) { m_isRunning = gameState; };

	Scene& getScene() { return m_currentScene; }
	void setScene(Scene scene) { m_currentScene = std::move(scene); }

	Input& getInputSys() { return m_currentInput; }
	void setInputSys(Input input) { m_currentInput = std::move(input); }

	void start();
	void stop();
	void update();

	window& getWindow() {
		return m_window;
	}

};
