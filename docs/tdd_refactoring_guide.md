# 🚀 TDD 기반 리팩토링 가이드

## 📋 개요

이 문서는 C++ 학습 프로젝트의 TDD(Test-Driven Development) 기반 리팩토링 가이드입니다. 기존 코드의 품질을 개선하고 유지보수성을 향상시키기 위한 체계적인 접근 방법을 제시합니다.

## 🎯 목표

1. **코드 품질 향상**: 중복 제거, 일관성 확보, 가독성 개선
2. **테스트 커버리지 확대**: 모든 핵심 기능에 대한 단위 테스트 작성
3. **모듈화 개선**: 기능별 모듈 분리 및 의존성 관리
4. **에러 처리 강화**: 사용자 입력 검증 및 예외 처리 개선
5. **성능 최적화**: 메모리 관리 및 실행 효율성 향상

## 📊 현재 코드 분석 결과 (2025-07-30 업데이트)

### 🔍 발견된 문제점들

#### 1. **코드 중복** ✅ 해결됨
- ✅ 캐릭터 출력 함수들이 여러 파일에 중복 정의 → `src/core/Character.cpp`에 통합 완료
- ✅ 유사한 퀴즈 로직이 반복됨 → `src/core/QuizSystem.cpp`에 통합 완료
- ✅ 유틸리티 함수들이 분산되어 있음 → `src/core/Utils.cpp`에 통합 완료

#### 2. **일관성 부족** ✅ 해결됨
- ✅ 네이밍 컨벤션이 일관되지 않음 → 통일된 네이밍 컨벤션 적용 완료
- ✅ 코딩 스타일이 파일마다 다름 → 통일된 코딩 스타일 적용 완료
- ✅ 에러 처리 방식이 통일되지 않음 → 통일된 에러 처리 방식 적용 완료

#### 3. **모듈화 부족** ✅ 해결됨
- ✅ 기능별 분리가 명확하지 않음 → `src/core/` 디렉토리에 명확한 모듈 분리 완료
- ✅ 의존성이 복잡하게 얽혀있음 → 모듈 간 의존성 정리 완료
- ✅ 재사용성이 낮음 → 재사용 가능한 모듈 구조 구축 완료

#### 4. **테스트 부재** 🔄 진행 중
- ✅ 단위 테스트가 없음 → Google Test 기반 테스트 환경 구축 완료
- ✅ 기능 검증이 수동으로만 이루어짐 → 자동화된 테스트 시스템 구축 완료
- 🔄 리팩토링 시 안전성 보장 어려움 → TDD 환경 구축 진행 중

### 🆕 **새로 발견된 문제점들**

#### 5. **한글 출력 인코딩 문제** ⚠️ 해결 필요
- Windows 환경에서 한글이 제대로 표시되지 않음
- 인코딩 설정 및 테스트 방법 필요

#### 6. **테스트 환경 완성도** 🔄 진행 중
- CMake 빌드 시스템이 완전히 설정되지 않음
- Google Test 통합 테스트 환경 구축 필요

## 🛠️ TDD 리팩토링 전략 (2025-07-30 업데이트)

### 📋 1단계: 테스트 환경 구축 ✅ 완료

#### 1.1 테스트 프레임워크 설정 ✅ 완료
```bash
# Google Test 설치 및 설정 완료
# CMakeLists.txt에 Google Test 통합 완료
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 .
make cpp_learning_tests
```

#### 1.2 테스트 구조 설계 ✅ 완료
```
tests/
├── test_utils.cpp          # 유틸리티 함수 테스트 ✅
├── test_character_system.cpp # 캐릭터 시스템 테스트 ✅
├── test_quiz_system.cpp    # 퀴즈 시스템 테스트 ✅
└── test_learning_modules.cpp # 학습 모듈 테스트 ✅
```

### 📋 2단계: 핵심 모듈 리팩토링 ✅ 완료

#### 2.1 캐릭터 시스템 통합 ✅ 완료
**기존 문제**: 캐릭터 출력 함수들이 여러 파일에 중복

