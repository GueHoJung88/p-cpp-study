// 🧮 Puppy Coding Game: Math & Boolean 실습편
// 학습 목표: 수학 연산 함수와 bool 타입, 조건 비교를 캐릭터와 함께 배워요!

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Character.h"

using namespace std;

// 🎮 캐릭터가 설명을 이끌어주는 구조체
void waitForEnter() {
    cout << "\n👉 계속하려면 Enter 키를 누르세요...";
    cin.ignore();
}

void printMathSection(Character& guide) {
    cout << "\n=== 🧠 수학 함수 배우기 ===\n";
    guide.display("thinking");

    cout << "C++에서는 <cmath> 라이브러리를 통해 다양한 수학 함수를 사용할 수 있어요!\n";
    waitForEnter();

    cout << "\n예를 들어, 제곱근을 구하고 싶다면 sqrt():\n";
    cout << " - sqrt(64) = " << sqrt(64) << endl;

    cout << "\n숫자를 반올림하려면 round():\n";
    cout << " - round(2.6) = " << round(2.6) << endl;

    cout << "\n로그 값을 구하려면 log():\n";
    cout << " - log(2) = " << log(2) << endl;

    waitForEnter();

    cout << "\n또한, 두 값 중 큰 값을 구하려면 max():\n";
    cout << " - max(10, 25) = " << max(10, 25) << endl;

    cout << "작은 값을 구하려면 min():\n";
    cout << " - min(10, 25) = " << min(10, 25) << endl;

    guide.display("happy");
}

void quizMath(Character& guide) {
    cout << "\n🐰 퀴즈: 다음 중 정답은 무엇일까요?" << endl;
    cout << "sqrt(81)의 결과는?\n";
    cout << "1. 8\n2. 9\n3. 10\n4. 6\n";

    int answer;
    cin >> answer;
    if (answer == 2) {
        guide.display("happy");
        cout << "정답이에요! sqrt(81)은 9죠!\n";
    } else {
        guide.display("sad");
        cout << "앗! 틀렸어요. 정답은 2번, 9입니다.\n";
    }
    cin.ignore();
}

void printBooleanSection(Character& guide) {
    cout << "\n=== 🧠 불리언(bool)과 조건 비교 ===\n";
    guide.display("thinking");

    cout << "C++에서는 true(참) 또는 false(거짓)를 저장하는 bool 타입을 사용해요!\n";
    cout << "\n예:\n";
    cout << "bool isSunny = true;\n";
    cout << "bool isRainy = false;\n";
    cout << "cout << isSunny; // 1 출력\n";
    cout << "cout << isRainy; // 0 출력\n";

    waitForEnter();

    cout << "\n👉 비교 연산을 통해 조건 판단도 가능해요!\n";
    cout << "int x = 7, y = 3;\n";
    cout << "cout << (x > y); // 1 출력됨 (참이므로)\n";
    cout << "cout << (x == 10); // 0 출력됨 (거짓이므로)\n";

    guide.display("surprised");
    waitForEnter();

    cout << "\n📦 현실 예시: 투표 가능 나이 판별하기\n";
    cout << "int age = 20;\nint votingAge = 18;\nif (age >= votingAge) {\n   cout << \"투표 가능!\";\n} else {\n   cout << \"아직 어려요.\";\n}\n";
    cout << "// 결과: 투표 가능!\n";

    guide.display("happy");
}

void quizBoolean(Character& guide) {
    cout << "\n🐰 퀴즈: 다음 중 결과가 false인 것은?\n";
    cout << "1. (10 > 3)\n2. (5 == 5)\n3. (2 >= 4)\n4. (7 != 3)\n";

    int answer;
    cin >> answer;
    if (answer == 3) {
        guide.display("happy");
        cout << "정답이에요! 2는 4보다 크거나 같지 않으니까 false입니다.\n";
    } else {
        guide.display("sad");
        cout << "앗! 다시 확인해보세요. 정답은 3번입니다.\n";
    }
    cin.ignore();
}

int main() {
    srand(time(0));
    vector<Character> characters = initializeCharacters();
    Character guide = characters[rand() % characters.size()];

    cout << "🐾 오늘의 강아지 선생님: " << guide.name << " (" << guide.species << ")\n";
    guide.display("happy");

    cout << "\n🐶 반가워요! 오늘은 수학 함수와 불리언 비교를 함께 배워볼 거예요!\n";
    waitForEnter();

    printMathSection(guide);
    quizMath(guide);

    printBooleanSection(guide);
    quizBoolean(guide);

    cout << "\n🎉 실습 완료! 정말 잘했어요! 다음 시간엔 조건문(if/else)을 더 깊이 배워볼 거예요!\n";
    guide.display("happy");

    return 0;
}
