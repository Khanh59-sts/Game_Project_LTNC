

#ifndef MAELDEVIL_ILEVEL_HPP
#define MAELDEVIL_ILEVEL_HPP

// ILevel: Tạo cấp độ 

class ILevel {
public:
    virtual ~ILevel() = default;

    virtual void Start() = 0; // khởi tạo mọi thứ khi trong cấp độ

    virtual void Update() = 0; // cập nhật logic game trong lặp chính
};

#endif 