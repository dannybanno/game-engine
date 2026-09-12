//
// Created by user on 9/12/26.
//

#ifndef ECSPROJ_MESH_H
#define ECSPROJ_MESH_H
#include <array>


class Mesh {
private:
    std::array<float, 6> m_vertices{
        {
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.0f,  0.5f
        }
    };
public:

    const std::array<float, 6>& getVertices() const{
        return m_vertices;
    }
};


#endif //ECSPROJ_MESH_H
