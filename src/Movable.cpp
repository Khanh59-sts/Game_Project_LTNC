
#include "Movable.hpp"
#include "Util/Time.hpp"

void Movable::Move(const std::shared_ptr<GameObject> &gameObject, glm::vec2 target_position, float speed) 
{
    auto vector = target_position - gameObject->GetPosition(); // tính 
    auto normalize = vector / hypot(vector.x, vector.y); // chuẩn hóa

    if (hypot(vector.x, vector.y) != 0) // nếu kc giữa hiện tại và mục tiêu khác 0, tiếp tục di chuyển
    {
        auto position = speed * Util::Time::GetDeltaTimeMs() / 1000 * normalize; // tính khoảng cách di chuyển
        auto new_position = glm::vec2(int(position.x), int(position.y)); // làm tròn


        if (abs(new_position.x) < abs(vector.x) || abs(new_position.y) < abs(vector.y)) // nếu kc di chuyển nhỏ hơn thì cập nhật luôn vị trí hiện tại
        { gameObject->SetPosition(gameObject->GetPosition() + new_position); } 
        else 
        { gameObject->SetPosition(target_position); }
    }
}
