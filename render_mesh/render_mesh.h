//
// Created by user on 9/12/26.
//

#ifndef ECSPROJ_RENDER_MESH_H
#define ECSPROJ_RENDER_MESH_H
#include "glad/gl.h"

class renderMesh {
private:
    GLuint m_vao{};
    GLuint m_vbo{};
    GLsizei m_vertexCount{};

public:
    GLuint getVAO() const{
        return m_vao;
    }

    GLuint& getVBO() {
        return m_vbo;
    }

    GLsizei getVertexCount() const {
        return m_vertexCount;
    }

    void create(const Mesh& mesh) {
        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &m_vbo);

        glBindVertexArray(m_vao);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

        glBufferData(
            GL_ARRAY_BUFFER,
            mesh.getVertices().size() * sizeof(float),
            mesh.getVertices().data(),
            GL_STATIC_DRAW
            );

        glVertexAttribPointer(
            0, // index -> location = 0.
            2, // 2 components -> x, y
            GL_FLOAT, // component type
            GL_FALSE, // normalise?
            2 * sizeof(float), // bytes from pos to next
            (void*)0
        );

        m_vertexCount = static_cast<GLsizei>(mesh.getVertices().size() / 2);

        glEnableVertexAttribArray(0);
    }

};

#endif //ECSPROJ_RENDER_MESH_H
