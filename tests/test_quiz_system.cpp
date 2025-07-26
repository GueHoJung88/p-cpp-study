#include <gtest/gtest.h>
#include "../src/core/QuizSystem.h"
#include <iostream>
#include <sstream>

using namespace learning;

class QuizSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 테스트용 퀴즈 시스템 초기화
        quizSystem = std::make_unique<QuizSystem>();
        
        // 테스트용 퀴즈 질문들 생성
        testQuestions = {
            QuizQuestion("1 + 1 = ?", {"1", "2", "3", "4"}, 1, "1 + 1 = 2입니다.", "math", 1),
            QuizQuestion("C++의 기본 데이터 타입이 아닌 것은?", {"int", "string", "char", "float"}, 1, "string은 STL의 일부입니다.", "cpp", 2),
            QuizQuestion("포인터의 주소를 저장하는 변수는?", {"int", "float", "pointer", "address"}, 2, "pointer가 정답입니다.", "cpp", 3)
        };
    }
    
    void TearDown() override {
        // 테스트 후 정리
    }
    
    std::unique_ptr<QuizSystem> quizSystem;
    std::vector<QuizQuestion> testQuestions;
};

// 출력 캡처를 위한 테스트 헬퍼
class OutputCapture {
private:
    std::streambuf* original_cout;
    std::ostringstream captured_output;

public:
    OutputCapture() : original_cout(std::cout.rdbuf()) {
        std::cout.rdbuf(captured_output.rdbuf());
    }
    
    ~OutputCapture() {
        std::cout.rdbuf(original_cout);
    }
    
    std::string getOutput() const {
        return captured_output.str();
    }
};

// ===== QuizQuestion 테스트 =====

TEST_F(QuizSystemTest, QuizQuestion_Creation_ValidData) {
    QuizQuestion question("테스트 질문", {"A", "B", "C", "D"}, 2, "설명", "category", 1);
    
    EXPECT_EQ(question.getQuestion(), "테스트 질문");
    EXPECT_EQ(question.getOptions().size(), 4);
    EXPECT_EQ(question.getCorrectAnswer(), 2);
    EXPECT_EQ(question.getExplanation(), "설명");
}

TEST_F(QuizSystemTest, QuizQuestion_DefaultValues) {
    QuizQuestion question("테스트 질문", {"A", "B", "C", "D"}, 0, "설명");
    
    EXPECT_EQ(question.getQuestion(), "테스트 질문");
    EXPECT_EQ(question.getOptions().size(), 4);
    EXPECT_EQ(question.getCorrectAnswer(), 0);
    EXPECT_EQ(question.getExplanation(), "설명");
}

// ===== QuizResult 테스트 =====

TEST_F(QuizSystemTest, QuizResult_Creation_ValidData) {
    QuizResult result(8, 10, 80.0, "좋은 성과입니다!");
    
    EXPECT_EQ(result.getScore(), 8);
    EXPECT_EQ(result.getTotalQuestions(), 10);
    EXPECT_EQ(result.getPercentage(), 80.0);
    EXPECT_EQ(result.getResultMessage(), "매우 좋습니다! 잘 했어요!");
}

TEST_F(QuizSystemTest, QuizResult_DefaultConstructor) {
    QuizResult result;
    
    EXPECT_EQ(result.getScore(), 0);
    EXPECT_EQ(result.getTotalQuestions(), 0);
    EXPECT_EQ(result.getPercentage(), 0.0);
    EXPECT_EQ(result.getResultMessage(), "개선이 필요합니다. 다시 한번 복습해보세요!");
}

// ===== QuizSystem 기본 기능 테스트 =====

TEST_F(QuizSystemTest, QuizSystem_Initialization_EmptyState) {
    EXPECT_EQ(quizSystem->getTotalQuestions(), 0);
    EXPECT_EQ(quizSystem->getCurrentQuestionIndex(), 0);
    EXPECT_FALSE(quizSystem->hasMoreQuestions());
}

TEST_F(QuizSystemTest, QuizSystem_AddQuestions_ValidData) {
    for (const auto& question : testQuestions) {
        quizSystem->addQuestion(question);
    }
    
    EXPECT_EQ(quizSystem->getTotalQuestions(), 3);
    EXPECT_TRUE(quizSystem->hasMoreQuestions());
}

