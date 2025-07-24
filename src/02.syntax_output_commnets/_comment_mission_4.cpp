/*
🎮 C++ 주석 실습 게임 – The Bunny & Cat Adventure 🐰🐱 [확장판]

💡 주석 실습 + 텍스트 RPG + 선택형 분기 모험!

📚 사용법:
- // 한 줄 주석: 해당 줄만 비활성화
- \/* ... *\/ 여러 줄 주석: 묶은 부분 전체 비활성화
- 주석을 해제/추가하면서 스토리를 바꾸고 퍼즐을 푸세요.

🎮 목표:
- 친구와 함께 위기를 극복하고 전설의 당근과 참치를 찾으세요!
- 주어진 선택마다 결과가 다릅니다. 모험을 완성해보세요!

🧠 시스템:
- 행동 포인트 (actionPoints), 친구 관계 (friendshipLevel), 위험도 (dangerLevel) 사용
- 중대한 선택마다 지표가 바뀌고, 주석 해제 여부에 따라 스토리가 분기됨
*/

#include <iostream>
using namespace std;

int main() {
    int actionPoints = 10;
    int friendshipLevel = 5;
    int dangerLevel = 0;

    cout << "🌄 [Chapter 1: 아침 숲속의 만남]\n\n";

    cout << "🐰 토끼 등장!\n";
    cout << "  (\\_/)\n";
    cout << "  (•_•)\n";
    cout << "  / >🥕 \n\n";

    // cout << "🐱 고양이 등장!\n";
    // cout << " /\\_/\\ \n";
    // cout << "( o.o )\n";
    // cout << " > ^ < \n\n";

    cout << "🐰: 오늘은 전설의 당근을 찾으러 떠날 거야!\n";
    cout << "🐱: 나도 전설의 참치를 찾아 동참할게!" << endl;

    cout << "\n🚪 [Chapter 2: 미로의 입구]\n";

    // 선택 분기: 올바른 방향은 오른쪽 + 아래
    cout << "Start ->" << endl;
    // cout << "↓ 낭떠러지! 행동 포인트 -2\n";
    cout << "→ 오른쪽으로 이동!" << endl;
    cout << "↓ 아래로 이동!" << endl;

    actionPoints -= 2;

    cout << "\n🌪️ [Chapter 3: 갑작스러운 폭풍우!]\n";

    cout << "🌧️ 비바람이 몰아칩니다! 아래 중 하나를 선택하세요.\n";
    cout << "1. 🌳 나무 밑으로 대피\n";
    cout << "2. 🪨 바위 뒤로 숨기\n";

    // 아래 중 하나만 주석 해제
    // cout << "⚡ 나무에 벼락이 떨어졌다! 위험도 +5\n";
    // dangerLevel += 5;

    cout << "🪨 바위 뒤로 숨었다. 안전했지만 젖었다. 행동 포인트 -1\n";
    actionPoints--;

    cout << "\n🐻 [Chapter 4: 무서운 야생 동물 출현!]\n";

    cout << "곰이 나타났다! 도망칠까, 도와줄까?\n";
    cout << "1. 도망치기 (🐰만 도망, friendship -2)\n";
    cout << "2. 함께 도망가기 (위험도 +2, 행동포인트 -2)\n";

    // cout << "🐰만 도망쳤다. 고양이는 토라졌다. friendship -2\n";
    // friendshipLevel -= 2;

    cout << "같이 도망쳤다! 우애가 깊어졌다. 위험도 +2, friendship +1\n";
    dangerLevel += 2;
    friendshipLevel += 1;
    actionPoints -= 2;

    cout << "\n🔥 [Chapter 5: 친구와 다툼 발생]\n";

    cout << "🐱: 왜 네 맘대로 길을 골라? 나도 의견이 있어!\n";

    cout << "선택하세요:\n";
    cout << "1. 무시하고 계속 간다 (우정 -3)\n";
    cout << "2. 사과하고 같이 길을 찾는다 (우정 +2, 행동 -1)\n";

    // cout << "무시했다. 분위기 싸하다... friendship -3\n";
    // friendshipLevel -= 3;

    cout << "사과했다. 고양이도 웃었다. friendship +2\n";
    friendshipLevel += 2;
    actionPoints -= 1;

    cout << "\n❄️ [Chapter 6: 혹한의 밤, 배고픔과 추위]\n";

    cout << "🔥 불을 피우려면 나뭇가지를 모아야 합니다. 행동포인트가 필요합니다.\n";

    if (actionPoints >= 2) {
        cout << "불을 피워 따뜻한 밤을 보냈습니다! 행동 포인트 -2\n";
        actionPoints -= 2;
    } else {
        cout << "너무 추웠다... 위험도 +5\n";
        dangerLevel += 5;
    }

    cout << "\n🏆 [Chapter 7: 전설의 보물]\n";

    if (friendshipLevel >= 6 && dangerLevel < 10) {
        cout << "🎉 두 친구는 협력하여 전설의 당근과 참치를 찾았습니다!\n";
        cout << "🐰: 이건 정말 최고의 모험이야!\n";
        cout << "🐱: 이 참치는 너와 함께라서 더 맛있어~\n";
    } else if (dangerLevel >= 10) {
        cout << "⚠️ 위험이 너무 커서 두 친구는 중간에 모험을 포기했습니다...\n";
    } else {
        cout << "😢 친구와 사이가 멀어져 결국 혼자 돌아갔습니다.\n";
    }

    cout << "\n📊 [엔딩 통계]\n";
    cout << "행동 포인트: " << actionPoints << endl;
    cout << "우정 지수: " << friendshipLevel << endl;
    cout << "위험도: " << dangerLevel << endl;

    cout << "\n🎊 THE END - C++ 주석 실습 게임 종료!\n";
    return 0;
}
