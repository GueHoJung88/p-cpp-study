/*
🎮 C++ 주석 실습 게임: 주석으로 퍼즐을 완성하라!

💡 미션 1: "토끼 그림"에 숨겨진 주석을 해석하고,
빈 칸을 주석으로 완성해 귀여운 토끼를 만들어보세요.

💡 미션 2: 주석으로 가려진 "미로 탈출 경로"를 찾아보세요.
탈출 가능한 경로에만 주석을 제거해보세요!

🧠 주석 규칙:

한 줄 주석: // 로 시작하며 해당 줄만 주석 처리

여러 줄 주석: \/* ... / 로 묶어서 처리

📘 팁: 코드는 컴파일되고 실행되지만, 주석은 무시됩니다.
주석은 협업, 설명, 테스트용 코드 비활성화에 매우 유용합니다.

📚 참고: 긴 설명은 \/* *\/, 짧은 코멘트는 // 를 권장합니다.
*/

#include <iostream>
using namespace std;

int main() {
    cout << "🐰 미션 1: 주석으로 귀여운 토끼를 완성하세요!\n\n";

    // (1) 아래 각 줄에 필요한 부분을 주석을 참고하여 채워보세요.

    cout << " (";
    cout << "\\_/";     // 토끼의 귀는 백슬래시와 언더바를 사용합니다.
    cout << ") " << endl;

    cout << " ( ";
    cout << "•_•";      // 눈은 점 대신 동그라미나 * 로 대체해도 좋습니다.
    cout << " )" << endl;

    cout << " / >";
    cout << "🥕";        // 당근 이모지! 변경해도 좋습니다.
    cout << " " << endl;

    cout << "\n🎯 미션: 출력 결과가 귀여운 토끼처럼 보이게 주석과 코드를 조정해보세요!\n\n";

    // =========================================================
    cout << "\n\n🌀 미션 2: 주석을 해제하여 미로에서 탈출하세요!\n\n";

    cout << "Start ->" << endl;

    // cout << "X 왼쪽으로 갔더니 벽이다!" << endl;

    cout << " ↓" << endl;
    cout << " ↓" << endl;

    // cout << "X 아래로 더 가면 함정이다!" << endl;

    cout << " → 오른쪽으로!" << endl;
    cout << " → 탈출 성공!" << endl;

    // 🎯 힌트: 주석 처리된 라인 중 함정이 있으니 신중하게 선택하세요!

    // =========================================================
    cout << "\n\n📖 주석 규칙 & 팁\n" << endl;

    // ✅ 일반적인 C++ 주석 스타일
    // 상황	                추천 주석 방식
    // 한 줄 설명	        // 한 줄 주석
    // 긴 설명 또는 블록	/* ... */
    // 함수/클래스 문서화	/// or /** ... */ (도큐 주석)
    // 디버깅/임시 비활성화	// 코드 일시 주석 처리

    // ✅ 실무에서 유용한 주석 팁

    // "왜"를 설명하라
    // 사용자 입력을 받아오는 함수 호출
    // getUserInput();

    // 변경 이유를 기록
    // 버그 #1021 해결: 음수일 때도 작동하게 수정

    // TODO 또는 FIXME 마크 활용
    // TODO: 예외 처리 추가
    // FIXME: null 포인터 접근 시 크래시 발생

    // ❌ 중첩된 // 또는 /* 중복은 피하기
    // C++은 중첩 블록 주석을 허용하지 않음 → 반드시 닫히는 */ 주의!

    return 0;
}
