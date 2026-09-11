#pragma once
#include <string_view>
#include <vector>

#include "../entity/entity.h"
#include "../movement_system/movement_system.h"
#include "../render_system/render_system.h"

class Scene {
public:

private:
	std::vector<Entity> m_currentEntities;
	movementSystem m_movementSystem;
	renderSystem m_renderSystem;

public:

	Scene() = default;

	void init() {
		m_renderSystem.init();
	}

	void Update(double deltaTime){
		m_movementSystem.update(m_currentEntities, deltaTime);
	}

	void Render() {
		m_renderSystem.render(m_currentEntities);
	}

	void createEntity(std::string_view name) {
		Entity entity{name};
		m_currentEntities.push_back(entity);
	}

	void removeEntityByID(int id) {
		auto it = std::find_if(m_currentEntities.begin(), m_currentEntities.end(),
			[id](const Entity& ent) {
				return ent.getEntityID() == id;
			});

		if (it != m_currentEntities.end())
			m_currentEntities.erase(it);
	}

	Entity& getEntityByID(int id) {
		for (auto &ent : m_currentEntities) {
			if (ent.getEntityID() == id) { return ent; }
		}
		std::cout << "Entity Not Found with ID: " << id << std::endl;
	}

};