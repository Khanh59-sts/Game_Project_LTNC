

#ifndef MAELDEVIL_PORTAL_HPP
#define MAELDEVIL_PORTAL_HPP

#include <string>
#include <glm/vec2.hpp>
#include "GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Animator.hpp"
#include "Character.hpp"

// Portal: Tạo cổng dịch chuyển qua màn chơi

class Portal : public GameObject {
public:
    enum class State {
        State1, // đầu tiên của cổng
        State2 // thứ 2 của cổng
    };

    explicit Portal(std::vector<std::string> image_paths, AudioManager audio_manager, glm::vec2 position = { 0,0 });

    inline void SetGoal(glm::vec2 position) { goal_ = position; } // đặt vị trí mục tiêu của cổng 

    [[nodiscard]] inline Collider GetCollider() const override{
        return {GetPosition() - glm::vec2(0, 21), GetSize() - glm::vec2(0, 42)}; // xử lý va chạm -> giảm kích thước và vị trí
    }

    void Update(const std::shared_ptr<Character> &character_); // cập nhật trạng thái của cổng dựa trên tương tác với nhân vật

    inline bool IsCollide() { return iscollide_; } // Check cổng có đang "va chạm" với nhân vật không

    void Enable() override; // ghi đè từ GameObject để "kích hoạt cổng"

private:
    Animator animator_;
    AudioManager audio_manager_;

    float draw_timer_ = 300; // thời gian vẽ và cập nhật cổng
    float speed_ = 100; // tốc độ dịch chuyển của cổng
    glm::vec2 goal_;
    State current_state_ = State::State1; // ban đầu là cổng 1
    bool iscollide_ = false; // set false cho cổng "có đang" va chạm nhân vật
};

#endif 