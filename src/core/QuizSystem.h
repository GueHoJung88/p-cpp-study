#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <map>

namespace learning {

// 퀴즈 질문 클래스
class QuizQuestion {
public:
    std::string question;
    std::vector<std::string> options;
    int correctAnswer;
    std::string explanation;
    std::string category;
    int difficulty;
    
    QuizQuestion(const std::string& q, const std::vector<std::string>& opts, 
                 int correct, const std::string& exp, const std::string& cat = "general", int diff = 1)
        : question(q), options(opts), correctAnswer(correct), explanation(exp), category(cat), difficulty(diff) {}
    
    // 접근자 메서드들
    std::string getQuestion() const;
    std::vector<std::string> getOptions() const;
    int getCorrectAnswer() const;
    std::string getExplanation() const;
};

// 퀴즈 결과 클래스
class QuizResult {
public:
    int totalQuestions;
    int correctAnswers;
    double percentage;
    std::string grade;
    std::vector<bool> answers;
    std::vector<int> timeSpent; // 초 단위
    
    QuizResult() : totalQuestions(0), correctAnswers(0), percentage(0.0), grade("F") {}
    QuizResult(int score, int total, double percentage, const std::string& message);
    
    // 접근자 메서드들
    int getScore() const;
    int getTotalQuestions() const;
    double getPercentage() const;
    std::string getResultMessage() const;
};

// 퀴즈 통계 구조체
struct QuizStatistics {
    int totalQuestions;
    int correctAnswers;
    int incorrectAnswers;
    double averageTime;
    
    QuizStatistics() : totalQuestions(0), correctAnswers(0), incorrectAnswers(0), averageTime(0.0) {}
};

// 퀴즈 분석 결과 구조체
struct QuizAnalysis {
    double averageScore;
    double averagePercentage;
    int totalQuizzes;
    int bestScore;
    int worstScore;
    
    QuizAnalysis() : averageScore(0.0), averagePercentage(0.0), totalQuizzes(0), bestScore(0), worstScore(0) {}
};

// 퀴즈 시스템 클래스
class QuizSystem {
private:
    std::vector<QuizQuestion> questions;
    int currentQuestionIndex;
    int score;
    bool isActive;
    
    // 콜백 함수들
    std::function<void(const QuizQuestion&)> onQuestionStart;
    std::function<void(bool, const std::string&)> onAnswerSubmit;
    std::function<void(const QuizResult&)> onQuizComplete;
    
public:
    QuizSystem();
    
    // 퀴즈 관리
    void addQuestion(const QuizQuestion& question);
    void addQuestions(const std::vector<QuizQuestion>& questions);
    void clearQuestions();
    
    // 퀴즈 실행
    void startQuiz();
    void pauseQuiz();
    void resumeQuiz();
    void endQuiz();
    
    // 질문 관리
    QuizQuestion getCurrentQuestion() const;
    QuizQuestion getQuestion(int index) const;
    bool hasNextQuestion() const;
    bool hasMoreQuestions() const;
    void nextQuestion();
    void previousQuestion();
    void goToQuestion(int index);
    
    // 답변 처리
    bool submitAnswer(int answer);
    bool submitAnswer(const std::string& answer);
    void skipQuestion();
    
    // 결과 관리
    QuizResult getCurrentResult() const;
    QuizResult getFinalResult() const;
    double getCurrentPercentage() const;
    std::string getCurrentGrade() const;
    int getScore() const;
    double getPercentage() const;
    std::string getResultMessage() const;
    
    // 통계
    QuizStatistics getStatistics() const;
    
    // 통계
    int getTotalQuestions() const;
    int getCurrentQuestionIndex() const;
    int getCorrectAnswers() const;
    bool isQuizActive() const;
    
    // 콜백 설정
    void setOnQuestionStart(std::function<void(const QuizQuestion&)> callback);
    void setOnAnswerSubmit(std::function<void(bool, const std::string&)> callback);
    void setOnQuizComplete(std::function<void(const QuizResult&)> callback);
    
    // 유틸리티
    void reset();
    std::vector<QuizQuestion> getQuestionsByCategory(const std::string& category) const;
    std::vector<QuizQuestion> getQuestionsByDifficulty(int difficulty) const;
};

// 퀴즈 팩토리 클래스
class QuizFactory {
public:
    // 기본 퀴즈 생성
    static QuizSystem createMathQuiz();
    static QuizSystem createCppQuiz();
    static QuizSystem createMixedQuiz();
    
    // 기본 퀴즈 생성
    static std::vector<QuizQuestion> createBasicVariableQuiz();
    static std::vector<QuizQuestion> createBasicInputQuiz();
    static std::vector<QuizQuestion> createBasicOperatorQuiz();
    static std::vector<QuizQuestion> createBasicStringQuiz();
    
    // 고급 퀴즈 생성
    static std::vector<QuizQuestion> createAdvancedCppQuiz();
    static std::vector<QuizQuestion> createLogicQuiz();
    static std::vector<QuizQuestion> createProblemSolvingQuiz();
    
    // 커스텀 퀴즈 생성
    static std::vector<QuizQuestion> createCustomQuiz(const std::string& category, int difficulty);
    
    // 퀴즈 로드 (JSON 등에서)
    static std::vector<QuizQuestion> loadQuizFromFile(const std::string& filename);
    static bool saveQuizToFile(const std::vector<QuizQuestion>& questions, const std::string& filename);
};

// 퀴즈 분석기 클래스
class QuizAnalyzer {
public:
    // 기본 분석
    static QuizAnalysis analyzeResults(const std::vector<QuizResult>& results);
    static std::string getRecommendations(const std::vector<QuizResult>& results);
    
    // 성과 분석
    static std::string analyzePerformance(const QuizResult& result);
    static std::vector<std::string> getWeakAreas(const QuizResult& result, const std::vector<QuizQuestion>& questions);
    static std::vector<std::string> getStrongAreas(const QuizResult& result, const std::vector<QuizQuestion>& questions);
    
    // 추천 시스템
    static std::vector<QuizQuestion> recommendNextQuestions(const QuizResult& result, const std::vector<QuizQuestion>& availableQuestions);
    static int recommendDifficulty(const QuizResult& result);
    
    // 통계 생성
    static std::map<std::string, double> generateCategoryStats(const QuizResult& result, const std::vector<QuizQuestion>& questions);
    static std::map<int, double> generateDifficultyStats(const QuizResult& result, const std::vector<QuizQuestion>& questions);
};

} // namespace learning 