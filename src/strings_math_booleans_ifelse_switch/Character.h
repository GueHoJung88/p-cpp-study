#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <locale>

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
    void display(const std::string &emotion = "default")
    {
        std::cout << "--- " << name << " (" << species << ") | 현재 감정: " << emotion << " ---" << std::endl;

        if (species == "치와와")
        {
            if (emotion == "happy")
            {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (o.o)" << std::endl;
                std::cout << " / > o  \"히히! 정말 좋아!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (T_T)" << std::endl;
                std::cout << " / > ;  \"너무 슬퍼...\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << " (\\o_o/)" << std::endl;
                std::cout << " ( o_o )" << std::endl;
                std::cout << " / > !  \"깜짝이야!\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (._.?)" << std::endl;
                std::cout << " / > ?  \"음... 뭘까?\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << " (>_<)" << std::endl;
                std::cout << " (o`_`o)" << std::endl;
                std::cout << " / > #  \"내 간식 건드리지 마!\"" << std::endl;
            }
            else
            {
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
                std::cout << "  |   |   \"기분 최고야! 콩콩!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << " (T.T)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   |   \"산책... 못 가서 슬퍼...\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << " (O.O)" << std::endl;
                std::cout << " /!---!\\" << std::endl;
                std::cout << "  |   |   \"헉! 내 빵!\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << " (._.?)" << std::endl;
                std::cout << " /-----\\" << std::endl;
                std::cout << "  |   |   \"정답이 뭐더라...\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << " (`_`)" << std::endl;
                std::cout << " /--#--\\" << std::endl;
                std::cout << "  |   |   \"내 방석 누가 가져갔어!\"" << std::endl;
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
                std::cout << "  |U U|  \"가자! 모험의 시간이다!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( ._. )" << std::endl;
                std::cout << "  |...|  \"혼자는 외로워...\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << "  /^o^\\" << std::endl;
                std::cout << " ( O_O )" << std::endl;
                std::cout << "  |! !|  \"저건... 곰인가!?\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << "  /^ ?^\\" << std::endl;
                std::cout << " ( -_- )" << std::endl;
                std::cout << "  |U U|  \"음, 논리적으로 생각해보자.\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << "  /^ ^\\" << std::endl;
                std::cout << " ( >A< )" << std::endl;
                std::cout << "  |# #|  \"누가 내 밥그릇에 손댔어!\"" << std::endl;
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
                std::cout << " o( )o  \"당근! 맛있어!\"" << std::endl;
            }
            else
            {
                std::cout << " (\\(\\ " << std::endl;
                std::cout << " (T_T)" << std::endl;
                std::cout << " o( )o  \"힝... 어려워...\"" << std::endl;
            }
        }
        else if (species == "고양이")
        {
            if (emotion == "happy")
            {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (^_^) " << std::endl;
                std::cout << " (   )  \"나름 재미있네옹~\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (-_-) " << std::endl;
                std::cout << " (   )  \"흥, 시시하다냥.\"" << std::endl;
            }
            else
            {
                std::cout << " /\\_/\\ " << std::endl;
                std::cout << " (*_*) " << std::endl;
                std::cout << " (   ) " << std::endl;
            }
        }
        else if (species == "보리")
        {
            /*말티즈 주인공 캐릭터 '보리' 디자인
이름: 보리
종족: 말티즈
나이: 13세
성별: 암컷 (수정 가능)
성격: 시크함 (겉으로는 무심하지만 속정 깊음)
특징: 고구마를 좋아하고 사료를 등한시함. 새침데기 같은 표정이 트레이드마크.
특장점: 상상을 초월하는 귀여움으로 모든 위기를 넘기는 행운의 아이콘.
고향: 댕댕월드 외곽의 조용한 주택가
사회적 지위: 은퇴한 산책 마스터
이상형: 정시에 고구마를 바치는 자
장래희망: 평생 고구마밭에서 뒹굴기
약점: 발바닥 만지기 (간지럼을 못 참음), 다이어트 강요

*/
            if (emotion == "happy")
            {
                std::cout << " (\\_/) " << std::endl;
                std::cout << " (^_^)" << std::endl;
                std::cout << "  o o   \"고구마라니! 심장이 뛴다!\"" << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << " (\\_/) " << std::endl;
                std::cout << " (T_T)" << std::endl;
                std::cout << "  o o   \"사료는 싫단 말이야...\"" << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << " (\\_O/) " << std::endl;
                std::cout << " (O.O)" << std::endl;
                std::cout << "  o o   \"앗! 간식 소리!\"" << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << " (\\_/)" << std::endl;
                std::cout << " (._.?)" << std::endl;
                std::cout << "  o o   \"흠... 이 시간에 누가 왔지?\"" << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << " (\\_/) " << std::endl;
                std::cout << " (>_<)" << std::endl;
                std::cout << "  o o   \"내 잠 방해하지 마!\"" << std::endl;
            }
            else
            { // default
                std::cout << " (\\_/) " << std::endl;
                std::cout << " (._.)" << std::endl;
                std::cout << "  o o " << std::endl;
            }
        }
        // For human characters like 임정찬, 정규호, 싀백
        else if (species == "임정찬")
        {
            /*1. 임정찬 (Liki)
    종족: 임정찬 (인간)

    이름: Liki (리키)

    나이: 10세 (C++ 스터디에 이제 막 흥미를 붙인 초등학생)

    HP: 10

    Power: 1

    재산: 500원 (문구점에서 군것질할 정도)

    고향: 서울 어딘가

    성별: 남성

    사회적 지위: 코딩 꿈나무

    이상형: 코딩 잘 가르쳐주는 형, 누나

    장래희망: 로봇을 만드는 프로그래머

    약점: 어려운 수학 문제, 밤샘 코딩

    성격: 호기심 많고 끈기 있지만, 가끔 엉뚱한 실수를 함. 새로운 것을 배우는 데 열정적.

    특징: 항상 연필과 노트를 들고 다니며 무엇이든 기록하려 함. 코딩할 때 집중하면 세상모름.*/
            if (emotion == "happy")
            {
                std::cout << "  (^_^)  \"와! 이해했어요!\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << "  (T_T)  \"이게 아닌데...\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << "  (O_O)  \"헉! 이렇게 되는 거였어요?\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << "  (._.)  \"음... 뭐가 문제지...?\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << "  (>_<)  \"아, 왜 안 되는 거야!\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else
            {
                std::cout << "  (*_*)  \"리키입니다!\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
        }
        else if (species == "정규호")
        {
            /*2. 정규호 (바보)
    종족: 정규호 (인간)

    이름: 바보 (본인 피셜 귀여운 별명, 실제로는 꽤 영리함)

    나이: 10세 (리키와 동갑, 스터디의 분위기 메이커)

    HP: 10

    Power: 2

    재산: 1,000원 (불량식품 컬렉터)

    고향: 동네 놀이터 근처

    성별: 남성

    사회적 지위: 공식 분위기 메이커

    이상형: 리액션 잘 해주는 친구

    장래희망: 세계 최고의 유튜버

    약점: 배고픔, 집중력 부족 (재미없는 내용은 바로 잠듦)

    성격: 장난기 많고 쾌활함. 쉽게 포기하지 않지만 가끔 엉뚱한 답을 내놓아 주변을 즐겁게 함.

    특징: 항상 해맑게 웃고 있으며, 어려운 상황에서도 긍정적인 면을 찾으려 노력함.

    */
            if (emotion == "happy")
            {
                std::cout << "  \\(^_^) /  \"아하하하! 정말 쉽죠?\"" << std::endl;
                std::cout << "    | |   " << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << "  (T_T)  \"으앙, 나만 몰라!\"" << std::endl;
                std::cout << "   / \\   " << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << "  (O.O)  \"와우! 대박!\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << "  (?.?)  \"음... 잠시만요...\"" << std::endl;
                std::cout << "   / \\   " << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << "  (>_<)  \"이거 아니면 안 돼!\"" << std::endl;
                std::cout << "  /| |\\ " << std::endl;
            }
            else
            {
                std::cout << "  (^o^)  \"바보입니다!\"" << std::endl;
                std::cout << "   / \\   " << std::endl;
            }
        }
        else if (species == "싀백")
        {
            /*3. 싀백 (먀엉)
    종족: 싀백 (고양이과 요괴, 고대 지식의 수호자)

    이름: 먀엉 (자신을 부르는 소리에서 따온 이름)

    나이: 불명 (최소 수백 년 이상)

    HP: 120

    Power: 100

    재산: 무한 (세상의 모든 보물을 본 적 있음)

    고향: 고대 지식의 신전

    성별: 없음 (혹은 자유로움)

    사회적 지위: 지식의 산 최종 보스 (혹은 현자)

    이상형: 자신을 뛰어넘는 지혜를 가진 자

    장래희망: 모든 인간이 지식의 가치를 깨닫는 것

    약점: 간지럼 (의외로 약함), 너무 단순한 문제 (지루해함)

    성격: 냉철하고 지혜로움. 쉽게 감정을 드러내지 않지만, 지식에 대한 열정은 누구보다 강함. 정답을 맞히면 만족하지만, 틀리면 가차 없다.

    특징: 신비로운 푸른 눈을 가지고 있으며, 항상 알 수 없는 미소를 띠고 있음. 엄청난 지식을 소유하고 있어 스터디의 최종 퀴즈 마스터 역할을 담당.*/
            if (emotion == "happy")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( o_o ) \"흐음, 제법이군.\" " << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
            else if (emotion == "sad")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( ._. ) \"기대에 미치지 못하는구나...\"" << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
            else if (emotion == "surprised")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( O_O ) \"놀랍군! 예상을 뛰어넘는 답이다!\"" << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
            else if (emotion == "thinking")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( -_- ) \"깊이 생각해보아라...\"" << std::endl;
                std::cout << " ( ~~~ )  " << std::endl;
            }
            else if (emotion == "angry")
            {
                std::cout << "  /\\_/\\  " << std::endl;
                std::cout << " ( >A< ) \"어리석은 대답이로다!\"" << std::endl;
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
        {
            std::cout << name << " (" << species << ") " << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
    }

    // --- 4. 멤버 함수: 캐릭터의 상세 프로필을 보여줍니다. ---
    void showProfile()
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
    characters.push_back(Character("임정찬", "Liki", 10, 1));
    characters.push_back(Character("정규호", "바보", 10, 2));
    characters.push_back(Character("싀백", "먀엉", 120, 100));

    return characters;
}

#endif // CHARACTER_H