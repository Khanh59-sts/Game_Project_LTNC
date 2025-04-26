
#include "SoundEffect.hpp"
#include "Util/Time.hpp"

SoundEffect::SoundEffect(const std::string_view path, float cooldown) : sfx_(Util::SFX(std::string(path))),
                                                                        initial_cooldown_(cooldown),
                                                                        cooldown_(cooldown) {}

void SoundEffect::Play() 
{ // đảm bảo âm thanh được phát khi tgian chờ HẾT
    if (cooldown_ < 0) 
    {
        sfx_.Play();
        cooldown_ = initial_cooldown_; // đặt lại thời gian chờ
    }
}

void SoundEffect::Update() 
{cooldown_ -= Util::Time::GetDeltaTimeMs();} // giảm giá trị cooldown theo delta
// cập nhật lại cooldown để check out thời gian chờ giữa các lần phát âm thanh
