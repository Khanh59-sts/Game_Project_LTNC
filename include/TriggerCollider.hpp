

#ifndef MAELDEVIL_TRIGGERCOLLIDER_HPP
#define MAELDEVIL_TRIGGERCOLLIDER_HPP

#include "Util/GameObject.hpp"
#include "glm/vec2.hpp"
#include "Collider.hpp"


// TriggerCollider: Quản lý vùng va chạm kích hoạt bẫy, bật,...

class TriggerCollider {
public:
    enum class State {
        Idle, // chưa 
        Trigger // rồi
    };

    explicit TriggerCollider(Collider collider) : position_(collider.center), size_(collider.size) {}; // khởi tạo lấy giá trị từ collider.center và size

    inline glm::vec2 GetPosition() { return position_; }
    inline glm::vec2 GetSize() { return size_; }

    inline Collider GetCollider() { return {GetPosition(), GetSize()}; } // lấy đại diện vùng va chạm
    inline State GetState() { return current_state_; } // lấy trạng thái hiện tại

    inline void SetPosition(glm::vec2 position) { position_ = position; } // đặt vị trí mới
    inline void SetSize(glm::vec2 size) { size_ = size; } // đặt kích thước mới

    void UpdateState(TriggerCollider::State state); // cập nhật trạng thái
    void Update(glm::vec2 position); // cập nhật vị trí

private:
    State current_state_ = State::Idle;
    glm::vec2 position_ = {0, 0};
    glm::vec2 size_ = {0, 0};
};


#endif 
