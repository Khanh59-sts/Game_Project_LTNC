

#ifndef MAELDEVIL_DOORBUTTON_HPP
#define MAELDEVIL_DOORBUTTON_HPP


#include "Button.hpp"
// DoorButton: Thêm tính năng mở cửa
class DoorButton : public Button {
public:
    explicit DoorButton(const std::shared_ptr<Core::Drawable> &idle, AudioManager audio_manager);

    void OnIdle() override; // ghi đè từ cơ sở Button, để xử lý hình ảnh và âm thanh
     
    void OnHover() override; // 
};


#endif 
