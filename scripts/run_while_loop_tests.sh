#!/bin/bash

# While Loop 프로그램 TDD 테스트 실행 스크립트
# src/05.while_for_loop_break_continue_arrays_structures_enums/gemini
# src/05.while_for_loop_break_continue_arrays_structures_enums/gpt
# 경로 이하 프로그램들의 TDD 테스트를 실행합니다.

echo "=========================================="
echo "While Loop 프로그램 TDD 테스트 실행"
echo "=========================================="

# 빌드 디렉토리 생성
mkdir -p build
cd build

# CMake 설정
echo "CMake 설정 중..."
cmake ..

# 빌드
echo "테스트 빌드 중..."
make cpp_learning_tests

# 테스트 실행
echo "=========================================="
echo "While Loop Gemini Interactive 테스트 실행"
echo "=========================================="
./cpp_learning_tests --gtest_filter="WhileLoopInteractiveTest*"

echo ""
echo "=========================================="
echo "While Loop GPT Quiz 테스트 실행"
echo "=========================================="
./cpp_learning_tests --gtest_filter="WhileLoopQuizTest*"

echo ""
echo "=========================================="
echo "모든 While Loop 관련 테스트 실행"
echo "=========================================="
./cpp_learning_tests --gtest_filter="*WhileLoop*"

echo ""
echo "=========================================="
echo "전체 테스트 스위트 실행"
echo "=========================================="
./cpp_learning_tests

echo ""
echo "=========================================="
echo "테스트 완료!"
echo "=========================================="

# 테스트 결과 요약
echo ""
echo "테스트 결과 요약:"
echo "- WhileLoopInteractiveTest: Gemini WhileLoop Interactive 프로그램 테스트"
echo "- WhileLoopQuizTest: GPT WhileLoop Quiz 프로그램 테스트"
echo ""
echo "테스트 파일 위치:"
echo "- tests/test_while_loop_gemini.cpp"
echo "- tests/test_while_loop_gpt.cpp"
echo ""
echo "테스트 대상 프로그램:"
echo "- src/05.while_for_loop_break_continue_arrays_structures_enums/gemini/01.WhileLoop_Interactive.cpp"
echo "- src/05.while_for_loop_break_continue_arrays_structures_enums/gpt/01.WhileLoop_Quiz.cpp" 