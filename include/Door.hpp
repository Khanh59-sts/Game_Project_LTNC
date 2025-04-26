

#ifndef MAELDEVIL_DOOR_HPP
#define MAELDEVIL_DOOR_HPP

#include <string>
#include <glm/vec2.hpp>
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Animator.hpp"
#include "Character.hpp"
#include "Collider.hpp"
#include "AudioManager.hpp"
#include "SoundEffect.hpp"

// Thêm cửa
class Door : public GameObject {
public:
    enum class State {
        Idle, 
        Delay, // Chờ
        CloseDoor
    };

    explicit Door(AudioManager audio_manager, std::vector<std::string> img_paths);

    [[nodiscard]] inline State GetState() const { return current_state_; }

    void Update(const std::shared_ptr<Character> &character_); // cập nhật trạng thái Door khi nhân vật bước vào

    State GetState() { return current_state_; }

private:
    State current_state_ = State::Idle;
    AudioManager audio_manager_;
    Animator animator_;
    float timer_ = 400; // Set trạng thái Delay 
};

#endif 