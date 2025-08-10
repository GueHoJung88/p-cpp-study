#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <locale> // setlocale을 위해 필요

// 모든 캐릭터의 기반이 되는 'Character' 클래스를 정의합니다.
class Character
{
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
    Character(std::string sp, std::string n, int h, int p)
    {
        species = sp;
        name = n;
        hp = h;
        power = p;

        age = 5; // 기본값
        assets = 100; // 기본값
        hometown = "댕댕월드"; // 기본값
        gender = "비밀"; // 기본값
        social_status = "모험가 지망생"; // 기본값
        ideal_type = "맛있는 거 주는 사람"; // 기본값
        future_hope = "세상 모든 공을 모으는 것"; // 기본값
        weakness = "진공청소기 소리"; // 기본값
    }

    // --- 3. 멤버 함수: 캐릭터의 다양한 표정을 출력합니다. ---
    void display(const std::string &emotion = "default") const
    {
        std::cout << "--- " << name << " (" << species << ") | 현재 감정: " << emotion << " ---" << std::endl;

        if (species == "치와와")
        {
            if (emotion == "happy")
            {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (o.o)" << std::endl;
                std::cout << " / > o  \"히히! 정말 좋아! 간식 줄래? 뿅!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (T_T)" << std::endl;
                std::cout << " / > ;  \"너무 슬퍼... 누가 나 좀 안아줘... 훌쩍...\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << " (\\o_o/)" << std::endl;
                std::cout << " ( O_O )" << std::endl;
                std::cout << " / > !  \"깜짝이야! 간식이 어디서 나타났지!? 멍!\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (._.?)" << std::endl;
                std::cout << " / > ?  \"음... 뭘까? 간식에 대한 고찰... 킁킁...\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << " (>_<)" << std::endl;
                std::cout << " (o`_`o)" << std::endl;
                std::cout << " / > #  \"내 간식 건드리지 마! 물어버릴 거야! 크르릉!\"" << std::endl;
            }
            else
            { // default
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (*.*)" << std::endl;
                std::cout << " / >   " << std::endl;
            }
        }
        else if (species == "웰시코기")
        {
            if (emotion == "happy")
            {
                std::cout << " (o.o)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   |   \"기분 최고야! 콩콩! 산책 가자! 엉덩이 씰룩!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << " (T.T)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   |   \"산책... 못 가서 슬퍼... 흑흑... 내 짧은 다리...\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << " (O.O)" << std::endl;
                std::cout << " /!---!\\" << std::endl;
                std::cout << "  |   |   \"헉! 내 빵이 사라졌어! 빵.. 빵... 빵빵!\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << " (._.?)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   |   \"정답이 뭐더라... 엉덩이로 생각 중... 긁적...\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << " (`_`)" << std::endl;
                std::cout << " /--#--\\" << std::endl;
                std::cout << "  |   |   \"내 방석 누가 가져갔어! 발바닥으로 혼내줄 거야! 쿵!\"" << std::endl;
            }
            else
            {
                std::cout << " (o.o)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   | " << std::endl;
            }
        }
        else if (species == "허스키")
        {
            if (emotion == "happy")
            {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( >_< )" << std::endl;
                std::cout << "  |U U|  \"가자! 모험의 시간이다! 으르렁! 시베리아에서 왔다!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( ._. )" << std::endl;
                std::cout << "  |...|  \"혼자는 외로워... 늑대 무리가 보고 싶다... 아우우...\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << "  /^o^\\" << std::endl;
                std::cout << " ( O_O )" << std::endl;
                std::cout << "  |! !|  \"저건... 곰인가!? 아니면 간식인가!? 눈이 휘둥그레!\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << "  /^ ?^\\" << std::endl;
                std::cout << " ( -_- )" << std::endl;
                std::cout << "  |U U|  \"음, 논리적으로 생각해보자. 내 털은 왜 이렇게 빠질까? 심각...\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( >A< )" << std::endl;
                std::cout << "  |# #|  \"누가 내 밥그릇에 손댔어! 얼음 찜질할 준비 해! 얼음 뿜뿜!\"" << std::endl;
            }
            else
            {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( * * )" << std::endl;
                std::cout << "  |U U| " << std::endl;
            }
        }
        else if (species == "토끼")
        {
            if (emotion == "happy")
            {
                std::cout << " (\\(\\ " << std::endl;
                std::cout << " (^_^) " << std::endl;
                std::cout << " o( )o  \"당근! 맛있어! 깡총깡총! 당근은 사랑!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << " (\\(\\ " << std::endl;
                std::cout << " (T_T)" << std::endl;
                std::cout << " o( )o  \"힝... 어려워... 당근으로 때려치고 싶어... 토무룩...\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << " (\\o_o/)" << std::endl;
                std::cout << " ( O_O )" << std::endl;
                std::cout << " o( )o  \"헉! 늑대가 나타났다! 깡총!\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << " (\\(\\ " << std::endl;
                std::cout << " (._.?)" << std::endl;
                std::cout << " o( )o  \"음... 당근의 개수는... 톡톡...\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << " (\\(\\ " << std::endl;
                std::cout << " (>_<)" << std::endl;
                std::cout << " o( )o  \"내 당근밭에 누가 발을 들였지!? 파이어볼!\"" << std::endl;
            }
            else
            {
                std::cout << " (\\(\\ " << std::endl;
                std::cout << " (*_*) " << std::endl;
                std::cout << " o( )o  " << std::endl;
            }
        }
        else if (species == "고양이")
        {
            if (emotion == "happy")
            {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (^_^) " << std::endl;
                std::cout << " (   )  \"나름 재미있네옹~ 그르릉... 집사 최고!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (T_T) " << std::endl;
                std::cout << " (   )  \"집사가 날 무시하다니... 냥무룩... 밥 안 줘?\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (O_O) " << std::endl;
                std::cout << " (   )  \"헉! 참치 캔 소리!? 튀어라 냥!\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (._.) " << std::endl;
                std::cout << " (   )  \"음... 저 상자에 들어가볼까...? 완벽한 은신처...\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (>_<) " << std::endl;
                std::cout << " (   )  \"흥, 시끄럽다옹! 내 낮잠 방해하지 마! 냥펀치!\"" << std::endl;
            }
            else
            {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (*_*) " << std::endl;
                std::cout << " (   ) " << std::endl;
            }
        }
        else if (species == "말티즈") // 보리 캐릭터
        {
            if (emotion == "happy")
            {
                std::cout << " (\\_/) " << std::endl;
                std::cout << " (^_^)" << std::endl;
                std::cout << "  o o   \"고구마라니! 심장이 뛴다! 멍멍! 꼬리 붕붕!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << " (\\_/) " << std::endl;
                std::cout << " (T_T)" << std::endl;
                std::cout << "  o o   \"사료는 싫단 말이야... 흑흑... 고구마 줘...\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << " (\\_O/) " << std::endl;
                std::cout << " (O.O)" << std::endl;
                std::cout << "  o o   \"앗! 간식 소리! 보리 번개! (휙)\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (._.?)" << std::endl;
                std::cout << "  o o   \"흠... 이 시간에 누가 왔지? 고구마 배달인가? 킁킁...\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << " (\\_/) " << std::endl;
                std::cout << " (>_<)" << std::endl;
                std::cout << "  o o   \"내 잠 방해하지 마! 시크하게 째려보기! (으르렁)\"" << std::endl;
            }
            else
            { // default
                std::cout << " (\\_/) " << std::endl;
                std::cout << " (._.)" << std::endl;
                std::cout << "  o o " << std::endl;
            }
        }
        // 인간 캐릭터들
        else if (species == "임정찬")
        {
            if (emotion == "happy")
            {
                std::cout << "  (^_^)  \"와! 이해했어요! 코딩 너무 재미있어요! (반짝반짝)\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << "  (T_T)  \"이게 아닌데... 코드가 또 안 돼요... (엉엉)\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << "  (O_O)  \"헉! 이렇게 되는 거였어요!? 로봇이 움직인다! (환호)\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << "  (._.)  \"음... 뭐가 문제지...? 버그는 어디 숨었을까...? (고뇌)\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << "  (>_<)  \"아, 왜 안 되는 거야! 키보드 뿌실뻔! (부들부들)\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else
            { // default
                std::cout << "  (*_*)  \"리키입니다! 코딩 꿈나무죠! (V)\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
        }
        else if (species == "정규호")
        {
            if (emotion == "happy")
            {
                std::cout << "  \\(^_^) /  \"아하하하! 정말 쉽죠? 구독과 좋아요! (함박웃음)\"" << std::endl;
                std::cout << "    | |   " << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << "  (T_T)  \"으앙, 나만 몰라! 난 바보인가봐... (좌절)\"" << std::endl;
                std::cout << "   / \\   " << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << "  (O.O)  \"와우! 대박! 이런 반전이!? (팝콘 냠냠)\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << "  (?.?)  \"음... 잠시만요... 다음 영상 콘텐츠는 뭐지...? (궁리)\"" << std::endl;
                std::cout << "   / \\   " << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << "  (>_<)  \"이거 아니면 안 돼! 난 천재인데! (빼액)\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else
            { // default
                std::cout << "  (^o^)  \"바보입니다! 하하! (능글)\"" << std::endl;
                std::cout << "   / \\   " << std::endl;
            }
        }
        else if (species == "싀백") // 고양이과 요괴 (지식의 수호자)
        {
            if (emotion == "happy")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( o_o ) \"흐음, 제법이군. 야옹~ 만족스럽다옹.\" " << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( ._. ) \"기대에 미치지 못하는구나... 냐아... 실망이다옹.\"" << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( O_O ) \"놀랍군! 예상을 뛰어넘는 답이다! 갸릉~ (흥미진진)\"" << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( -_- ) \"깊이 생각해보아라... 진정한 지혜란 무엇인가... (정색)\"" << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( >A< ) \"어리석은 대답이로다! 감히 나의 지혜에 도전하느냐! (하악질)\"" << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
            else
            { // default
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( ^_~ ) " << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
        }
        else
        { // 정의되지 않은 종족
            std::cout << name << " (" << species << ") " << std::endl;
            std::cout << " (\\_/) " << std::endl;
            std::cout << " ('.')" << std::endl;
            std::cout << " o(\")(\") " << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
    }

    // --- 4. 멤버 함수: 캐릭터의 상세 프로필을 보여줍니다. ---
    void showProfile() const
    {
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
std::vector<Character> initializeCharacters()
{
    std::vector<Character> characters;
    characters.push_back(Character("치와와", "치치", 80, 20));
    characters.push_back(Character("웰시코기", "코코", 120, 30));
    characters.push_back(Character("허스키", "허허", 200, 50));
    characters.push_back(Character("토끼", "토토", 50, 5));
    characters.push_back(Character("고양이", "냥냥", 70, 25));
    characters.push_back(Character("골든 리트리버", "리버", 150, 40));
    characters.push_back(Character("비숑 프리제", "숑숑", 90, 15));
    characters.push_back(Character("불독", "불리", 180, 60));
    characters.push_back(Character("말티즈", "보리", 130, 35)); // 보리를 말티즈로 명시
    characters.push_back(Character("임정찬", "리키", 10, 1));
    characters.push_back(Character("정규호", "바보", 10, 2));
    characters.push_back(Character("싀백", "먀엉", 120, 100));

    return characters;
}

#endif // CHARACTER_H