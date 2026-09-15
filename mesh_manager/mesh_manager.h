//
// Created by user on 9/15/26.
//

#ifndef ECSPROJ_MESH_MANAGER_H
#define ECSPROJ_MESH_MANAGER_H
#include <unordered_map>
#include "../mesh_resource/mesh_resource.h"

class meshManager {

private:
    std::unordered_map<int, meshResource> m_meshes;

public:

    bool hasMesh(int id) const{
        if (m_meshes.find(id) != m_meshes.end()) {
            return true;
        }else {
            return false;
        }
    }

    Mesh& getMesh(const int id) {
        if (m_meshes.find(id) != m_meshes.end()) {
            return m_meshes.at(id).getMesh();
        }
    }

    renderMesh& getRenderMesh(const int id) {
        if (m_meshes.find(id) != m_meshes.end()) {
            return m_meshes.at(id).getRenderMesh();
        }
    }

    void addMesh(int id, meshResource& mesh) {
        m_meshes.insert({id, mesh});
    }

};


#endif //ECSPROJ_MESH_MANAGER_H
