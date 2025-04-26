

#ifndef MAELDEVIL_BACKGROUND_HPP
#define MAELDEVIL_BACKGROUND_HPP


#include <memory>
#include "Util/Image.hpp"
#include "GameObject.hpp"

// Background: Hiển thị background và kế thừa từ GameObject
class Background : public GameObject {
public:
    explicit Background(const std::string &path);
};

#endif 
