#!/bin/bash

echo "=== Super Mario ECS 프로젝트 초기 설정 ==="
echo ""

# 의존성 설치
echo "시스템 의존성 설치 중..."
sudo apt update
sudo apt install -y build-essential cmake pkg-config git
sudo apt install -y libsdl2-dev libsdl2-2.0-0
sudo apt install -y libglm-dev  
sudo apt install -y freeglut3-dev libgl1-mesa-dev

echo ""
echo "OpenGL 버전 확인:"
glxinfo | grep "OpenGL version" || echo "mesa-utils 설치 필요: sudo apt install mesa-utils"

echo ""
echo "=== 설정 완료 ==="
echo "이제 build.sh를 실행하여 프로젝트를 빌드하세요."