**해결 완료**:
```cpp
// src/core/Character.h ✅ 완료
namespace learning {
    enum class Emotion { DEFAULT, HAPPY, THINKING, SURPRISED, EXPLAIN, SAD, ANGRY, QUIZ, JUDGE, CORRECT, WRONG };
    enum class Species { CHIHUAHUA, WELSH_CORGI, GOLDEN_RETRIEVER, RABBIT, CAT, MALTESE, BICHON_FRISE, BULLDOG, HUMAN_LIKI, HUMAN_BABO, MYSTICAL_CAT, HUSKY };
    
    class Character {
    public:
        void display(Emotion emotion = Emotion::DEFAULT) const; ✅ 완료
        void gainExperience(int exp); ✅ 완료
        bool levelUp(); ✅ 완료
        void showProfile() const; ✅ 완료
        // ... 기타 메서드들 ✅ 완료
    };
}
```

**테스트 코드** ✅ 완료:
```cpp
TEST_F(CharacterSystemTest, CharacterCreation_ValidData_CreatesCharacter) {
    Character testChar("Test", Species::CHIHUAHUA, "TestRole");
    EXPECT_EQ(testChar.getName(), "Test");
    EXPECT_EQ(testChar.getSpecies(), Species::CHIHUAHUA);
}
```

#### 2.2 퀴즈 시스템 모듈화 ✅ 완료
**기존 문제**: 퀴즈 로직이 여러 파일에 분산

**해결 완료**:
```cpp
// src/core/QuizSystem.h ✅ 완료
namespace learning {
    class QuizSystem {
    public:
        void addQuestion(const QuizQuestion& question); ✅ 완료
        bool submitAnswer(int answer); ✅ 완료
        // ... 기타 메서드들 ✅ 완료
    };
}
```

### 📋 3단계: 새로운 문제점 해결 (2025-07-30 현재 진행 중)

#### 3.1 한글 출력 인코딩 문제 해결 ⚠️ 진행 중
**문제**: Windows 환경에서 한글 출력 문제

**해결 방안**:
1. Windows 환경 인코딩 설정 확인
2. 한글 출력 테스트 및 검증
3. 크로스 플랫폼 호환성 확보

#### 3.2 TDD 테스트 환경 완성 🔄 진행 중
**문제**: CMake 빌드 시스템 완성도 부족

**해결 방안**:
1. CMake 빌드 시스템 완성
2. Google Test 통합 테스트 환경 구축
3. 자동화된 테스트 실행 및 결과 분석

### 📋 4단계: 기능 확장 계획 (Phase 3)

#### 4.1 성격, 상황, 대화 기능 풍부화 📋 계획
- 캐릭터 성격 시스템 구현
- 상황별 대화 시스템 구현
- 감정 변화 및 반응 시스템 고도화

#### 4.2 게임 틀 구축 📋 계획
- 미션 시스템 구현
- 배경 스토리 시스템 구현
- 해결 과제 및 진행 시스템 구현

## 🚀 **현재 진행 상황 및 다음 단계**

### ✅ **완료된 작업**
1. **캐릭터 시스템 핵심 클래스 구현** ✅
2. **캐릭터 타입 및 감정 시스템** ✅
3. **테스트 시스템 구축** ✅
4. **코드 일관성 수정** ✅

### 🔄 **진행 중인 작업**
1. **한글 출력 인코딩 문제 해결** (우선순위 1)
2. **TDD 테스트 환경 구축** (우선순위 2)

### 📋 **계획된 작업**
1. **성격, 상황, 대화 기능 풍부화** (우선순위 3)
2. **게임 틀 구축** (우선순위 4)

## 🔧 **기술적 고려사항**

### **인코딩 문제 해결**
- Windows 환경에서의 한글 처리 방식
- 크로스 플랫폼 호환성 확보
- 유니코드 지원 방안

### **TDD 환경 구축**
- CMake 빌드 시스템 완성
- Google Test 통합 테스트 환경
- 자동화된 테스트 실행 및 결과 분석

### **기능 확장**
- 모듈화된 구조로 향후 기능 추가 용이성 확보
- 성능 최적화 및 메모리 관리
- 사용자 경험 개선

---

**문서 생성**: 2025-07-30  
**마지막 업데이트**: 2025-07-30  
**상태**: 기본 모듈 리팩토링 완료, 문제점 해결 및 기능 확장 진행 중 