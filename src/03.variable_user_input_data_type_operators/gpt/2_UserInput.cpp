// 🐶 Puppy Coding Game: 02. 사용자 입력(User Input) 실습
// 학습 내용: cin을 이용한 입력 받기, 기본 연산자 활용, 변수 선언 복습

#include <iostream>
#include <string>
using namespace std;

// 🐕 ASCII 캐릭터 아트 정의
void print_chihuahua_happy() {
    cout << " (\\_/)\n";
    cout << " (•ᴥ•)\n";
    cout << " / >🍖  \"히히! 간식이다!\"\n\n";
}

void print_shiba_happy() {
    cout << " ／＞　 フ\n";
    cout << " | 　_　_|  \"공부하러 왔개!\"\n";
    cout << "／` ミ＿xノ\n";
    cout << "|　　  | \n";
    cout << "＼　　  \\＿_／\n\n";
}

void print_rabbit_quiz() {
    cout << " (\\(\\ \n";
    cout << " ( •‿•)   \"숫자를 두 개 입력해서 계산해보자!\"\n";
    cout << " o( o )o\n\n";
}

void print_cat_judge(bool correct) {
    if (correct) {
        cout << " /\\_/\\ \n";
        cout << " (≧▽≦)  \"잘했어! 고양이도 감탄했어!\"\n\n";
    } else {
        cout << " /\\_/\\ \n";
        cout << " (•_•)  \"흠... 다시 도전해볼까냥?\"\n\n";
    }
}

void print_dog_react(bool correct, int result) {
    if (correct) {
        cout << " 🐶  \"정답은 " << result << "이야! 똑똑하구나!\"\n\n";
        print_chihuahua_happy();
    } else {
        cout << " 🐶  \"아쉽다! 다시 도전해봐!\"\n\n";
    }
}

// 🧠 사용자 입력 퀴즈
void quiz_user_input() {
    print_rabbit_quiz();

    int x, y;
    cout << "첫 번째 숫자를 입력하세요: ";
    cin >> x;
    cout << "두 번째 숫자를 입력하세요: ";
    cin >> y;

    int sum = x + y;
    int user_answer;
    cout << "\n🧮 " << x << " + " << y << " = ? 정답은?: ";
    cin >> user_answer;
    cout << endl;

    bool correct = (user_answer == sum);
    print_cat_judge(correct);
    print_dog_react(correct, sum);

    cout << "\n📝 해설:\n";
    cout << "- cin은 키보드 입력을 변수에 저장할 때 사용합니다.\n";
    cout << "- cout은 결과나 안내 문장을 출력할 때 사용합니다.\n";
    cout << "- 입력된 두 숫자를 더해 계산한 결과와 비교해봅니다.\n";
    cout << "- 연산자 '+'는 덧셈 연산을 수행합니다.\n";

    cout << "\n💡 요약 정리:\n";
    cout << "- 입력: cin >> 변수명;\n";
    cout << "- 출력: cout << 변수명 또는 문자열;\n";
    cout << "- 계산 예: int sum = x + y;\n";
    cout << "- 변수는 선언 후 사용하며 타입에 맞게 초기화하세요.\n";
}

// 🐾 강아지 선택 함수
void select_main_character() {
    cout << "🐶 주인공 강아지를 선택하세요:\n";
    cout << "1. 초코 치와와\n";
    cout << "2. 씩씩한 시바견\n";
    cout << "번호 입력 (1~2): ";
    int choice;
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            cout << "🐾 초코 치와와 등장!\n";
            print_chihuahua_happy();
            break;
        case 2:
            cout << "🐾 씩씩한 시바견 등장!\n";
            print_shiba_happy();
            break;
        default:
            cout << "🐾 잘못된 선택입니다. 기본 캐릭터로 시작합니다!\n";
            print_chihuahua_happy();
            break;
    }
}

// 🎮 메인 실행 함수
int main() {
    cout << "🐾🐶 강아지와 함께하는 C++ 사용자 입력 실습! 🐶🐾\n\n";

    select_main_character();

    quiz_user_input();

    cout << "\n🎉 실습 종료! 다음 퀴즈에서 또 만나요!\n";
    return 0;
}
