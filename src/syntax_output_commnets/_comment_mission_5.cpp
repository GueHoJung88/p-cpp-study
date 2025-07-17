/*
🎮 The Bunny & Cat Adventure 🐰🐱
C++ 실습 게임: 주석 + 입력 + 조건문 + 클래스 + 귀염뽀짝 아트!

🌟 미션:
1. 토끼(Ruby)와 고양이(Mocha)가 모험을 떠납니다.
2. 당신의 선택으로 스토리가 분기되고 결말이 달라집니다!
3. 각 위기 상황에서 어떤 선택을 할지 입력하세요 (1 또는 2).
4. 성공, 실패, 귀여운 결말이 달라져요!

🚨 등장 위기 상황:
- 무서운 늑대 출현 🐺
- 갑작스러운 눈보라 ❄️
- 배고픔과 추위 🥶
- 친구와의 다툼 💢

💡 cin과 if/else, 클래스, 주석 실습을 겸한 C++ 텍스트 어드벤처!
*/

#include <iostream>
using namespace std;

// 캐릭터 클래스 정의
class Character {
public:
    string name;
    string species;
    string favoriteFood;

    Character(string n, string s, string f) {
        name = n;
        species = s;
        favoriteFood = f;
    }

    void intro() {
        cout << "안녕! 나는 " << species << " " << name << "야." << endl;
        cout << "내가 가장 좋아하는 건 " << favoriteFood << "!" << endl;
    }
};

int main() {
    // 캐릭터 생성
    Character bunny("Ruby", "토끼🐰", "당근🥕");
    Character cat("Mocha", "고양이🐱", "참치🐟");

    cout << "🌄 새로운 아침이 밝았습니다. 두 친구는 모험을 떠나기로 합니다!\n\n";

    bunny.intro();
    cat.intro();

    cout << "\n🌲 숲속을 걷던 중 갑자기 늑대가 나타났습니다! 🐺" << endl;
    cout << "1. 도망친다   2. 함께 소리 지르며 늑대를 쫓아낸다" << endl;
    int choice1;
    cin >> choice1;

    if (choice1 == 1) {
        cout << "\n🏃 도망치던 중 Ruby가 넘어졌어요!" << endl;
        cout << "Mocha가 도움을 주지 않으면 위험해요..." << endl;
    } else {
        cout << "\n📢 두 친구가 힘을 합쳐 늑대를 쫓아냈어요! 용감했어요!" << endl;
    }

    cout << "\n❄️ 하지만 갑작스럽게 눈보라가 몰아칩니다!" << endl;
    cout << "1. 나무 밑에 숨는다   2. 눈보라를 뚫고 간다" << endl;
    int choice2;
    cin >> choice2;

    if (choice2 == 2) {
        cout << "\n😵 눈보라 속에서 길을 잃었어요. Ruby가 배고프고 추워합니다..." << endl;
    } else {
        cout << "\n🌳 나무 밑에서 몸을 피하며 따뜻하게 시간을 보냈어요!" << endl;
    }

    cout << "\n🍽️ Mocha가 먹을 것을 발견했지만 Ruby는 너무 배고픈 상태!" << endl;
    cout << "1. Mocha가 양보한다   2. 각자 먹는다" << endl;
    int choice3;
    cin >> choice3;

    if (choice3 == 1) {
        cout << "\n💞 Mocha의 배려로 Ruby는 회복하고 고마워했어요." << endl;
    } else {
        cout << "\n💢 Ruby가 속상해서 둘이 잠시 말다툼을 했어요..." << endl;
    }

    // 🎨 결과 출력
    cout << "\n🎬 모험의 끝! 오늘의 결말은...\n\n";

    if (choice1 == 2 && choice2 == 1 && choice3 == 1) {
        cout << "💕 두 친구는 함께 위기를 극복하고, 우정이 더 깊어졌어요!" << endl;
        cout << "\n  (\\__/)\n  (•ㅅ•)\n  / >🍰 친구랑 나눠먹기!\n";
    } else if (choice2 == 2) {
        cout << "🥶 추위 속에 헤매던 두 친구는 결국 집으로 돌아오지 못했어요... 다음에 더 잘하자!" << endl;
        cout << "\n  (；×_×)\n  (   )\n  / >💤\n";
    } else {
        cout << "🤝 몇 가지 어려움은 있었지만, 결국 함께 웃으며 돌아왔어요!" << endl;
        cout << "\n  (=^･ｪ･^=)\n  (•‿•)\n  / >🍡 모험 후 달콤한 간식!\n";
    }

    cout << "\n🎉 게임 끝! 고마워요, 모험가님!\n" << endl;

    return 0;
}
