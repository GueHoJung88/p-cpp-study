# 🐾 Character System TDD 테스트 가이드

## 📋 개요

이 문서는 업데이트된 `Character.h` 파일을 기반으로 한 TDD(Test-Driven Development) 방식의 테스트 가이드입니다. 기존 `gemini/Character.h` 파일의 모든 캐릭터 정보와 기능을 통합하여 체계적인 테스트 전략을 제시합니다.

## 🎯 목표

1. **완전한 캐릭터 시스템**: 12가지 캐릭터 종류 지원
2. **상세한 프로필 정보**: 나이, 재산, 고향, 성별 등 풍부한 정보
3. **감정 표현 시스템**: 6가지 감정 상태별 ASCII 아트
4. **게임 시스템**: 경험치, 레벨업, HP, Power 등
5. **팩토리 패턴**: 체계적인 캐릭터 생성
6. **관리자 시스템**: 캐릭터 검색, 필터링, 통계

## 🐕 지원하는 캐릭터 종류

### 🐕 동물 캐릭터들
1. **치와와 (치치)** - 선생님 역할
2. **웰시코기 (코코)** - 도우미 역할
3. **골든리트리버 (리버)** - 친구 역할
4. **허스키 (허허)** - 모험가 역할
5. **토끼 (토토)** - 퀴즈 역할
6. **고양이 (냥냥)** - 채점 역할
7. **말티즈 (보리)** - 주인공 역할
8. **비숑 프리제 (숑숑)** - 친구 역할
9. **불독 (불리)** - 보호자 역할

### 👤 인간 캐릭터들
10. **임정찬 (Liki)** - 학생 역할
11. **정규호 (바보)** - 분위기메이커 역할

### 🐱 신비한 캐릭터
12. **싀백 (먀엉)** - 현자 역할

## 🧪 TDD 테스트 전략

### 📋 1단계: Red-Green-Refactor 사이클

#### 🔴 Red 단계: 실패하는 테스트 작성
```cpp
TEST_F(CharacterSystemTest, CharacterCreation_ValidData_CreatesCharacter) {
    Character testChar("Test", Species::CHIHUAHUA, "TestRole");
    
    EXPECT_EQ(testChar.getName(), "Test");
    EXPECT_EQ(testChar.getSpecies(), Species::CHIHUAHUA);
    EXPECT_EQ(testChar.getRole(), "TestRole");
    EXPECT_EQ(testChar.getLevel(), 1);
    EXPECT_EQ(testChar.getExperience(), 0);
}
```

#### 🟢 Green 단계: 최소한의 코드로 테스트 통과
```cpp
class Character {
private:
    std::string name;
    Species species;
    std::string role;
    int level;
    int experience;
    
public:
    Character(const std::string& n, Species s, const std::string& r)
        : name(n), species(s), role(r), level(1), experience(0) {}
    
    std::string getName() const { return name; }
    Species getSpecies() const { return species; }
    std::string getRole() const { return role; }
    int getLevel() const { return level; }
    int getExperience() const { return experience; }
};
```

#### 🔄 Refactor 단계: 코드 개선
- 중복 제거
- 가독성 향상
- 성능 최적화
- 코드 구조 개선

### 📋 2단계: 테스트 카테고리별 접근

#### 🎯 기본 기능 테스트
```cpp
// 캐릭터 생성 테스트
TEST_F(CharacterSystemTest, CharacterCreation_ValidData_CreatesCharacter)
TEST_F(CharacterSystemTest, CharacterCreation_EmptyData_CreatesCharacter)

// 상세 프로필 테스트
TEST_F(CharacterSystemTest, DetailedConstructor_ValidData_CreatesCharacterWithProfile)
TEST_F(CharacterSystemTest, DetailedConstructor_DifferentSpecies_CreatesCorrectCharacter)
```

