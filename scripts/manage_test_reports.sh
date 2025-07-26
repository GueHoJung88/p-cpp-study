#!/bin/bash

# 테스트 결과 시각화 자료 자동 저장 및 관리 스크립트

set -e

# 색상 정의
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
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

log_report() {
    echo -e "${PURPLE}[REPORT]${NC} $1"
}

# 프로젝트 루트 확인
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
REPORTS_DIR="$PROJECT_ROOT/docs/reports"
ARCHIVE_DIR="$PROJECT_ROOT/docs/reports/archive"
TIMESTAMP=$(date +%Y%m%d_%H%M%S)

# 디렉토리 생성
mkdir -p "$REPORTS_DIR"
mkdir -p "$ARCHIVE_DIR"
mkdir -p "$REPORTS_DIR/coverage"
mkdir -p "$REPORTS_DIR/test_results"
mkdir -p "$REPORTS_DIR/performance"

log_info "테스트 결과 관리 시스템 시작..."

# 1. 기존 리포트 백업
backup_existing_reports() {
    log_info "1단계: 기존 리포트 백업..."
    
    if [ -d "$REPORTS_DIR/coverage" ] && [ "$(ls -A "$REPORTS_DIR/coverage")" ]; then
        mkdir -p "$ARCHIVE_DIR/coverage_$TIMESTAMP"
        cp -r "$REPORTS_DIR/coverage"/* "$ARCHIVE_DIR/coverage_$TIMESTAMP/"
        log_success "커버리지 리포트 백업 완료: $ARCHIVE_DIR/coverage_$TIMESTAMP"
    fi
    
    if [ -d "$REPORTS_DIR/test_results" ] && [ "$(ls -A "$REPORTS_DIR/test_results")" ]; then
        mkdir -p "$ARCHIVE_DIR/test_results_$TIMESTAMP"
        cp -r "$REPORTS_DIR/test_results"/* "$ARCHIVE_DIR/test_results_$TIMESTAMP/"
        log_success "테스트 결과 리포트 백업 완료: $ARCHIVE_DIR/test_results_$TIMESTAMP"
    fi
    
    if [ -f "$REPORTS_DIR/summary.md" ]; then
        cp "$REPORTS_DIR/summary.md" "$ARCHIVE_DIR/summary_$TIMESTAMP.md"
        log_success "요약 리포트 백업 완료: $ARCHIVE_DIR/summary_$TIMESTAMP.md"
    fi
}

# 2. 새로운 리포트 생성
generate_new_reports() {
    log_info "2단계: 새로운 리포트 생성..."
    
    # 테스트 실행 및 리포트 생성
    cd "$PROJECT_ROOT/build"
    
    # 테스트 실행
    if ./cpp_learning_tests --gtest_output=xml:test_results.xml; then
        log_success "테스트 실행 완료"
    else
        log_error "테스트 실행 실패"
        return 1
    fi
    
    # 커버리지 리포트 생성
    if command -v lcov &> /dev/null; then
        lcov --capture --directory . --output-file coverage.info
        genhtml coverage.info --output-directory "$REPORTS_DIR/coverage"
        log_success "커버리지 리포트 생성 완료"
    else
        log_warning "lcov가 설치되지 않았습니다. 커버리지 리포트를 건너뜁니다."
    fi
    
    # 성능 데이터 수집
    if command -v time &> /dev/null; then
        { time ./cpp_learning_tests; } 2> "$REPORTS_DIR/performance/performance_data.txt"
        log_success "성능 데이터 수집 완료"
    fi
    
    # HTML 리포트 생성
    if command -v python3 &> /dev/null && [ -f "test_results.xml" ]; then
        python3 "$PROJECT_ROOT/scripts/xml_to_html.py" test_results.xml "$REPORTS_DIR/test_results"
        log_success "HTML 리포트 생성 완료"
    fi
    
    # 요약 리포트 생성
    {
        echo "# 테스트 결과 요약 - $(date)"
        echo ""
        echo "## 📊 테스트 통계"
        echo "- 생성 시간: $(date)"
        echo "- 총 테스트 수: $(grep -c 'testcase' test_results.xml 2>/dev/null || echo 'N/A')"
        echo "- 통과한 테스트: $(grep -c 'PASSED' test_results.xml 2>/dev/null || echo 'N/A')"
        echo "- 실패한 테스트: $(grep -c 'FAILED' test_results.xml 2>/dev/null || echo 'N/A')"
        echo ""
        echo "## 📁 리포트 위치"
        echo "- 커버리지 리포트: $REPORTS_DIR/coverage/index.html"
        echo "- 테스트 결과: $REPORTS_DIR/test_results/index.html"
        echo "- 성능 데이터: $REPORTS_DIR/performance/performance_data.txt"
        echo "- 이전 리포트: $ARCHIVE_DIR/"
        echo ""
        echo "## 🔗 빠른 링크"
        echo "- [최신 커버리지 리포트]($REPORTS_DIR/coverage/index.html)"
        echo "- [최신 테스트 결과]($REPORTS_DIR/test_results/index.html)"
        echo "- [성능 데이터]($REPORTS_DIR/performance/performance_data.txt)"
    } > "$REPORTS_DIR/summary.md"
    
    log_success "요약 리포트 생성 완료"
}

# 3. 리포트 정리 및 관리
organize_reports() {
    log_info "3단계: 리포트 정리 및 관리..."
    
    # 오래된 리포트 정리 (30일 이상)
    find "$ARCHIVE_DIR" -type d -name "*_*" -mtime +30 -exec rm -rf {} \; 2>/dev/null || true
    find "$ARCHIVE_DIR" -name "summary_*.md" -mtime +30 -delete 2>/dev/null || true
    
    # 리포트 인덱스 생성
    {
        echo "# 📊 테스트 리포트 아카이브"
        echo ""
        echo "## 📅 최근 리포트"
        echo ""
        
        # 최근 커버리지 리포트
        latest_coverage=$(find "$ARCHIVE_DIR" -type d -name "coverage_*" | sort | tail -1)
        if [ -n "$latest_coverage" ]; then
            echo "- **커버리지 리포트**: $(basename "$latest_coverage")"
        fi
        
        # 최근 테스트 결과
        latest_test=$(find "$ARCHIVE_DIR" -type d -name "test_results_*" | sort | tail -1)
        if [ -n "$latest_test" ]; then
            echo "- **테스트 결과**: $(basename "$latest_test")"
        fi
        
        # 최근 요약 리포트
        latest_summary=$(find "$ARCHIVE_DIR" -name "summary_*.md" | sort | tail -1)
        if [ -n "$latest_summary" ]; then
            echo "- **요약 리포트**: $(basename "$latest_summary")"
        fi
        
        echo ""
        echo "## 📈 통계"
        echo "- 총 아카이브 수: $(find "$ARCHIVE_DIR" -type d -name "*_*" | wc -l)"
        echo "- 최근 생성: $(date)"
        echo ""
        echo "## 🗂️ 전체 아카이브 목록"
        echo ""
        
        # 모든 아카이브 목록
        find "$ARCHIVE_DIR" -type d -name "*_*" | sort -r | while read -r dir; do
            echo "- $(basename "$dir") ($(stat -f "%Sm" "$dir" 2>/dev/null || echo "Unknown"))"
        done
        
        echo ""
        echo "## 📋 관리 명령어"
        echo "```bash"
        echo "# 새로운 리포트 생성"
        echo "./scripts/manage_test_reports.sh"
        echo ""
        echo "# 오래된 리포트 정리 (30일 이상)"
        echo "find docs/reports/archive -type d -name '*_*' -mtime +30 -exec rm -rf {} \\;"
        echo ""
        echo "# 전체 아카이브 정리"
        echo "rm -rf docs/reports/archive/*"
        echo "```"
    } > "$ARCHIVE_DIR/README.md"
    
    log_success "리포트 정리 및 관리 완료"
}

# 4. 리포트 상태 확인
check_report_status() {
    log_info "4단계: 리포트 상태 확인..."
    
    echo ""
    log_report "📊 현재 리포트 상태:"
    echo ""
    
    # 커버리지 리포트 확인
    if [ -f "$REPORTS_DIR/coverage/index.html" ]; then
        echo "✅ 커버리지 리포트: $REPORTS_DIR/coverage/index.html"
    else
        echo "❌ 커버리지 리포트: 없음"
    fi
    
    # 테스트 결과 확인
    if [ -f "$REPORTS_DIR/test_results/index.html" ]; then
        echo "✅ 테스트 결과: $REPORTS_DIR/test_results/index.html"
    else
        echo "❌ 테스트 결과: 없음"
    fi
    
    # 성능 데이터 확인
    if [ -f "$REPORTS_DIR/performance/performance_data.txt" ]; then
        echo "✅ 성능 데이터: $REPORTS_DIR/performance/performance_data.txt"
    else
        echo "❌ 성능 데이터: 없음"
    fi
    
    # 요약 리포트 확인
    if [ -f "$REPORTS_DIR/summary.md" ]; then
        echo "✅ 요약 리포트: $REPORTS_DIR/summary.md"
    else
        echo "❌ 요약 리포트: 없음"
    fi
    
    # 아카이브 확인
    archive_count=$(find "$ARCHIVE_DIR" -type d -name "*_*" | wc -l)
    echo "📦 아카이브된 리포트: $archive_count개"
    
    echo ""
}

# 5. 브라우저에서 열기
open_reports() {
    log_info "5단계: 브라우저에서 리포트 열기..."
    
    if [[ "$OSTYPE" == "darwin"* ]]; then
        if [ -f "$REPORTS_DIR/coverage/index.html" ]; then
            open "$REPORTS_DIR/coverage/index.html" 2>/dev/null || true
        fi
        if [ -f "$REPORTS_DIR/test_results/index.html" ]; then
            open "$REPORTS_DIR/test_results/index.html" 2>/dev/null || true
        fi
        log_success "브라우저에서 리포트 열기 완료"
    else
        log_warning "macOS가 아닌 환경입니다. 브라우저 자동 열기를 건너뜁니다."
    fi
}

# 메인 실행
main() {
    echo ""
    echo "📊 =========================================="
    echo "📊   테스트 결과 관리 시스템"
    echo "📊 =========================================="
    echo ""
    
    backup_existing_reports
    generate_new_reports
    organize_reports
    check_report_status
    open_reports
    
    echo ""
    log_success "테스트 결과 관리가 완료되었습니다!"
    echo ""
    echo "📊 생성된 리포트:"
    echo "  - 커버리지: $REPORTS_DIR/coverage/index.html"
    echo "  - 테스트 결과: $REPORTS_DIR/test_results/index.html"
    echo "  - 성능 데이터: $REPORTS_DIR/performance/performance_data.txt"
    echo "  - 요약: $REPORTS_DIR/summary.md"
    echo "  - 아카이브: $ARCHIVE_DIR/"
    echo ""
}

# 스크립트 실행
main "$@" 