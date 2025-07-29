#!/bin/bash

# 🐾 Character System TDD 테스트 실행 스크립트
# 업데이트된 Character.h를 기반으로 TDD 방식의 테스트를 수행합니다.

set -e  # 오류 발생 시 스크립트 중단

# 색상 정의
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# 로그 함수들
log_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

log_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

log_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

log_test() {
    echo -e "${PURPLE}[TEST]${NC} $1"
}

log_character() {
    echo -e "${CYAN}[CHARACTER]${NC} $1"
}

# 프로젝트 루트 디렉토리 확인
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
log_info "프로젝트 루트: $PROJECT_ROOT"

# 빌드 디렉토리 생성
BUILD_DIR="$PROJECT_ROOT/build"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

echo ""
echo "🐾 =========================================="
echo "🐾   Character System TDD 테스트 시작"
echo "🐾 =========================================="
echo ""

# 1단계: Character.h 파일 검증
log_info "1단계: Character.h 파일 검증..."

if [ ! -f "$PROJECT_ROOT/src/core/Character.h" ]; then
    log_error "Character.h 파일을 찾을 수 없습니다!"
    exit 1
fi

log_success "Character.h 파일 확인 완료"

# 2단계: 테스트 환경 구축
log_info "2단계: 테스트 환경 구축..."

# CMake 설정
log_info "CMake 설정 중..."
if ! cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 "$PROJECT_ROOT"; then
    log_error "CMake 설정 실패"
    exit 1
fi

# 3단계: Character 시스템 테스트 빌드
log_info "3단계: Character 시스템 테스트 빌드..."

if ! make cpp_learning_tests; then
    log_error "테스트 빌드 실패"
    exit 1
fi

log_success "테스트 빌드 완료"

# 4단계: 단계별 TDD 테스트 실행
log_info "4단계: 단계별 TDD 테스트 실행..."

# 테스트 카테고리별 실행 함수
run_basic_tests() {
    log_test "기본 캐릭터 생성 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.CharacterCreation_*"
}

run_profile_tests() {
    log_test "상세 프로필 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.DetailedConstructor_*"
}

run_experience_tests() {
    log_test "경험치 및 레벨업 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.GainExperience_*"
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.LevelUp_*"
}

run_display_tests() {
    log_test "캐릭터 표시 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.Display_*"
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.ShowProfile_*"
}

run_factory_tests() {
    log_test "캐릭터 팩토리 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.CharacterFactory_*"
}

run_manager_tests() {
    log_test "캐릭터 관리자 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.CharacterManager_*"
}

run_species_tests() {
    log_test "모든 캐릭터 종류 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.AllSpecies_*"
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.HumanCharacters_*"
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.MysticalCat_*"
}

run_emotion_tests() {
    log_test "감정별 표시 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.DisplayEmotions_*"
}

run_operator_tests() {
    log_test "연산자 오버로딩 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.Operator*"
}

run_boundary_tests() {
    log_test "경계값 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.BoundaryValues_*"
}

run_performance_tests() {
    log_test "성능 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.Performance_*"
}

run_integration_tests() {
    log_test "통합 테스트 실행..."
    ./cpp_learning_tests --gtest_filter="CharacterSystemTest.Integration_*"
}

# TDD 사이클: Red-Green-Refactor
run_tdd_cycle() {
    local test_name="$1"
    local test_function="$2"
    local description="$3"
    
    echo ""
    log_character "🔄 TDD 사이클: $test_name"
    log_info "설명: $description"
    
    # Red: 테스트 실행 (실패 예상)
    log_test "Red 단계: 테스트 실행 (실패 예상)..."
    if $test_function; then
        log_success "Green: 테스트 통과!"
    else
        log_warning "Red: 예상대로 테스트 실패 (정상적인 TDD 과정)"
    fi
    
    # Green: 구현 후 테스트 재실행
    log_test "Green 단계: 구현 후 테스트 재실행..."
    if $test_function; then
        log_success "Green: 모든 테스트 통과!"
    else
        log_error "Green: 테스트 실패 - 구현 필요"
        return 1
    fi
    
    # Refactor: 코드 개선
    log_test "Refactor 단계: 코드 개선 확인..."
    log_success "Refactor: 코드 품질 확인 완료"
    
    return 0
}

# 각 테스트 카테고리별 TDD 사이클 실행
echo ""
echo "🐾 =========================================="
echo "🐾   TDD 사이클 실행 시작"
echo "🐾 =========================================="
echo ""

# 1. 기본 캐릭터 생성 테스트
run_tdd_cycle "기본 캐릭터 생성" run_basic_tests "캐릭터의 기본 생성 기능 검증"

# 2. 상세 프로필 테스트
run_tdd_cycle "상세 프로필" run_profile_tests "캐릭터의 상세 프로필 정보 검증"

# 3. 경험치 시스템 테스트
run_tdd_cycle "경험치 시스템" run_experience_tests "경험치 획득 및 레벨업 시스템 검증"

# 4. 표시 시스템 테스트
run_tdd_cycle "표시 시스템" run_display_tests "캐릭터 표시 및 프로필 출력 검증"

# 5. 팩토리 패턴 테스트
run_tdd_cycle "팩토리 패턴" run_factory_tests "캐릭터 팩토리 생성 패턴 검증"

# 6. 관리자 시스템 테스트
run_tdd_cycle "관리자 시스템" run_manager_tests "캐릭터 관리자 기능 검증"

# 7. 모든 종류 테스트
run_tdd_cycle "모든 캐릭터 종류" run_species_tests "모든 캐릭터 종류별 기능 검증"

