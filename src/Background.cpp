

#include "Background.hpp"

Background::Background(const std::string &path) : GameObject() {
    SetDrawable(std::make_unique<Util::Image>(path));
    SetZIndex(-10); // của GameObject, z-index cho -10 để nền được vẽ "đằng sau" các GameObject khác
}