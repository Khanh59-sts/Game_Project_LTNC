
#ifndef MAELDEVIL_COIN_HPP
#define MAELDEVIL_COIN_HPP

#include <string>
#include <glm/vec2.hpp> // phục vụ cho tính toán vector 2D và kích thước
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Animator.hpp"
#include "Character.hpp"
#include "AudioManager.hpp"
#include "SoundEffect.hpp"
#include "GameObject.hpp"

// Thêm XU
class Coin : public GameObject {
public:
    enum class State {
        Idle, // trạng thái chờ
        Trigger // đã "ăn"
    };

    explicit Coin(AudioManager audio_manager, const std::string &image_path = RESOURCE_DIR"/image/component/coin.png");

    void SetImage(const std::string &image_path);

    [[nodiscard]] inline Collider GetCollider() const override {
        return {GetPosition(), GetSize() - glm::vec2(42, 42)}; // lấy thông tin và giảm xuống 42, 42 cho phù hợp hình ảnh và logic va chạm
    }

    [[nodiscard]] inline State GetState() const { return current_state_; } // trả về Idle or Trigger

    void Update(const std::shared_ptr<Character> &character_); // Cập nhật trạng thái của Coins

private:
    State current_state_ = State::Idle; // Set ban đầu là Idle
    AudioManager audio_manager_;
    std::string image_path_;
};

#endif 