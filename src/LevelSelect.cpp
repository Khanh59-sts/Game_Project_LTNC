
#include "LevelSelect.hpp"

#include <utility>
#include "Util/Animation.hpp"
#include "Util/Time.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

LevelSelect::LevelSelect(AudioManager audio_manager, std::function<void(Level::State)> set_level_state_function)
        : set_level_state_function_(std::move(set_level_state_function)), audio_manager_(std::move(audio_manager)) {}
/*
* Đối tượng LevelSelect để truyền hàm Âm thanh và Trạng thái Level
*/
void LevelSelect::Start() {
    renderer_.AddChild(transition_.GetTop());
    renderer_.AddChild(transition_.GetBottom());
    background_ = std::make_shared<Background>(RESOURCE_DIR"/image/background/level_select.png");
    renderer_.AddChild(background_);
    std::array<glm::vec2, 15> door_positions = {glm::vec2(-580, 4), glm::vec2(-500, -70), glm::vec2(-400, -8),
                                                glm::vec2(-200, -30), glm::vec2(-200, -100), glm::vec2(-200, -300),
                                                glm::vec2(-80, -200), glm::vec2(20, -100)}; // mảng set tọa độ 10 màn chơi (x, y) 
    for (int i = 0; i < 15; ++i) {
        std::string image_path;
        if (i < 8 && i != 5) {
            image_path.append(RESOURCE_DIR"/image/ui/unlock_door");
            image_path.append(std::to_string(i+1));
            image_path.append(".png"); // unlock_door1.png,...
        }
        else {
            image_path.append(RESOURCE_DIR"/image/ui/unlock_door.png"); // regular
        }

        auto door_button = std::make_shared<DoorButton>( // Tạo nút cửa với Âm thanh và Ảnh
            std::make_shared<Util::Image>(image_path), audio_manager_);
        door_button->SetPosition(door_positions[i]); // set vị trí theo i
        // Set di chuột cho cửa bằng animation
        auto button_hover = std::make_shared<Sprite>(std::make_shared<Util::Animation>(
                std::vector<std::string>{RESOURCE_DIR"/image/ui/door_hover1.png",
                                         RESOURCE_DIR"/image/ui/door_hover2.png",
                                         RESOURCE_DIR"/image/ui/door_hover3.png",
                                         RESOURCE_DIR"/image/ui/door_hover4.png"}, true, 200, true, 0), 11);
        button_hover->SetPosition(door_positions[i] + glm::vec2(0, 32)); // set vị trí chuột trong (x, y) để "select" các cửa
        button_hover->SetVisible(false); // Ẩn nút hover ban đầu đi vì kh đẹp !!!

        door_buttons_.push_back(door_button); // lưu cửa
        button_hovers_.push_back(button_hover); // lưu nút di chuột (hover)
        door_button->AddChild(button_hover); // combine hiệu ứng 
        renderer_.AddChild(door_button); // render nó lên 
    }

    // Set riêng màn BOSS
    auto door_button = std::make_shared<DoorButton>(
        std::make_shared<Util::Image>(RESOURCE_DIR"/image/ui/unlock_boss_door.png"), audio_manager_);
    door_button->SetPosition({ 235, -20 }); // set tọa độ (x, y)

    auto button_hover = std::make_shared<Sprite>(std::make_shared<Util::Animation>(
        std::vector<std::string>{RESOURCE_DIR"/image/ui/boos_door_hover1.png",
        RESOURCE_DIR"/image/ui/boos_door_hover2.png",
        RESOURCE_DIR"/image/ui/boos_door_hover3.png",
        RESOURCE_DIR"/image/ui/boos_door_hover4.png"}, true, 200, true, 0), 11);

    // không dùng i, set riêng tọa độ tách biệt các cửa trước bằng tọa độ chay
    button_hover->SetPosition(glm::vec2({ 235, -20 }) + glm::vec2({ -4, 26 })); // Để "select"
    button_hover->SetVisible(false);

    // Lưu các cửa, nút rồi combine rồi render lên
    door_buttons_.push_back(door_button);
    button_hovers_.push_back(button_hover);
    door_button->AddChild(button_hover);
    renderer_.AddChild(door_button);
}

void LevelSelect::Update() {
    switch (current_state_) {
        case State::Intro: // Hiệu ứng chuyển cảnh khi chọn cấp
            transition_.Intro([this]() { UpdateCurrentState(State::Start); });
            break; // chuyển trạng thái sang State::Start ở bước kế

        case State::Start: // Select Door Main
            for (int i = 0; i < int(door_buttons_.size()); ++i) {
                door_buttons_[i]->Update();
                if (door_buttons_[i]->GetState() == Button::State::Click) { // Nếu nút được "nhấn"
                    switch (i) { // gán cấp độ tương ứng
                        case 0:
                            level_ = Level::State::LEVEL_1;
                            break;
                        case 1:
                            level_ = Level::State::LEVEL_2;
                            break;
                        case 2:
                            level_ = Level::State::LEVEL_3;
                            break;
                        case 3:
                            level_ = Level::State::LEVEL_4;
                            break;
                        case 4:
                            level_ = Level::State::LEVEL_5;
                            break;
                        case 6:
                            level_ = Level::State::LEVEL_7;
                            break;
                        case 7:
                            level_ = Level::State::LEVEL_8;
                            break;
                        case 15:
                            level_ = Level::State::LEVEL_DEVIL;
                            break;
                        default:
                            renderer_.Update();
                            return;
                    }

                    UpdateCurrentState(State::Outro); // chuyển sang Outro
                }
            }
            break;
        case State::Outro: // hiệu ứng chuyển cảnh khi rời khỏi màn hình chọn cấp
            transition_.Outro([this]() { set_level_state_function_(level_); }); 
            break;
    }

    renderer_.Update();
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE)) { // Nếu nút ESC nhả ra, chuyển sang Outro và END luôn
        UpdateCurrentState(State::Outro);
        level_ = Level::State::END;
    }
}

void LevelSelect::UpdateCurrentState(LevelSelect::State state) { // Gồm Intro và Outro
    if (current_state_ == state) return; // đúng thì return luôn
    switch (current_state_) { // Hoán đổi giữa Intro, Start, Outro
        case State::Intro:
            if (state == State::Start)current_state_ = state;
            break;
        case State::Start:
            if (state == State::Outro) {
                current_state_ = state;
                transition_.ResetTimer();
            }
            break;
        case State::Outro:
            break;
    }
}
