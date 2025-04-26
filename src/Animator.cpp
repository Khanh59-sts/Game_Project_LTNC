

#include "Animator.hpp"
#include "Util/Animation.hpp"

#include <utility>

// Animator: Quản lý trạng thái hoạt ảnh

void Animator::SetAnimationStates(std::map<std::string, std::shared_ptr<Core::Drawable>, std::less<>> states) { // lưu trữ các trạng thái của hoạt ảnh
    animation_states_ = std::move(states);
    // tránh sao chép sai từ animation_states <-> states
}

void Animator::UpdateAnimationState(const std::string &animation_state_name,
                                    const std::function<void(std::shared_ptr<Core::Drawable>)> &set_drawable) {
    if (current_animation_state_ == animation_state_name) return;
    
    current_animation_state_ = animation_state_name;// cập nhật trạng thái
    set_drawable(animation_states_[animation_state_name]); // thiết lập đồ họa
    auto animation = std::dynamic_pointer_cast<Util::Animation>(animation_states_[animation_state_name]);
    if (animation == nullptr) return;
    animation->Play(); // chuyển thành util::Animation, gọi "Play" để phát
}

std::shared_ptr<Util::Animation> Animator::GetAnimation(const std::string& key) {
    return std::dynamic_pointer_cast<Util::Animation>(animation_states_[key]);
}
