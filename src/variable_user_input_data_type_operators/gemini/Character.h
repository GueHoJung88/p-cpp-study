#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <locale>

// 모든 캐릭터의 기반이 되는 'Character' 클래스를 정의합니다.
class Character {
public:
    // --- 1. 캐릭터 특성 변수들 ---
    std::string name;
    std::string species;
    int age;
    long long assets;
    std::string hometown;
    std::string gender;
    std::string social_status;
    std::string ideal_type;
    std::string future_hope;
    std::string weakness;
    int hp;
    int power;

    // --- 2. 생성자 ---
    Character(std::string sp, std::string n, int h, int p) {
        species = sp;
        name = n;
        hp = h;
        power = p;

        age = 5;
        assets = 100;
        hometown = "댕댕월드";
        gender = "비밀";
        social_status = "모험가 지망생";
        ideal_type = "맛있는 거 주는 사람";
        future_hope = "세상 모든 공을 모으는 것";
        weakness = "진공청소기 소리";
    }

    // --- 3. 멤버 함수: 캐릭터의 다양한 표정을 출력합니다. (업데이트된 부분) ---
    void display(const std::string& emotion = "default") {
        std::cout << "--- " << name << " (" << species << ") | 현재 감정: " << emotion << " ---" << std::endl;

        if (species == "치와와") {
            if (emotion == "happy") {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (o.o)" << std::endl;
                std::cout << " / > o  \"히히! 정말 좋아!\"" << std::endl;
            }
            else if (emotion == "sad") {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (T_T)" << std::endl;
                std::cout << " / > ;  \"너무 슬퍼...\"" << std::endl;
            }
            else if (emotion == "surprised") {
                std::cout << " (\\o_o/)" << std::endl;
                std::cout << " ( o_o )" << std::endl;
                std::cout << " / > !  \"깜짝이야!\"" << std::endl;
            }
            else if (emotion == "thinking") {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (._.?)" << std::endl;
                std::cout << " / > ?  \"음... 뭘까?\"" << std::endl;
            }
            else if (emotion == "angry") {
                std::cout << " (>_<)" << std::endl;
                std::cout << " (o`_`o)" << std::endl;
                std::cout << " / > #  \"내 간식 건드리지 마!\"" << std::endl;
            }
            else {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (*.*)" << std::endl;
                std::cout << " / >   " << std::endl;
            }
        } 
        else if (species == "웰시코기") {
            if (emotion == "happy") {
                std::cout << " (o.o)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   |   \"기분 최고야! 콩콩!\"" << std::endl;
            }
            else if (emotion == "sad") {
                std::cout << " (T.T)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   |   \"산책... 못 가서 슬퍼...\"" << std::endl;
            }
            else if (emotion == "surprised") {
                std::cout << " (O.O)" << std::endl;
                std::cout << " /!---!\\" << std::endl;
                std::cout << "  |   |   \"헉! 내 빵!\"" << std::endl;
            }
            else if (emotion == "thinking") {
                std::cout << " (._.?)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   |   \"정답이 뭐더라...\"" << std::endl;
            }
            else if (emotion == "angry") {
                std::cout << " (`_`)" << std::endl;
                std::cout << " /--#--\\" << std::endl;
                std::cout << "  |   |   \"내 방석 누가 가져갔어!\"" << std::endl;
            }
            else {
                std::cout << " (o.o)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   | " << std::endl;
            }
        }
        else if (species == "허스키") {
            if (emotion == "happy") {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( >_< )" << std::endl;
                std::cout << "  |U U|  \"가자! 모험의 시간이다!\"" << std::endl;
            }
            else if (emotion == "sad") {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( ._. )" << std::endl;
                std::cout << "  |...|  \"혼자는 외로워...\"" << std::endl;
            }
            else if (emotion == "surprised") {
                std::cout << "  /^o^\\" << std::endl;
                std::cout << " ( O_O )" << std::endl;
                std::cout << "  |! !|  \"저건... 곰인가!?\"" << std::endl;
            }
            else if (emotion == "thinking") {
                std::cout << "  /^ ?^\\" << std::endl;
                std::cout << " ( -_- )" << std::endl;
                std::cout << "  |U U|  \"음, 논리적으로 생각해보자.\"" << std::endl;
            }
            else if (emotion == "angry") {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( >A< )" << std::endl;
                std::cout << "  |# #|  \"누가 내 밥그릇에 손댔어!\"" << std::endl;
            }
            else {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( * * )" << std::endl;
                std::cout << "  |U U| " << std::endl;
            }
        }
        else if (species == "토끼") {
            if (emotion == "happy") {
                std::cout << " (\\(\\ " << std::endl;
                std::cout << " (^_^) " << std::endl;
                std::cout << " o( )o  \"당근! 맛있어!\"" << std::endl;
            }
            else {
                std::cout << " (\\(\\ " << std::endl;
                std::cout << " (T_T)" << std::endl;
                std::cout << " o( )o  \"힝... 어려워...\"" << std::endl;
            }
        }
        else if (species == "고양이") {
            if (emotion == "happy") {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (^_^) " << std::endl;
                std::cout << " (   )  \"나름 재미있네옹~\"" << std::endl;
            }
             else if (emotion == "angry") {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (-_-) " << std::endl;
                std::cout << " (   )  \"흥, 시시하다냥.\"" << std::endl;
            }
            else {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (*_*) " << std::endl;
                std::cout << " (   ) " << std::endl;
            }
        }
        else {
             std::cout << name << " (" << species << ") " << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
    }


    // --- 4. 멤버 함수: 캐릭터의 상세 프로필을 보여줍니다. ---
    void showProfile() {
        std::cout << "\n--- " << name << " (" << species << ")의 프로필 ---" << std::endl;
        std::cout << "나이: " << age << "살" << std::endl;
        std::cout << "재산: " << assets << "뼈다귀" << std::endl;
        std::cout << "출신지: " << hometown << std::endl;
        std::cout << "성별: " << gender << std::endl;
        std::cout << "사회적 지위: " << social_status << std::endl;
        std::cout << "이성 취향: " << ideal_type << std::endl;
        std::cout << "장래희망: " << future_hope << std::endl;
        std::cout << "약점: " << weakness << std::endl;
        std::cout << "체력(HP): " << hp << " | 공격력(Power): " << power << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
};

// --- 5. 헬퍼 함수: 게임 시작 시 모든 캐릭터 목록을 생성합니다. ---
std::vector<Character> initializeCharacters() {
    std::vector<Character> characters;
    characters.push_back(Character("치와와", "치치", 80, 20));
    characters.push_back(Character("웰시코기", "코코", 120, 30));
    characters.push_back(Character("허스키", "허허", 200, 50));
    characters.push_back(Character("토끼", "토토", 50, 5));
    characters.push_back(Character("고양이", "냥냥", 70, 25));
    characters.push_back(Character("골든 리트리버", "리버", 150, 40));
    characters.push_back(Character("비숑 프리제", "숑숑", 90, 15));
    characters.push_back(Character("불독", "불리", 180, 60));
    return characters;
}


#endif // CHARACTER_H