# 🐾 C++ 학습 여정: 귀여운 동물들과 함께하는 코딩 모험

> **코딩 경험이 없는 분들을 위한 실습 기반 C++ 학습 프로젝트**

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Integration%20Progress-blue.svg)]()
[![TDD](https://img.shields.io/badge/TDD-Test%20Driven%20Development-orange.svg)]()
[![CMake](https://img.shields.io/badge/CMake-Build%20System-blue.svg)]()
[![Progress](https://img.shields.io/badge/Progress-85%25-brightgreen.svg)]()

## 📚 프로젝트 문서 / Project Documentation

프로젝트 개발 및 관리를 위한 문서들을 확인하세요:

### 🔧 개발 환경 설정
- **[개발 환경 구축 및 관리 가이드](./docs/development_environment_guide.md)** - TDD 개발 환경 구축 및 프로젝트 관리
- **[VSCode Git Commit 설정 가이드](./docs/vscode-git-commit-setup.md)** - VSCode를 Git 커밋 메시지 에디터로 설정하고 커스텀 템플릿 사용하기

### 🧪 TDD 테스트 시스템
- **[Character System TDD 테스트 가이드](./docs/character_tdd_testing_guide.md)** - 캐릭터 시스템 전용 TDD 테스트 가이드
- **[Character System 요약](./docs/character_system_summary.md)** - 업데이트된 캐릭터 시스템 및 TDD 적용 요약

### 🌿 브랜칭 및 협업
- **[브랜칭 컨벤션 가이드](./docs/branching-convention-with-images.md)** - 프로젝트 브랜칭 전략과 협업 가이드라인

### 📖 추가 문서
더 많은 개발 문서는 [`docs/`](./docs/) 폴더를 확인하세요.

### 🎯 통합 리팩토링 전략
- **[통합 리팩토링 전략](./docs/integration_refactoring_strategy.md)** - src 폴더 이하 프로그램 통합 리팩토링 전략
- **[프로젝트 리팩토링 체크리스트](./docs/refactoring_todo.md)** - 현재 진행 상황 및 체크리스트

### 📊 현재 프로젝트 상태 (2025-08-11)
- **전체 진행률**: 85% 🚀
- **Core 모듈**: 100% 완성 ✅
- **Gamification 모듈**: 70% 완성 🔄
- **테스트 시스템**: 100% 완성 ✅
- **한글 출력 문제**: 완전 해결 ✅

## 🚀 빠른 시작 (Quick Start)

### 📋 필수 도구 설치

#### macOS
```bash
# Homebrew로 필수 도구 설치
brew install cmake git llvm make

# 선택적 도구 (권장)
brew install cppcheck clang-format valgrind lcov
```

#### Linux (Ubuntu/Debian)
```bash
# 필수 패키지 설치
sudo apt update
sudo apt install build-essential cmake git clang llvm

# 선택적 도구
sudo apt install cppcheck clang-format valgrind lcov
```

### 🧪 TDD 테스트 실행

```bash
# 1. 프로젝트 클론
git clone <repository-url>
cd p-cpp-study

# 2. 실행 권한 부여
chmod +x scripts/*.sh

# 3. 전체 프로젝트 TDD 리팩토링 (먼저 실행)
./scripts/run_tdd_refactoring.sh

# 4. 캐릭터 시스템 전용 TDD 테스트 (그 다음 실행)
./scripts/run_character_tdd_tests.sh
```

### 🔧 수동 빌드 및 테스트

```bash
# 빌드 환경 설정
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 ..

# 테스트 빌드 및 실행
make cpp_learning_tests
./cpp_learning_tests

# 특정 테스트 실행
./cpp_learning_tests --gtest_filter="CharacterSystemTest.*"
```

## 🌟 프로젝트 소개

이 프로젝트는 **코딩이나 C++에 대한 경험이 없는 사람**을 위한 **실습 기반 C++ 학습 프로젝트**입니다. 개인이나 스터디 그룹이 C++를 쉽고 재미있게 학습할 수 있도록 설계되었습니다.

### 🔄 지속적인 업데이트
이 프로젝트는 **지속적으로 발전하고 있습니다**:
- **캐릭터 시스템**: 새로운 동물 캐릭터들과 감정 표현 추가
- **학습 범위**: C++의 새로운 개념들과 실습 자료 확장
- **퀴즈와 미션**: 더욱 재미있고 도전적인 문제들 추가
- **포트폴리오**: 학습 완료 후 만들 수 있는 프로젝트들 확장
- **사용자 피드백**: 학습자들의 의견을 반영한 개선사항 적용
- **TDD 시스템**: Test-Driven Development 방식의 체계적인 개발 환경

### 🎯 핵심 목표
- **코드 실습 기반 학습**: 실제 코드를 작성하고 실행하며 학습
- **콘솔 인터페이스 기반 학습**: 코드를 직접 보지 않고도 콘솔을 통해 학습 진행 가능
- **누적 학습 방식**: 이전 학습 내용을 다음 단계에 자연스럽게 포함
- **점진적 난이도 상승**: 기초부터 고급까지 단계별 학습
- **포트폴리오 완성**: 학습 완료 시 게임 및 프로그램 제작
- **TDD 기반 개발**: 테스트 주도 개발 방식으로 안정적인 코드 작성

## 🧪 TDD 테스트 시스템

### 📋 테스트 스크립트 종류

#### 1. **전체 프로젝트 리팩토링** (`scripts/run_tdd_refactoring.sh`)
- **목적**: 전체 프로젝트의 TDD 기반 리팩토링
- **범위**: 모든 모듈, 전체 코드베이스
- **시간**: 10-15분 (전체 프로젝트 분석)
- **기능**: 코드 분석, 테스트 실행, 품질 검사, 성능 프로파일링

#### 2. **캐릭터 시스템 전용** (`scripts/run_character_tdd_tests.sh`)
- **목적**: Character.h 기반 전용 TDD 테스트
- **범위**: 캐릭터 시스템만
- **시간**: 5-8분 (캐릭터 모듈 집중)
- **기능**: 12가지 캐릭터 종류, 감정 시스템, 팩토리 패턴, 관리자 시스템

### 🎯 TDD 사이클 (Red-Green-Refactor)

#### 🔴 Red 단계: 실패하는 테스트 작성
```cpp
TEST_F(CharacterSystemTest, CharacterCreation_ValidData_CreatesCharacter) {
    Character testChar("Test", Species::CHIHUAHUA, "TestRole");
    EXPECT_EQ(testChar.getName(), "Test");
    EXPECT_EQ(testChar.getSpecies(), Species::CHIHUAHUA);
    EXPECT_EQ(testChar.getRole(), "TestRole");
}
```

#### 🟢 Green 단계: 최소한의 코드로 테스트 통과
```cpp
class Character {
    std::string name;
    Species species;
    std::string role;
    
public:
    Character(const std::string& n, Species s, const std::string& r)
        : name(n), species(s), role(r) {}
    
    std::string getName() const { return name; }
    Species getSpecies() const { return species; }
    std::string getRole() const { return role; }
};
```

#### 🔄 Refactor 단계: 코드 개선
- 중복 제거, 가독성 향상, 성능 최적화, 구조 개선

### 📊 테스트 커버리지

**지원하는 테스트 카테고리**:
- ✅ 기본 캐릭터 생성 테스트
- ✅ 상세 프로필 정보 테스트
- ✅ 경험치 및 레벨업 시스템 테스트
- ✅ 감정별 표시 시스템 테스트
- ✅ 캐릭터 팩토리 패턴 테스트
- ✅ 캐릭터 관리자 기능 테스트
- ✅ 연산자 오버로딩 테스트
- ✅ 경계값 처리 테스트
- ✅ 성능 최적화 테스트
- ✅ 통합 테스트

## 🐕 테마: 귀여운 동물 캐릭터들의 C++ 모험

### 🎭 메인 캐릭터들 (12가지 종류)
- **🐕 치와와 (치치)**: 선생님 역할
- **🐕 웰시코기 (코코)**: 도우미 역할
- **🐶 골든리트리버 (리버)**: 친구 역할
- **🐺 허스키 (허허)**: 모험가 역할
- **🐰 토끼 (토토)**: 퀴즈 역할
- **🐱 고양이 (냥냥)**: 채점 역할
- **🐕 말티즈 (보리)**: 주인공 역할
- **🐕 비숑 프리제 (숑숑)**: 친구 역할
- **🐕 불독 (불리)**: 보호자 역할
- **👤 임정찬 (Liki)**: 학생 역할
- **👤 정규호 (바보)**: 분위기메이커 역할
- **🐱 싀백 (먀엉)**: 현자 역할

### 🎮 학습 방식
각 캐릭터는 C++의 다양한 개념을 재미있는 스토리와 함께 가르쳐줍니다:
- **변수**: 캐릭터의 이름, 나이, 체력 등을 저장
- **사용자 입력**: 캐릭터와의 대화, 선택지
- **데이터 타입**: 다양한 정보의 저장 방식
- **연산자**: 캐릭터의 능력치 계산, 게임 로직
- **객체지향**: 캐릭터 클래스와 상속
- **디자인 패턴**: 팩토리 패턴, 관리자 패턴

## 📚 학습 커리큘럼

### 🚀 1단계: 기초 문법 (Begin)
```
src/01.beggin/
├── main.cpp      # 기본 Hello World
├── util.h        # 유틸리티 함수 헤더
└── util.cpp      # 유틸리티 함수 구현
```

### 📝 2단계: 문법과 출력 (Syntax & Output)
```
src/02.syntax_output_commnets/
├── _syntax.cpp           # 기본 문법 학습
├── _output.cpp           # 출력 방법 학습
├── _comment.cpp          # 주석 사용법
├── _statements.cpp       # 문장과 표현식
└── _comment_mission_*.cpp # 주석 실습 미션들
```

### 🎯 3단계: 변수, 입력, 데이터 타입, 연산자
```
src/03.variable_user_input_data_type_operators/
├── Comprehensive_Learning.cpp  # 통합 학습 프로그램
├── draft/                      # 초안 버전들
├── gpt/                        # GPT 기반 학습 자료
└── gemini/                     # Gemini 기반 학습 자료
```

### 🧪 4단계: 문자열, 수학, 불린, 조건문, 스위치
```
src/04.strings_math_boolean_ifelse_switch/
├── contents/                   # 학습 내용
├── gpt/                        # GPT 기반 학습 자료
└── gemini/                     # Gemini 기반 학습 자료
```

### 🏗️ 핵심 모듈 (Core System)
```
src/core/
├── Character.h          # 캐릭터 시스템 (12가지 종류)
├── QuizSystem.h         # 퀴즈 시스템
├── LearningModule.h     # 학습 모듈
└── Utils.h              # 유틸리티 함수
```

## 🎮 학습 특징

### 1. **인터랙티브 학습**
- 콘솔을 통한 대화형 학습
- 캐릭터와의 상호작용
- 실시간 피드백과 격려

### 2. **누적 학습 방식**
- 이전 단계의 내용이 다음 단계에 자연스럽게 포함
- 점진적 복습을 통한 이해도 향상
- 단계별 성취감 제공

### 3. **실습 중심 학습**
- 이론보다는 실제 코드 작성과 실행
- 즉시 결과 확인 가능
- 오류를 통한 학습

### 4. **게임화된 학습**
- 퀴즈와 미션을 통한 동기부여
- 캐릭터의 감정 변화를 통한 피드백
- 점수와 레벨 시스템

### 5. **TDD 기반 개발**
- 테스트 주도 개발 방식
- 안정적이고 확장 가능한 코드
- 체계적인 품질 관리

## 🛠️ 개발 환경 설정

### 필수 요구사항
- **C++ 컴파일러**: GCC, Clang, 또는 MSVC
- **CMake**: 3.10 이상
- **Make**: 빌드 도구
- **Git**: 버전 관리
- **터미널/콘솔**: 코드 실행 및 출력 확인
- **텍스트 에디터**: VS Code, Sublime Text 등

### 선택적 도구 (권장)
- **Cppcheck**: 정적 분석
- **Clang-format**: 코드 포맷팅
- **Valgrind**: 메모리 누수 검사
- **Lcov**: 테스트 커버리지 분석

### 빠른 시작
```bash
# 프로젝트 클론
git clone [repository-url]
cd p-cpp-study

# TDD 테스트 실행
./scripts/run_character_tdd_tests.sh

# 수동 컴파일 및 실행 (Linux/Mac)
g++ -o program src/01.beggin/main.cpp src/01.beggin/util.cpp
./program

# Windows
g++ -o program.exe src/01.beggin/main.cpp src/01.beggin/util.cpp
program.exe
```

## 📖 학습 가이드

### 🎯 권장 학습 순서
1. **기초 문법** (`src/01.beggin/`)
   - Hello World 프로그램
   - 기본 출력과 함수 사용

2. **문법과 주석** (`src/02.syntax_output_commnets/`)
   - C++ 기본 문법
   - 주석 작성법
   - 출력 방법

3. **핵심 개념** (`src/03.variable_user_input_data_type_operators/`)
   - 변수와 데이터 타입
   - 사용자 입력 처리
   - 연산자 사용법
   - 통합 실습

4. **고급 개념** (`src/04.strings_math_boolean_ifelse_switch/`)
   - 문자열 처리
   - 수학 연산
   - 조건문과 스위치
   - 불린 로직

5. **TDD 테스트** (`scripts/`)
   - 테스트 주도 개발 학습
   - 코드 품질 관리
   - 자동화된 테스트 실행

### 🎮 학습 팁
- **천천히 진행**: 각 단계를 충분히 이해한 후 다음 단계로
- **직접 타이핑**: 복사-붙여넣기보다 직접 코드 작성
- **실험해보기**: 코드를 수정하고 결과 확인
- **오류 활용**: 컴파일 오류를 통해 학습
- **테스트 작성**: TDD 방식으로 안정적인 코드 작성

## 🏆 학습 목표

### 📋 기초 단계 완료 시
- C++ 기본 문법 이해
- 변수와 데이터 타입 사용
- 사용자 입력 처리
- 기본 연산자 활용

### 🎯 중급 단계 완료 시
- 함수 작성과 사용
- 조건문과 반복문
- 배열과 문자열 처리
- 간단한 게임 제작
- TDD 방식 이해

### 🚀 고급 단계 완료 시
- 객체지향 프로그래밍
- 클래스와 상속
- 포인터와 메모리 관리
- 포트폴리오 프로젝트 완성
- 체계적인 테스트 작성

## 🎨 프로젝트 구조

```
p-cpp-study/
├── 📁 src/                          # 소스 코드
│   ├── 📁 core/                     # 핵심 모듈
│   │   ├── Character.h              # 캐릭터 시스템 (12가지 종류)
│   │   ├── QuizSystem.h             # 퀴즈 시스템
│   │   ├── LearningModule.h         # 학습 모듈
│   │   └── Utils.h                  # 유틸리티
│   ├── 📁 01.beggin/               # 기초 문법
│   ├── 📁 02.syntax_output_commnets/  # 문법과 출력
│   ├── 📁 03.variable_user_input_data_type_operators/  # 핵심 개념
│   └── 📁 04.strings_math_boolean_ifelse_switch/  # 고급 개념
├── 📁 tests/                        # 테스트 코드
│   ├── test_utils.cpp
│   ├── test_character_system.cpp
│   ├── test_quiz_system.cpp
│   └── test_learning_modules.cpp
├── 📁 scripts/                      # 실행 스크립트
│   ├── run_tdd_refactoring.sh       # 전체 리팩토링
│   └── run_character_tdd_tests.sh   # 캐릭터 테스트
├── 📁 docs/                         # 문서
│   ├── development_environment_guide.md
│   ├── character_tdd_testing_guide.md
│   ├── character_system_summary.md
│   ├── vscode-git-commit-setup.md
│   └── branching-convention-with-images.md
├── 📁 asset/                        # 학습 자료
│   ├── 📁 article/                 # C++ 개념 설명
│   ├── 📁 image/                   # 시각화 자료
│   └── 📁 python/                  # 보조 도구
├── 📁 build/                        # 빌드 출력 (자동 생성)
├── CMakeLists.txt                   # CMake 설정
└── README.md                        # 프로젝트 설명
```

## 🤝 기여하기

이 프로젝트는 학습 커뮤니티의 성장을 위해 기여를 환영합니다!

### 🔄 업데이트 현황
프로젝트는 정기적으로 업데이트되며, 다음과 같은 영역에서 지속적인 개선이 이루어지고 있습니다:

- **📚 학습 자료**: 새로운 C++ 개념과 실습 예제 추가
- **🎮 게임 요소**: 더욱 재미있는 퀴즈와 미션 개발
- **🐾 캐릭터**: 새로운 동물 캐릭터와 상호작용 방식 추가
- **🎯 난이도 조정**: 학습자 피드백을 반영한 난이도 최적화
- **📱 사용자 경험**: 더욱 직관적이고 사용하기 쉬운 인터페이스 개선
- **🧪 TDD 시스템**: Test-Driven Development 방식의 체계적인 개발 환경

### 기여 방법
1. **이슈 리포트**: 버그나 개선 사항 제안
2. **풀 리퀘스트**: 새로운 학습 자료나 기능 추가
3. **문서 개선**: README나 주석 개선
4. **테스트**: 새로운 학습자 관점에서 테스트
5. **TDD 테스트**: 새로운 테스트 케이스 추가

### 기여 가이드라인
- **학습자 중심**: 초보자가 이해하기 쉬운 코드와 설명
- **일관성 유지**: 기존 스타일과 패턴 준수
- **문서화**: 새로운 기능에 대한 설명 추가
- **테스트 우선**: TDD 방식으로 테스트 먼저 작성

## 📄 라이선스

이 프로젝트는 MIT 라이선스 하에 배포됩니다. 자세한 내용은 [LICENSE](LICENSE) 파일을 참조하세요.

## 🙏 감사의 말

- **C++ 커뮤니티**: 영감과 지식을 제공해주신 모든 분들
- **오픈소스 프로젝트들**: 참고 자료로 활용한 프로젝트들
- **학습자들**: 피드백과 개선 제안을 해주신 분들
- **TDD 커뮤니티**: 테스트 주도 개발 방법론을 발전시켜주신 분들

## 📞 연락처

프로젝트에 대한 질문이나 제안사항이 있으시면 이슈를 통해 연락해주세요.

---

**🐾 함께 C++의 세계로 모험을 떠나봐요!**

*"코딩은 어렵지 않아요. 귀여운 동물 친구들과 함께라면 더욱 재미있답니다!"*

*"TDD로 안정적이고 확장 가능한 코드를 작성해봐요!"* 