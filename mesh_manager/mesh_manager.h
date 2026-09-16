//
// Created by user on 9/15/26.
//

#ifndef ECSPROJ_MESH_MANAGER_H
#define ECSPROJ_MESH_MANAGER_H
#include <stdexcept>
#include <unordered_map>
#include "../mesh_resource/mesh_resource.h"

class meshManager {

private:
    std::unordered_map<int, meshResource> m_meshes;

public:

    bool hasMesh(const int id) const{
        if (m_meshes.contains(id)) {
            return true;
        }else {
            return false;
        }
    }

    Mesh& getMesh(const int id) {
        if (m_meshes.contains(id)) {
            return m_meshes.at(id).getMesh();
        }else {
            throw std::out_of_range("Mesh ID not found");
        }
    }

    renderMesh& getRenderMesh(const int id) {
        if (m_meshes.contains(id)) {
            return m_meshes.at(id).getRenderMesh();
        }else {
            throw std::out_of_range("Render Mesh ID not found");
        }
    }

    void addMesh(int id, const Mesh& mesh) {
        m_meshes.try_emplace(id, mesh);
    }

};


#endif //ECSPROJ_MESH_MANAGER_H
