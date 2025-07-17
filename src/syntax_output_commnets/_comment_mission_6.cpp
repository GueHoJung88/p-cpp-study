#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// 날씨 타입
string weathers[] = {"맑음", "비", "눈", "폭풍", "안개"};

// 캐릭터 클래스
class Character {
public:
    string name;
    int x, y;  // 위치 좌표

    Character(string n) {
        name = n;
        x = 0;
        y = 0;
    }

    void showPosition() {
        cout << "📍 현재 위치: (" << x << ", " << y << ")" << endl;
    }

    void move(char direction) {
        switch (direction) {
            case 'w': y++; break;
            case 's': y--; break;
            case 'a': x--; break;
            case 'd': x++; break;
            default: cout << "잘못된 입력입니다!\n"; return;
        }
        showPosition();
    }
};

// 랜덤 날씨 출력
string getRandomWeather() {
    return weathers[rand() % 5];
}

// 귀여운 토끼 출력
void printBunny() {
    cout << R"(  
     (\_/)
     (•ᴥ•)
     / >🍓
    )" << endl;
}

// 귀여운 고양이 출력
void printCat() {
    cout << R"(
     /\_/\  
    ( o.o ) 
     > ^ <
    )" << endl;
}

// 미니맵 출력
void showMiniMap(int x, int y) {
    cout << "\n🗺️ 미니맵 (당신의 위치는 *로 표시됨)\n";
    for (int j = 2; j >= -2; j--) {
        for (int i = -2; i <= 2; i++) {
            if (i == x && j == y) cout << "* ";
            else cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    
    cout << "🐰🐱 The Bunny & Cat Adventure에 오신 것을 환영합니다!\n";
    cout << "당신의 캐릭터 이름을 입력하세요: ";
    string playerName;
    getline(cin, playerName);

    Character player(playerName);
    cout << "환영합니다, " << player.name << "님!\n\n";

    string weather = getRandomWeather();
    cout << "🌤️ 오늘의 날씨는 '" << weather << "' 입니다.\n";

    cout << "\n🚶 이동: w(위) a(왼쪽) s(아래) d(오른쪽), x를 누르면 종료됩니다.\n";

    char choice;
    while (true) {
        showMiniMap(player.x, player.y);
        player.showPosition();

        // 랜덤 이벤트
        int eventChance = rand() % 100;
        if (eventChance < 15) {
            cout << "\n🌪️ 자연재해 발생! 폭풍우가 몰아쳐서 이동이 제한됩니다!\n";
            cout << "이동 불가. 다음 턴으로 넘어갑니다.\n";
        }
        else if (eventChance < 30) {
            cout << "\n🐻 무서운 곰을 마주쳤습니다! 도망치시겠습니까? (y/n): ";
            char flee;
            cin >> flee;
            if (flee == 'y') {
                cout << "성공적으로 도망쳤습니다!\n";
            } else {
                cout << "곰에게 쫓겨 1칸 뒤로 이동합니다!\n";
                player.move('s');
            }
        }
        else if (eventChance < 45) {
            cout << "\n😿 고양이 친구와 다툼이 있었습니다. 사과하시겠습니까? (y/n): ";
            char apologize;
            cin >> apologize;
            if (apologize == 'y') {
                cout << "친구가 화해했습니다! 따뜻한 포옹 🤗\n";
                printCat();
            } else {
                cout << "고양이 친구가 떠났습니다... 😢\n";
            }
        }

        // 사용자 입력
        cout << "\n이동 방향 입력: ";
        cin >> choice;
        if (choice == 'x') {
            cout << "\n게임 종료! 수고하셨습니다! 🎮\n";
            break;
        }

        player.move(choice);

        // 스토리 지점 도달 시
        if (player.x == 2 && player.y == 2) {
            cout << "\n❄️ 추운 눈 속에서 길을 잃었습니다. 캠프파이어를 피우시겠습니까? (y/n): ";
            char fire;
            cin >> fire;
            if (fire == 'y') {
                cout << "🔥 몸을 녹이며 살아남았습니다. 따뜻한 스프도 한그릇!\n";
            } else {
                cout << "🥶 너무 추워서 탈진했습니다... 게임 오버!\n";
                break;
            }
        }

        if (player.x == -2 && player.y == 1) {
            cout << "\n🍎 배가 너무 고픕니다. 사과를 드시겠습니까? (y/n): ";
            char eat;
            cin >> eat;
            if (eat == 'y') {
                cout << "🍎 배를 채우고 기운을 회복했습니다!\n";
                printBunny();
            } else {
                cout << "😵 기운이 빠져 쓰러졌습니다. 모험 실패!\n";
                break;
            }
        }
    }

    return 0;
}
