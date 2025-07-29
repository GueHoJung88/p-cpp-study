# 🚀 TDD 기반 리팩토링 가이드

## 📋 개요

이 문서는 C++ 학습 프로젝트의 TDD(Test-Driven Development) 기반 리팩토링 가이드입니다. 기존 코드의 품질을 개선하고 유지보수성을 향상시키기 위한 체계적인 접근 방법을 제시합니다.

## 🎯 목표

1. **코드 품질 향상**: 중복 제거, 일관성 확보, 가독성 개선
2. **테스트 커버리지 확대**: 모든 핵심 기능에 대한 단위 테스트 작성
3. **모듈화 개선**: 기능별 모듈 분리 및 의존성 관리
4. **에러 처리 강화**: 사용자 입력 검증 및 예외 처리 개선
5. **성능 최적화**: 메모리 관리 및 실행 효율성 향상

## 📊 현재 코드 분석 결과

### 🔍 발견된 문제점들

#### 1. **코드 중복**
- 캐릭터 출력 함수들이 여러 파일에 중복 정의
- 유사한 퀴즈 로직이 반복됨
- 유틸리티 함수들이 분산되어 있음

#### 2. **일관성 부족**
- 네이밍 컨벤션이 일관되지 않음
- 코딩 스타일이 파일마다 다름
- 에러 처리 방식이 통일되지 않음

#### 3. **모듈화 부족**
- 기능별 분리가 명확하지 않음
- 의존성이 복잡하게 얽혀있음
- 재사용성이 낮음

#### 4. **테스트 부재**
- 단위 테스트가 없음
- 기능 검증이 수동으로만 이루어짐
- 리팩토링 시 안전성 보장 어려움

## 🛠️ TDD 리팩토링 전략

### 📋 1단계: 테스트 환경 구축

#### 1.1 테스트 프레임워크 설정
```bash
# Google Test 설치 및 설정
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 .
make cpp_learning_tests
```

#### 1.2 테스트 구조 설계
```
tests/
├── test_utils.cpp          # 유틸리티 함수 테스트
├── test_character_system.cpp # 캐릭터 시스템 테스트
├── test_quiz_system.cpp    # 퀴즈 시스템 테스트
└── test_learning_modules.cpp # 학습 모듈 테스트
```

### 📋 2단계: 핵심 모듈 리팩토링

#### 2.1 캐릭터 시스템 통합
**기존 문제**: 캐릭터 출력 함수들이 여러 파일에 중복

**해결 방안**:
```cpp
// src/core/Character.h
namespace learning {
    enum class Emotion { DEFAULT, HAPPY, THINKING, SURPRISED, EXPLAIN };
    enum class Species { CHIHUAHUA, WELSH_CORGI, GOLDEN_RETRIEVER, RABBIT, CAT };
    
    class Character {
    public:
        void display(Emotion emotion = Emotion::DEFAULT) const;
        void gainExperience(int exp);
        bool levelUp();
        // ... 기타 메서드들
    };
}
```

**테스트 코드**:
```cpp
TEST_F(CharacterSystemTest, CharacterCreation_ValidData_CreatesCharacter) {
    Character testChar("Test", Species::CHIHUAHUA, "TestRole");
    EXPECT_EQ(testChar.getName(), "Test");
    EXPECT_EQ(testChar.getSpecies(), Species::CHIHUAHUA);
}
```

#### 2.2 퀴즈 시스템 모듈화
**기존 문제**: 퀴즈 로직이 여러 파일에 분산

**해결 방안**:
```cpp
// src/core/QuizSystem.h
namespace learning {
    class QuizSystem {
    public:
        void addQuestion(const QuizQuestion& question);
        bool submitAnswer(int answer);
        QuizResult getCurrentResult() const;
        // ... 기타 메서드들
    };
}
```

**테스트 코드**:
```cpp
TEST_F(QuizSystemTest, SubmitAnswer_CorrectAnswer_ReturnsTrue) {
    bool result = quizSystem.submitAnswer(2); // 정답
    EXPECT_TRUE(result);
    EXPECT_EQ(quizSystem.getScore(), 1);
}
```

#### 2.3 학습 모듈 추상화
**기존 문제**: 학습 로직이 하드코딩되어 있음

**해결 방안**:
```cpp
// src/core/LearningModule.h
namespace learning {
    class LearningModule {
    public:
        virtual void startLesson() = 0;
        virtual bool validateAnswer(const std::string& answer) = 0;
        virtual std::string getHint() const = 0;
        // ... 기타 가상 메서드들
    };
    
    class VariableModule : public LearningModule {
        // 변수 학습 전용 구현
    };
}
```

