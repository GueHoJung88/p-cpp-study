cmake_minimum_required(VERSION 3.10)
project(CharacterGamification)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 소스 파일들
set(SOURCES
    main.cpp
    CharacterSelector.cpp
)

# 헤더 파일들
set(HEADERS
    CharacterSelector.h
)

# 실행 파일 생성
add_executable(character_gamification ${SOURCES} ${HEADERS})

# core 라이브러리 링크
target_link_libraries(character_gamification core)

# include 디렉토리 설정
target_include_directories(character_gamification PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../core
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 컴파일 옵션
if(MSVC)
    target_compile_options(character_gamification PRIVATE /W4)
else()
    target_compile_options(character_gamification PRIVATE -Wall -Wextra -Wpedantic)
endif() 