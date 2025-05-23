
#include <cmath>
#include <memory>
#include "Rigidbody.hpp"
#include "CollisionHandler.hpp"
#include "Collider.hpp"
#include "Sprite.hpp"

void Rigidbody::Update(const Collider &collider, const std::vector<std::shared_ptr<GameObject>> &walls,
                       const std::function<void(glm::vec2)> &translate) 
// Kiểm tra va chạm giữa walls, vật với walls
{
    SetVelocity(GetVelocity() + GetAcceleration());
    ResetAcceleration();

    glm::vec2 nearest_delta_position = GetVelocity();
    for (const auto &wall: walls) 
    {
        if (!wall->GetEnabled()) { continue; }
        glm::vec2 delta_velocity = CollisionHandler::SweepTest(collider, wall->GetCollider(), GetVelocity());
        // Dùng CollisionHandler để tránh va chạm


        if (hypot(GetVelocity().x, GetVelocity().y) != 0) 
        {
            if (abs(delta_velocity.x) < abs(nearest_delta_position.x)) 
            {nearest_delta_position.x = int(delta_velocity.x);}
            if (abs(delta_velocity.y) < abs(nearest_delta_position.y)) 
            {nearest_delta_position.y = int(delta_velocity.y);}
        }
    }
    SetVelocity(nearest_delta_position); // update vận tốc
    translate(GetVelocity()); // cập nhật vịt trí
}
