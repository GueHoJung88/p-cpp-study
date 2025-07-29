#include <iostream>
#include <string>
#include <limits>

// --- 추가된 코드 시작 ---

// 할 일의 완료 여부를 나타내는 열거형
enum TaskStatus {
    PENDING,   // 미완료
    COMPLETED  // 완료
}; // [cite: 166]

// 할 일 정보를 저장하는 구조체
struct Task {
    std::string description; // 할 일 내용
    TaskStatus status;       // 할 일 상태 (미완료/완료)
}; // 

// 최대 할 일 개수 정의 (배열 크기)
const int MAX_TASKS = 10;
// 할 일 목록을 저장할 Task 구조체 배열
Task todoList[MAX_TASKS]; // 
// 현재 등록된 할 일 개수
int taskCount = 0;

// --- 추가된 코드 끝 ---

// ======================= 함수 프로토타입 선언 =======================
void clearInputBuffer();
void addTask();          // 1. 할 일 추가 함수
void listTasks();        // 2. 할 일 목록 보기 함수
void markTaskCompleted(); // 3. 할 일 완료 처리 함수
// void deleteTask();      // 4. 할 일 삭제 함수 (나중에 추가)

// ========================= 메인 함수 =========================
int main() {
    int choice;

    do {
        std::cout << "\n--- 할 일 목록 관리자 ---\n";
        std::cout << "1. 할 일 추가\n";
        std::cout << "2. 할 일 목록 보기\n";
        std::cout << "3. 할 일 완료 처리\n";
        std::cout << "4. 할 일 삭제\n";
        std::cout << "5. 프로그램 종료\n";
        std::cout << "메뉴를 선택하세요: ";

        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1:
                addTask(); // 함수 호출로 변경
                break;
            case 2:
                listTasks(); // 함수 호출로 변경
                break;
            case 3:
                markTaskCompleted(); // 함수 호출로 변경
                break;
            case 4:
                std::cout << "할 일 삭제 기능 (아직 구현 안됨)\n"; // 계속 미구현 상태
                break;
            case 5:
                std::cout << "프로그램을 종료합니다.\n";
                break;
            default:
                std::cout << "잘못된 메뉴 선택입니다. 다시 시도해주세요.\n";
                break;
        }
    } while (choice <= 5);

    return 0;
}

// ========================= 헬퍼 함수 정의 =========================
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ========================= 기능 함수 정의 =========================

// --- 추가된 코드 시작 ---

// 1. 할 일 추가 기능
void addTask() {
    // 배열이 가득 찼는지 확인 
    if (taskCount >= MAX_TASKS) {
        std::cout << "할 일 목록이 가득 찼습니다. 더 이상 추가할 수 없습니다.\n";
        return; // 함수 종료
    }

    std::cout << "\n--- 할 일 추가 ---\n";
    std::cout << "새로운 할 일 내용을 입력하세요: ";
    std::getline(std::cin, todoList[taskCount].description); // 할 일 내용 입력 [cite: 4]

    todoList[taskCount].status = PENDING; // 기본 상태는 미완료 
    taskCount++; // 할 일 개수 증가
    std::cout << "할 일이 성공적으로 추가되었습니다.\n";
}

// 2. 할 일 목록 보기 기능
void listTasks() {
    if (taskCount == 0) {
        std::cout << "\n등록된 할 일이 없습니다.\n";
        return;
    }

    std::cout << "\n--- 할 일 목록 ---\n";
    // for 루프를 사용하여 모든 할 일 출력 
    for (int i = 0; i < taskCount; ++i) {
        std::cout << i + 1 << ". "; // 1부터 시작하는 번호 표시 
        std::cout << todoList[i].description << " ["; // 할 일 내용 [cite: 132]
        // 할 일 상태에 따라 "미완료" 또는 "완료" 출력 
        if (todoList[i].status == PENDING) {
            std::cout << "미완료";
        } else {
            std::cout << "완료";
        }
        std::cout << "]\n";
    }
}

// 3. 할 일 완료 처리 기능
void markTaskCompleted() {
    if (taskCount == 0) {
        std::cout << "\n등록된 할 일이 없어 완료 처리할 수 없습니다.\n";
        return;
    }

    listTasks(); // 현재 할 일 목록을 먼저 보여줌

    int taskNumber;
    std::cout << "완료할 할 일의 번호를 입력하세요: ";
    std::cin >> taskNumber;
    clearInputBuffer();

    // 입력된 번호가 유효한 범위(1 ~ taskCount)인지 확인 
    if (taskNumber < 1 || taskNumber > taskCount) {
        std::cout << "잘못된 할 일 번호입니다. 다시 확인해주세요.\n";
        return;
    }

    // 배열 인덱스는 0부터 시작하므로 입력받은 번호에서 1을 뺌 
    int index = taskNumber - 1;
    if (todoList[index].status == COMPLETED) {
        std::cout << "이미 완료된 할 일입니다.\n";
    } else {
        todoList[index].status = COMPLETED; // 상태를 완료로 변경 
        std::cout << "\"" << todoList[index].description << "\"이(가) 완료 처리되었습니다.\n";
    }
}

// --- 추가된 코드 끝 ---