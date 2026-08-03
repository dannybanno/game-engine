#pragma once
#include <string_view>
#include <vector>

#include "../entity/entity.h"

class Scene {
public:

private:

	int m_xPos{ 0 };
	int m_yPos{ 0 };

	std::vector<Entity> m_currentEntities;

public:

	void Update(){};

	void createEntity(std::string_view name) {
		Entity entity{name};
		m_currentEntities.push_back(entity);
	}

	Entity getEntityByID(int id) {
		for (auto ent : m_currentEntities) {
			if (ent.getEntityID() == id) { return ent; }
		}
		std::cout << "Entity Not Found with ID: " << id << std::endl;
	}

};