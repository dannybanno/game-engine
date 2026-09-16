//
// Created by user on 9/12/26.
//

#ifndef ECSPROJ_MESH_H
#define ECSPROJ_MESH_H
#include <array>
#include <vector>


class Mesh {
private:
    std::vector<float> m_vertices{};
public:

    Mesh(const std::vector<float>& vertices) : m_vertices(vertices) {};

    const std::vector<float>& getVertices() const{
        return m_vertices;
    }
};


#endif //ECSPROJ_MESH_H