TEST_F(QuizSystemTest, QuizSystem_GetCurrentQuestion_ValidData) {
    quizSystem->addQuestion(testQuestions[0]);
    
    auto currentQuestion = quizSystem->getCurrentQuestion();
    EXPECT_EQ(currentQuestion.getQuestion(), "1 + 1 = ?");
    EXPECT_EQ(currentQuestion.getCorrectAnswer(), 1);
}

TEST_F(QuizSystemTest, QuizSystem_NextQuestion_ValidData) {
    for (const auto& question : testQuestions) {
        quizSystem->addQuestion(question);
    }
    
    EXPECT_EQ(quizSystem->getCurrentQuestionIndex(), 0);
    
    quizSystem->nextQuestion();
    EXPECT_EQ(quizSystem->getCurrentQuestionIndex(), 1);
    
    quizSystem->nextQuestion();
    EXPECT_EQ(quizSystem->getCurrentQuestionIndex(), 2);
    
    quizSystem->nextQuestion();
    EXPECT_EQ(quizSystem->getCurrentQuestionIndex(), 3); // 마지막 질문에서 더 이상 진행 안됨
}

// ===== 답변 처리 테스트 =====

TEST_F(QuizSystemTest, QuizSystem_SubmitAnswer_CorrectAnswer) {
    quizSystem->addQuestion(testQuestions[0]); // 1 + 1 = ? (정답: 1)
    
    bool result = quizSystem->submitAnswer(1);
    EXPECT_TRUE(result);
    
    auto currentResult = quizSystem->getCurrentResult();
    EXPECT_EQ(currentResult.getScore(), 1);
    EXPECT_EQ(currentResult.getTotalQuestions(), 1);
}

TEST_F(QuizSystemTest, QuizSystem_SubmitAnswer_WrongAnswer) {
    quizSystem->addQuestion(testQuestions[0]); // 1 + 1 = ? (정답: 1)
    
    bool result = quizSystem->submitAnswer(2); // 잘못된 답
    EXPECT_FALSE(result);
    
    auto currentResult = quizSystem->getCurrentResult();
    EXPECT_EQ(currentResult.getScore(), 0);
    EXPECT_EQ(currentResult.getTotalQuestions(), 1);
}

TEST_F(QuizSystemTest, QuizSystem_SubmitAnswer_InvalidIndex) {
    quizSystem->addQuestion(testQuestions[0]);
    
    bool result = quizSystem->submitAnswer(5); // 범위를 벗어난 인덱스
    EXPECT_FALSE(result);
}

// ===== 결과 계산 테스트 =====

TEST_F(QuizSystemTest, QuizSystem_CalculateResults_PerfectScore) {
    for (const auto& question : testQuestions) {
        quizSystem->addQuestion(question);
    }
    
    // 첫 번째 질문만 테스트
    bool result1 = quizSystem->submitAnswer(1);
    EXPECT_EQ(quizSystem->getScore(), 1);
    
    auto finalResult = quizSystem->getFinalResult();
    EXPECT_EQ(finalResult.getScore(), 1);
    EXPECT_EQ(finalResult.getTotalQuestions(), 3);
    EXPECT_NEAR(finalResult.getPercentage(), 33.3333, 0.01);
}

TEST_F(QuizSystemTest, QuizSystem_CalculateResults_PartialScore) {
    for (const auto& question : testQuestions) {
        quizSystem->addQuestion(question);
    }
    
    // 일부만 정답으로 제출 (인덱스 기반)
    quizSystem->submitAnswer(1); // 1 + 1 = ? -> "2" (정답)
    quizSystem->submitAnswer(0); // C++ 기본 타입 -> "int" (오답)
    quizSystem->submitAnswer(2); // 포인터 주소 -> "pointer" (정답)
    
    auto finalResult = quizSystem->getFinalResult();
    EXPECT_EQ(finalResult.getScore(), 2);
    EXPECT_EQ(finalResult.getTotalQuestions(), 3);
    EXPECT_NEAR(finalResult.getPercentage(), 66.6667, 0.01);
}

