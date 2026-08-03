#pragma once
#include <iostream>
#include <ostream>
#include <string>

#include "../transform/transform.h"



class Entity {
private:
    Transform m_entTransform;
    std::string m_entityName;

    static inline int s_idGenerator {1};
    int m_entityID;

public:

    Entity(std::string_view entName) :
    m_entTransform{ 0, 0 },
    m_entityID { s_idGenerator++ },
    m_entityName{ entName } {};

    [[nodiscard]] int getEntityID() const { return m_entityID;}
    [[nodiscard]] std::string_view getEntityName() const { return m_entityName; }

};
