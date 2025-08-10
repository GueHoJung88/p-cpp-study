#include <iostream>
#include <string>
#include <vector>
// #include <locale> // cout/string 버전에서는 필수는 아닙니다.
#include "Character.h" // string/cout을 사용하는 헤더 파일

// using 선언을 string/cout/cin에 맞게 변경합니다.
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
    // setlocale(LC_ALL, ""); // cout/string 버전에서는 필수는 아닙니다.

    // --- 파트너 캐릭터 선택 ---
    cout << "---------- 멍멍 탐험대 파트너를 선택하세요! ----------" << endl;
    vector<Character> all_characters = initializeCharacters();
    for (int i = 0; i < all_characters.size(); ++i) {
        cout << i + 1 << ". " << all_characters[i].species << std::endl;
    }
    
    cout << "\n함께할 파트너의 번호를 선택하세요: ";
    int choice_idx;
    cin >> choice_idx;
    choice_idx--; 

    Character my_partner = all_characters[choice_idx];
    cout << "\n당신의 파트너는 " << my_partner.species << " 입니다!" << endl;
    my_partner.display("happy");


    // ===== C++ Variables 학습 (실습 튜토리얼) =====
    cout << "\n\n--- C++ 변수(Variables) 학습을 시작합니다! ---" << endl;
    cout << "변수는 데이터를 저장하는 '컨테이너'입니다." << endl;

    // --- Declaring (Creating) Variables ---
    cout << "\n// 1. 변수 선언 및 생성" << endl;
    cout << "파트너의 새로운 이름을 string(문자열) 타입의 'partner_name' 변수에 저장해봅시다." << endl;
    cout << "파트너의 이름을 지어주세요: ";
    
    string partner_name; // string 타입의 변수 선언
    cin >> partner_name; // 사용자 입력을 받아 변수에 값 할당
    my_partner.name = partner_name; // 객체의 이름도 업데이트

    cout << "좋아요! 이제 당신의 파트너 이름은 '" << my_partner.name << "' 입니다!" << endl;


    // --- Other Types & Display Variables ---
    cout << "\n// 2. 다양한 타입의 변수와 출력" << endl;
    cout << "C++에는 여러 데이터 타입이 있습니다. 파트너의 정보로 확인해봅시다." << endl;
    
    int partner_hp = my_partner.hp; // int: 정수
    double partner_power_rate = (my_partner.power / 100.0) * 100.0; // double: 실수
    char partner_rank = 'B'; // char: 단일 문자
    bool is_strong = (my_partner.power > 40); // bool: 참(true) 또는 거짓(false)

    cout << " - 파트너의 체력(int): " << partner_hp << endl;
    cout << " - 파트너의 파워 비율(double): " << partner_power_rate << "%" << endl;
    cout << " - 파트너의 랭크(char): " << partner_rank << endl;
    cout << " - 파트너는 강한가요?(bool): " << (is_strong ? "네" : "아니오") << endl;


    // --- Changing Variable Values ---
    cout << "\n// 3. 변수 값 변경하기" << endl;
    cout << "파트너가 맛있는 간식을 먹어 체력이 10 올랐습니다!" << endl;
    cout << "이전 체력: " << partner_hp << endl;
    partner_hp = partner_hp + 10; // 기존 변수에 새로운 값을 할당 (덮어쓰기)
    cout << "현재 체력: " << partner_hp << endl;


    // --- Add Variables Together ---
    cout << "\n// 4. 변수끼리 더하기" << endl;
    int item_power = 20;
    int total_power = my_partner.power + item_power;
    cout << "파트너의 기본 파워(" << my_partner.power << ")에 아이템 파워(" << item_power << ")를 더하면, 총 파워는 " << total_power << " 입니다." << endl;


    // --- Declare Many Variables & Identifiers ---
    cout << "\n// 5. 여러 변수 한번에 선언하기 & 식별자 규칙" << endl;
    cout << "탐험에 필요한 아이템들을 선언해봅시다. 변수 이름은 내용물을 알아보기 쉽게 짓는게 좋아요." << endl;
    int potion = 3, map = 1, compass = 1; // 쉼표(,)로 구분하여 같은 타입의 변수를 여러 개 선언
    cout << " - 현재 보유 아이템: 포션 " << potion << "개, 지도 " << map << "개, 나침반 " << compass << "개" << endl;

    // --- Constants ---
    cout << "\n// 6. 상수 (Constants)" << endl;
    cout << "'const' 키워드를 사용하면 절대 변하지 않는 상수를 만들 수 있습니다." << endl;
    const string GUILD_NAME = "새싹 탐험대"; // 상수는 대문자로 표기하는 경우가 많습니다.
    cout << "당신이 소속된 길드의 이름은 '" << GUILD_NAME << "' 이며, 이 이름은 바꿀 수 없습니다." << endl;
    // GUILD_NAME = "전설의 탐험대"; // 주석을 풀면 컴파일 에러 발생!

    cout << "\n\n축하합니다! 변수에 대한 모든 실습을 마쳤습니다!" << endl;

    return 0;
}