
#ifndef MAELDEVIL_EASINGFUNCTION_HPP
#define MAELDEVIL_EASINGFUNCTION_HPP

// Tăng độ mượt cho Animation
class EasingFunction {
public:
    static inline float EaseInCubic(float x) {
        return x * x * x;
    }

    static inline float EaseOutCubic(float x) {
        return 1 - powf(1 - x, 3);
    }
};


#endif 
