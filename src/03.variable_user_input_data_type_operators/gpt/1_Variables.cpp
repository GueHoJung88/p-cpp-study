// 🐶 Puppy Coding Game: 01. 변수(Variables) 실습
// 학습 내용: 변수의 선언, 초기화, 변수명 규칙, 타입 구분

#include <iostream>
#include <string>
using namespace std;

// 🐶 ASCII 강아지 캐릭터 아트들
void print_chihuahua_happy() {
    cout << " (\\_/)\n";
    cout << " (•ᴥ•)\n";
    cout << " / >🍖  \"히히! 간식이다!\"\n\n";
}

void print_shiba_happy() {
    cout << " (•̀ᴥ•́)\n";
    cout << " / >🍠  \"고구마 좋아! 와아~\"\n\n";
}

void print_golden_happy() {
    cout << " U・ᴥ・U\n";
    cout << " / >🦴  \"주인님 짱이에요!\"\n\n";
}

void print_chihuahua_sad() {
    cout << " (；ᴥ；)\n";
    cout << " / >💧  \"공부 더 하고 올게요...!\"\n\n";
}

void print_shiba_sad() {
    cout << " (｡•́︿•̀｡)\n";
    cout << " / >💤  \"으으... 다음엔 맞출거야!\"\n\n";
}

void print_golden_sad() {
    cout << " ( ´•̥̥̥ω•̥̥̥` )\n";
    cout << " / >🥲  \"실망시키고 싶지 않았는데...\"\n\n";
}

// 🐰 퀴즈 출제 캐릭터: 토끼
void print_rabbit_quiz() {
    cout << " (\\(\\ \n";
    cout << " ( •‿•)   \"다음 중 올바른 변수 선언은 무엇일까요?\"\n";
    cout << " o( o )o\n\n";
}

// 🐱 채점 캐릭터: 고양이
void print_cat_judge(bool correct) {
    if (correct) {
        cout << " /\\_/\\ \n";
        cout << " (≧▽≦)  \"정답이냥~ 똑똑하구나!\"\n\n";
    } else {
        cout << " /\\_/\\ \n";
        cout << " (ಠ_ಠ)  \"틀렸군... 다음엔 더 잘하자냥.\"\n\n";
    }
}

// 🐶 주인공 강아지 반응
void print_dog_react(int dog_type, bool correct) {
    if (correct) {
        switch (dog_type) {
            case 1: print_chihuahua_happy(); break;
            case 2: print_shiba_happy(); break;
            case 3: print_golden_happy(); break;
            default: print_chihuahua_happy(); break;
        }
    } else {
        switch (dog_type) {
            case 1: print_chihuahua_sad(); break;
            case 2: print_shiba_sad(); break;
            case 3: print_golden_sad(); break;
            default: print_chihuahua_sad(); break;
        }
    }
}

// 🧠 변수 퀴즈 출력 및 학습
void quiz_variables(int dog_type) {
    print_rabbit_quiz();

    cout << "1. int 3dogs = 5;\n";
    cout << "2. int dogs = 'five';\n";
    cout << "3. int dogs = 5;\n";
    cout << "4. string dogs = five;\n\n";
    cout << "번호를 입력하세요 (1~4): ";

    int answer;
    cin >> answer;

    cout << endl;

    bool correct = (answer == 3);
    print_cat_judge(correct);
    print_dog_react(dog_type, correct);

    // 학습 해설
    cout << "\n📝 해설: \n";
    cout << "1번: ❌ 변수명은 숫자로 시작할 수 없습니다.\n";
    cout << "2번: ❌ 'five'는 문자형 리터럴입니다. int에는 사용할 수 없습니다.\n";
    cout << "3번: ✅ 정답! int형 변수 dogs를 정수 5로 초기화했습니다.\n";
    cout << "4번: ❌ 문자열은 반드시 \"큰따옴표\"로 감싸야 합니다.\n";

    cout << "\n💡 변수 기초 정리:\n";
    cout << "- 변수명은 문자 또는 밑줄(_)로 시작해야 합니다.\n";
    cout << "- 숫자로 시작하면 안됩니다.\n";
    cout << "- C++의 주요 자료형: int, float, double, char, string, bool\n";
    cout << "- 선언 시 초기값을 주는 것이 좋습니다. (예: int x = 10;)\n";
    cout << "- 타입 불일치 시 컴파일 오류가 발생할 수 있습니다.\n";
}

int main() {
    cout << "🐾🐶 강아지와 함께하는 C++ 변수 퀴즈! 🐶🐾\n\n";

    cout << "주인공 강아지를 선택하세요:\n";
    cout << "1. 초코 치와와\n";
    cout << "2. 시바견\n";
    cout << "3. 골든리트리버\n";
    cout << "번호 입력: ";

    int choice;
    cin >> choice;
    cout << endl;

    cout << "🐾 강아지 등장!\n";
    print_dog_react(choice, true);  // 기쁜 표정으로 등장

    quiz_variables(choice);

    cout << "\n🎉 실습 종료! 다음 퀴즈에서 만나요!\n";
    return 0;
}
