#include "GameObject.hpp"

// Quản lý trạng thái đối tượng
void GameObject::Enable() 
{
    SetVisible(true); // hiển thị
    SetEnabled(true); // kích hoạt
}

void GameObject::Disable() 
{
    SetVisible(false);
    SetEnabled(false);
}