#include <iostream>
#include <string>
#include <limits>

using namespace std;

// 캐릭터 아트 함수 (재사용)
void displayHusky(string mood) {
    if (mood == "happy") {
        cout << R"(
  /^ ^\
 ( ᴥᴥ )
  |U U| "역시 내 파트너! 똑똑하군!"
        )" << endl;
    } else {
        cout << R"(
  /^ ^\
 ( ︶︵︶ )
  |...| "괜찮아, 다시 해보면 되지..."
        )" << endl;
    }
}

int main() {
    // ===== 1, 2, 3단계 복습 =====
    string player_name = "용감한 탐험가";
    string character_name = "허스키";
    int health = 100;
    int snack_count = 3;

    cout << "---------- 연산자 동굴 대탐험! ----------" << endl;
    cout << player_name << "와(과) 파트너 " << character_name << "가 동굴에 들어섰다." << endl;
    cout << "현재 체력: " << health << ", 보유 간식: " << snack_count << endl;

    // 여기서부터 '불독'이 NPC로 등장해 문제를 냅니다.
    cout << "\n동굴의 수호자 '무뚝뚝 불독'이 길을 막아섰다." << endl;
    cout << R"(
 (ಠᴥಠ)
 (ง •̀_•́)ง "이 동굴을 지나가려면 내 시험을 통과해야 한다!"
    )" << endl;

    // ===== 4. 연산자 (Operators) 학습 퀴즈 =====
    // 연산자는 변수와 값에 대한 연산을 수행하는 데 사용돼요.

    // --- Arithmetic Operators (산술 연산자) ---
    cout << "\n[시험 1] 내가 간식 5개를 갖고 있고, 네가 가진 " << snack_count << "개를 더하면 총 몇 개가 될까?" << endl;
    int answer1;
    cout << "정답: ";
    cin >> answer1;
    
    int correct_answer1 = 5 + snack_count;
    if (answer1 == correct_answer1) {
        cout << "\n흥, 덧셈은 좀 하는군. 정답이다! 간식을 하나 주지." << endl;
        snack_count++; // ++ (증감 연산자): 변수 값을 1 증가시킴
        cout << "보유 간식: " << snack_count << endl;
        displayHusky("happy");
    } else {
        cout << "\n이런, 틀렸잖아! 정답은 " << correct_answer1 << "개다. 실망이군. 체력 -20." << endl;
        health -= 20; // -= (할당 연산자): health = health - 20 과 같음
        cout << "현재 체력: " << health << endl;
        displayHusky("sad");
    }

    // --- Comparison & Logical Operators (비교 & 논리 연산자) ---
    int bulldog_power = 80;
    cout << "\n[시험 2] 내 전투력은 " << bulldog_power << "이고, 네 파트너의 체력은 " << health << "이다." << endl;
    cout << "내 전투력이 네 파트너의 체력보다 강한가(true) 약한가(false)?" << endl;
    cout << "(true는 1, false는 0으로 답하시오)" << endl;
    bool answer2;
    cout << "정답: ";
    cin >> answer2;
    
    bool correct_answer2 = bulldog_power > health;
    if (answer2 == correct_answer2) {
        cout << "\n상황 판단이 빠르군. 정답이다! 계속 진행해라." << endl;
        displayHusky("happy");
    } else {
        cout << "\n쯧쯧, 현실을 직시해라. 정답은 " << correct_answer2 << "다! 체력 -20." << endl;
        health -= 20;
        cout << "현재 체력: " << health << endl;
        displayHusky("sad");
    }

    cout << "\n[시험 3 - 최종] 동굴을 나가려면 두 개의 문이 있다." << endl;
    cout << "문 A: '날씨가 맑다(true)' 그리고 '열쇠가 있다(false)'" << endl;
    cout << "문 B: '배가 고프다(true)' 또는 '간식이 있다(true)'" << endl;
    cout << "&& (AND)와 || (OR) 논리 연산자를 생각했을 때, 어떤 문이 열릴까? (A 또는 B로 답하시오)" << endl;
    char answer3;
    cout << "정답: ";
    cin >> answer3;

    // 논리 연산자: &&는 둘 다 true여야 true, ||는 하나만 true여도 true
    if (answer3 == 'B' || answer3 == 'b') {
        cout << "\n훌륭하군! 논리적으로 생각할 줄 아는군. 동굴을 지나가도 좋다!" << endl;
        cout << "불독이 길을 비켜주었다." << endl;
        displayHusky("happy");
    } else {
        cout << "\n논리력이 부족하군! 정답은 B다. &&는 둘 다 참이어야 하지만, ||는 하나만 참이면 되니까. 마지막 벌이다! 체력 -20" << endl;
        health -= 20;
        cout << "현재 체력: " << health << endl;
        displayHusky("sad");
    }

    cout << "\n연산자 동굴 탐험 종료! 현재 체력: " << health << ", 보유 간식: " << snack_count << endl;

    return 0;
}