#### 🎯 게임 시스템 테스트
```cpp
// 경험치 시스템
TEST_F(CharacterSystemTest, GainExperience_PositiveValue_IncreasesExperience)
TEST_F(CharacterSystemTest, GainExperience_ZeroValue_NoChange)
TEST_F(CharacterSystemTest, GainExperience_NegativeValue_NoChange)

// 레벨업 시스템
TEST_F(CharacterSystemTest, LevelUp_SufficientExperience_LevelsUp)
TEST_F(CharacterSystemTest, LevelUp_InsufficientExperience_NoLevelUp)
```

#### 🎯 표시 시스템 테스트
```cpp
// 캐릭터 표시
TEST_F(CharacterSystemTest, Display_ValidEmotion_ShowsCorrectOutput)
TEST_F(CharacterSystemTest, Display_DefaultEmotion_ShowsDefaultOutput)

// 프로필 표시
TEST_F(CharacterSystemTest, ShowProfile_ValidCharacter_ShowsCompleteProfile)
```

#### 🎯 팩토리 패턴 테스트
```cpp
// 팩토리 메서드
TEST_F(CharacterSystemTest, CharacterFactory_CreateChihuahua_ReturnsValidCharacter)
TEST_F(CharacterSystemTest, CharacterFactory_CreateAllTypes_ReturnsValidCharacters)
TEST_F(CharacterSystemTest, CharacterFactory_InitializeAllCharacters_ReturnsCorrectCount)
```

#### 🎯 관리자 시스템 테스트
```cpp
// 캐릭터 관리
TEST_F(CharacterSystemTest, CharacterManager_AddCharacter_StoresCharacter)
TEST_F(CharacterSystemTest, CharacterManager_GetCharacterByName_ReturnsCorrectCharacter)
TEST_F(CharacterSystemTest, CharacterManager_GetCharacterBySpecies_ReturnsCorrectCharacter)

// 검색 및 필터링
TEST_F(CharacterSystemTest, CharacterManager_GetCharactersByRole_ReturnsCorrectCharacters)
TEST_F(CharacterSystemTest, CharacterManager_GetStrongestCharacter_ReturnsHighestPower)
TEST_F(CharacterSystemTest, CharacterManager_GetWeakestCharacter_ReturnsLowestPower)
```

#### 🎯 특수 기능 테스트
```cpp
// 모든 종류 테스트
TEST_F(CharacterSystemTest, AllSpecies_DisplayCorrectly)

// 감정 시스템
TEST_F(CharacterSystemTest, DisplayEmotions_AllEmotions_ShowCorrectOutput)

// 특수 캐릭터
TEST_F(CharacterSystemTest, HumanCharacters_HaveCorrectProperties)
TEST_F(CharacterSystemTest, MysticalCat_HasCorrectProperties)
```

#### 🎯 연산자 및 경계값 테스트
```cpp
// 연산자 오버로딩
TEST_F(CharacterSystemTest, OperatorEquality_SameCharacter_ReturnsTrue)
TEST_F(CharacterSystemTest, OperatorEquality_DifferentCharacter_ReturnsFalse)
TEST_F(CharacterSystemTest, OperatorInequality_DifferentCharacter_ReturnsTrue)

// 경계값 처리
TEST_F(CharacterSystemTest, BoundaryValues_ExtremeExperience_HandlesCorrectly)
TEST_F(CharacterSystemTest, BoundaryValues_EmptyStrings_HandlesCorrectly)
```

#### 🎯 성능 및 통합 테스트
```cpp
// 성능 테스트
TEST_F(CharacterSystemTest, Performance_MultipleCharacters_HandlesEfficiently)

// 통합 테스트
TEST_F(CharacterSystemTest, Integration_CompleteCharacterLifecycle_WorksCorrectly)
```

## 🛠️ 테스트 실행 방법

### 📋 자동화된 TDD 테스트 실행
```bash
# Character 시스템 전용 TDD 테스트 실행
./scripts/run_character_tdd_tests.sh
```

