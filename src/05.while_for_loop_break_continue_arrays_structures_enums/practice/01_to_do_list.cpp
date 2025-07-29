#include <iostream> // 입출력 스트림을 위한 헤더 (std::cout, std::cin)
#include <string>   // std::string 사용을 위한 헤더
#include <limits>   // std::numeric_limits를 사용하여 입력 버퍼 비우기 위함

// 전역 변수 또는 상수 정의 (필요에 따라 추가)

// ======================= 함수 프로토타입 선언 =======================
// (나중에 추가될 기능들을 위한 함수 선언)
void clearInputBuffer(); // 입력 버퍼를 비우는 헬퍼 함수

// ========================= 메인 함수 =========================
int main() {
    int choice; // 사용자 메뉴 선택을 위한 변수

    // do-while 루프를 사용하여 최소 한 번은 메뉴를 표시하고, 사용자가 종료를 선택할 때까지 반복
    do {
        // --- 메뉴 표시 ---
        std::cout << "\n--- 할 일 목록 관리자 ---\n";
        std::cout << "1. 할 일 추가\n";
        std::cout << "2. 할 일 목록 보기\n";
        std::cout << "3. 할 일 완료 처리\n";
        std::cout << "4. 할 일 삭제\n";
        std::cout << "5. 프로그램 종료\n";
        std::cout << "메뉴를 선택하세요: ";

        std::cin >> choice; // 사용자 입력 받기 

        // std::cin 사용 후 남은 개행 문자(\n)를 버퍼에서 제거.
        // std::getline을 사용하기 전에 필수적으로 호출해야 합니다.
        clearInputBuffer();

        // switch 문을 사용하여 사용자 선택에 따른 기능 실행
        switch (choice) {
            case 1:
                std::cout << "할 일 추가 기능 (아직 구현 안됨)\n";
                break;
            case 2:
                std::cout << "할 일 목록 보기 기능 (아직 구현 안됨)\n";
                break;
            case 3:
                std::cout << "할 일 완료 처리 기능 (아직 구현 안됨)\n";
                break;
            case 4:
                std::cout << "할 일 삭제 기능 (아직 구현 안됨)\n";
                break;
            case 5:
                std::cout << "프로그램을 종료합니다.\n";
                break; // '5'를 선택하면 do-while 루프를 탈출 [cite: 196]
            default:
                std::cout << "잘못된 메뉴 선택입니다. 다시 시도해주세요.\n";
                break;
        }
    } while (choice != 5); // choice가 5가 아닐 동안 루프 반복 

    return 0; // 프로그램 종료
}

// ========================= 헬퍼 함수 정의 =========================
// 입력 버퍼를 비우는 함수. std::cin과 std::getline 혼용 시 발생할 수 있는 문제 방지
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}