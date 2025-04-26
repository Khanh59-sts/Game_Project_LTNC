#ifndef CORE_DEBUG_MESSAGE_CALLBACK_HPP
#define CORE_DEBUG_MESSAGE_CALLBACK_HPP

#include "pch.hpp" 

namespace Core {

void GLAPIENTRY OpenGLDebugMessageCallback(GLenum source, GLenum type,
                                           GLuint id, 
                                           GLenum severity, GLsizei length,
                                           const GLchar *message,
                                           const void *data);
} 

#endif
