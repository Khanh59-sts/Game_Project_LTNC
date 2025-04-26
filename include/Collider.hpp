
#ifndef MAELDEVIL_COLLIDER_HPP
#define MAELDEVIL_COLLIDER_HPP

#include "glm/vec2.hpp"

// Collider: Kiểm tra va chạm, xử lý va chạm

class Collider { // đại diện vùng va chạm (collision area) trong game
public:
    Collider(glm::vec2 position, glm::vec2 _size); 
    // Gồm vị trí "trung tâm" và size of collison area (height and width)

    glm::vec2 center{};
    glm::vec2 size{};


    float top;      // hình dung vùng va chạm là 1 ô vuông nhỏ
    float bottom;   // ...
    float left;     // ...
    float right;    // ...
};

/*
* #include "Collider.hpp"

int main() {
    Tạo một vùng va chạm với vị trí (100, 200) và kích thước (50, 50)
    Collider collider({100, 200}, {50, 50});

    collider.top = collider.center.y + collider.size.y / 2;
    collider.bottom = collider.center.y - collider.size.y / 2;
    collider.left = collider.center.x - collider.size.x / 2;
    collider.right = collider.center.x + collider.size.x / 2;

    Kiểm tra va chạm với một đối tượng khác (giả sử có hàm CheckCollision)
    if (CheckCollision(collider, other_collider)) { Xử lý va chạm }
    return 0;
}
*/

#endif 