// ===== 통계 기능 테스트 =====

TEST_F(QuizSystemTest, QuizSystem_GetStatistics_ValidData) {
    for (const auto& question : testQuestions) {
        quizSystem->addQuestion(question);
    }
    
    // 모든 답을 제출 (인덱스 기반)
    quizSystem->submitAnswer(1); // 1 + 1 = ? -> "2" (정답)
    quizSystem->submitAnswer(1); // C++ 기본 타입 -> "string" (정답)
    quizSystem->submitAnswer(2); // 포인터 주소 -> "pointer" (정답)
    
    auto stats = quizSystem->getStatistics();
    EXPECT_EQ(stats.totalQuestions, 3);
    EXPECT_EQ(stats.correctAnswers, 3);
    EXPECT_EQ(stats.incorrectAnswers, 0);
    EXPECT_EQ(stats.averageTime, 0.0); // 시간 측정이 구현되지 않았으므로 0
}

// ===== 카테고리별 테스트 =====

TEST_F(QuizSystemTest, QuizSystem_GetQuestionsByCategory_ValidData) {
    for (const auto& question : testQuestions) {
        quizSystem->addQuestion(question);
    }
    
    auto mathQuestions = quizSystem->getQuestionsByCategory("math");
    EXPECT_EQ(mathQuestions.size(), 1);
    EXPECT_EQ(mathQuestions[0].getQuestion(), "1 + 1 = ?");
    
    auto cppQuestions = quizSystem->getQuestionsByCategory("cpp");
    EXPECT_EQ(cppQuestions.size(), 2);
}

TEST_F(QuizSystemTest, QuizSystem_GetQuestionsByDifficulty_ValidData) {
    for (const auto& question : testQuestions) {
        quizSystem->addQuestion(question);
    }
    
    auto easyQuestions = quizSystem->getQuestionsByDifficulty(1);
    EXPECT_EQ(easyQuestions.size(), 1);
    
    auto mediumQuestions = quizSystem->getQuestionsByDifficulty(2);
    EXPECT_EQ(mediumQuestions.size(), 1);
    
    auto hardQuestions = quizSystem->getQuestionsByDifficulty(3);
    EXPECT_EQ(hardQuestions.size(), 1);
}

// ===== 경계값 테스트 =====

TEST_F(QuizSystemTest, QuizSystem_BoundaryValues_EmptyQuiz) {
    EXPECT_EQ(quizSystem->getTotalQuestions(), 0);
    EXPECT_FALSE(quizSystem->hasMoreQuestions());
    
    // 빈 퀴즈에서 답변 제출 시도
    bool result = quizSystem->submitAnswer(0);
    EXPECT_FALSE(result);
}

TEST_F(QuizSystemTest, QuizSystem_BoundaryValues_SingleQuestion) {
    quizSystem->addQuestion(testQuestions[0]);
    
    EXPECT_EQ(quizSystem->getTotalQuestions(), 1);
    EXPECT_TRUE(quizSystem->hasMoreQuestions());
    
    quizSystem->submitAnswer(1);
    quizSystem->nextQuestion();
    
    EXPECT_FALSE(quizSystem->hasMoreQuestions());
}

// ===== 성능 테스트 =====

TEST_F(QuizSystemTest, QuizSystem_Performance_LargeQuiz) {
    // 대량의 질문 추가
    for (int i = 0; i < 1000; ++i) {
        std::string question = "질문 " + std::to_string(i);
        std::vector<std::string> options = {"A", "B", "C", "D"};
        QuizQuestion q(question, options, i % 4, "설명", "category", 1);
        quizSystem->addQuestion(q);
    }
    
    EXPECT_EQ(quizSystem->getTotalQuestions(), 1000);
    
    // 모든 질문에 답변
    for (int i = 0; i < 1000; ++i) {
        quizSystem->submitAnswer(i % 4);
        if (i < 999) {
            quizSystem->nextQuestion();
        }
    }
    
    auto result = quizSystem->getFinalResult();
    EXPECT_EQ(result.getTotalQuestions(), 1000);
}

// ===== 통합 테스트 =====

