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

    meshResource(Mesh& mesh, renderMesh& renderMesh) : m_mesh(mesh), m_renderMesh(renderMesh) {}

    Mesh& getMesh() { return m_mesh; }
    renderMesh& getRenderMesh() { return m_renderMesh; }
};


#endif //ECSPROJ_MESH_RESOURCE_H
