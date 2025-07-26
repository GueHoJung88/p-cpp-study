# 🛠️ 개발 환경 구축 및 관리 가이드

## 📋 개요

이 문서는 C++ 학습 프로젝트의 개발 환경을 구축하고, TDD 방식의 테스트를 실행하며, 프로젝트를 관리하는 방법을 설명합니다.

## 🎯 목표

1. **개발 환경 구축**: 필요한 도구들 설치 및 설정
2. **TDD 테스트 실행**: 단계별 테스트 수행
3. **프로젝트 관리**: 코드 품질 유지 및 개선
4. **자동화**: 반복 작업의 자동화

## 🛠️ 필수 도구 설치

### 📋 macOS 환경 설정

#### 1. Homebrew 설치 (패키지 관리자)
```bash
# Homebrew가 설치되지 않은 경우
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

#### 2. 필수 개발 도구 설치
```bash
# CMake (빌드 시스템)
brew install cmake

# Git (버전 관리)
brew install git

# Clang/LLVM (컴파일러)
brew install llvm

# Make (빌드 도구)
brew install make
```

#### 3. 선택적 도구 설치 (권장)
```bash
# 코드 품질 도구들
brew install cppcheck          # 정적 분석
brew install clang-format     # 코드 포맷팅
brew install valgrind         # 메모리 누수 검사

# 테스트 커버리지 도구
brew install lcov             # 커버리지 리포트
brew install gcovr            # 커버리지 분석

# 추가 개발 도구
brew install gdb              # 디버거
brew install ctags            # 코드 태그
```

### 📋 Linux 환경 설정

#### Ubuntu/Debian
```bash
# 필수 패키지 설치
sudo apt update
sudo apt install build-essential cmake git clang llvm

# 선택적 도구
sudo apt install cppcheck clang-format valgrind lcov
```

#### CentOS/RHEL
```bash
# 개발 도구 설치
sudo yum groupinstall "Development Tools"
sudo yum install cmake git clang llvm

# 선택적 도구
sudo yum install cppcheck clang-format valgrind lcov
```

### 📋 Windows 환경 설정

#### 1. Visual Studio 설치
- Visual Studio Community (무료) 다운로드
- C++ 개발 도구 포함하여 설치

#### 2. CMake 설치
- CMake 공식 사이트에서 다운로드
- PATH에 추가

#### 3. Git 설치
- Git for Windows 다운로드 및 설치

## 🏗️ 프로젝트 구조

```
p-cpp-study/
├── src/                          # 소스 코드
│   ├── core/                     # 핵심 모듈
│   │   ├── Character.h          # 캐릭터 시스템
│   │   ├── QuizSystem.h         # 퀴즈 시스템
│   │   ├── LearningModule.h     # 학습 모듈
│   │   └── Utils.h              # 유틸리티
│   ├── 01.beggin/              # 기초 학습
│   ├── 02.syntax_output_commnets/
│   ├── 03.variable_user_input_data_type_operators/
│   └── 04.strings_math_boolean_ifelse_switch/
├── tests/                        # 테스트 코드
│   ├── test_utils.cpp
│   ├── test_character_system.cpp
│   ├── test_quiz_system.cpp
│   └── test_learning_modules.cpp
├── scripts/                      # 실행 스크립트
│   ├── run_tdd_refactoring.sh   # 전체 리팩토링
│   └── run_character_tdd_tests.sh # 캐릭터 테스트
├── docs/                         # 문서
│   ├── development_environment_guide.md
│   ├── character_tdd_testing_guide.md
│   └── character_system_summary.md
├── build/                        # 빌드 출력 (자동 생성)
├── CMakeLists.txt               # CMake 설정
└── README.md                    # 프로젝트 설명
```

## 🚀 개발 환경 구축

### 📋 1단계: 저장소 클론
```bash
# 프로젝트 클론
git clone <repository-url>
cd p-cpp-study

# 의존성 확인
which cmake
which make
which git
```

### 📋 2단계: 빌드 환경 설정
```bash
# 빌드 디렉토리 생성
mkdir build
cd build

# CMake 설정
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 ..

# 빌드
make
```

### 📋 3단계: 테스트 환경 확인
```bash
# 테스트 빌드
make cpp_learning_tests

# 테스트 실행
./cpp_learning_tests
```

## 🧪 TDD 테스트 실행

### 📋 테스트 스크립트 종류

#### 1. **전체 프로젝트 리팩토링** (`run_tdd_refactoring.sh`)
- **목적**: 전체 프로젝트의 TDD 기반 리팩토링
- **범위**: 모든 모듈, 전체 코드베이스
- **시간**: 10-15분 (전체 프로젝트 분석)

#### 2. **캐릭터 시스템 전용** (`run_character_tdd_tests.sh`)
- **목적**: Character.h 기반 전용 TDD 테스트
- **범위**: 캐릭터 시스템만
- **시간**: 5-8분 (캐릭터 모듈 집중)

### 📋 실행 순서

```bash
# 1. 전체 프로젝트 리팩토링 (먼저 실행)
./scripts/run_tdd_refactoring.sh

