# Super Mario ECS 프로젝트

C++17과 OpenGL을 사용한 Entity-Component-System 아키텍처 기반의 2D 게임 프로젝트입니다.

## 개발 환경
- **OS**: Ubuntu 24.04
- **언어**: C++17
- **그래픽**: OpenGL 3.3 Core Profile
- **윈도우 관리**: SDL2
- **수학 라이브러리**: GLM

## 프로젝트 구조 (새로 생성 부분은 미구현)


```
project_root/
├── CMakeLists.txt
├── build.sh
├── README.md
├── glad/
│   ├── include/
│   └── src/
├── assets/                          # 새로 생성
│   └── textures/
│       └── mario_spritesheet.png    # 마리오 스프라이트시트
├── src/
│   ├── main.cpp                     # 수정
│   ├── core/
│   │   ├── Window.hpp/.cpp
│   │   └── Time.hpp/.cpp            # 새로 생성 (델타타임 관리)
│   ├── renderer/
│   │   ├── Renderer.hpp/.cpp
│   │   ├── Shader.hpp/.cpp
│   │   └── Texture.hpp/.cpp
│   ├── ecs/
│   │   ├── Registry.hpp/.cpp
│   │   ├── System.hpp
│   │   ├── components/
│   │   │   ├── Components.hpp       # 수정
│   │   │   ├── Transform.hpp        # 새로 생성
│   │   │   ├── Sprite.hpp           # 새로 생성
│   │   │   ├── Velocity.hpp         # 새로 생성
│   │   │   ├── Input.hpp            # 새로 생성
│   │   │   └── Animation.hpp        # 새로 생성
│   │   └── systems/
│   │       ├── RenderSystem.hpp/.cpp
│   │       ├── InputSystem.hpp/.cpp # 새로 생성
│   │       ├── MovementSystem.hpp/.cpp # 새로 생성
│   │       └── AnimationSystem.hpp/.cpp # 새로 생성
│   └── game/
│       ├── Game.hpp/.cpp            # 수정
│       └── entities/
│           └── Mario.hpp/.cpp       # 새로 생성
└── build/
```




## 빌드 방법

### 1. 자동 빌드 (권장)
```bash
chmod +x build.sh
./build.sh
```

### 2. 수동 빌드

#### 의존성 설치
```bash
sudo apt update
sudo apt install -y build-essential cmake pkg-config
sudo apt install -y libsdl2-dev libsdl2-2.0-0
sudo apt install -y libglm-dev
sudo apt install -y freeglut3-dev libgl1-mesa-dev
```

#### GLAD 설정
1. https://glad.dav1d.de/ 접속
2. 다음 설정으로 생성:
   - Language: C/C++
   - API: OpenGL
   - Version: 3.3
   - Profile: Core
   - Options: Generate a loader 체크
3. 다운로드한 파일을 프로젝트 루트에 `glad` 폴더로 압축 해제

#### 빌드 실행
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

## 실행 방법
```bash
cd build
./SuperMario
```

## 아키텍처 설명

### ECS (Entity-Component-System)
- **Entity**: 고유 ID (숫자)
- **Component**: 데이터만 포함하는 구조체 (Transform, Sprite, Animation 등)
- **System**: 특정 컴포넌트 조합을 가진 엔티티들을 처리하는 로직

### Renderer 레이어
- **Window**: SDL2 기반 윈도우 및 OpenGL 컨텍스트 관리
- **Renderer**: OpenGL 드로우 콜 추상화, 스프라이트 렌더링
- **Shader**: 셰이더 프로그램 컴파일 및 관리
- **Texture**: 텍스처 로딩 및 관리

### 시스템 흐름
1. **초기화**: Window → OpenGL 컨텍스트 → Renderer → ECS Registry
2. **게임 루프**: 입력 처리 → 시스템 업데이트 → 렌더링 → 버퍼 스왑
3. **렌더링**: RenderSystem이 Transform+Sprite 컴포넌트를 가진 엔티티를 조회하여 렌더링

<!-- ## 핵심 기능

### 현재 구현된 기능
- [x] SDL2 윈도우 생성 및 이벤트 처리
- [x] OpenGL 3.3 컨텍스트 초기화
- [x] ECS 아키텍처 (Entity, Component, System)
- [x] 기본 스프라이트 렌더링
- [x] 변환 행렬 (위치, 크기, 회전)
- [x] 셰이더 관리 시스템

### 향후 확장 가능한 기능
- [ ] 스프라이트 애니메이션 시스템
- [ ] 물리 시스템 (충돌 감지, 중력)
- [ ] 타일맵 렌더링
- [ ] 사운드 시스템
- [ ] 입력 처리 시스템
- [ ] 게임 상태 관리 -->

## 문제 해결

### 빌드 오류
1. **SDL2를 찾을 수 없음**: `sudo apt install libsdl2-dev` 실행
2. **OpenGL 헤더 없음**: `sudo apt install freeglut3-dev libgl1-mesa-dev` 실행
3. **GLM 없음**: `sudo apt install libglm-dev` 실행

### 실행 오류
1. **OpenGL 컨텍스트 생성 실패**: 그래픽 드라이버가 OpenGL 3.3을 지원하는지 확인
2. **검은 화면**: GLAD가 올바르게 설정되었는지 확인

## 개발자 노트

이 프로젝트는 학습 목적으로 제작되었으며, 다음 개념들을 실습합니다:
- Entity-Component-System 아키텍처
- OpenGL을 이용한 2D 렌더링
- C++17 모던 기능 활용
- CMake 빌드 시스템

```
