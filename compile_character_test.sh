#!/bin/bash

echo "=== 캐릭터 시스템 테스트 컴파일 ==="

# 컴파일러 설정
CXX="g++"
CXXFLAGS="-std=c++17 -Wall -Wextra -I."

# 소스 파일들
SOURCES="test_character_simple.cpp src/core/Character.cpp"

# 실행 파일명
EXECUTABLE="character_test"

echo "컴파일 중..."
$CXX $CXXFLAGS -o $EXECUTABLE $SOURCES

if [ $? -eq 0 ]; then
    echo "컴파일 성공!"
    echo "실행 파일: $EXECUTABLE"
    echo ""
    echo "실행하려면: ./$EXECUTABLE"
else
    echo "컴파일 실패!"
    exit 1
fi 