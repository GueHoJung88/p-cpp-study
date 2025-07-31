#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include "Character.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::istringstream;

// 색상 출력 함수들
void printBlue(const string& text) {
    cout << "\033[34m" << text << "\033[0m";
}

void printYellow(const string& text) {
    cout << "\033[33m" << text << "\033[0m";
}

void printGreen(const string& text) {
    cout << "\033[32m" << text << "\033[0m";
}

void printRed(const string& text) {
    cout << "\033[31m" << text << "\033[0m";
}

void printPurple(const string& text) {
    cout << "\033[35m" << text << "\033[0m";
}

void printCyan(const string& text) {
    cout << "\033[36m" << text << "\033[0m";
}

// 테스트용 메인 함수
int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    
    cout << "🐾 ==========================================" << endl;
    cout << "🐾   C++ While Loop 대화형 학습 프로그램" << endl;
    cout << "🐾 ==========================================" << endl;
    
    cout << "프로그램이 정상적으로 시작되었습니다!" << endl;
    cout << "Character.h 파일이 정상적으로 포함되었습니다." << endl;
    
    // 캐릭터 초기화 테스트
    try {
        vector<Character> all_characters = initializeCharacters();
        cout << "캐릭터 초기화 성공! 총 " << all_characters.size() << "개의 캐릭터가 로드되었습니다." << endl;
        
        // 첫 번째 캐릭터 정보 출력
        if (!all_characters.empty()) {
            cout << "첫 번째 캐릭터: " << all_characters[0].name << " (" << all_characters[0].species << ")" << endl;
            all_characters[0].display("happy");
        }
        
    } catch (const std::exception& e) {
        cout << "오류 발생: " << e.what() << endl;
        return 1;
    }
    
    cout << "\n프로그램이 정상적으로 종료됩니다." << endl;
    return 0;
} 