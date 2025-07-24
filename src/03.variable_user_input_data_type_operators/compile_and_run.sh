#!/bin/bash

echo "🐾 C++ 종합 학습 프로그램 컴파일 중..."
echo "=================================="

# C++11 표준으로 컴파일
g++ -std=c++11 Comprehensive_Learning.cpp -o Comprehensive_Learning

if [ $? -eq 0 ]; then
    echo "✅ 컴파일 성공!"
    echo "🚀 프로그램을 실행합니다..."
    echo "=================================="
    ./Comprehensive_Learning
else
    echo "❌ 컴파일 실패!"
    echo "다시 시도해주세요."
fi 