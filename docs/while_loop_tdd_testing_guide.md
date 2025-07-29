# While Loop 프로그램 TDD 테스트 가이드

## 개요

이 문서는 `src/05.while_for_loop_break_continue_arrays_structures_enums/gemini`와 `src/05.while_for_loop_break_continue_arrays_structures_enums/gpt` 경로의 프로그램들에 대한 TDD(Test-Driven Development) 테스트 구현을 설명합니다.

## 테스트 대상 프로그램

### 1. Gemini WhileLoop Interactive 프로그램
- **파일**: `src/05.while_for_loop_break_continue_arrays_structures_enums/gemini/01.WhileLoop_Interactive.cpp`
- **기능**: 
  - 학습 단계 관리 (LearningStep)
  - 간단한 퀴즈 시스템 (SimpleQuiz)
  - 사용자 학습 데이터 관리 (UserLearningData)
  - 캐릭터 시스템
  - 색상 출력 기능

### 2. GPT WhileLoop Quiz 프로그램
- **파일**: `src/05.while_for_loop_break_continue_arrays_structures_enums/gpt/01.WhileLoop_Quiz.cpp`
- **기능**:
  - 퀴즈 문제 관리 (QuizQuestion)
  - 퀴즈 유형 분류 (QuizType)
  - 사용자 퀴즈 데이터 관리 (UserQuizData)
  - 퀴즈 진행 및 통계

## 테스트 파일 구조

### 1. tests/test_while_loop_gemini.cpp
Gemini WhileLoop Interactive 프로그램의 TDD 테스트

#### 주요 테스트 클래스
- `WhileLoopInteractiveTest`: 메인 테스트 클래스

#### 테스트 카테고리

##### 학습 단계 테스트
- `LearningStepCreation_ValidData_CreatesStep`: 학습 단계 생성 테스트
- `BuildWhileLoopLearningSteps_ReturnsValidSteps`: 학습 단계 빌드 테스트
- `LearningStepTeacherDialogue_ContainsValidContent`: 교사 대화 내용 테스트

##### 간단한 퀴즈 테스트
- `SimpleQuizCreation_ValidData_CreatesQuiz`: 퀴즈 생성 테스트
- `BuildSimpleQuizzes_ReturnsValidQuizzes`: 퀴즈 빌드 테스트
- `QuizCorrectIndex_WithinValidRange`: 정답 인덱스 범위 테스트

##### 사용자 데이터 관리 테스트
- `UserLearningDataCreation_ValidData_CreatesData`: 사용자 데이터 생성 테스트
- `SaveUserData_ValidData_SavesToFile`: 데이터 저장 테스트
- `LoadUserData_ExistingFile_LoadsCorrectData`: 데이터 로드 테스트
- `LoadUserData_NonExistentFile_ReturnsDefaultData`: 파일 없음 처리 테스트

##### 색상 출력 함수 테스트
- `PrintColorFunctions_OutputCorrectFormat`: 색상 출력 형식 테스트

##### 캐릭터 시스템 테스트
- `CharacterCreation_ValidData_CreatesCharacter`: 캐릭터 생성 테스트
- `CharacterDisplay_ValidEmotion_DoesNotThrow`: 캐릭터 표시 테스트

##### 통합 테스트
- `Integration_CompleteLearningFlow_WorksCorrectly`: 전체 학습 플로우 테스트

##### 경계값 테스트
- `BoundaryValues_EmptyStrings_HandlesCorrectly`: 빈 문자열 처리 테스트
- `BoundaryValues_ZeroScores_HandlesCorrectly`: 0점 처리 테스트
- `BoundaryValues_MaximumScores_HandlesCorrectly`: 최대값 처리 테스트

##### 성능 테스트
- `Performance_MultipleLearningSteps_HandlesEfficiently`: 다중 학습 단계 성능 테스트

##### 예외 처리 테스트
- `ExceptionHandling_InvalidQuizIndex_HandlesGracefully`: 잘못된 퀴즈 인덱스 처리
- `ExceptionHandling_EmptyQuizOptions_HandlesGracefully`: 빈 퀴즈 옵션 처리

### 2. tests/test_while_loop_gpt.cpp
GPT WhileLoop Quiz 프로그램의 TDD 테스트

#### 주요 테스트 클래스
- `WhileLoopQuizTest`: 메인 테스트 클래스

#### 테스트 카테고리

##### 퀴즈 유형 테스트
- `QuizTypeEnum_ValidValues_DefinedCorrectly`: 퀴즈 유형 열거형 테스트

