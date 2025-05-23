#ifndef CORE_CONTEXT_HPP
#define CORE_CONTEXT_HPP

#include "pch.hpp" 
#include "config.hpp"
#include "Util/Time.hpp"

namespace Core {
class Context {
public:
   
    Context();
    Context(const Context &) = delete;
    Context(Context &&) = delete;

    ~Context();

    Context &operator=(const Context &) = delete;
    Context &operator=(Context &&) = delete;

    static std::shared_ptr<Context> GetInstance();

    bool GetExit() const { return m_Exit; }
    unsigned int GetWindowWidth() const { return m_WindowWidth; }
    unsigned int GetWindowHeight() const { return m_WindowHeight; }

    void SetExit(bool exit) { m_Exit = exit; }
    void SetWindowWidth(unsigned int width) { m_WindowWidth = width; }
    void SetWindowHeight(unsigned int height) { m_WindowHeight = height; }
    void SetWindowIcon(const std::string &path);

    void Setup();
    void Update();

private:
    SDL_Window *m_Window;
    SDL_GLContext m_GlContext;

    static std::shared_ptr<Context> s_Instance;
    bool m_Exit = false;

    unsigned int m_WindowWidth = PTSD_Config::WINDOW_WIDTH;
    unsigned int m_WindowHeight = PTSD_Config::WINDOW_HEIGHT;

    Util::ms_t m_BeforeUpdateTime = Util::Time::GetElapsedTimeMs();
};
} 

#endif
