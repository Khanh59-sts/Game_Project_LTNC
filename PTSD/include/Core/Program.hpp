#ifndef CORE_PROGRAM_HPP
#define CORE_PROGRAM_HPP

#include "pch.hpp" 

namespace Core {

class Program {
public:
    Program(const std::string &vertexShaderFilepath,
            const std::string &fragmentShaderFilepath);
    Program(const Program &) = delete;
    Program(Program &&other);

    ~Program();

    Program &operator=(const Program &) = delete;
    Program &operator=(Program &&other);

    GLuint GetId() const { return m_ProgramId; }

    void Bind() const;
    void Unbind() const;

    void Validate() const;

private:
    void CheckStatus() const;

    GLuint m_ProgramId;
};
} 
#endif
