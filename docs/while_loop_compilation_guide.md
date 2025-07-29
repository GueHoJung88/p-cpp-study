# While Loop 프로그램 컴파일 및 실행 가이드

## 개요

`src/05.while_for_loop_break_continue_arrays_structures_enums/gemini`와 `src/05.while_for_loop_break_continue_arrays_structures_enums/gpt` 경로의 프로그램들을 컴파일하고 실행하는 방법을 설명합니다.

## 프로그램 소개

### 1. Gemini WhileLoop Interactive 프로그램
- **파일**: `src/05.while_for_loop_break_continue_arrays_structures_enums/gemini/01.WhileLoop_Interactive.cpp`
- **기능**: While Loop에 대한 대화형 학습 프로그램
- **특징**: 
  - 단계별 학습 진행
  - 실습 문제 제공
  - 캐릭터 기반 대화형 인터페이스
  - 학습 데이터 저장/로드

### 2. GPT WhileLoop Quiz 프로그램
- **파일**: `src/05.while_for_loop_break_continue_arrays_structures_enums/gpt/01.WhileLoop_Quiz.cpp`
- **기능**: While Loop 퀴즈 프로그램
- **특징**:
  - 다양한 퀴즈 유형 (복습, 최종, 연습)
  - 난이도별 문제 제공
  - 퀴즈 결과 통계
  - 사용자 진행 상황 추적

## 컴파일 방법

### 1. 자동 컴파일 (권장)
```bash
# 프로젝트 루트 디렉토리에서
./scripts/compile_while_loop_programs.sh
```

### 2. 수동 컴파일

#### Gemini 프로그램 컴파일
```bash
cd src/05.while_for_loop_break_continue_arrays_structures_enums/gemini
g++ 01.WhileLoop_Interactive.cpp ../../../../p_cpp/src/core/Character.cpp -o 01.WhileLoop_Interactive
```

#### GPT 프로그램 컴파일
```bash
cd src/05.while_for_loop_break_continue_arrays_structures_enums/gpt
g++ 01.WhileLoop_Quiz.cpp ../../../../p_cpp/src/core/Character.cpp -o 01.WhileLoop_Quiz
```

## 실행 방법

### 1. Gemini 프로그램 실행
```bash
cd src/05.while_for_loop_break_continue_arrays_structures_enums/gemini
./01.WhileLoop_Interactive
```

### 2. GPT 프로그램 실행
```bash
cd src/05.while_for_loop_break_continue_arrays_structures_enums/gpt
./01.WhileLoop_Quiz
```

## 프로그램 기능

### Gemini WhileLoop Interactive 프로그램

#### 학습 단계
1. **While Loop 기본 개념**
   - While Loop의 기본 문법
   - 조건문과 반복 구조
   - 코드 예제와 실습

2. **While Loop 실행 과정**
   - 조건 확인 → 코드 실행 → 다시 조건 확인
   - 단계별 실행 과정 설명

3. **무한 루프 주의사항**
   - 무한 루프의 원인과 방지 방법
   - 조건 변경 코드의 중요성

4. **Do-While Loop**
   - While Loop와의 차이점
   - 최소 한 번 실행되는 특징

5. **While Loop 활용 예제**
   - 실제 사용 사례
   - 사용자 입력 처리

#### 퀴즈 시스템
- 각 단계별 실습 문제
- 즉시 피드백 제공
- 최종 이해도 점검 퀴즈

### GPT WhileLoop Quiz 프로그램

#### 퀴즈 유형
1. **복습 퀴즈 (Review Quiz)**
   - 기본 개념 복습
   - 문법 이해도 확인

2. **최종 점검 퀴즈 (Final Quiz)**
   - 종합적인 이해도 평가
   - 고급 문제 포함

3. **연습 퀴즈 (Practice Quiz)**
   - 실습 중심 문제
   - 코드 작성 연습

#### 퀴즈 특징
- 난이도별 문제 제공 (1-5단계)
- 카테고리별 분류
- 상세한 설명과 힌트 제공
- 점수 시스템과 통계

## 파일 구조

```
src/05.while_for_loop_break_continue_arrays_structures_enums/
├── gemini/
│   ├── 01.WhileLoop_Interactive.cpp
│   └── 01.WhileLoop_Interactive (실행 파일)
├── gpt/
│   ├── 01.WhileLoop_Quiz.cpp
│   └── 01.WhileLoop_Quiz (실행 파일)
└── contents/
    └── while_loop.txt (학습 내용)
```

## 의존성

### 필수 파일
- `src/core/Character.h` - 캐릭터 시스템 헤더
- `src/core/Character.cpp` - 캐릭터 시스템 구현

### 컴파일러 요구사항
- GCC 7.0 이상 또는 Clang 5.0 이상
- C++17 표준 지원

## 문제 해결

### 1. 컴파일 오류: Character.h를 찾을 수 없음
```bash
# 올바른 경로 확인
find . -name "Character.h" -type f
```

### 2. 실행 파일이 생성되지 않음
```bash
# 컴파일러 버전 확인
g++ --version

# 권한 확인
ls -la 01.WhileLoop_Interactive
```

### 3. 프로그램 실행 중 오류
```bash
# 실행 권한 확인
chmod +x 01.WhileLoop_Interactive
chmod +x 01.WhileLoop_Quiz
```

## 사용 팁

### 1. 프로그램 종료
- `q` 또는 `quit` 입력
- Ctrl+C (강제 종료)

### 2. 학습 데이터
- 프로그램 실행 후 `user_learning_data.txt` 파일 생성
- 학습 진행 상황 자동 저장

### 3. 퀴즈 데이터
- 프로그램 실행 후 `user_quiz_data.txt` 파일 생성
- 퀴즈 결과 및 통계 저장

## 개발 환경

### 권장 환경
- **OS**: Linux, macOS, Windows (WSL)
- **컴파일러**: GCC 7.0+, Clang 5.0+
- **터미널**: ANSI 색상 지원

### 최소 요구사항
- **메모리**: 512MB 이상
- **디스크**: 100MB 이상 여유 공간
- **터미널**: 80x24 이상 크기

## 라이선스

이 프로그램들은 교육 목적으로 제작되었습니다.

---

**마지막 업데이트**: 2024년 1월  
**버전**: 1.0  
**작성자**: AI Assistant 