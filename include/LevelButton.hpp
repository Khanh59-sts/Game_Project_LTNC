

#ifndef MAELDEVIL_LEVELBUTTON_HPP
#define MAELDEVIL_LEVELBUTTON_HPP

#include <string>
#include <glm/vec2.hpp>
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Animator.hpp"
#include "AudioManager.hpp"
#include "SoundEffect.hpp"
#include "Character.hpp"

// LevelButton: Thêm 1 nút chọn cấp độ vào Game

class LevelButton : public GameObject {
public:
    enum class State {
        Up, // Chưa "nhấn"
        Down // Đã "nhấn"
    };

    explicit LevelButton(AudioManager audiomanager);

    [[nodiscard]] inline Collider GetCollider() const override {
        return {GetPosition() - glm::vec2(0, 21), GetSize() - glm::vec2(24, 42)}; // xử lý va chạm -> giảm kích thước và set lại vị trí
    }

    inline void SetUp() { current_state_ = State::Up; }

    inline State GetcurrentState() { return current_state_; }

    void Update(const std::shared_ptr<Character> &character); // cập nhật lại State dựa trên tương tác của nhân vật

private:
    Animator animator_;
    AudioManager audiomanager_;
    State current_state_ = State::Up;
};

#endif 