#ifndef CORE_UNIFORM_BUFFER_HPP
#define CORE_UNIFORM_BUFFER_HPP

#include "pch.hpp" 

#include "Core/Program.hpp"

namespace Core {

template <typename T>
class UniformBuffer {
public:
    UniformBuffer(const Program &program, const std::string &name, int binding);
    UniformBuffer(const UniformBuffer &) = delete;
    UniformBuffer(UniformBuffer &&other);

    ~UniformBuffer();

    UniformBuffer &operator=(const UniformBuffer &) = delete;
    UniformBuffer &operator=(UniformBuffer &&other);

    void SetData(int offset, const T &data);

private:
    GLuint m_Binding;
    GLuint m_BufferId;
};
} 

#include "UniformBuffer.inl"

#endif
