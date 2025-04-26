

#ifndef MAELDEVIL_TRANSITION_HPP
#define MAELDEVIL_TRANSITION_HPP


#include <functional>
#include "GameObject.hpp"
#include "Sprite.hpp"


// Transition: Quản lý hiệu ứng chuyển cảnh

class Transition {
public:
    Transition();

    [[nodiscard]] inline std::shared_ptr<GameObject> GetTop() const { return top_; } // lấy đối tượng Sprite ở trên
    [[nodiscard]] inline std::shared_ptr<GameObject> GetBottom() const { return bottom_; } // Lấy đối tượng Sprite ở dưới

    inline void ResetTimer() { transition_timer_ = 0; } // đặt thời gian hiệu ứng chuyển cảnh là 0

    void Intro(const std::function<void()> &function); // chuyển cảnh vào
    void Outro(const std::function<void()> &function); // chuyển cảnh ra

private:
    std::shared_ptr<Sprite> top_;
    std::shared_ptr<Sprite> bottom_;

    float transition_timer_ = 0; // thời gian quản lý tiến trình Transition
    float transition_delta_time_multiple_ = 0.003f; // tốc độ hiệu ứng chuyển cảnh, mặc định là 0.003f
    float transition_end_timer_ = 0; // thời gian khi nào kết thúc Transition
    float transition_end_delay_ = 300; // độ trễ trước khi kết thúc chuyển cảnh
};


#endif 
