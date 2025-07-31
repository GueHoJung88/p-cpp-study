#!/bin/bash

# 날짜 검증 및 자동 수정 스크립트
# 사용법: ./date_validation.sh [파일명]

set -e

# 현재 날짜 확인
CURRENT_DATE=$(date +%Y-%m-%d)
CURRENT_YEAR=$(date +%Y)
CURRENT_MONTH=$(date +%m)
CURRENT_DAY=$(date +%d)

echo "=== 날짜 검증 시스템 ==="
echo "현재 날짜: $CURRENT_DATE"
echo "현재 시간: $(date +%H:%M:%S)"
echo ""

# 파일명에 날짜가 포함된 경우 검증
if [ $# -eq 1 ]; then
    FILENAME="$1"
    
    # 파일명에서 날짜 추출 (YYYYMMDD 형식)
    if [[ $FILENAME =~ ([0-9]{8}) ]]; then
        FILE_DATE="${BASH_REMATCH[1]}"
        FILE_YEAR="${FILE_DATE:0:4}"
        FILE_MONTH="${FILE_DATE:4:2}"
        FILE_DAY="${FILE_DATE:6:2}"
        
        echo "파일명에서 추출된 날짜: $FILE_YEAR-$FILE_MONTH-$FILE_DAY"
        
        # 날짜 비교
        if [ "$FILE_YEAR" != "$CURRENT_YEAR" ] || [ "$FILE_MONTH" != "$CURRENT_MONTH" ] || [ "$FILE_DAY" != "$CURRENT_DAY" ]; then
            echo "⚠️  경고: 파일명의 날짜가 현재 날짜와 다릅니다!"
            echo "   파일명 날짜: $FILE_YEAR-$FILE_MONTH-$FILE_DAY"
            echo "   현재 날짜: $CURRENT_DATE"
            echo ""
            echo "올바른 파일명으로 변경하시겠습니까? (y/n)"
            read -r response
            if [[ "$response" =~ ^[Yy]$ ]]; then
                NEW_FILENAME=$(echo "$FILENAME" | sed "s/$FILE_DATE/$(date +%Y%m%d)/g")
                echo "새 파일명: $NEW_FILENAME"
                echo "파일명을 변경하려면 다음 명령어를 실행하세요:"
                echo "mv \"$FILENAME\" \"$NEW_FILENAME\""
            fi
        else
            echo "✅ 파일명의 날짜가 정확합니다."
        fi
    fi
fi

# 프로젝트 내 날짜 관련 파일 검사
echo ""
echo "=== 프로젝트 내 날짜 관련 파일 검사 ==="

# history 폴더의 파일들 검사
if [ -d "history" ]; then
    echo "history 폴더 검사 중..."
    for file in history/*.md; do
        if [ -f "$file" ]; then
            # 파일 내용에서 날짜 패턴 검사
            if grep -q "2025-01-29\|20250129" "$file"; then
                echo "⚠️  발견: $file 에 잘못된 날짜가 포함되어 있습니다."
                echo "   수정이 필요합니다."
            fi
        fi
    done
fi

echo ""
echo "=== 날짜 검증 완료 ===" 