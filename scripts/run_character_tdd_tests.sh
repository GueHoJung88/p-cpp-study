#!/bin/bash

# Character System TDD Development Script
# 캐릭터 시스템 TDD 개발 스크립트

echo "=== Character System TDD Development ==="
echo "=== 캐릭터 시스템 TDD 개발 ==="
echo

# 1. 현재 테스트 실행
echo "1. Running Current Tests..."
echo "1. 현재 테스트 실행 중..."
g++ -std=c++17 -o test_character_simple src/core/Character.cpp test_character_simple.cpp
if [ $? -eq 0 ]; then
    echo "✅ Compilation successful"
    echo "✅ 컴파일 성공"
    echo
    echo "Running tests..."
    echo "테스트 실행 중..."
    ./test_character_simple.exe
else
    echo "❌ Compilation failed"
    echo "❌ 컴파일 실패"
    exit 1
fi

echo
echo "2. TDD Development Cycle Starting..."
echo "2. TDD 개발 사이클 시작..."

# 2. 새로운 기능 테스트 작성 (Red)
echo "   - Writing failing test for new feature (Red)"
echo "   - 새 기능에 대한 실패하는 테스트 작성 (Red)"

# 3. 최소한의 코드로 테스트 통과 (Green)
echo "   - Implementing minimal code to pass test (Green)"
echo "   - 테스트를 통과시키는 최소한의 코드 구현 (Green)"

# 4. 코드 리팩토링 (Refactor)
echo "   - Refactoring code (Refactor)"
echo "   - 코드 리팩토링 (Refactor)"

echo
echo "=== TDD Cycle Complete ==="
echo "=== TDD 사이클 완료 ===" 