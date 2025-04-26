
#ifndef MAELDEVIL_BUTTON_HPP
#define MAELDEVIL_BUTTON_HPP


#include "Animator.hpp" // Hoạt ảnh 
#include "Collider.hpp" // Xử lí va chạm
#include "Util/Image.hpp" // Hình ảnh
#include "Util/SFX.hpp" // Quản lý hiệu ứng âm thanh
#include "AudioManager.hpp" // Quản lý âm thanh chung
#include "SoundEffect.hpp" // Xử lý âm thanh cụ thể
#include "GameObject.hpp" // Bố của Button

// Button: Quản lý các nút Idle + Hover + Click

class Button : public GameObject {
public:
    enum class State {
        Idle, // Clone
        Hover,
        Click
    };
    // explicit: ngăn chặn việc chuyển đổi ngầm định
    explicit Button(const std::shared_ptr<Core::Drawable> &idle, // ảnh
                    const std::shared_ptr<Core::Drawable> &hover,
                    const std::shared_ptr<Core::Drawable> &click, 
                    AudioManager audio_manager,
                    float z_index = 10); // thứ tự hiển thị nút

    [[nodiscard]] inline State GetState() const { return current_state_; } // warning nếu trả về 3 trạng thái của nút trên "không được sử dụng"

    void UpdateState(State state); // Idle -> Hover
    void Update(); // New Logic of Nút
    void Enable() override; // Cho phép Nút
    void Disable() override; // Vô hiệu hóa Nút với pp ghi đè từ Bố (GameObject)
    virtual void OnClick(); // Phương thức ảo để xử lí
    virtual void OnHover();
    virtual void OnIdle();



private:
    AudioManager audio_manager_;
    Animator animator_;
    State current_state_ = State::Idle;
};
#endif 