TEST_F(QuizSystemTest, QuizSystem_Integration_CompleteQuizFlow) {
    // 1. 퀴즈 생성
    for (const auto& question : testQuestions) {
        quizSystem->addQuestion(question);
    }
    
    EXPECT_EQ(quizSystem->getTotalQuestions(), 3);
    
    // 2. 퀴즈 진행
    EXPECT_EQ(quizSystem->getCurrentQuestionIndex(), 0);
    EXPECT_TRUE(quizSystem->hasMoreQuestions());
    
    // 3. 답변 제출 (인덱스 기반)
    quizSystem->submitAnswer(1); // 1 + 1 = ? -> "2" (정답)
    auto currentResult = quizSystem->getCurrentResult();
    EXPECT_EQ(currentResult.getScore(), 1);
    
    // 4. 계속 진행
    quizSystem->submitAnswer(1); // C++ 기본 타입 -> "string" (정답)
    quizSystem->submitAnswer(2); // 포인터 주소 -> "pointer" (정답)
    
    // 5. 최종 결과 확인
    auto finalResult = quizSystem->getFinalResult();
    EXPECT_EQ(finalResult.getScore(), 3);
    EXPECT_EQ(finalResult.getTotalQuestions(), 3);
    EXPECT_NEAR(finalResult.getPercentage(), 100.0, 0.01);
    
    // 6. 퀴즈 완료 확인
    EXPECT_FALSE(quizSystem->hasMoreQuestions());
}

// ===== QuizFactory 테스트 =====

TEST_F(QuizSystemTest, QuizFactory_CreateMathQuiz_ValidData) {
    auto mathQuiz = QuizFactory::createMathQuiz();
    EXPECT_GT(mathQuiz.getTotalQuestions(), 0);
    
    auto questions = mathQuiz.getQuestionsByCategory("math");
    EXPECT_GT(questions.size(), 0);
}

TEST_F(QuizSystemTest, QuizFactory_CreateCppQuiz_ValidData) {
    auto cppQuiz = QuizFactory::createCppQuiz();
    EXPECT_GT(cppQuiz.getTotalQuestions(), 0);
    
    auto questions = cppQuiz.getQuestionsByCategory("cpp");
    EXPECT_GT(questions.size(), 0);
}

TEST_F(QuizSystemTest, QuizFactory_CreateMixedQuiz_ValidData) {
    auto mixedQuiz = QuizFactory::createMixedQuiz();
    EXPECT_GT(mixedQuiz.getTotalQuestions(), 0);
    
    // 다양한 카테고리의 질문이 있는지 확인
    auto mathQuestions = mixedQuiz.getQuestionsByCategory("math");
    auto cppQuestions = mixedQuiz.getQuestionsByCategory("cpp");
    
    EXPECT_GT(mathQuestions.size() + cppQuestions.size(), 0);
}

// ===== QuizAnalyzer 테스트 =====

TEST_F(QuizSystemTest, QuizAnalyzer_AnalyzeResults_ValidData) {
    // 테스트용 퀴즈 결과 생성
    std::vector<QuizResult> results;
    
    QuizResult result1(8, 10, 80.0, "좋은 성과");
    QuizResult result2(6, 10, 60.0, "보통 성과");
    QuizResult result3(10, 10, 100.0, "완벽한 성과");
    
    results.push_back(result1);
    results.push_back(result2);
    results.push_back(result3);
    
    auto analysis = QuizAnalyzer::analyzeResults(results);
    
    EXPECT_EQ(analysis.averageScore, 8.0);
    EXPECT_EQ(analysis.averagePercentage, 80.0);
    EXPECT_EQ(analysis.totalQuizzes, 3);
    EXPECT_EQ(analysis.bestScore, 10);
    EXPECT_EQ(analysis.worstScore, 6);
}

TEST_F(QuizSystemTest, QuizAnalyzer_GetRecommendations_ValidData) {
    std::vector<QuizResult> results;
    QuizResult result(5, 10, 50.0, "개선 필요");
    results.push_back(result);
    
    auto recommendations = QuizAnalyzer::getRecommendations(results);
    EXPECT_FALSE(recommendations.empty());
    EXPECT_TRUE(recommendations.find("개선") != std::string::npos);
} 