#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
#include <limits>

using namespace std;

// ===== 캐릭터 클래스 선언 =====
// struct보다 기능이 많은 class를 사용해 캐릭터를 표현해봅시다.
class Character {
public:
    string name;
    string species;
    int age;
    long long assets; // 재산
    string hometown;
    string gender;
    string social_status;
    string ideal_type;
    string future_hope;
    string weakness;
    int hp;
    int power;

    // 생성자: 클래스가 생성될 때 자동으로 호출되는 함수
    Character(string n, string s, int h, int p) {
        name = n;
        species = s;
        hp = h;
        power = p;
        // 기본값 설정
        age = 5;
        assets = 100;
        hometown = "멍멍 마을";
        gender = "미상";
        social_status = "모험가";
        ideal_type = "간식 잘 주는 사람";
        future_hope = "세상 모든 뼈다귀 수집";
        weakness = "고양이";
    }

    void displayArt(string mood) {
        // 간단한 감정 표현
        if (mood == "happy") {
            cout << name << ": " << "야호! 신난다!" << endl;
        } else if (mood == "sad") {
            cout << name << ": " << "우엥... 틀렸어..." << endl;
        } else if (mood == "attack") {
            cout << name << ": " << "내 지식을 받아라!" << endl;
        }
    }

    void showProfile() {
        cout << "\n--- " << name << " (" << species << ")의 프로필 ---" << endl;
        cout << "나이: " << age << "살" << endl;
        cout << "재산: " << assets << "뼈다귀" << endl;
        cout << "출신지: " << hometown << endl;
        cout << "장래희망: " << future_hope << endl;
        cout << "약점: " << weakness << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    srand(time(0)); // 랜덤 시드 초기화

    // --- 캐릭터 목록 생성 ---
    vector<Character> all_characters;
    all_characters.push_back(Character("치치", "치와와", 80, 20));
    all_characters.push_back(Character("코코", "웰시코기", 120, 30));
    all_characters.push_back(Character("허허", "허스키", 200, 50));
    all_characters.push_back(Character("토토", "토끼", 50, 5));
    all_characters.push_back(Character("냥냥", "고양이", 70, 25));
    all_characters.push_back(Character("리버", "골든 리트리버", 150, 40));
    all_characters.push_back(Character("숑숑", "비숑", 90, 15));
    all_characters.push_back(Character("불리", "불독", 180, 60));

    // --- 사용자 입력: 캐릭터 커스터마이징 여부 ---
    cout << "멍멍 탐험대에 오신 것을 환영합니다!" << endl;
    cout << "기본 캐릭터 설정을 사용하시겠습니까, 아니면 직접 만드시겠습니까? (1: 기본, 2: 직접 만들기): ";
    int custom_choice;
    cin >> custom_choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (custom_choice == 2) {
        cout << "\n--- 나만의 캐릭터 만들기 ---" << endl;
        for (int i = 0; i < all_characters.size(); ++i) {
            cout << "\n" << i + 1 << "번째 캐릭터 (" << all_characters[i].species << ")의 새 이름을 지어주세요: ";
            getline(cin, all_characters[i].name);
            cout << all_characters[i].name << "의 장래희망은 무엇인가요?: ";
            getline(cin, all_characters[i].future_hope);
        }
        cout << "\n좋아요! 개성 넘치는 탐험대가 꾸려졌네요!" << endl;
    }


    // --- 메인 캐릭터 선택 ---
    cout << "\n함께 여정을 떠날 메인 캐릭터를 선택해주세요!" << endl;
    for (int i = 0; i < all_characters.size(); ++i) {
        cout << i + 1 << ". " << all_characters[i].name << " (" << all_characters[i].species << ")" << endl;
    }
    cout << "선택 (숫자): ";
    int player_choice_idx;
    cin >> player_choice_idx;
    player_choice_idx--; // 인덱스는 0부터 시작하므로 1을 빼줌

    Character player_character = all_characters[player_choice_idx];
    all_characters.erase(all_characters.begin() + player_choice_idx); // 선택된 캐릭터는 퀴즈 출제자에서 제외

    cout << "\n" << player_character.name << "와(과) 함께 '지식의 산'을 오릅니다!" << endl;
    player_character.showProfile();


    // --- 통합 미니 게임 시작 (3 라운드) ---
    for (int round = 1; round <= 3; ++round) {
        cout << "\n========== 라운드 " << round << " ==========" << endl;
        if (player_character.hp <= 0) {
            cout << "체력이 모두 소진되어 더 이상 진행할 수 없습니다..." << endl;
            break;
        }

        // 랜덤으로 퀴즈 출제자 선정
        int quiz_master_idx = rand() % all_characters.size();
        Character quiz_master = all_characters[quiz_master_idx];
        
        cout << quiz_master.name << " (" << quiz_master.species << ") 이(가) 문제를 냅니다!" << endl;
        quiz_master.displayArt("attack");

        // 랜덤으로 문제 유형 결정
        int quiz_type = rand() % 3;
        bool is_correct = false;

        if (quiz_type == 0) { // 데이터형 퀴즈
            cout << "[퀴즈] 내 힘(power)은 " << quiz_master.power << "이야. 이 숫자를 저장하기 위한 기본 '정수' 데이터 타입은 무엇일까? (예: int): ";
            string answer;
            cin >> answer;
            if (answer == "int") is_correct = true;

        } else if (quiz_type == 1) { // 연산자 퀴즈
            int num1 = rand() % 10 + 1;
            int num2 = rand() % 10 + 1;
            cout << "[퀴즈] " << num1 << " * " << num2 << " 의 값은 얼마일까?: ";
            int answer;
            cin >> answer;
            if (answer == num1 * num2) is_correct = true;

        } else { // 변수/논리 퀴즈
            cout << "[퀴즈] '절대 변하지 않는 수'를 선언할 때 사용하는 키워드는? (예: const): ";
            string answer;
            cin >> answer;
            if (answer == "const") is_correct = true;
        }

        // --- 결과 처리 ---
        if (is_correct) {
            cout << "\n정답입니다!" << endl;
            quiz_master.displayArt("happy");
            cout << player_character.name << "의 자신감이 10 상승했습니다!" << endl;
            player_character.hp += 10;
        } else {
            cout << "\n틀렸습니다! 아쉽네요." << endl;
            quiz_master.displayArt("sad");
            cout << player_character.name << "의 체력이 30 감소했습니다!" << endl;
            player_character.hp -= 30;
        }
        cout << "현재 " << player_character.name << "의 체력: " << player_character.hp << endl;
    }

    // --- 최종 결과 ---
    cout << "\n========== 여정 종료 ==========" << endl;
    if (player_character.hp > 0) {
        cout << player_character.name << "는(은) '지식의 산' 정상에 무사히 도착했습니다! 축하합니다!" << endl;
        player_character.displayArt("happy");
    } else {
        cout << player_character.name << "는(은) 아쉽게도 등반에 실패했습니다... 하지만 많은 것을 배웠을 거예요!" << endl;
        player_character.displayArt("sad");
    }
    cout << "\nC++ 그룹 스터디 1주차 내용을 모두 마쳤습니다! 수고하셨습니다!" << endl;

    return 0;
}