##### 퀴즈 문제 테스트
- `QuizQuestionCreation_ValidData_CreatesQuestion`: 퀴즈 문제 생성 테스트
- `BuildReviewQuizzes_ReturnsValidQuizzes`: 복습 퀴즈 빌드 테스트
- `BuildWhileLoopQuizzes_ReturnsValidQuizzes`: While Loop 퀴즈 빌드 테스트
- `BuildPracticeQuizzes_ReturnsValidQuizzes`: 연습 퀴즈 빌드 테스트
- `QuizCorrectIndex_WithinValidRange`: 정답 인덱스 범위 테스트

##### 사용자 퀴즈 데이터 테스트
- `UserQuizDataCreation_ValidData_CreatesData`: 사용자 퀴즈 데이터 생성 테스트
- `SaveUserQuizData_ValidData_SavesToFile`: 퀴즈 데이터 저장 테스트
- `LoadUserQuizData_ExistingFile_LoadsCorrectData`: 퀴즈 데이터 로드 테스트
- `LoadUserQuizData_NonExistentFile_ReturnsDefaultData`: 파일 없음 처리 테스트

##### 색상 출력 함수 테스트
- `PrintColorFunctions_OutputCorrectFormat`: 색상 출력 형식 테스트

##### 캐릭터 시스템 테스트
- `CharacterCreation_ValidData_CreatesCharacter`: 캐릭터 생성 테스트
- `CharacterDisplay_ValidEmotion_DoesNotThrow`: 캐릭터 표시 테스트

##### 퀴즈 난이도 및 카테고리 테스트
- `QuizDifficulty_ValidRange_WithinBounds`: 퀴즈 난이도 범위 테스트
- `QuizCategories_ValidCategories_NotEmpty`: 퀴즈 카테고리 테스트

##### 통합 테스트
- `Integration_CompleteQuizFlow_WorksCorrectly`: 전체 퀴즈 플로우 테스트

##### 경계값 테스트
- `BoundaryValues_EmptyStrings_HandlesCorrectly`: 빈 문자열 처리 테스트
- `BoundaryValues_ZeroScores_HandlesCorrectly`: 0점 처리 테스트
- `BoundaryValues_MaximumScores_HandlesCorrectly`: 최대값 처리 테스트

##### 성능 테스트
- `Performance_MultipleQuizQuestions_HandlesEfficiently`: 다중 퀴즈 문제 성능 테스트

##### 예외 처리 테스트
- `ExceptionHandling_InvalidQuizIndex_HandlesGracefully`: 잘못된 퀴즈 인덱스 처리
- `ExceptionHandling_EmptyQuizOptions_HandlesGracefully`: 빈 퀴즈 옵션 처리
- `ExceptionHandling_InvalidDifficulty_HandlesGracefully`: 잘못된 난이도 처리

##### 퀴즈 타입별 분류 테스트
- `QuizTypeClassification_ReviewQuizzes_HaveCorrectType`: 복습 퀴즈 타입 분류 테스트
- `QuizTypeClassification_FinalQuizzes_HaveCorrectType`: 최종 퀴즈 타입 분류 테스트
- `QuizTypeClassification_PracticeQuizzes_HaveCorrectType`: 연습 퀴즈 타입 분류 테스트

## TDD 접근 방식

### 1. 테스트 우선 설계 (Test-First Design)
- 각 기능에 대한 테스트를 먼저 작성
- 실패하는 테스트부터 시작
- 최소한의 코드로 테스트 통과
- 리팩토링을 통한 코드 개선

### 2. 테스트 구조
```cpp
TEST_F(TestClassName, TestMethodName_InputCondition_ExpectedResult) {
    // Arrange (준비)
    // Act (실행)
    // Assert (검증)
}
```

### 3. 테스트 범주
- **단위 테스트**: 개별 함수/클래스 테스트
- **통합 테스트**: 여러 컴포넌트 간 상호작용 테스트
- **경계값 테스트**: 극한 상황 처리 테스트
- **성능 테스트**: 대용량 데이터 처리 테스트
- **예외 처리 테스트**: 오류 상황 처리 테스트

## 테스트 실행 방법

### 1. 전체 테스트 실행
```bash
./scripts/run_while_loop_tests.sh
```

