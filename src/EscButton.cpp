#include "EscButton.hpp"
#include <utility> // move

EscButton::EscButton(AudioManager audio_manager) // quản lý âm thanh
        : Button(std::make_shared<Util::Image>(RESOURCE_DIR"/image/button/escbtn_up.png"), // Clone
                 std::make_shared<Util::Image>(RESOURCE_DIR"/image/button/escbtn_up.png"), // Hover
                 std::make_shared<Util::Image>(RESOURCE_DIR"/image/button/escbtn_down.png"), // Click
                 std::move(audio_manager)) {} // chuyển âm thanh và Class Button để quản lý thêm