### 📋 수동 테스트 실행
```bash
# 빌드 디렉토리 생성
mkdir build && cd build

# CMake 설정
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 ..

# 테스트 빌드
make cpp_learning_tests

# 전체 Character 테스트 실행
./cpp_learning_tests --gtest_filter="CharacterSystemTest.*"

# 특정 카테고리 테스트 실행
./cpp_learning_tests --gtest_filter="CharacterSystemTest.CharacterCreation_*"
./cpp_learning_tests --gtest_filter="CharacterSystemTest.CharacterFactory_*"
./cpp_learning_tests --gtest_filter="CharacterSystemTest.CharacterManager_*"
```

### 📋 테스트 커버리지 확인
```bash
# 커버리지 분석
gcov -r ../src/core

# 커버리지 리포트 생성 (lcov 필요)
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_report
```

## 📊 테스트 결과 분석

### 📋 성공 지표
- **테스트 통과율**: 100% 목표
- **코드 커버리지**: 80% 이상 목표
- **메모리 누수**: 0개 목표
- **성능**: 100개 캐릭터 처리 < 1초

### 📋 품질 지표
- **기능 완성도**: 모든 캐릭터 종류 지원
- **확장성**: 새로운 캐릭터 추가 용이
- **유지보수성**: 코드 가독성 및 구조
- **안정성**: 예외 상황 처리

## 🔧 구현 우선순위

### 🥇 1순위: 핵심 기능
1. **기본 캐릭터 생성**
2. **상세 프로필 정보**
3. **경험치 및 레벨업 시스템**
4. **기본 표시 기능**

### 🥈 2순위: 고급 기능
1. **감정별 ASCII 아트**
2. **팩토리 패턴 구현**
3. **관리자 시스템**
4. **연산자 오버로딩**

### 🥉 3순위: 최적화
1. **성능 최적화**
2. **메모리 관리**
3. **에러 처리 강화**
4. **사용자 경험 개선**

## 🐛 일반적인 문제 및 해결책

### 📋 컴파일 오류
```bash
# 헤더 파일 누락
fatal error: '../src/core/Character.h' file not found
# 해결: CMakeLists.txt에 include_directories 추가

# 네임스페이스 오류
error: 'learning' is not a namespace-name
# 해결: using namespace learning; 추가
```

### 📋 런타임 오류
```bash
# 세그멘테이션 폴트
Segmentation fault (core dumped)
# 해결: 포인터 null 체크 추가

# 메모리 누수
Memory leak detected
# 해결: RAII 패턴 적용, 스마트 포인터 사용
```

### 📋 테스트 실패
```bash
# 예상값과 실제값 불일치
Expected: "Test"
Actual: ""
# 해결: 생성자 구현 확인

# 출력 캡처 실패
Expected: contains "치치"
Actual: ""
# 해결: display 함수 구현 확인
```

## 🚀 다음 단계

### 📋 즉시 구현 필요
1. **Character.cpp 구현 파일 작성**
2. **ASCII 아트 출력 함수 구현**
3. **상세 프로필 정보 초기화**
4. **팩토리 메서드 구현**

### 📋 중기 목표
1. **게임 로직과 통합**
2. **사용자 인터페이스 개선**
3. **추가 캐릭터 종류 확장**
4. **성능 최적화**

### 📋 장기 목표
1. **네트워크 멀티플레이어 지원**
2. **캐릭터 커스터마이징**
3. **AI 캐릭터 행동 패턴**
4. **크로스 플랫폼 지원**

## 📚 참고 자료

### 📋 테스트 관련
- [Google Test 문서](https://google.github.io/googletest/)
- [TDD Best Practices](https://www.agilealliance.org/glossary/tdd/)
- [C++ Testing Strategies](https://en.cppreference.com/)

### 📋 캐릭터 시스템 관련
- [Factory Pattern](https://refactoring.guru/design-patterns/factory-method)
- [Observer Pattern](https://refactoring.guru/design-patterns/observer)
- [State Pattern](https://refactoring.guru/design-patterns/state)

---

**🎯 목표**: 모든 테스트가 통과하며, 확장 가능하고 유지보수하기 쉬운 Character 시스템을 구축하는 것입니다! 🐾 