### 📋 3단계: 유틸리티 함수 통합

#### 3.1 공통 유틸리티 모듈
```cpp
// src/core/Utils.h
namespace learning {
    class OutputUtils {
    public:
        static void printColored(const std::string& text, const std::string& color);
        static void printHeader(const std::string& title, char border = '=');
        // ... 기타 출력 관련 함수들
    };
    
    class InputUtils {
    public:
        static std::string getStringInput(const std::string& prompt);
        static int getIntInput(const std::string& prompt, int min, int max);
        // ... 기타 입력 관련 함수들
    };
}
```

### 📋 4단계: 에러 처리 개선

#### 4.1 입력 검증 강화
```cpp
// 기존 코드
int answer;
cin >> answer;

// 개선된 코드
int answer = InputUtils::getIntInput("답을 선택하세요 (1-4): ", 1, 4);
if (answer == -1) {
    OutputUtils::printError("잘못된 입력입니다. 다시 시도해주세요.");
    continue;
}
```

#### 4.2 예외 처리 추가
```cpp
class QuizException : public std::exception {
private:
    std::string message;
public:
    QuizException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

// 사용 예시
try {
    quizSystem.submitAnswer(answer);
} catch (const QuizException& e) {
    OutputUtils::printError(e.what());
}
```

## 🧪 테스트 전략

### 📋 단위 테스트 작성 원칙

#### 1. **AAA 패턴 (Arrange-Act-Assert)**
```cpp
TEST_F(CharacterSystemTest, GainExperience_PositiveValue_IncreasesExperience) {
    // Arrange (준비)
    Character chihuahua("치와와", Species::CHIHUAHUA, "선생님");
    int initialExp = chihuahua.getExperience();
    
    // Act (실행)
    chihuahua.gainExperience(50);
    
    // Assert (검증)
    EXPECT_EQ(chihuahua.getExperience(), initialExp + 50);
}
```

#### 2. **경계값 테스트**
```cpp
TEST_F(InputUtilsTest, GetIntInput_BoundaryValues_HandlesCorrectly) {
    // 최소값 테스트
    EXPECT_EQ(InputUtils::getIntInput("", 1, 10), 1);
    
    // 최대값 테스트
    EXPECT_EQ(InputUtils::getIntInput("", 1, 10), 10);
    
    // 범위 밖 값 테스트
    EXPECT_EQ(InputUtils::getIntInput("", 1, 10), -1); // 에러
}
```

#### 3. **예외 상황 테스트**
```cpp
TEST_F(QuizSystemTest, SubmitAnswer_InvalidAnswer_ThrowsException) {
    EXPECT_THROW(quizSystem.submitAnswer(10), QuizException);
    EXPECT_THROW(quizSystem.submitAnswer(-1), QuizException);
}
```

### 📋 통합 테스트

#### 1. **시나리오 기반 테스트**
```cpp
TEST_F(LearningSystemTest, CompleteLearningSession_ValidFlow_CompletesSuccessfully) {
    // 1. 캐릭터 생성
    Character teacher = CharacterFactory::createChihuahua();
    
    // 2. 퀴즈 생성
    QuizSystem quiz;
    quiz.addQuestions(QuizFactory::createBasicVariableQuiz());
    
    // 3. 학습 세션 실행
    LearningSession session(teacher, quiz);
    bool success = session.run();
    
    // 4. 결과 검증
    EXPECT_TRUE(success);
    EXPECT_GT(session.getScore(), 0);
}
```

## 🔄 리팩토링 실행 프로세스

### 📋 자동화된 리팩토링 스크립트

```bash
# 리팩토링 실행
./scripts/run_tdd_refactoring.sh
```

**스크립트 실행 단계**:
1. **코드 분석**: 기존 코드의 복잡도 및 품질 분석
2. **테스트 환경 구축**: CMake 및 Google Test 설정
3. **기존 테스트 실행**: 현재 상태 확인
4. **단계별 리팩토링**: 각 모듈별 개선 작업
5. **성능 테스트**: 메모리 누수 및 성능 검사
6. **코드 품질 검사**: 포맷팅 및 스타일 통일
7. **최종 테스트**: 모든 테스트 통과 확인
8. **문서 생성**: 테스트 커버리지 및 결과 리포트

### 📋 수동 리팩토링 체크리스트

