
#ifndef MAELDEVIL_RIGIDBODY_HPP
#define MAELDEVIL_RIGIDBODY_HPP


#include <glm/vec2.hpp>
#include <functional>
#include "Collider.hpp"
#include "Sprite.hpp"

class Rigidbody {
public:
    Rigidbody() = default;


    inline void SetAcceleration(glm::vec2 acceleration) { acceleration_ = acceleration; } // gia tốc
    inline void SetVelocity(glm::vec2 velocity) { velocity_ = velocity; } // vận tốc


    [[nodiscard]] inline glm::vec2 GetAcceleration() const { return acceleration_; }
    [[nodiscard]] inline glm::vec2 GetVelocity() const { return velocity_; }


    inline void ResetAcceleration() { acceleration_ = {0, 0}; }
    inline void ResetVelocity() { velocity_ = {0, 0}; }
    inline void AddAcceleration(glm::vec2 acceleration) { acceleration_ += acceleration; } // thêm giá trị gia tốc vào gia tốc hiện tại


    void Update(const Collider &collider, const std::vector<std::shared_ptr<GameObject>> &walls,
                const std::function<void(glm::vec2)> &translate); // cập nhật trạng thái GameObject dựa trên vận tốc, gia tốc, xử lí va chạm qua đó
    // gọi hàm translate để cập nhật vị trí của GameObject


private:
    glm::vec2 acceleration_ = {0, 0};
    glm::vec2 velocity_ = {0, 0};
};


/*
* Update: vận tốc hiện tại += gia tốc hiện tại * thời gian giữa 2 khung hình
* void Rigidbody::Update(const Collider &collider, const std::vector<std::shared_ptr<GameObject>> &walls,
                       const std::function<void(glm::vec2)> &translate) {
    Giả sử delta_time là 1/60 giây (60 FPS)
    float delta_time = 1.0f / 60.0f;

    Tính toán vận tốc mới
    velocity_ += acceleration_ * delta_time;

    Tính toán khoảng cách di chuyển
    glm::vec2 displacement = velocity_ * delta_time;

    Kiểm tra va chạm với các tường
    for (const auto &wall : walls) {
        if (collider.CheckCollision(wall->GetCollider())) {
            // Xử lý va chạm (ví dụ: đặt lại vận tốc)
            velocity_ = {0, 0};
            return;
        }
    }

    Dịch chuyển đối tượng
    translate(displacement);
*/

#endif 
