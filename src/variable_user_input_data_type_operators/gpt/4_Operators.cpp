// 🐶 Puppy Coding Game: 04. 연산자(Operators) 실습
// 학습 내용: 산술, 비교, 논리 연산자

#include <iostream>
#include <string>
using namespace std;

// 🐕 ASCII 캐릭터 아트 정의
void print_chihuahua_excited() {
    cout << " (\\_/)\n";
    cout << " (•ᴥ•)\n";
    cout << " / >🧮  \"연산자 공부! 재밌다!\"\n\n";
}

void print_rabbit_quiz() {
    cout << " (\\(\\ \n";
    cout << " ( •‿•)   \"이 연산자의 결과는 무엇일까요?\"\n";
    cout << " o( o )o\n\n";
}

void print_cat_judge(bool correct) {
    if (correct) {
        cout << " /\\_/\\ \n";
        cout << " (≧▽≦)  \"정답이냥~ 완벽해!\"\n\n";
    } else {
        cout << " /\\_/\\ \n";
        cout << " (ಠ_ಠ)  \"틀렸어냥... 다시 도전하자.\"\n\n";
    }
}

void print_chihuahua_react(bool correct) {
    if (correct) {
        print_chihuahua_excited();
    } else {
        cout << " (；ᴥ；)\n";
        cout << " / >💧  \"좀 더 연습해야겠어요...!\"\n\n";
    }
}

// 🧠 연산자 퀴즈 출력
void quiz_operators() {
    print_rabbit_quiz();

    cout << "문제 1: int x = 10; int y = 3; x % y 는?\n";
    cout << "1. 1\n";
    cout << "2. 2\n";
    cout << "3. 3\n";
    cout << "4. 0\n";
    cout << "번호 입력: ";
    int answer1;
    cin >> answer1;
    cout << endl;
    bool correct1 = (answer1 == 1);
    print_cat_judge(correct1);
    print_chihuahua_react(correct1);

    cout << "문제 2: int a = 5; int b = 10; (a < b) && (b < 20) 는?\n";
    cout << "1. true (1)\n";
    cout << "2. false (0)\n";
    cout << "번호 입력: ";
    int answer2;
    cin >> answer2;
    cout << endl;
    bool correct2 = (answer2 == 1);
    print_cat_judge(correct2);
    print_chihuahua_react(correct2);

    cout << "문제 3: int c = 8; c += 2; c 는?\n";
    cout << "1. 10\n";
    cout << "2. 8\n";
    cout << "3. 2\n";
    cout << "4. 12\n";
    cout << "번호 입력: ";
    int answer3;
    cin >> answer3;
    cout << endl;
    bool correct3 = (answer3 == 1);
    print_cat_judge(correct3);
    print_chihuahua_react(correct3);

    cout << "\n📝 해설:\n";
    cout << "- % 연산자는 나머지를 구합니다. 10 % 3 = 1\n";
    cout << "- && 는 두 조건이 모두 참일 때 참입니다.\n";
    cout << "- += 연산자는 누적 더하기입니다. c += 2 는 c = c + 2 와 같음\n";

    cout << "\n💡 연산자 요약:\n";
    cout << "- 산술: + - * / % ++ --\n";
    cout << "- 할당: = += -= *= /= %=\n";
    cout << "- 비교: == != > < >= <=\n";
    cout << "- 논리: && || !\n";
}

int main() {
    cout << "🐾🐶 강아지와 함께하는 C++ 연산자 퀴즈! 🐶🐾\n\n";
    cout << "주인공 강아지를 선택하세요 (1. 초코 치와와): ";
    int choice;
    cin >> choice;
    cout << endl;

    cout << "🐾 강아지 등장!\n";
    print_chihuahua_excited();

    quiz_operators();

    cout << "\n🎉 실습 종료! 다음 단계도 기대해주세요!\n";
    return 0;
}
