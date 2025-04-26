

#ifndef MAELDEVIL_LEVELSELECT_HPP
#define MAELDEVIL_LEVELSELECT_HPP

#include <utility>

#include "ILevel.hpp"
#include "DoorButton.hpp"
#include "Sprite.hpp"
#include "Background.hpp"
#include "Level.hpp"
#include "Util/Renderer.hpp"
#include "AudioManager.hpp"
#include "Transition.hpp"

// LevelSelect: Khởi tạo và chạy giao diện chọn cấp độ 

class LevelSelect : public ILevel {
public:
    enum class State {
        Intro, // giới thiệu Giao diện
        Start,
        Outro
    };

    explicit LevelSelect(AudioManager audio_manager, std::function<void(Level::State)> set_level_state_function);
    void Start() override;
    void Update() override;
    void UpdateCurrentState(State state);

private:
    Util::Renderer renderer_;
    State current_state_ = State::Intro;
    Level::State level_ = Level::State::LEVEL_SELECT;

    std::function<void(Level::State)> set_level_state_function_;

    AudioManager audio_manager_; // quản lí âm thanh
    Transition transition_; // quản lí hiệu ứng chuyển cảnh
    std::shared_ptr<Background> background_; 
    std::vector<std::shared_ptr<DoorButton>> door_buttons_;
    std::vector<std::shared_ptr<Sprite>> button_hovers_;
};


#endif 
