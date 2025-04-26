#include "CollisionHandler.hpp"
#include "Collider.hpp"

// Kiểm tra va chạm giữa các 2 đối tượng, hoặc 1 điểm với vùng va chạm,...


// Kiểm tra 2 vùng va chạm "CHỒNG" nhau
bool CollisionHandler::CheckCollision(const Collider &collider, const Collider &other) {
    return collider.right >= other.left && collider.left <= other.right && collider.top >= other.bottom &&
           collider.bottom <= other.top;
} 

// Kiểm tra xem (position) có nằm trong vùng va chạm ??!!
bool CollisionHandler::IsCollide(glm::vec2 position, const Collider &collider) {
    return collider.right > position.x && collider.left < position.x && collider.top > position.y &&
           collider.bottom < position.y;
} // ------
  // |  * |
  // |*  *|


// Quét kiểm tra va chạm dựa trên vận tốc giữa Collider Areas
glm::vec2 CollisionHandler::SweepTest(const Collider &collider, const Collider &other, glm::vec2 velocity) {

    float deltaX = velocity.x;
    float deltaY = velocity.y;

    if (collider.top > other.bottom && collider.bottom < other.top) { // nếu Y
        float d1; // kiểm tra va chạm theo X
        // xét đk deltaX để vùng 1 kh vượt qua vùng 2
        if (deltaX > 0 && collider.right <= other.left) {
            d1 = other.left - collider.right;

            if (d1 < deltaX) {
                deltaX = d1;
            }
        } else if (deltaX < 0 && collider.left >= other.right) {
            d1 = other.right - collider.left;

            if (d1 > deltaX) {
                deltaX = d1;
            }
        }
    }

    if (collider.right > other.left && collider.left < other.right) { // nếu X
        float d1;
        // kiểm tra va chạm theo Y
        if (deltaY > 0 && collider.top <= other.bottom) {
            d1 = other.bottom - collider.top;

            if (d1 < deltaY) {
                deltaY = d1;
            }
        } else if (deltaY < 0 && collider.bottom >= other.top) {
            d1 = other.top - collider.bottom;

            if (d1 > deltaY) {
                deltaY = d1;
            }
        }
    }
    return {deltaX, deltaY};
}
