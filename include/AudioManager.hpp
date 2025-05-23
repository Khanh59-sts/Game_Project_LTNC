
#ifndef MAELDEVIL_AUDIOMANAGER_HPP
#define MAELDEVIL_AUDIOMANAGER_HPP

#include <map>
#include "SoundEffect.hpp"
// AudioManager: Quản lý âm thanh chung


class AudioManager {
public:
    enum class SFX {
        Run,
        Jump,
        Bounce, // nảy
        Button, 
        Coin,
        Dead, 
        Door,
        Revive, // Hồi sinh
        Saw, // cưa
        StageClear, // finish cấp độ
        Trap,
        WallTrap // bẫy tường
    };

    AudioManager() = default;
    void Play(SFX sfx);
    void Update();

private:
    std::array<SFX, 12> all_sfxs_ = {SFX::Run, SFX::Jump, SFX::Bounce, SFX::Button, SFX::Coin, SFX::Dead, SFX::Door,
                                     SFX::Revive, SFX::Saw, SFX::StageClear, SFX::Trap, SFX::WallTrap};
    std::map<SFX, std::shared_ptr<SoundEffect>> sfxs_ = {
            {SFX::Run,        std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/run.mp3", 250)}, // set cooldown là 250ms tức 0,25s
            {SFX::Jump,       std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/jump.mp3", 130)},
            {SFX::Bounce,     std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/bounce.mp3", 200)},
            {SFX::Button,     std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/Button.mp3", 100)},
            {SFX::Coin,       std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/coin.mp3", 100)},
            {SFX::Dead,       std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/dead.mp3", 1000)},
            {SFX::Door,       std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/door.mp3", 100)},
            {SFX::Revive,     std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/revive.mp3", 100)},
            {SFX::Saw,        std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/saw.mp3", 1000)},
            {SFX::StageClear, std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/stageclear.mp3", 100)},
            {SFX::Trap,       std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/trap.mp3", -1)},
            {SFX::WallTrap,   std::make_shared<SoundEffect>(RESOURCE_DIR"/sound/wall trap.mp3", 100)}
    };
};


#endif 
