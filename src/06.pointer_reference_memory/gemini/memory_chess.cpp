#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

// 메모리 체스판의 한 칸을 나타내는 구조체
struct Cell {
    char type; // 'V': Variable, 'P': Pointer, 'R': Reference, 'E': Empty
    int value; // 변수의 값 (해당 칸이 변수일 경우)
    int target_id; // 포인터/레퍼런스가 가리키는 변수의 ID
    bool is_linked; // 이미 연결되었는지 여부
};

// 게임 보드 및 상태를 관리하는 구조체
struct GameState {
    std::vector<std::vector<Cell>> board;
    int cursor_x;
    int cursor_y;
    int selected_x;
    int selected_y;
};

// 보드를 초기화하는 함수
void initializeBoard(GameState& state) {
    state.board.assign(8, std::vector<Cell>(8, {'E', 0, -1, false}));
    state.cursor_x = 0;
    state.cursor_y = 0;
    state.selected_x = -1;
    state.selected_y = -1;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 7);

    // 변수, 포인터, 레퍼런스 쌍을 생성하고 보드에 무작위 배치
    for (int i = 0; i < 4; ++i) {
        int var_id = i;
        int var_x, var_y, ptr_x, ptr_y, ref_x, ref_y;

        // 변수 위치
        do {
            var_x = dis(gen);
            var_y = dis(gen);
        } while (state.board[var_y][var_x].type != 'E');
        state.board[var_y][var_x] = {'V', 100 + i, var_id, false};

        // 포인터 위치
        do {
            ptr_x = dis(gen);
            ptr_y = dis(gen);
        } while (state.board[ptr_y][ptr_x].type != 'E');
        state.board[ptr_y][ptr_x] = {'P', 0, var_id, false};

        // 레퍼런스 위치 (레퍼런스는 실제 변수 주소를 직접 가리키는 것처럼 구현)
        do {
            ref_x = dis(gen);
            ref_y = dis(gen);
        } while (state.board[ref_y][ref_x].type != 'E');
        state.board[ref_y][ref_x] = {'R', 0, var_id, false};
    }
}

// 보드를 그리는 함수
void drawBoard(const GameState& state) {
    system("cls || clear");
    std::cout << "--- Memory Chess Game ---" << std::endl;
    std::cout << "Move the cursor to connect 'V' (variable), 'P' (pointer), and 'R' (reference)." << std::endl;
    std::cout << "Move : WASD , Select : Enter , Quit : Q" << std::endl;
    std::cout << "-------------------------" << std::endl;

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            char symbol = state.board[y][x].type;
            if (state.board[y][x].is_linked) {
                symbol = '✅';
            }
            if (state.cursor_x == x && state.cursor_y == y) {
                std::cout << "[" << symbol << "] ";
            } else if (state.selected_x == x && state.selected_y == y) {
                std::cout << "(" << symbol << ") ";
            } else {
                std::cout << " " << symbol << "  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}

// 게임 로직을 처리하는 함수
void gameLoop(GameState& state) {
    char input;
    bool running = true;
    int linked_count = 0;

    while (running) {
        drawBoard(state);

        std::cout << "Input : ";
        std::cin >> input;

        switch (input) {
            case 'w': state.cursor_y = std::max(0, state.cursor_y - 1); break;
            case 's': state.cursor_y = std::min(7, state.cursor_y + 1); break;
            case 'a': state.cursor_x = std::max(0, state.cursor_x - 1); break;
            case 'd': state.cursor_x = std::min(7, state.cursor_x + 1); break;
            case '\n': // Enter 키 처리
            case ' ':
                if (state.selected_x == -1) {
                    state.selected_x = state.cursor_x;
                    state.selected_y = state.cursor_y;
                } else {
                    Cell& cell1 = state.board[state.selected_y][state.selected_x];
                    Cell& cell2 = state.board[state.cursor_y][state.cursor_x];

                    if (cell1.target_id == cell2.target_id && cell1.target_id != -1 && !cell1.is_linked) {
                        cell1.is_linked = true;
                        cell2.is_linked = true;
                        linked_count += 2;
                        std::cout << "Connection successful!" << std::endl;
                    } else {
                        std::cout << "Connection failed! Please try again." << std::endl;
                    }

                    state.selected_x = -1;
                    state.selected_y = -1;
                    if (linked_count >= 12) { // 4쌍 * 3개 = 12개
                        drawBoard(state);
                        std::cout << "All variables and pointers/references connected! Game win!" << std::endl;
                        running = false;
                    }
                }
                break;
            case 'q':
                running = false;
                break;
        }
    }
}

int main() {
    GameState state;
    initializeBoard(state);
    gameLoop(state);
    return 0;
}