
#include "Sprite.hpp"

Sprite::Sprite(const std::shared_ptr<Core::Drawable>& drawable, float z_index) : GameObject() {
    SetDrawable(drawable);
    SetZIndex(z_index);
}
