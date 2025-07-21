// 🐶 Puppy Coding Game: 05. 변수~연산자 통합 실습
// 학습 내용: 변수 선언, 사용자 입력, 데이터형 구분, 연산자 사용

#include <iostream>
#include <string>
using namespace std;

// 🐕 ASCII 캐릭터 아트 정의
void print_chihuahua_happy() {
    cout << " (\\_/)\n";
    cout << " (•ᴥ•)\n";
    cout << " / >🍖  \"히히! 간식이다!\"\n\n";
}

void print_chihuahua_sad() {
    cout << " (；ᴥ；)\n";
    cout << " / >💧  \"공부 더 하고 올게요...!\"\n\n";
}

void print_rabbit_quiz(const string& question) {
    cout << " (\\(\\ \n";
    cout << " ( •‿•)   \"" << question << "\"\n";
    cout << " o( o )o\n\n";
}

void print_cat_judge(bool correct) {
    if (correct) {
        cout << " /\\_/\\ \n";
        cout << " (≧▽≦)  \"정답이냥~ 똑똑하구나!\"\n\n";
    } else {
        cout << " /\\_/\\ \n";
        cout << " (ಠ_ಠ)  \"틀렸군... 다음엔 더 잘하자냥.\"\n\n";
    }
}

void print_chihuahua_react(bool correct) {
    if (correct) {
        print_chihuahua_happy();
    } else {
        print_chihuahua_sad();
    }
}

// 🧠 퀴즈 함수들
bool quiz_variables() {
    print_rabbit_quiz("다음 중 올바른 변수 선언은 무엇일까요?");

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
    print_chihuahua_react(correct);

    cout << "\n📝 해설:\n";
    cout << "3번: ✅ 정답! int형 변수 dogs를 정수 5로 초기화했습니다.\n";
    return correct;
}

bool quiz_input_and_type() {
    print_rabbit_quiz("사용자 입력을 받을 때 사용하는 객체는 무엇인가요?");

    cout << "1. cout\n";
    cout << "2. cin\n";
    cout << "3. int\n";
    cout << "4. string\n\n";
    cout << "번호를 입력하세요 (1~4): ";

    int answer;
    cin >> answer;
    cout << endl;

    bool correct = (answer == 2);
    print_cat_judge(correct);
    print_chihuahua_react(correct);

    cout << "\n📝 해설:\n";
    cout << "2번: ✅ cin은 사용자 입력을 받는 객체입니다.\n";
    return correct;
}

bool quiz_operator() {
    print_rabbit_quiz("5 + 3 * 2의 결과는? (연산자 우선순위 고려)");

    cout << "1. 11\n";
    cout << "2. 16\n";
    cout << "3. 13\n";
    cout << "4. 10\n\n";
    cout << "번호를 입력하세요 (1~4): ";

    int answer;
    cin >> answer;
    cout << endl;

    bool correct = (answer == 1);
    print_cat_judge(correct);
    print_chihuahua_react(correct);

    cout << "\n📝 해설:\n";
    cout << "1번: ✅ 곱셈이 우선! 3*2 = 6, 그 후 5+6 = 11\n";
    return correct;
}

int main() {
    cout << "🐾🐶 강아지와 함께하는 C++ 통합 퀴즈! 🐶🐾\n\n";
    cout << "주인공 강아지를 선택하세요 (1. 초코 치와와): ";
    int choice;
    cin >> choice;
    cout << endl;

    cout << "🐾 강아지 등장!\n";
    print_chihuahua_happy();

    int score = 0;
    if (quiz_variables()) score++;
    if (quiz_input_and_type()) score++;
    if (quiz_operator()) score++;

    cout << "\n📊 최종 점수: " << score << " / 3" << endl;
    cout << "\n🎉 실습 종료! 다음 퀴즈에서 만나요!\n";
    return 0;
}
