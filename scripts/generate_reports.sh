#!/bin/bash

# 테스트 결과 시각화 자동화 스크립트

set -e

# 색상 정의
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# 로그 함수
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

# 프로젝트 루트 확인
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"
REPORTS_DIR="$PROJECT_ROOT/docs/reports"

# 디렉토리 생성
mkdir -p "$REPORTS_DIR/coverage"
mkdir -p "$REPORTS_DIR/performance"
mkdir -p "$REPORTS_DIR/test_results"

cd "$BUILD_DIR"

log_info "테스트 실행 및 리포트 생성 시작..."

# 1. 테스트 실행
log_info "1단계: 테스트 실행..."
if ./cpp_learning_tests --gtest_output=xml:test_results.xml; then
    log_success "테스트 실행 완료"
else
    log_error "테스트 실행 실패"
    exit 1
fi

# 2. 커버리지 리포트 생성
log_info "2단계: 커버리지 리포트 생성..."
if command -v lcov &> /dev/null; then
    lcov --capture --directory . --output-file coverage.info
    genhtml coverage.info --output-directory "$REPORTS_DIR/coverage"
    log_success "커버리지 리포트 생성 완료: $REPORTS_DIR/coverage/index.html"
else
    log_warning "lcov가 설치되지 않았습니다. 커버리지 리포트를 건너뜁니다."
fi

# 3. 성능 데이터 수집
log_info "3단계: 성능 데이터 수집..."
if command -v time &> /dev/null; then
    { time ./cpp_learning_tests; } 2> performance_data.txt
    mv performance_data.txt "$REPORTS_DIR/performance/"
    log_success "성능 데이터 수집 완료"
else
    log_warning "time 명령어를 사용할 수 없습니다."
fi

# 4. XML to HTML 변환
log_info "4단계: 테스트 결과 HTML 변환..."
if [ -f "test_results.xml" ]; then
    if command -v python3 &> /dev/null; then
        python3 "$PROJECT_ROOT/scripts/xml_to_html.py" test_results.xml "$REPORTS_DIR/test_results"
        log_success "테스트 결과 HTML 생성 완료"
    else
        log_warning "Python3가 설치되지 않았습니다. HTML 변환을 건너뜁니다."
    fi
fi

# 5. 요약 리포트 생성
log_info "5단계: 요약 리포트 생성..."
{
    echo "# 테스트 결과 요약"
    echo "생성 시간: $(date)"
    echo ""
    echo "## 테스트 통계"
    echo "- 총 테스트 수: $(grep -c 'testcase' test_results.xml 2>/dev/null || echo 'N/A')"
    echo "- 통과한 테스트: $(grep -c 'PASSED' test_results.xml 2>/dev/null || echo 'N/A')"
    echo "- 실패한 테스트: $(grep -c 'FAILED' test_results.xml 2>/dev/null || echo 'N/A')"
    echo ""
    echo "## 리포트 위치"
    echo "- 커버리지 리포트: $REPORTS_DIR/coverage/index.html"
    echo "- 테스트 결과: $REPORTS_DIR/test_results/index.html"
    echo "- 성능 데이터: $REPORTS_DIR/performance/performance_data.txt"
} > "$REPORTS_DIR/summary.md"

log_success "요약 리포트 생성 완료: $REPORTS_DIR/summary.md"

# 6. 브라우저에서 열기 (macOS)
if [[ "$OSTYPE" == "darwin"* ]]; then
    log_info "6단계: 브라우저에서 리포트 열기..."
    open "$REPORTS_DIR/coverage/index.html" 2>/dev/null || true
    open "$REPORTS_DIR/test_results/index.html" 2>/dev/null || true
fi

log_success "모든 리포트 생성이 완료되었습니다!"
echo ""
echo "📊 생성된 리포트:"
echo "  - 커버리지: $REPORTS_DIR/coverage/index.html"
echo "  - 테스트 결과: $REPORTS_DIR/test_results/index.html"
echo "  - 요약: $REPORTS_DIR/summary.md" 