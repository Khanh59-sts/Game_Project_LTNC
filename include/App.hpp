#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // tăng tốc độ biên dịch thôi
#include "ILevel.hpp" // Giao diện Level 
#include "Level.hpp" 
#include "AudioManager.hpp"

// App: Quản lý và Combine giữa ILevel + AudioManager + Logic Game

class App {
public:
    enum class State {
        START, // Khởi động
        UPDATE, // Logic Game
        END // END GAME
    };


    [[nodiscard]] inline State GetCurrentState() const { return current_state_; } // warning nếu trả về "no used"


    void UpdateCurrentLevelState(Level::State level_state); // Đồng bộ trạng thái level
    void Start();
    void Update();
    void End(); 

// Thuộc tính riêng
private:
    State current_state_ = State::START; // Lưu ban đầu là START
    Level::State current_level_state_ = Level::State::LEVEL_SELECT; // Lưu ban đầu là Level 1

    std::unique_ptr<ILevel> level_ = nullptr;
    AudioManager audio_manager_;
};

#endif
