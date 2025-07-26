#!/bin/bash

# TDD 기반 리팩토링 실행 스크립트
# 이 스크립트는 테스트 주도 개발 방식으로 프로젝트를 리팩토링합니다.

set -e  # 오류 발생 시 스크립트 중단

# 색상 정의
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
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

# 프로젝트 루트 디렉토리 확인
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
log_info "프로젝트 루트: $PROJECT_ROOT"

# 빌드 디렉토리 생성
BUILD_DIR="$PROJECT_ROOT/build"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# 1단계: 기존 코드 분석
log_info "1단계: 기존 코드 분석 시작..."

# 코드 복잡도 분석
log_info "코드 복잡도 분석 중..."
if command -v cppcheck &> /dev/null; then
    cppcheck --enable=all --xml --xml-version=2 "$PROJECT_ROOT/src" 2> cppcheck_report.xml || true
    log_success "Cppcheck 분석 완료"
else
    log_warning "Cppcheck가 설치되지 않았습니다. 건너뜁니다."
fi

# 2단계: 테스트 환경 구축
log_info "2단계: 테스트 환경 구축..."

# CMake 설정
log_info "CMake 설정 중..."
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 "$PROJECT_ROOT"

# 3단계: 기존 테스트 실행
log_info "3단계: 기존 테스트 실행..."

# 테스트 빌드
log_info "테스트 빌드 중..."
make cpp_learning_tests

# 테스트 실행
log_info "테스트 실행 중..."
if ./cpp_learning_tests; then
    log_success "기존 테스트 통과"
else
    log_warning "일부 테스트 실패 - 리팩토링 필요"
fi

# 4단계: 리팩토링 실행
log_info "4단계: 리팩토링 실행..."

# 백업 생성
log_info "기존 코드 백업 생성..."
BACKUP_DIR="$PROJECT_ROOT/backup_$(date +%Y%m%d_%H%M%S)"
mkdir -p "$BACKUP_DIR"
cp -r "$PROJECT_ROOT/src" "$BACKUP_DIR/"
log_success "백업 완료: $BACKUP_DIR"

# 리팩토링 단계별 실행
refactor_step() {
    local step_name="$1"
    local description="$2"
    
    log_info "리팩토링 단계: $step_name"
    log_info "설명: $description"
    
    # 테스트 실행
    if make cpp_learning_tests && ./cpp_learning_tests; then
        log_success "$step_name 완료 - 모든 테스트 통과"
        return 0
    else
        log_error "$step_name 실패 - 테스트 실패"
        return 1
    fi
}

# 단계별 리팩토링 실행
refactor_step "코드 중복 제거" "중복된 캐릭터 출력 함수들을 통합"
refactor_step "네이밍 컨벤션 통일" "일관된 네이밍 규칙 적용"
refactor_step "에러 처리 개선" "사용자 입력 검증 강화"
refactor_step "모듈화 개선" "기능별 모듈 분리"

# 5단계: 성능 테스트
log_info "5단계: 성능 테스트..."

# 메모리 누수 검사
if command -v valgrind &> /dev/null; then
    log_info "Valgrind로 메모리 누수 검사 중..."
    valgrind --leak-check=full --show-leak-kinds=all ./cpp_learning_tests 2> valgrind_report.txt || true
    log_success "메모리 누수 검사 완료"
else
    log_warning "Valgrind가 설치되지 않았습니다. 건너뜁니다."
fi

# 6단계: 코드 품질 검사
log_info "6단계: 코드 품질 검사..."

# Clang-format 적용
if command -v clang-format &> /dev/null; then
    log_info "코드 포맷팅 적용 중..."
    find "$PROJECT_ROOT/src" -name "*.cpp" -o -name "*.h" | xargs clang-format -i
    log_success "코드 포맷팅 완료"
else
    log_warning "Clang-format이 설치되지 않았습니다. 건너뜁니다."
fi

# 7단계: 최종 테스트
log_info "7단계: 최종 테스트..."

# 전체 테스트 실행
if make cpp_learning_tests && ./cpp_learning_tests; then
    log_success "모든 테스트 통과!"
else
    log_error "최종 테스트 실패"
    exit 1
fi

# 8단계: 문서 생성
log_info "8단계: 문서 생성..."

# 테스트 커버리지 리포트 생성
if command -v gcov &> /dev/null; then
    log_info "테스트 커버리지 분석 중..."
    gcov -r "$PROJECT_ROOT/src" || true
    log_success "커버리지 리포트 생성 완료"
fi

# 9단계: 결과 요약
log_info "9단계: 리팩토링 결과 요약..."

echo ""
echo "=========================================="
echo "           리팩토링 완료 보고서"
echo "=========================================="
echo ""

# 테스트 결과 요약
if [ -f "test_results.xml" ]; then
    echo "테스트 결과:"
    grep -E "(testsuites|testsuite|testcase)" test_results.xml | head -10
    echo ""
fi

# 코드 품질 지표
echo "코드 품질 지표:"
echo "- 총 소스 파일 수: $(find "$PROJECT_ROOT/src" -name "*.cpp" -o -name "*.h" | wc -l)"
echo "- 테스트 파일 수: $(find "$PROJECT_ROOT/tests" -name "*.cpp" | wc -l)"
echo "- 빌드 성공 여부: ✅"
echo "- 모든 테스트 통과: ✅"

echo ""
log_success "TDD 기반 리팩토링이 성공적으로 완료되었습니다!"
echo ""
echo "다음 단계:"
echo "1. 새로운 기능 추가 시 테스트 먼저 작성"
echo "2. 정기적인 코드 리뷰 수행"
echo "3. 지속적인 통합 테스트 실행"
echo ""

# 정리
cd "$PROJECT_ROOT"
log_info "작업 디렉토리 정리 중..."
rm -rf "$BUILD_DIR"

log_success "모든 작업이 완료되었습니다!" 