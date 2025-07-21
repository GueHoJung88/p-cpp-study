#include <iostream>
#include <string>
#include <locale>
#include <clocale>

int main() {
    std::setlocale(LC_ALL, ""); // 또는 "en_US.UTF-8"

    std::cout << "유니코드 출력 테스트: 🍖 히히!" << std::endl;
    return 0;
}
