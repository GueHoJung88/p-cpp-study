#!/bin/bash

# While Loop 프로그램 컴파일 스크립트
# src/05.while_for_loop_break_continue_arrays_structures_enums/gemini
# src/05.while_for_loop_break_continue_arrays_structures_enums/gpt
# 경로의 프로그램들을 컴파일합니다.

echo "=========================================="
echo "While Loop 프로그램 컴파일"
echo "=========================================="

# 프로젝트 루트 디렉토리로 이동
cd "$(dirname "$0")/.."

# Gemini 프로그램 컴파일
echo "Gemini WhileLoop Interactive 프로그램 컴파일 중..."
cd src/05.while_for_loop_break_continue_arrays_structures_enums/gemini
g++ 01.WhileLoop_Interactive.cpp ../../../../p_cpp/src/core/Character.cpp -o 01.WhileLoop_Interactive

if [ $? -eq 0 ]; then
    echo "✅ Gemini 프로그램 컴파일 성공!"
else
    echo "❌ Gemini 프로그램 컴파일 실패!"
    exit 1
fi

# GPT 프로그램 컴파일
echo "GPT WhileLoop Quiz 프로그램 컴파일 중..."
cd ../gpt
g++ 01.WhileLoop_Quiz.cpp ../../../../p_cpp/src/core/Character.cpp -o 01.WhileLoop_Quiz

if [ $? -eq 0 ]; then
    echo "✅ GPT 프로그램 컴파일 성공!"
else
    echo "❌ GPT 프로그램 컴파일 실패!"
    exit 1
fi

echo ""
echo "=========================================="
echo "컴파일 완료!"
echo "=========================================="

# 실행 파일 확인
echo ""
echo "생성된 실행 파일:"
echo "- src/05.while_for_loop_break_continue_arrays_structures_enums/gemini/01.WhileLoop_Interactive"
echo "- src/05.while_for_loop_break_continue_arrays_structures_enums/gpt/01.WhileLoop_Quiz"
echo ""
echo "실행 방법:"
echo "cd src/05.while_for_loop_break_continue_arrays_structures_enums/gemini"
echo "./01.WhileLoop_Interactive"
echo ""
echo "cd src/05.while_for_loop_break_continue_arrays_structures_enums/gpt"
echo "./01.WhileLoop_Quiz" 