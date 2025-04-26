

#ifndef MAELDEVIL_SPRITE_HPP
#define MAELDEVIL_SPRITE_HPP


// Sprite: đại diện đối tượng đồ họa như Character,... 

#include <string>
#include "Collider.hpp"
#include "GameObject.hpp"

class Sprite : public GameObject{
public:
    explicit Sprite(const std::shared_ptr<Core::Drawable> &drawable, float z_index = 0);
};


#endif 
