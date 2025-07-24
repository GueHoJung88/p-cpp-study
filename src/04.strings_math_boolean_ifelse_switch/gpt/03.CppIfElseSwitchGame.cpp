// 🧠 Puppy Coding Game: If/Else & Switch 실습편
// 학습 목표: 조건문 if, else if, else, switch를 귀여운 캐릭터와 함께 배워요!

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Character.h"

using namespace std;

void waitEnter() {
    cout << "\n👉 Enter 키를 누르면 계속됩니다...";
    cin.ignore();
}

void learnIfElse(Character& dog) {
    cout << "\n=== 🧠 조건문: if / else / else if 배우기 ===\n";
    dog.display("thinking");

    cout << "C++에서는 조건에 따라 코드를 다르게 실행할 수 있어요.\n";
    cout << "조건 연산자: <, <=, >, >=, ==, != 등을 활용하죠.\n";
    waitEnter();

    int age = 17;
    cout << "예제: 투표 가능 여부 판단\n";
    cout << "int age = 17;\n";
    cout << "if (age >= 18) { cout << '투표 가능!'; } else { cout << '아직 어려요'; }\n";
    if (age >= 18) {
        cout << "[실행 결과] 투표 가능!\n";
    } else {
        cout << "[실행 결과] 아직 어려요\n";
    }

    waitEnter();

    int num = 0;
    cout << "예제: 숫자의 부호 확인\n";
    cout << "int num = 0;\n";
    if (num > 0) cout << "양수입니다\n";
    else if (num < 0) cout << "음수입니다\n";
    else cout << "0입니다\n";

    dog.display("happy");
    waitEnter();

    cout << "🎯 3항 연산자 (Short Hand If-Else) 도 있어요!\n";
    cout << "string msg = (age >= 18) ? '투표 가능' : '아직 어려요';\n";
    string msg = (age >= 18) ? "투표 가능" : "아직 어려요";
    cout << "[3항 결과] " << msg << endl;
    dog.display("thinking");
}

void quizIfElse(Character& dog) {
    cout << "\n🐰 퀴즈: 다음 중 결과가 '음수입니다'가 되는 경우는?\n";
    cout << "1. int x = 5;\n";
    cout << "2. int x = 0;\n";
    cout << "3. int x = -3;\n";
    cout << "4. int x = 100;\n";
    cout << "정답 입력: ";
    int ans;
    cin >> ans;
    if (ans == 3) {
        dog.display("happy");
        cout << "정답이에요! -3은 음수입니다.\n";
    } else {
        dog.display("sad");
        cout << "아쉽네요. 정답은 3번이에요.\n";
    }
    cin.ignore();
}

void learnSwitch(Character& dog) {
    cout << "\n=== 🧠 switch 문 배우기 ===\n";
    dog.display("thinking");

    cout << "switch문은 여러 조건을 처리할 때 사용해요.\n";
    cout << "예: 요일 번호에 따라 요일 이름 출력\n";

    int day = 4;
    cout << "int day = 4;\n";
    cout << "switch(day) {...}\n";

    cout << "[실행 결과] ";
    switch(day) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
        case 7: cout << "Sunday"; break;
        default: cout << "Invalid day";
    }
    cout << endl;

    waitEnter();

    int drinkCode = 3;
    cout << "예제: 음료 자판기\n";
    cout << "int drinkCode = 3;\n";
    cout << "switch(drinkCode) {...}\n";

    cout << "[실행 결과] ";
    switch(drinkCode) {
        case 1: cout << "콜라"; break;
        case 2: cout << "사이다"; break;
        case 3: cout << "오렌지 주스"; break;
        default: cout << "선택 없음";
    }
    cout << endl;
    dog.display("happy");
}

void quizSwitch(Character& dog) {
    cout << "\n🐰 퀴즈: switch 문에서 일치하는 case가 없을 때 실행되는 키워드는?\n";
    cout << "1. skip\n2. default\n3. break\n4. else\n정답 입력: ";
    int ans;
    cin >> ans;
    if (ans == 2) {
        dog.display("happy");
        cout << "정답! default는 일치하는 case가 없을 때 실행됩니다!\n";
    } else {
        dog.display("sad");
        cout << "틀렸어요! 정답은 2번 default입니다.\n";
    }
    cin.ignore();
}

int main() {
    srand(time(0));
    vector<Character> characters = initializeCharacters();
    Character dog = characters[rand() % characters.size()];

    cout << "🐾 조건 탐험에 함께할 캐릭터: " << dog.name << " (" << dog.species << ")\n";
    dog.display("happy");

    learnIfElse(dog);
    quizIfElse(dog);

    learnSwitch(dog);
    quizSwitch(dog);

    cout << "\n🎉 잘했어요! 이제 조건문 if/else/switch를 쓸 수 있어요! 다음은 반복문을 배워볼까요?\n";
    dog.display("surprised");

    return 0;
}
