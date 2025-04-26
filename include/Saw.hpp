

#ifndef MAELDEVIL_SAW_HPP
#define MAELDEVIL_SAW_HPP

#define _USE_MATH_DEFINES // để sử dụng hằng số toán học 

#include <string>
#include <glm/vec2.hpp>
#include <cmath>
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Animator.hpp"
#include "Character.hpp"
#include "AudioManager.hpp"
#include "SoundEffect.hpp"

// Saw: Tạo cưa (Chướng ngại vật)

class Saw : public GameObject {
public:
    explicit Saw(const std::string& image_path, AudioManager audio_manager);

    void SetImage(const std::string& image_path);
    void Update(const std::shared_ptr<Character>& character); // cập nhật sau khi tương tác với nhân vật

    void Enable() override; // kích hoạt từ GameObject
    void Disable() override; // vô hiệu hóa từ GameObject

private:
    std::string image_path_;
    AudioManager audio_manager_;
    float angle_ = 0; // góc 
    float rotate_ = 2 * M_PI / 16; // góc quay mỗi lần cập nhật
    float rotate_timer_ = 100; // tốc độ quay của cưa
};

#endif 