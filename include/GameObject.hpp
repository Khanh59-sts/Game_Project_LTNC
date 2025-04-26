

#ifndef MAELDEVIL_GAMEOBJECT_HPP
#define MAELDEVIL_GAMEOBJECT_HPP

#include "Util/GameObject.hpp"
#include "Collider.hpp" 

// GameObject: Tạo đối tượng cho game (vị trí, kích thước)

class GameObject : public Util::GameObject {
public:
    GameObject() = default;

    inline void SetPosition(glm::vec2 position) { m_Transform.translation = position; } // Vector 2D
    inline void SetRotation(float rotation) { m_Transform.rotation = rotation; } // Quay
    inline void SetEnabled(bool enabled) { enabled_ = enabled; }

    [[nodiscard]] inline glm::vec2 GetPosition() const { return m_Transform.translation; } // lấy vị trí
    [[nodiscard]] inline glm::vec2 GetSize() const { return m_Drawable->GetSize(); } // Lấy kích thước
    [[nodiscard]] virtual inline Collider GetCollider() const { return {GetPosition(), GetSize()}; } // Lấy thông tin va chạm
    [[nodiscard]] inline bool GetEnabled() const { return enabled_; }

    virtual void Enable(); // phương thức ảo để ghi đè trong Class con
    virtual void Disable();

private:
    bool enabled_ = true;
};


#endif 