# 2. 캐릭터 시스템 전용 테스트 (그 다음 실행)
./scripts/run_character_tdd_tests.sh
```

### 📋 개별 테스트 실행

```bash
# 특정 테스트만 실행
cd build
./cpp_learning_tests --gtest_filter="CharacterSystemTest.*"
./cpp_learning_tests --gtest_filter="QuizSystemTest.*"
./cpp_learning_tests --gtest_filter="LearningModuleTest.*"
```

## 🔧 프로젝트 관리

### 📋 코드 품질 관리

#### 1. 정적 분석
```bash
# Cppcheck 실행
cppcheck --enable=all src/

# Clang-Tidy 실행
clang-tidy src/**/*.cpp
```

#### 2. 코드 포맷팅
```bash
# Clang-format 적용
find src/ -name "*.cpp" -o -name "*.h" | xargs clang-format -i
```

#### 3. 메모리 누수 검사
```bash
# Valgrind 실행
valgrind --leak-check=full ./cpp_learning_tests
```

### 📋 테스트 커버리지 분석

```bash
# 커버리지 분석
gcov -r src/
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_report
```

### 📋 성능 프로파일링

```bash
# 성능 측정
time ./cpp_learning_tests

# 메모리 사용량 분석
valgrind --tool=massif ./cpp_learning_tests
ms_print massif.out.* > memory_report.txt
```

## 🐛 문제 해결

### 📋 일반적인 문제들

#### 1. CMake 오류
```bash
# 오류: cmake: command not found
# 해결: CMake 설치
brew install cmake  # macOS
sudo apt install cmake  # Ubuntu
```

#### 2. 컴파일 오류
```bash
# 오류: C++17 지원 안됨
# 해결: 컴파일러 업데이트
brew install llvm  # macOS
sudo apt install clang  # Ubuntu
```

#### 3. 테스트 실패
```bash
# 오류: 테스트 파일을 찾을 수 없음
# 해결: 빌드 디렉토리 확인
cd build
make clean
make cpp_learning_tests
```

#### 4. 권한 오류
```bash
# 오류: Permission denied
# 해결: 실행 권한 부여
chmod +x scripts/*.sh
```

### 📋 디버깅 팁

#### 1. 로그 확인
```bash
# 상세 로그 출력
./scripts/run_character_tdd_tests.sh 2>&1 | tee test_log.txt
```

#### 2. 단계별 실행
```bash
# 빌드만 실행
cd build && make cpp_learning_tests

# 테스트만 실행
./cpp_learning_tests --gtest_filter="CharacterSystemTest.*"
```

#### 3. 환경 변수 확인
```bash
# PATH 확인
echo $PATH

# CMake 경로 확인
which cmake
cmake --version
```

## 📊 모니터링 및 보고

### 📋 성능 지표

#### 1. 빌드 시간
```bash
# 빌드 시간 측정
time make cpp_learning_tests
```

#### 2. 테스트 실행 시간
```bash
# 테스트 시간 측정
time ./cpp_learning_tests
```

#### 3. 메모리 사용량
```bash
# 메모리 사용량 확인
valgrind --tool=massif ./cpp_learning_tests
```

### 📋 품질 지표

#### 1. 테스트 커버리지
- 목표: 80% 이상
- 측정: `gcov`, `lcov`

#### 2. 코드 복잡도
- 목표: 순환 복잡도 10 이하
- 측정: `cppcheck`

#### 3. 메모리 누수
- 목표: 0개
- 측정: `valgrind`

## 🚀 자동화

### 📋 CI/CD 파이프라인

#### 1. GitHub Actions 설정
```yaml
# .github/workflows/ci.yml
name: CI
on: [push, pull_request]
jobs:
  test:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v2
    - name: Install dependencies
      run: |
        sudo apt update
        sudo apt install cmake build-essential
    - name: Build and test
      run: |
        mkdir build && cd build
        cmake ..
        make cpp_learning_tests
        ./cpp_learning_tests
```

#### 2. 로컬 자동화 스크립트
```bash
#!/bin/bash
# scripts/auto_test.sh
set -e

echo "🔧 자동 테스트 시작..."

# 빌드
cd build
make clean
make cpp_learning_tests

# 테스트 실행
./cpp_learning_tests

# 커버리지 분석
gcov -r ../src/

echo "✅ 자동 테스트 완료!"
```

## 📚 추가 자료

### 📋 유용한 링크
- [CMake 공식 문서](https://cmake.org/documentation/)
- [Google Test 가이드](https://google.github.io/googletest/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)

### 📋 도구 문서
- [Cppcheck 매뉴얼](http://cppcheck.sourceforge.net/)
- [Clang-format 가이드](https://clang.llvm.org/docs/ClangFormat.html)
- [Valgrind 사용법](https://valgrind.org/docs/manual/)

---

**🎯 목표**: 안정적이고 효율적인 개발 환경을 구축하여 TDD 방식의 개발을 원활하게 수행하는 것입니다! 🛠️ 