### 2. 개별 테스트 실행
```bash
# 빌드 디렉토리로 이동
cd build

# Gemini 테스트만 실행
./cpp_learning_tests --gtest_filter="WhileLoopInteractiveTest*"

# GPT 테스트만 실행
./cpp_learning_tests --gtest_filter="WhileLoopQuizTest*"

# 모든 While Loop 관련 테스트 실행
./cpp_learning_tests --gtest_filter="*WhileLoop*"
```

### 3. 특정 테스트 실행
```bash
# 특정 테스트 메서드 실행
./cpp_learning_tests --gtest_filter="WhileLoopInteractiveTest.LearningStepCreation_ValidData_CreatesStep"

# 패턴 매칭으로 테스트 실행
./cpp_learning_tests --gtest_filter="*Creation*"
```

## 테스트 커버리지

### 1. 기능 커버리지
- ✅ 구조체 생성 및 초기화
- ✅ 데이터 저장/로드 기능
- ✅ 퀴즈 생성 및 관리
- ✅ 색상 출력 기능
- ✅ 캐릭터 시스템
- ✅ 파일 I/O 처리

### 2. 경계값 커버리지
- ✅ 빈 문자열 처리
- ✅ 0값 처리
- ✅ 최대값 처리
- ✅ 잘못된 인덱스 처리
- ✅ 파일 없음 상황 처리

### 3. 예외 처리 커버리지
- ✅ 잘못된 데이터 처리
- ✅ 파일 I/O 오류 처리
- ✅ 메모리 할당 실패 처리

## 테스트 데이터

### 1. 테스트용 구조체
```cpp
// 학습 단계 구조체
struct LearningStep {
    string title;
    string explanation;
    string codeExample;
    string practiceQuestion;
    string practiceAnswer;
    string hint;
    vector<string> teacherDialogue;
    vector<string> studentDialogue;
};

// 퀴즈 문제 구조체
struct QuizQuestion {
    string question;
    string hint;
    vector<string> options;
    int correctIndex;
    string explanation;
    string category;
    int difficulty;
    QuizType type;
};

// 사용자 데이터 구조체
struct UserLearningData {
    string username;
    int whileLoopScore;
    int totalQuestions;
    vector<string> completedTopics;
    string lastStudyDate;
};
```

### 2. 테스트용 함수들
- `buildWhileLoopLearningSteps()`: 학습 단계 생성
- `buildSimpleQuizzes()`: 간단한 퀴즈 생성
- `buildReviewQuizzes()`: 복습 퀴즈 생성
- `buildWhileLoopQuizzes()`: While Loop 퀴즈 생성
- `buildPracticeQuizzes()`: 연습 퀴즈 생성
- `saveUserData()` / `loadUserData()`: 사용자 데이터 저장/로드
- `saveUserQuizData()` / `loadUserQuizData()`: 퀴즈 데이터 저장/로드

## 모범 사례

### 1. 테스트 네이밍
- `ClassName_MethodName_InputCondition_ExpectedResult` 형식 사용
- 명확하고 설명적인 테스트 이름 작성

### 2. 테스트 구조
- Arrange-Act-Assert 패턴 준수
- 각 테스트는 독립적으로 실행 가능
- 테스트 간 의존성 최소화

### 3. 테스트 데이터 관리
- 테스트용 파일은 `test_` 접두사 사용
- 테스트 후 자동 정리 (TearDown)
- 격리된 테스트 환경 제공

### 4. 출력 캡처
```cpp
class OutputCapture {
    // 표준 출력을 캡처하여 테스트에서 검증
};
```

## 문제 해결

### 1. 빌드 오류
```bash
# CMake 캐시 정리
rm -rf build
mkdir build
cd build
cmake ..
make
```

### 2. 테스트 실패
- 테스트 로그 확인
- 입력 데이터 검증
- 예상 결과와 실제 결과 비교

### 3. 메모리 누수
- Valgrind를 사용한 메모리 검사
- 스마트 포인터 사용 권장

## 향후 개선 사항

### 1. 추가 테스트 케이스
- 더 많은 경계값 테스트
- 스트레스 테스트
- 동시성 테스트

### 2. 테스트 자동화
- CI/CD 파이프라인 통합
- 자동 테스트 실행 스케줄링

### 3. 테스트 커버리지 향상
- 코드 커버리지 측정 도구 사용
- 미사용 코드 식별 및 제거

## 결론

이 TDD 테스트 구현을 통해 While Loop 프로그램들의 안정성과 신뢰성을 보장할 수 있습니다. 체계적인 테스트 구조와 포괄적인 테스트 커버리지를 통해 프로그램의 품질을 지속적으로 향상시킬 수 있습니다. 