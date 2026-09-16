//
// Created by user on 9/15/26.
//

#ifndef ECSPROJ_MESH_RESOURCE_H
#define ECSPROJ_MESH_RESOURCE_H
#include <string_view>

#include "../mesh/mesh.h"
#include "../render_mesh/render_mesh.h"


class meshResource {
private:
    Mesh m_mesh;
    renderMesh m_renderMesh;
public:

    meshResource(const Mesh& mesh) : m_mesh(mesh) {m_renderMesh.create(m_mesh);}

    // Prevents Copying
    meshResource(const meshResource&) = delete;
    meshResource& operator=(const meshResource&) = delete;

    meshResource(meshResource&&) noexcept = delete;
    meshResource& operator=(meshResource&&) noexcept = default;

    Mesh& getMesh() { return m_mesh; }
    renderMesh& getRenderMesh() { return m_renderMesh; }
};


#endif //ECSPROJ_MESH_RESOURCE_H
