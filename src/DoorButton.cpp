#include "DoorButton.hpp"
#include <utility>

DoorButton::DoorButton(const std::shared_ptr<Core::Drawable> &idle, AudioManager audio_manager)
        : Button(idle, idle, idle, std::move(audio_manager)) {}

void DoorButton::OnIdle() // ghi đè phương thức OnIdle từ Button
{ // Xét các nút ở "Idle", đối tượng con của DoorButton sẽ ẩn
    for (const auto &child: m_Children) 
    {child->SetVisible(false);}
}

void DoorButton::OnHover() 
{ // "Hover" thì con sẽ hiển thị
    for (const auto &child: m_Children) 
    {child->SetVisible(true);}
}
