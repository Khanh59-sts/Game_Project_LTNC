
#ifndef MAELDEVIL_INPUTHANDLER_HPP
#define MAELDEVIL_INPUTHANDLER_HPP

#include "glm/vec2.hpp"
#include "Util/Input.hpp"


// InputHander: Kiểm tra và Set nút di chuyển WASD cho nhân vật

class InputHandler {
public:
    static glm::vec2 GetCharacterMoveVelocity(); // lấy tốc độ di chuyển dựa trên nút di chuyển 
    static glm::vec2 GetGodMoveVelocity(); // God Mod

    static bool isForwardPressed(); //  D ->
    static bool isBackwardPressed(); 
    static bool isJumpPressed();
    static bool isUpPressed();
    static bool isDownPressed();
    static bool isRevivePressed();
    static bool isResetLevelPressed();
    static bool isGodPressed();

private:
    constexpr static const std::array<Util::Keycode, 2> forward_keycodes_ = {Util::Keycode::D, Util::Keycode::RIGHT};
    constexpr static const std::array<Util::Keycode, 2> backward_keycodes_ = {Util::Keycode::A, Util::Keycode::LEFT};
    constexpr static const std::array<Util::Keycode, 3> jump_keycodes_ = {Util::Keycode::W, Util::Keycode::SPACE,
                                                                           Util::Keycode::UP};
    constexpr static const std::array<Util::Keycode, 2> up_keycodes_ = {Util::Keycode::W, Util::Keycode::UP};
    constexpr static const std::array<Util::Keycode, 2> down_keycodes_ = {Util::Keycode::S, Util::Keycode::DOWN};
    constexpr static const std::array<Util::Keycode, 7> revive_keycodes_ = {Util::Keycode::D, Util::Keycode::RIGHT,
                                                                            Util::Keycode::A, Util::Keycode::LEFT,
                                                                            Util::Keycode::W, Util::Keycode::SPACE,
                                                                            Util::Keycode::UP};
    constexpr static const Util::Keycode reset_level_keycode = Util::Keycode::R;
    constexpr static const Util::Keycode god_keycode = Util::Keycode::G;
};


#endif 
