
#ifndef MAELDEVIL_COLLISIONHANDLER_HPP
#define MAELDEVIL_COLLISIONHANDLER_HPP


#include <glm/vec2.hpp>
#include <optional>
#include "Collider.hpp"
// CollisonHandler: Xử lý va chạm giữa đối tượng + ktra va chạm điểm 
class CollisionHandler {
public:
    static bool CheckCollision(const Collider &collider, const Collider &other); // kiểm tra nếu 2 vùng thì có CHỒNG nhau không ??

    static bool IsCollide(glm::vec2 position, const Collider &collider); // kiểm tra xem 1 vị trí có nằm trong vùng CA không ?

    static glm::vec2 SweepTest(const Collider &collider, const Collider &other, glm::vec2 velocity);
    // "quét" xem khi di chuyển thì va chạm với đối tượng khác không
};

/*
* #include "CollisionHandler.hpp"

int main() {
    // Tạo hai vùng va chạm
    Collider collider1({100, 200}, {50, 50});
    Collider collider2({120, 220}, {50, 50});

    // Kiểm tra va chạm
    if (CollisionHandler::CheckCollision(collider1, collider2)) {
        std::cout << "Collision detected!" << std::endl;
    } else {
        std::cout << "No collision." << std::endl;
    }

    // Kiểm tra va chạm điểm
    glm::vec2 point = {110, 210};
    if (CollisionHandler::IsCollide(point, collider1)) {
        std::cout << "Point is inside the collider!" << std::endl;
    }

    // Kiểm tra va chạm quét
    glm::vec2 velocity = {10, 0};
    glm::vec2 new_position = CollisionHandler::SweepTest(collider1, collider2, velocity);
    std::cout << "New position after sweep test: (" << new_position.x << ", " << new_position.y << ")" << std::endl;

    return 0;
}
*/
#endif 
