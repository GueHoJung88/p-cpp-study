#include <iostream>
#include <string>

using namespace std;

// 각 캐릭터의 모습을 보여주는 함수들을 미리 만들어 둬요.
void displayChihuahua() {
    cout << R"(
 (\_/)
 (•ᴥ•)
 / >🍖
    )" << endl;
}

void displayCorgi() {
    cout << R"(
 (❍ᴥ❍)
 /⌒🍑⌒\
  ￣|￣|
    )" << endl;
}

void displayHusky() {
    cout << R"(
  /^ ^\
 ( ᴥᴥ )
  |U U|
    )" << endl;
}


int main() {
    // ===== 1단계 복습: 변수 선언 =====
    string my_dog_name;
    int choice;

    // ===== 2. 사용자 입력 (User Input) 학습 =====
    // cin은 키보드로부터 입력을 받는 데 사용돼요. (추출 연산자 >> 와 함께)

    cout << "---------- 멍멍 탐험대 입단 시험 ----------" << endl;
    cout << "함께 여정을 떠날 파트너를 선택하세요!" << endl << endl;
    
    cout << "1. 치와와" << endl;
    displayChihuahua();
    cout << "2. 웰시코기" << endl;
    displayCorgi();
    cout << "3. 시베리안 허스키" << endl;
    displayHusky();
    
    cout << "\n당신의 선택은? (숫자 입력): ";
    cin >> choice; // 사용자가 입력한 숫자가 choice 변수에 저장됩니다.

    cout << "\n좋아요! 당신의 파트너에게 멋진 이름을 지어주세요: ";
    cin >> my_dog_name; // 사용자가 입력한 이름이 my_dog_name 변수에 저장됩니다.

    // --- Creating a Simple "Profile" ---
    // 사용자 입력을 통해 변수 값을 설정하고, 그 결과를 출력해봅니다.
    cout << "\n---------- 나의 파트너 정보 ----------" << endl;
    cout << "이름: " << my_dog_name << endl;
    
    if (choice == 1) {
        cout << "종족: 치와와" << endl;
        displayChihuahua();
        cout << my_dog_name << " (이)가 신나서 꼬리를 흔듭니다!" << endl;
    } else if (choice == 2) {
        cout << "종족: 웰시코기" << endl;
        displayCorgi();
        cout << my_dog_name << " (이)가 짧은 다리로 콩콩 뜁니다!" << endl;
    } else if (choice == 3) {
        cout << "종족: 시베리안 허스키" << endl;
        displayHusky();
        cout << my_dog_name << " (이)가 늠름한 울음소리를 냅니다. 아우~!" << endl;
    } else {
        cout << "음... 그런 친구는 없는데... 일단 토끼를 데려가세요!" << endl;
        cout << R"(
 (\(\ 
 ( •‿•)
 o( o )o
        )" << endl;
    }

    cout << "\n" << my_dog_name << "와(과) 함께 즐거운 C++ 탐험을 시작해봅시다!" << endl;

    return 0;
}