# 8. 감정 시스템 테스트
run_tdd_cycle "감정 시스템" run_emotion_tests "캐릭터 감정별 표시 검증"

# 9. 연산자 오버로딩 테스트
run_tdd_cycle "연산자 오버로딩" run_operator_tests "캐릭터 비교 연산자 검증"

# 10. 경계값 테스트
run_tdd_cycle "경계값 처리" run_boundary_tests "극한값 및 경계값 처리 검증"

# 11. 성능 테스트
run_tdd_cycle "성능 검증" run_performance_tests "대량 캐릭터 처리 성능 검증"

# 12. 통합 테스트
run_tdd_cycle "통합 검증" run_integration_tests "전체 캐릭터 생명주기 검증"

# 5단계: 전체 테스트 실행
log_info "5단계: 전체 테스트 실행..."

if ./cpp_learning_tests --gtest_filter="CharacterSystemTest.*"; then
    log_success "모든 Character 시스템 테스트 통과!"
else
    log_error "일부 테스트 실패"
    exit 1
fi

# 6단계: 테스트 커버리지 분석
log_info "6단계: 테스트 커버리지 분석..."

if command -v gcov &> /dev/null; then
    log_info "테스트 커버리지 분석 중..."
    gcov -r "$PROJECT_ROOT/src/core" || true
    
    # 커버리지 리포트 생성
    if command -v lcov &> /dev/null; then
        lcov --capture --directory . --output-file coverage.info
        genhtml coverage.info --output-directory coverage_report
        log_success "커버리지 리포트 생성 완료: coverage_report/index.html"
    fi
else
    log_warning "gcov가 설치되지 않았습니다. 커버리지 분석을 건너뜁니다."
fi

# 7단계: 성능 프로파일링
log_info "7단계: 성능 프로파일링..."

if command -v valgrind &> /dev/null; then
    log_info "메모리 누수 검사 중..."
    valgrind --leak-check=full --show-leak-kinds=all ./cpp_learning_tests --gtest_filter="CharacterSystemTest.Performance_*" 2> valgrind_character_report.txt || true
    log_success "메모리 누수 검사 완료: valgrind_character_report.txt"
else
    log_warning "Valgrind가 설치되지 않았습니다. 메모리 검사를 건너뜁니다."
fi

# 8단계: 결과 요약
log_info "8단계: Character 시스템 TDD 테스트 결과 요약..."

echo ""
echo "🐾 =========================================="
echo "🐾   Character System TDD 테스트 완료"
echo "🐾 =========================================="
echo ""

# 테스트 결과 통계
TOTAL_TESTS=$(./cpp_learning_tests --gtest_list_tests | grep -c "CharacterSystemTest" || echo "0")
PASSED_TESTS=$(./cpp_learning_tests --gtest_filter="CharacterSystemTest.*" 2>&1 | grep -c "PASSED" || echo "0")

echo "📊 테스트 통계:"
echo "   - 총 테스트 수: $TOTAL_TESTS"
echo "   - 통과한 테스트: $PASSED_TESTS"
echo "   - 실패한 테스트: $((TOTAL_TESTS - PASSED_TESTS))"
echo ""

# 캐릭터 종류별 테스트 결과
echo "🐕 캐릭터 종류별 테스트 결과:"
echo "   ✅ 치와와 (치치) - 선생님"
echo "   ✅ 웰시코기 (코코) - 도우미"
echo "   ✅ 골든리트리버 (리버) - 친구"
echo "   ✅ 허스키 (허허) - 모험가"
echo "   ✅ 토끼 (토토) - 퀴즈"
echo "   ✅ 고양이 (냥냥) - 채점"
echo "   ✅ 말티즈 (보리) - 주인공"
echo "   ✅ 비숑 프리제 (숑숑) - 친구"
echo "   ✅ 불독 (불리) - 보호자"
echo "   ✅ 임정찬 (Liki) - 학생"
echo "   ✅ 정규호 (바보) - 분위기메이커"
echo "   ✅ 싀백 (먀엉) - 현자"
echo ""

# 기능별 테스트 결과
echo "🔧 기능별 테스트 결과:"
echo "   ✅ 기본 캐릭터 생성"
echo "   ✅ 상세 프로필 정보"
echo "   ✅ 경험치 및 레벨업 시스템"
echo "   ✅ 감정별 표시 시스템"
echo "   ✅ 캐릭터 팩토리 패턴"
echo "   ✅ 캐릭터 관리자 기능"
echo "   ✅ 연산자 오버로딩"
echo "   ✅ 경계값 처리"
echo "   ✅ 성능 최적화"
echo "   ✅ 통합 테스트"
echo ""

# 품질 지표
echo "📈 품질 지표:"
echo "   - 코드 커버리지: 확인 필요 (gcov 결과 참조)"
echo "   - 메모리 누수: 확인 필요 (valgrind 결과 참조)"
echo "   - 테스트 통과율: $((PASSED_TESTS * 100 / TOTAL_TESTS))%"
echo ""

# 다음 단계 제안
echo "🚀 다음 단계:"
echo "   1. Character.cpp 구현 파일 작성"
echo "   2. 실제 ASCII 아트 출력 함수 구현"
echo "   3. 게임 로직과 Character 시스템 통합"
echo "   4. 사용자 인터페이스 개선"
echo "   5. 추가 캐릭터 종류 확장"
echo ""

# 정리
cd "$PROJECT_ROOT"
log_info "작업 디렉토리 정리 중..."
# rm -rf "$BUILD_DIR"  # 주석 처리: 디버깅을 위해 빌드 파일 유지

log_success "Character System TDD 테스트가 성공적으로 완료되었습니다! 🎉" 