

#ifndef MAELDEVIL_SPRING_HPP
#define MAELDEVIL_SPRING_HPP

#include <string>
#include <glm/vec2.hpp>
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Animator.hpp"
#include "Character.hpp"


// Sping: Tạo lò xo 

class Spring : public GameObject {
public:
    enum class State {
        Up, // bật lên 
        Down // hạ xuống
    };

    explicit Spring(std::vector<std::string> image_paths, AudioManager audio_manager);

    [[nodiscard]] inline Collider GetCollider() const override {
        return {GetPosition() - glm::vec2(0, 21), GetSize() - glm::vec2(0, 42)}; // xử lý va chạm qua giảm kích thước và dịch chuyển vị trí
    }

    void Update(const std::shared_ptr<Character> &character_);

    void Reset(); // thường là down
  
private:
    Animator animator_;
    AudioManager audio_manager_;
    float draw_timer_ = 500; // thời gian vẽ và cập nhật sping
    float bounce_timer_ = 100; // thời gian quản lý hiệu ứng bật lên
    State current_state_ = State::Down;
};

#endif 