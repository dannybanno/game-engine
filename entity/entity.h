#pragma once
#include <iostream>
#include <ostream>
#include <string>

#include "../transform/transform.h"
#include "../mesh/mesh.h"
#include "../render_mesh/render_mesh.h"


class Entity {
private:
    inline static Entity* instance;

    Transform m_entTransform;
    std::string m_entityName;

    static inline int s_idGenerator {1};
    int m_entityID;

    std::vector<double> velocity{1, 1};

    Mesh m_mesh;
    renderMesh m_renderMesh;

public:

    Entity(std::string_view entName) :
        m_entTransform{ 0, 0 },
        m_entityID{ s_idGenerator++ },
        m_entityName{ entName }
    {
        instance = this;
    };

    ~Entity() {
        if (instance == this)
            instance = nullptr;
    }

    void update(double deltaTime) {
        std::cout << "Updated: " << m_entityName << std::endl;
    }

    Transform& getTransform() {
        return m_entTransform;
    }

    Mesh& getMesh() {
        return m_mesh;
    }

    [[nodiscard]] const Mesh& getMesh() const{
        return m_mesh;
    }

    renderMesh& getRenderMesh() {
        return m_renderMesh;
    }

    [[nodiscard]] const renderMesh& getRenderMesh() const{
        return m_renderMesh;
    }


    static bool exists() {
        return instance != nullptr;
    }

    static Entity* getInstance() {
        return instance;
    }

    [[nodiscard]] int getEntityID() const { 
        return m_entityID;
    }

    [[nodiscard]] std::string_view getEntityName() const {
        return m_entityName;
    }


    // Accessing Transform - get / set through entity
    void setPosition(double x, double y) {
        m_entTransform.setTransformX(x);
        m_entTransform.setTransformY(y);
    }
    void setPosX(double x) { m_entTransform.setTransformX(x); }
    void setPosY(double y) { m_entTransform.setTransformY(y); }

    [[nodiscard]] double getTransformX() const { return m_entTransform.getTransformX(); };
    [[nodiscard]] double getTransformY() const { return m_entTransform.getTransformY(); };

    // Velocity
    [[nodiscard]] std::vector<double>& getVelocity() { return velocity; }
    void setVelocityX(double x) { velocity[0] = x; }
    void setVelocityY(double y) { velocity[1] = y; }

};

