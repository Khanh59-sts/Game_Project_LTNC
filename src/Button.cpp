

#include "Button.hpp"
#include "Util/Input.hpp"
#include "CollisionHandler.hpp"


// khởi tạo Button với các trạng thái đồ họa và âm thanh
Button::Button(const std::shared_ptr<Core::Drawable> &idle, const std::shared_ptr<Core::Drawable> &hover,
               const std::shared_ptr<Core::Drawable> &click, AudioManager audio_manager, float z_index)
        : GameObject(), audio_manager_(std::move(audio_manager)) {
    SetDrawable(idle);
    SetZIndex(z_index); // thứ tự hiển thị nút
    animator_.SetAnimationStates({{"Idle",  idle},
                                  {"Hover", hover},
                                  {"Click", click}});
}

void Button::UpdateState(Button::State state) {
    if (current_state_ == state) return;

    current_state_ = state;

    switch (current_state_) {
        case State::Idle:
            OnIdle();
            break;
        case State::Hover:
            OnHover();
            break;
        case State::Click:
            OnClick();
            audio_manager_.Play(AudioManager::SFX::Button); // Hiển thị âm thanh "Click"
            break;
    }
}

// Xử lý va chạm với Button
void Button::Update() {
    if (CollisionHandler::IsCollide({Util::Input::GetCursorPosition().x, -Util::Input::GetCursorPosition().y}, // kiểm tra Pointer có trong CA
                                    GetCollider())) {
        UpdateState(State::Hover); // nếu "va chạm" thì chuyển sang "Giữ"
        if (Util::Input::IsKeyUp(Util::Keycode::MOUSE_LB)) { // nếu "nhả" chuyển sang "Click"
            UpdateState(State::Click); // nếu "không va chạm" chuyển sang Idle
        }
    } else {
        UpdateState(State::Idle);
    }
}

void Button::Enable() {
    SetVisible(true);
    UpdateState(State::Idle);
}

void Button::Disable() {
    SetVisible(false);
    UpdateState(State::Idle);
}

void Button::OnClick() {
    animator_.UpdateAnimationState("Click", [this](const std::shared_ptr<Core::Drawable> &drawable) {
        this->SetDrawable(drawable); // cập nhật đồ họa
    });
}

void Button::OnHover() {
    animator_.UpdateAnimationState("Hover", [this](const std::shared_ptr<Core::Drawable> &drawable) {
        this->SetDrawable(drawable);
    });
}

void Button::OnIdle() {
    animator_.UpdateAnimationState("Idle", [this](const std::shared_ptr<Core::Drawable> &drawable) {
        this->SetDrawable(drawable);
    });
}
