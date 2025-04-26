

#ifndef MAELDEVIL_MOVABLE_HPP
#define MAELDEVIL_MOVABLE_HPP

#include "GameObject.hpp"

// Movable: Di chuyển đến vị trí bất kỳ với tốc độ bất kỳ

class Movable {
public:
    static void Move(const std::shared_ptr<GameObject> &gameObject, glm::vec2 target_position, float speed);
}; // di chuyển từ vị trí hiện tại tới vị trí mục tiêu

/*
* void Movable::Move(const std::shared_ptr<GameObject> &gameObject, glm::vec2 target_position, float speed) {
    Lấy vị trí hiện tại của đối tượng
    glm::vec2 current_position = gameObject->GetPosition();

    Tính toán vector hướng
    glm::vec2 direction = target_position - current_position;

    Kiểm tra nếu đã đến vị trí mục tiêu
    if (glm::length(direction) < 0.01f) {
        return; // Đối tượng đã đến vị trí mục tiêu
    }

    Chuẩn hóa vector hướng
    direction = glm::normalize(direction);

    Tính toán vị trí mới
    float delta_time = 1.0f / 60.0f; // Giả sử tốc độ khung hình là 60 FPS
    glm::vec2 new_position = current_position + direction * speed * delta_time;

    Cập nhật vị trí của đối tượng
    gameObject->SetPosition(new_position);
*/
#endif 
