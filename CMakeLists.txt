cmake_minimum_required(VERSION 3.10)
project(CppLearningProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Google Test 설정
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# 메인 소스 파일들
set(MAIN_SOURCES
    src/01.beggin/main.cpp
    src/01.beggin/util.cpp
    src/02.syntax_output_commnets/_syntax.cpp
    src/02.syntax_output_commnets/_output.cpp
    src/02.syntax_output_commnets/_comment.cpp
)

# Core 시스템 소스 파일들
set(CORE_SOURCES
    src/core/Character.cpp
    src/core/QuizSystem.cpp
    src/core/LearningModule.cpp
    src/core/Utils.cpp
)

# 테스트 소스 파일들
set(TEST_SOURCES
    tests/test_character_system.cpp
    tests/test_quiz_system.cpp
    tests/test_learning_modules.cpp
    tests/test_utils.cpp
)

# 메인 실행 파일
add_executable(cpp_learning ${MAIN_SOURCES})

# 테스트 실행 파일
enable_testing()
add_executable(cpp_learning_tests ${TEST_SOURCES} ${CORE_SOURCES})
target_link_libraries(cpp_learning_tests gtest gtest_main)

# 테스트 등록
include(GoogleTest)
gtest_discover_tests(cpp_learning_tests) 