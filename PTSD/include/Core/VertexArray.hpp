#ifndef CORE_VERTEX_ARRAY_HPP
#define CORE_VERTEX_ARRAY_HPP

#include "pch.hpp" 

#include "Core/IndexBuffer.hpp"
#include "Core/VertexBuffer.hpp"

namespace Core {

class VertexArray {
public:
    VertexArray();
    VertexArray(const VertexArray &) = delete;
    VertexArray(VertexArray &&other);

    ~VertexArray();

    VertexArray &operator=(const VertexArray &) = delete;
    VertexArray &operator=(VertexArray &&other);

    void Bind() const;
    void Unbind() const;

    void AddVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer);
   
    void SetIndexBuffer(std::unique_ptr<IndexBuffer> indexBuffer);

    void DrawTriangles() const;

private:
    GLuint m_ArrayId;

    std::vector<std::unique_ptr<VertexBuffer>> m_VertexBuffers;
    std::unique_ptr<IndexBuffer> m_IndexBuffer;
};
} 
#endif
