#include "AudioManager.hpp"

void AudioManager::Update() {
    for (auto sfx : all_sfxs_){
        sfxs_[sfx]->Update();
    } // duyệt qua tất cả hiệu ứng âm thanh và cập nhật từng cái 1
    // ...giảm thời gian cooldown giữa các lần phát âm thanh
}

void AudioManager::Play(AudioManager::SFX sfx) {
    sfxs_[sfx]->Play(); // truy cập và phát bằng "Play" của SoundEffect
}
