#pragma once
#include <glm/glm.hpp>
#include <string>
#include <vector>
/*
Component: 순수 데이터만 포함하는 구조체. 위치, 속도, 애니메이션 등의 속성을 정의
*/

// Transform 컴포넌트 : 위치, 회전, 크기 정보 ( x, y축 )

struct Transform {
    glm::vec2 position{0.0f};
    glm::vec2 scale{1.0f};
    float rotation = 0.0f;
};

// Velocity 컴포넌트 - 속도 정보
struct Velocity {
    glm::vec2 velocity{0.0f, 0.0f};
    float max_speed = 5.0f;
};

// Sprite 컴포넌트 - 렌더링 정보
struct Sprite {
    GLuint texture_id = 0;
    SDL_Rect sprite_rect{0, 0, 32, 32};
    glm::vec4 color{1.0f, 1.0f, 1.0f, 1.0f};
};

// Input 컴포넌트 - 입력 상태
struct Input {
    bool left = false;
    bool right = false;
    bool jump = false;
    bool run = false;
};

// Physics 컴포넌트 - 물리 속성
struct Physics {
    float gravity = -9.8f;
    bool ground_check = false;
    SDL_Rect collision_rect{0, 0, 32, 32};
};

// Animation 컴포넌트 - 애니메이션 상태
struct Animation {
    int current_frame = 0;
    float frame_time = 0.0f;
    int frame_count = 4;
    bool is_playing = true;
};


// struct Sprite {
//     unsigned int textureID = 0;
//     glm::vec2 size{32.0f, 32.0f};
//     glm::vec4 color{1.0f};  // RGBA
// };

// struct Animation {
//     std::vector<unsigned int> frames;
//     float frameTime = 0.1f;
//     float currentTime = 0.0f;
//     int currentFrame = 0;
//     bool loop = true;
// };

// struct Velocity {
//     glm::vec2 velocity{0.0f};
// };

// struct PlayerController {
//     float speed = 200.0f;
//     bool isGrounded = false;
//     float jumpForce = 400.0f;
// };