#### ✅ 코드 중복 제거
- [ ] 캐릭터 출력 함수 통합
- [ ] 퀴즈 로직 모듈화
- [ ] 유틸리티 함수 통합
- [ ] 공통 상수 정의

#### ✅ 네이밍 컨벤션 통일
- [ ] 클래스명: PascalCase
- [ ] 함수명: camelCase
- [ ] 상수명: UPPER_SNAKE_CASE
- [ ] 네임스페이스: snake_case

#### ✅ 에러 처리 개선
- [ ] 입력 검증 함수 추가
- [ ] 예외 클래스 정의
- [ ] 에러 메시지 통일
- [ ] 복구 메커니즘 구현

#### ✅ 모듈화 개선
- [ ] 기능별 헤더 파일 분리
- [ ] 의존성 최소화
- [ ] 인터페이스 추상화
- [ ] 팩토리 패턴 적용

## 📈 품질 지표

### 📋 코드 품질 메트릭

#### 1. **테스트 커버리지**
- 목표: 80% 이상
- 현재: 0% (테스트 없음)
- 측정 도구: gcov

#### 2. **순환 복잡도**
- 목표: 함수당 10 이하
- 현재: 일부 함수 15+ (개선 필요)
- 측정 도구: cppcheck

#### 3. **중복 코드 비율**
- 목표: 5% 이하
- 현재: 약 20% (대폭 개선 필요)
- 측정 도구: PMD CPD

#### 4. **메모리 누수**
- 목표: 0개
- 현재: 확인 필요
- 측정 도구: Valgrind

### 📋 성능 지표

#### 1. **컴파일 시간**
- 목표: 30초 이하
- 현재: 약 10초 (양호)

#### 2. **실행 시간**
- 목표: 퀴즈 로딩 1초 이하
- 현재: 확인 필요

#### 3. **메모리 사용량**
- 목표: 50MB 이하
- 현재: 확인 필요

## 🚀 향후 개선 계획

### 📋 단기 목표 (1-2주)

1. **기본 테스트 프레임워크 구축**
   - Google Test 설정 완료
   - 핵심 모듈 테스트 작성
   - CI/CD 파이프라인 구축

2. **코드 중복 제거**
   - 캐릭터 시스템 통합
   - 퀴즈 로직 모듈화
   - 유틸리티 함수 통합

3. **에러 처리 개선**
   - 입력 검증 강화
   - 예외 처리 추가
   - 사용자 친화적 에러 메시지

### 📋 중기 목표 (1-2개월)

1. **아키텍처 개선**
   - MVC 패턴 적용
   - 의존성 주입 구현
   - 플러그인 아키텍처 도입

2. **성능 최적화**
   - 메모리 풀 구현
   - 캐싱 시스템 추가
   - 비동기 처리 도입

3. **확장성 향상**
   - 다국어 지원
   - 테마 시스템
   - 플러그인 API

### 📋 장기 목표 (3-6개월)

1. **고급 기능 추가**
   - AI 기반 학습 경로 추천
   - 실시간 협업 학습
   - 클라우드 동기화

2. **플랫폼 확장**
   - 웹 버전 개발
   - 모바일 앱 개발
   - API 서버 구축

## 📚 참고 자료

### 📋 도구 및 라이브러리

- **테스트 프레임워크**: Google Test
- **정적 분석**: cppcheck, clang-tidy
- **코드 포맷팅**: clang-format
- **메모리 검사**: Valgrind
- **빌드 시스템**: CMake

### 📋 참고 문서

- [Google Test 문서](https://google.github.io/googletest/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [Modern C++ Design Patterns](https://en.cppreference.com/)

## 🤝 기여 가이드

### 📋 개발 환경 설정

```bash
# 필수 도구 설치
brew install cmake googletest cppcheck clang-format valgrind

# 프로젝트 클론 및 설정
git clone <repository-url>
cd p-cpp-study
mkdir build && cd build
cmake ..
make
```

### 📋 테스트 작성 가이드

1. **새로운 기능 추가 시**
   - 먼저 테스트 작성
   - 최소한의 코드로 테스트 통과
   - 리팩토링으로 코드 개선

2. **버그 수정 시**
   - 버그를 재현하는 테스트 작성
   - 버그 수정
   - 테스트 통과 확인

3. **리팩토링 시**
   - 기존 테스트가 모두 통과하는지 확인
   - 리팩토링 수행
   - 테스트 재실행

---

**🎯 목표**: 모든 코드 변경이 테스트로 검증되며, 지속적으로 품질이 향상되는 프로젝트를 만드는 것입니다! 