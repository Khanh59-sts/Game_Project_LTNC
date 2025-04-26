

#ifndef MAELDEVIL_LEVELDEVIL_HPP
#define MAELDEVIL_LEVELDEVIL_HPP

#include "ILevel.hpp"
#include "AudioManager.hpp"
#include "Door.hpp"
#include "Character.hpp"
#include "Level.hpp"
#include "Background.hpp"
#include "Util/Renderer.hpp"
#include "Portal.hpp"
#include "Saw.hpp"
#include "Spike.hpp"
#include "Button.hpp"
#include "EscButton.hpp"
#include "TriggerCollider.hpp"
#include "Transition.hpp"

// LevelDevil: khởi tạo và tạo cấp độ 

class LevelDevil : public ILevel {
public:
    enum class State {
        Intro, // giới thiệu
        Start, // bắt đầu
        Move1, // di chuyển cấp độ
        Move2,
        Move3,
        Move4,
        Move5,
        Move6,
        Move7,
        Move8,
        Move9,
        Move10,
        Outro // kết thúc
    };

    explicit LevelDevil(AudioManager audio_manager, std::function<void(Level::State)> set_level_state_function);

    void Start() override; // ghi đè từ ILevel, tạo cấp độ từ ban dàua
    void Update() override; // ghi đè để cập nhật logic 

    void ResetLevel();
    void UpdateCurrentState(State state);
    void SpikeAct(); // xử lý bẫy gai từ Spike và Saw

private:
    Util::Renderer renderer_;
    State current_state_ = State::Intro;
    Level::State level_ = Level::State::LEVEL_7; // ban đầu là 7

    std::function<void(Level::State)> set_level_state_function_;

    AudioManager audio_manager_;
    Transition transition_;

    std::shared_ptr<Background> background_;
    std::shared_ptr<EscButton> button_;


    std::vector<std::shared_ptr<GameObject>> walls_; // danh sách walls
    std::vector<std::shared_ptr<Portal>> portals_;
    std::vector<std::shared_ptr<Saw>> saws_;
    std::vector<std::shared_ptr<Spike>> spikes_;
    std::vector<std::shared_ptr<TriggerCollider>> triggerColliders_; // vùng kích hoạt
    std::shared_ptr<Door> door_;
    std::shared_ptr<Character> character_;

    float spike_timer_ = 0; 
    int spike_num_ = 0;

    float delay_timer_ = 500;
    float revive_timer_ = 500; // coutdown
    float trap_speed_ = 370; // set tốc độ 370 pixel/s
    bool audio_trig_ = false; // cờ kích hoạt âm thanh
};

#endif 
