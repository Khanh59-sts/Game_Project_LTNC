

#ifndef MAELDEVIL_SPIKE_HPP
#define MAELDEVIL_SPIKE_HPP

#include <string>
#include <glm/vec2.hpp>
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Animator.hpp"
#include "Character.hpp"
#include "AudioManager.hpp"
#include "SoundEffect.hpp"


// Spike: đại diện bẫy gai

class Spike : public GameObject {
public:
    enum class Position {
        Top,
        Bottom,
        Left,
        Right
    };

    explicit Spike(const std::string &image_path, Position position_inbox, AudioManager audio_manager);
                                                 // Vị trí spike trong hộp va chạm

    void SetImage(const std::string &image_path);

    [[nodiscard]] Collider GetCollider() const override;

    void Update(const std::shared_ptr<Character> &character);

    void Enable() override; // ghi đè từ GameObject để kích hoạt

private:
    Position position_inbox_ = Position::Bottom; // set mặc định
    std::string image_path_;
    AudioManager audio_manager_;
};

#endif 