
#include "TriggerCollider.hpp"
#include "CollisionHandler.hpp"


// Quản lý vùng va chạm, kích hoạt TRAP
void TriggerCollider::Update(glm::vec2 position) 
{
    // Kiểm tra va chạm
    if (CollisionHandler::IsCollide(position, GetCollider())) 
    {
        UpdateState(State::Trigger);
        return;
    }
    UpdateState(State::Idle);
}

void TriggerCollider::UpdateState(TriggerCollider::State state) 
{
    if (current_state_ == state)return;
    current_state_ = state;
}
