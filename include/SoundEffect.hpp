

#ifndef MAELDEVIL_SOUNDEFFECT_HPP
#define MAELDEVIL_SOUNDEFFECT_HPP


#include <string>
#include "Util/SFX.hpp"

class SoundEffect {
public:
    explicit SoundEffect(const std::string_view path, float cooldown = 0);

    void Play();
    /*
    * Nếu cooldown > 0, kh phải âm thanh
    * gọi Play để phát, đặt cooldown bằng initial_cooldown
    */
    void Update();
    /*
    * Nếu cooldown > 0, giảm giá trị theo (delta_time)
    * Nếu cooldown < 0 thì đặt lại thành 0
    */


private:
    Util::SFX sfx_;
    float initial_cooldown_; // thời gian chờ BAN ĐẦU (Play) giữa các lần phát
    float cooldown_; // thời gian chờ HIỆN TẠI (Update) giữa các lần phát
};


#endif 
