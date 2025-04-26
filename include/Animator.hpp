
#ifndef MAELDEVIL_ANIMATOR_HPP
#define MAELDEVIL_ANIMATOR_HPP

// Animator: SET - UPDATE - GET ==> ANIMATION
#include <string>
#include <memory>
#include <map>
#include "Core/Drawable.hpp"
#include "Util/Animation.hpp"
#include <functional> // truyền hàm callback

class Animator {
public:
    Animator() = default;

    void SetAnimationStates(std::map<std::string, std::shared_ptr<Core::Drawable>, std::less<>> states);
    void UpdateAnimationState(const std::string &animation_state_name,
                              const std::function<void(std::shared_ptr<Core::Drawable>)> &set_drawable);
    std::shared_ptr<Util::Animation> GetAnimation(const std::string& key);

private:
    std::string current_animation_state_;
    std::map<std::string, std::shared_ptr<Core::Drawable>, std::less<>> animation_states_;
};


#endif 
