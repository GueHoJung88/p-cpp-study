// 🐶 Puppy Coding Game: 03. 데이터형(Data Types) 실습
#include <iostream>
#include <string>
using namespace std;

// 🎨 캐릭터 함수 정의
void print_cat_quiz_intro() {
    cout << " /\\_/\\  \n";
    cout << "(・ω・)  고양이: \"데이터형 퀴즈를 시작할게!\"\n\n";
}

void print_dog_correct() {
    cout << "🐶 \"역시 나야! 냄새 맡고 맞혔지롱~\"\n";
    cout << "     (❁´◡`❁)\n\n";
}

void print_dog_wrong() {
    cout << "🐶 \"에잇 틀렸개... 다음엔 꼭 맞출게!\"\n";
    cout << "     (ง •̀_•́)ง\n\n";
}

void print_rabbit_comment() {
    cout << " (\\(\\ \n";
    cout << " (•‿•)  토끼: \"데이터형은 아주 중요하지!\"\n\n";
}

void print_data_types_summary() {
    cout << "\n📚 데이터형 요약:\n";
    cout << "- int: 정수형, 예: 10, -3\n";
    cout << "- float: 실수형, 예: 3.14\n";
    cout << "- char: 문자형, 예: 'A'\n";
    cout << "- string: 문자열형, 예: \"hello\"\n";
    cout << "- bool: 논리형, true 또는 false\n";
}

// 🧠 퀴즈 로직
void start_data_type_quiz() {
    print_cat_quiz_intro();

    // 문제 1: 정수와 실수 계산
    int a = 10;
    float b = 3.5;
    float sum = a + b;

    float user_answer;
    cout << "Q1) 정수 10 + 실수 3.5의 결과는? (소수 포함): ";
    cin >> user_answer;

    if (abs(user_answer - sum) < 0.01) {
        print_dog_correct();
    } else {
        print_dog_wrong();
        cout << "🐾 정답은: " << sum << " 이었어요!\n";
    }

    // 문제 2: 문자형 입력
    char user_char;
    cout << "\nQ2) 영문 대문자 A를 입력해보세요: ";
    cin >> user_char;

    if (user_char == 'A') {
        print_dog_correct();
    } else {
        print_dog_wrong();
        cout << "🐾 A는 대문자입니다! 소문자가 아니에요~\n";
    }

    // 문제 3: 문자열 확인
    string user_string;
    cout << "\nQ3) 강아지를 영어로 입력해보세요 (힌트: dog): ";
    cin >> user_string;

    if (user_string == "dog") {
        print_dog_correct();
    } else {
        print_dog_wrong();
        cout << "🐾 'dog'를 영어로 정확히 입력해야 해요!\n";
    }

    // 마무리
    print_rabbit_comment();
    print_data_types_summary();
}

// 🐕 강아지 선택
void select_main_dog() {
    cout << "🐶 주인공 강아지를 골라주세요!\n";
    cout << "1. 초코 치와와\n";
    cout << "2. 씩씩한 시바견\n";
    cout << "선택 (1~2): ";
    int choice;
    cin >> choice;

    cout << "\n";
    switch (choice) {
        case 1:
            cout << "🐾 초코 치와와 등장!\n";
            break;
        case 2:
            cout << "🐾 씩씩한 시바견 등장!\n";
            break;
        default:
            cout << "🐾 기본 강아지로 시작할게요!\n";
            break;
    }
}

// 🎮 메인 실행
int main() {
    cout << "🐾🐶 강아지와 함께하는 C++ 데이터형 실습! 🐶🐾\n\n";

    select_main_dog();
    start_data_type_quiz();

    cout << "\n🎉 잘했어요! 다음 단계로 넘어가볼까요?\n";
    return 0;
}
