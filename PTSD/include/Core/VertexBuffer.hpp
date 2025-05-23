#ifndef CORE_VERTEX_BUFFER_HPP
#define CORE_VERTEX_BUFFER_HPP

#include "pch.hpp" 

namespace Core {

class VertexBuffer {
public:
    VertexBuffer(const std::vector<float> &vertices,
                 unsigned int componentCount);
    VertexBuffer(const VertexBuffer &) = delete;
    VertexBuffer(VertexBuffer &&other);

    ~VertexBuffer();

    VertexBuffer &operator=(const VertexBuffer &) = delete;
    VertexBuffer &operator=(VertexBuffer &&other);

    unsigned int GetComponentCount() const { return m_ComponentCount; }
    GLenum GetType() const { return m_Type; }

    void Bind() const;
    void Unbind() const;

private:
    GLuint m_BufferId;

    unsigned int m_ComponentCount;
    GLenum m_Type = GL_FLOAT;
};
} 
#endif
