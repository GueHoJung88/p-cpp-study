# 📊 테스트 결과 시각화 가이드

## 🎯 개요

이 문서는 프로젝트의 테스트 결과를 시각화하고 리포트를 생성하는 방법을 설명합니다.

## 📁 디렉토리 구조

```
docs/
├── reports/           # 생성된 리포트 파일들
│   ├── coverage/      # 코드 커버리지 리포트
│   ├── test_results/  # 테스트 결과 HTML
│   └── performance/   # 성능 데이터
└── visualization_guide.md  # 이 문서
```

## 🛠️ 설치 및 설정

### 1. 필수 도구 설치

#### macOS (Homebrew 사용)
```bash
# 코드 커버리지 도구
brew install lcov

# Python3 (이미 설치되어 있을 수 있음)
brew install python3

# 성능 분석 도구 (선택사항)
brew install valgrind
```

#### Ubuntu/Debian
```bash
# 코드 커버리지 도구
sudo apt-get install lcov

# Python3
sudo apt-get install python3

# 성능 분석 도구 (선택사항)
sudo apt-get install valgrind
```

### 2. 스크립트 권한 설정
```bash
chmod +x scripts/generate_reports.sh
chmod +x scripts/xml_to_html.py
```

## 🚀 사용 방법

### 1. 자동화된 리포트 생성

```bash
# 프로젝트 루트에서 실행
./scripts/generate_reports.sh
```

이 명령어는 다음을 자동으로 수행합니다:
- 테스트 실행 및 XML 결과 생성
- 코드 커버리지 분석
- 성능 데이터 수집
- HTML 리포트 생성
- 브라우저에서 리포트 열기

### 2. 수동으로 단계별 실행

#### A. 테스트 실행 및 XML 생성
```bash
cd build
./cpp_learning_tests --gtest_output=xml:test_results.xml
```

#### B. 커버리지 리포트 생성
```bash
# 커버리지 데이터 수집
lcov --capture --directory . --output-file coverage.info

# HTML 리포트 생성
genhtml coverage.info --output-directory ../docs/reports/coverage
```

#### C. 테스트 결과 HTML 변환
```bash
python3 ../scripts/xml_to_html.py test_results.xml ../docs/reports/test_results
```

## 📊 생성되는 리포트 종류

### 1. 코드 커버리지 리포트
- **위치**: `docs/reports/coverage/index.html`
- **내용**: 
  - 각 파일별 코드 커버리지 비율
  - 테스트되지 않은 코드 라인 하이라이트
  - 브랜치 커버리지 정보

### 2. 테스트 결과 리포트
- **위치**: `docs/reports/test_results/index.html`
- **내용**:
  - 테스트 스위트별 통과/실패 통계
  - 개별 테스트 케이스 결과
  - 실패한 테스트의 상세 오류 메시지
  - 테스트 실행 시간

### 3. 성능 데이터
- **위치**: `docs/reports/performance/performance_data.txt`
- **내용**: 테스트 실행 시간 및 메모리 사용량

### 4. 요약 리포트
- **위치**: `docs/reports/summary.md`
- **내용**: 모든 리포트의 요약 및 링크

## 🔧 커스터마이징

### 1. HTML 템플릿 수정
`scripts/xml_to_html.py` 파일의 `generate_html()` 함수에서 HTML 템플릿을 수정할 수 있습니다.

### 2. 추가 메트릭 수집
`scripts/generate_reports.sh`에 다음을 추가할 수 있습니다:
- 메모리 사용량 분석
- 정적 코드 분석 결과
- 복잡도 메트릭

### 3. CI/CD 통합
GitHub Actions나 GitLab CI에서 이 스크립트를 사용하여 자동 리포트 생성을 설정할 수 있습니다.

## 📈 리포트 해석 방법

### 커버리지 리포트
- **80% 이상**: 좋은 커버리지
- **60-80%**: 개선 필요
- **60% 미만**: 테스트 케이스 추가 필요

### 테스트 결과
- **모든 테스트 통과**: 안정적인 코드
- **일부 실패**: 버그 수정 또는 테스트 코드 개선 필요
- **실패율 높음**: 리팩토링 또는 아키텍처 개선 필요

## 🐛 문제 해결

### 1. lcov 설치 오류
```bash
# macOS에서 lcov 설치 문제 시
brew install lcov --HEAD
```

### 2. Python 스크립트 실행 오류
```bash
# 실행 권한 확인
chmod +x scripts/xml_to_html.py

# Python 경로 확인
which python3
```

### 3. 리포트가 생성되지 않는 경우
```bash
# 빌드 디렉토리 확인
ls -la build/

# 테스트 실행 확인
cd build && ./cpp_learning_tests
```

## 📅 정기적인 리포트 생성

### 1. 수동 실행
```bash
# 매일 또는 주요 변경 후
./scripts/generate_reports.sh
```

### 2. 자동화 (cron 사용)
```bash
# crontab 편집
crontab -e

# 매일 오전 9시에 실행
0 9 * * * cd /path/to/project && ./scripts/generate_reports.sh
```

## 🔗 관련 문서

- [개발 환경 구축 가이드](./development_environment_guide.md)
- [TDD 테스트 가이드](./character_tdd_testing_guide.md)
- [리팩토링 체크리스트](./refactoring_todo.md) 