
#ifndef MAELDEVIL_CHARACTER_HPP
#define MAELDEVIL_CHARACTER_HPP

#include <string>
#include <glm/vec2.hpp>
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Util/SFX.hpp"
#include "Animator.hpp"
#include "Rigidbody.hpp" // xử lý vật lý 
#include "Collider.hpp" // xử lý va chạm
#include "SoundEffect.hpp"
#include "AudioManager.hpp"
// Thêm nhân vật
class Character : public GameObject {
public:
    enum class State {
        Alive,
        Dead,
        LevelClear,
        Vanish,
        Appear,
        Portal,
        Warp
    };

    explicit Character(AudioManager audio_manager); // tránh việc chuyển ngầm định từ AudioManager -> Character

    void SetCheckPoint(glm::vec2 check_point); // set tọa độ (checkpoint)

    inline void SetMoveSpeed(float speed) { move_speed_ = speed; } // speed nhân vật

    [[nodiscard]] inline Collider GetCollider() const override { return {GetPosition() - glm::vec2(2, 6), {32, 52}}; } // lấy tt va chạm...trả về tọa độ với...
    [[nodiscard]] inline State GetCurrentState() const { return current_state_; } // trả về trạng thái hiện tại
    [[nodiscard]] inline bool GetGod() const { return god_; } // God mode
    inline void ChangeGod() { god_ = !GetGod(); } 

    void CharacterMove(glm::vec2 input_velocity, const std::vector<std::shared_ptr<GameObject>> &walls); // di chuyển dựa trên tốc độ đầu vào và check va chạm tường
    void GodMove(glm::vec2 input_velocity); // GOD
    void Update(glm::vec2 input_velocity, const std::vector<std::shared_ptr<GameObject>> &walls); // cập nhật lại vị trí và trạng thái dựa trên tốc độ và walls

    [[nodiscard]] bool GroundCheck(const std::vector<std::shared_ptr<GameObject>> &others) const; // kiểm tra nhân vật đứng trên mặt đất hay không

    void Revive();
    void Dead();
    void Vanish();
    void Appear();
    void Bounce();
    void Warp();
    void UpdateState(State state);

private:
    State current_state_ = State::Alive;
    Animator animator_;
    Rigidbody rigidbody_;
    AudioManager audio_manager_;

    glm::vec2 check_point_ = { 0, 0 };
    float move_speed_ = 350;
    float jump_height_ = 12;
    float gravity_ = -1;  // Lực hút
    float spring_height_ = 24; // chiều cao nhân vật khi nhảy
    bool is_direction_right_ = true; // hướng di chuyển theo mũi tên
    bool is_run_ = false; // trạng thái chạy
    bool god_ = false; // God mode
};

#endif 
