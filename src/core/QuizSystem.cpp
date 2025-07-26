#include "QuizSystem.h"
#include <iostream>
#include <algorithm>

namespace learning {

// QuizQuestion 구현
std::string QuizQuestion::getQuestion() const {
    return question;
}

std::vector<std::string> QuizQuestion::getOptions() const {
    return options;
}

int QuizQuestion::getCorrectAnswer() const {
    return correctAnswer;
}

std::string QuizQuestion::getExplanation() const {
    return explanation;
}

// QuizResult 구현
QuizResult::QuizResult(int score, int total, double percentage, const std::string& message)
    : totalQuestions(total), correctAnswers(score), percentage(percentage), grade("F") {}

int QuizResult::getScore() const {
    return correctAnswers;
}

int QuizResult::getTotalQuestions() const {
    return totalQuestions;
}

double QuizResult::getPercentage() const {
    return percentage;
}

std::string QuizResult::getResultMessage() const {
    if (percentage >= 90.0) return "완벽합니다! 훌륭한 성과입니다!";
    else if (percentage >= 80.0) return "매우 좋습니다! 잘 했어요!";
    else if (percentage >= 70.0) return "좋습니다! 더 노력해보세요!";
    else if (percentage >= 60.0) return "보통입니다. 더 공부가 필요해요!";
    else return "개선이 필요합니다. 다시 한번 복습해보세요!";
}

// QuizSystem 구현
QuizSystem::QuizSystem() : currentQuestionIndex(0), score(0) {}

void QuizSystem::addQuestion(const QuizQuestion& question) {
    questions.push_back(question);
}

QuizQuestion QuizSystem::getCurrentQuestion() const {
    if (currentQuestionIndex < questions.size()) {
        return questions[currentQuestionIndex];
    }
    return QuizQuestion("", {}, 0, "");
}

bool QuizSystem::submitAnswer(int answer) {
    if (currentQuestionIndex >= questions.size()) {
        return false;
    }
    
    bool isCorrect = (answer == questions[currentQuestionIndex].getCorrectAnswer());
    if (isCorrect) {
        score++;
    }
    
    currentQuestionIndex++;
    return isCorrect;
}

bool QuizSystem::hasNextQuestion() const {
    return currentQuestionIndex < questions.size();
}

void QuizSystem::nextQuestion() {
    if (currentQuestionIndex < questions.size()) {
        currentQuestionIndex++;
    }
}

int QuizSystem::getScore() const {
    return score;
}

int QuizSystem::getTotalQuestions() const {
    return questions.size();
}

double QuizSystem::getPercentage() const {
    if (questions.empty()) return 0.0;
    return (static_cast<double>(score) / questions.size()) * 100.0;
}

std::string QuizSystem::getResultMessage() const {
    double percentage = getPercentage();
    
    if (percentage >= 90.0) {
        return "완벽합니다! 훌륭한 성과입니다!";
    } else if (percentage >= 80.0) {
        return "매우 좋습니다! 잘 했어요!";
    } else if (percentage >= 70.0) {
        return "좋습니다! 더 노력해보세요!";
    } else if (percentage >= 60.0) {
        return "보통입니다. 더 공부가 필요해요!";
    } else {
        return "개선이 필요합니다. 다시 한번 복습해보세요!";
    }
}

// 추가 메서드들 구현
int QuizSystem::getCurrentQuestionIndex() const {
    return currentQuestionIndex;
}

bool QuizSystem::hasMoreQuestions() const {
    return currentQuestionIndex < questions.size();
}

void QuizSystem::reset() {
    currentQuestionIndex = 0;
    score = 0;
}

QuizResult QuizSystem::getCurrentResult() const {
    return QuizResult(score, questions.size(), getPercentage(), getResultMessage());
}

QuizResult QuizSystem::getFinalResult() const {
    return QuizResult(score, questions.size(), getPercentage(), getResultMessage());
}

double QuizSystem::getCurrentPercentage() const {
    return getPercentage();
}

std::string QuizSystem::getCurrentGrade() const {
    double percentage = getPercentage();
    if (percentage >= 90.0) return "A";
    else if (percentage >= 80.0) return "B";
    else if (percentage >= 70.0) return "C";
    else if (percentage >= 60.0) return "D";
    else return "F";
}

QuizStatistics QuizSystem::getStatistics() const {
    QuizStatistics stats;
    stats.totalQuestions = questions.size();
    stats.correctAnswers = score;
    stats.incorrectAnswers = questions.size() - score;
    stats.averageTime = 0.0; // 시간 측정 기능은 나중에 구현
    return stats;
}

std::vector<QuizQuestion> QuizSystem::getQuestionsByCategory(const std::string& category) const {
    std::vector<QuizQuestion> result;
    for (const auto& question : questions) {
        if (question.category == category) {
            result.push_back(question);
        }
    }
    return result;
}

std::vector<QuizQuestion> QuizSystem::getQuestionsByDifficulty(int difficulty) const {
    std::vector<QuizQuestion> result;
    for (const auto& question : questions) {
        if (question.difficulty == difficulty) {
            result.push_back(question);
        }
    }
    return result;
}

// QuizFactory 구현
QuizSystem QuizFactory::createMathQuiz() {
    QuizSystem quiz;
    
    std::vector<QuizQuestion> mathQuestions = {
        QuizQuestion("1 + 1 = ?", {"1", "2", "3", "4"}, 1, "1 + 1 = 2입니다.", "math", 1),
        QuizQuestion("2 * 3 = ?", {"4", "5", "6", "7"}, 2, "2 * 3 = 6입니다.", "math", 1),
        QuizQuestion("10 / 2 = ?", {"3", "4", "5", "6"}, 2, "10 / 2 = 5입니다.", "math", 1),
        QuizQuestion("7 - 3 = ?", {"2", "3", "4", "5"}, 2, "7 - 3 = 4입니다.", "math", 1),
        QuizQuestion("3^2 = ?", {"6", "8", "9", "12"}, 2, "3^2 = 9입니다.", "math", 2)
    };
    
    for (const auto& question : mathQuestions) {
        quiz.addQuestion(question);
    }
    
    return quiz;
}

QuizSystem QuizFactory::createCppQuiz() {
    QuizSystem quiz;
    
    std::vector<QuizQuestion> cppQuestions = {
        QuizQuestion("C++의 기본 데이터 타입이 아닌 것은?", {"int", "string", "char", "float"}, 1, "string은 STL의 일부입니다.", "cpp", 2),
        QuizQuestion("포인터의 주소를 저장하는 변수는?", {"int", "float", "pointer", "address"}, 2, "pointer가 정답입니다.", "cpp", 3),
        QuizQuestion("클래스의 생성자는 언제 호출되는가?", {"객체 생성 시", "객체 소멸 시", "프로그램 시작 시", "프로그램 종료 시"}, 0, "객체가 생성될 때 생성자가 호출됩니다.", "cpp", 2),
        QuizQuestion("C++에서 상속을 나타내는 키워드는?", {"extends", "inherits", ":", "implements"}, 2, "C++에서는 : 를 사용합니다.", "cpp", 2),
        QuizQuestion("가상 함수를 선언하는 키워드는?", {"virtual", "abstract", "override", "final"}, 0, "virtual 키워드를 사용합니다.", "cpp", 3)
    };
    
    for (const auto& question : cppQuestions) {
        quiz.addQuestion(question);
    }
    
    return quiz;
}

QuizSystem QuizFactory::createMixedQuiz() {
    QuizSystem quiz;
    
    // 수학 문제들
    std::vector<QuizQuestion> mathQuestions = {
        QuizQuestion("1 + 1 = ?", {"1", "2", "3", "4"}, 1, "1 + 1 = 2입니다.", "math", 1),
        QuizQuestion("2 * 3 = ?", {"4", "5", "6", "7"}, 2, "2 * 3 = 6입니다.", "math", 1)
    };
    
    // C++ 문제들
    std::vector<QuizQuestion> cppQuestions = {
        QuizQuestion("C++의 기본 데이터 타입이 아닌 것은?", {"int", "string", "char", "float"}, 1, "string은 STL의 일부입니다.", "cpp", 2),
        QuizQuestion("포인터의 주소를 저장하는 변수는?", {"int", "float", "pointer", "address"}, 2, "pointer가 정답입니다.", "cpp", 3)
    };
    
    // 모든 문제 추가
    for (const auto& question : mathQuestions) {
        quiz.addQuestion(question);
    }
    for (const auto& question : cppQuestions) {
        quiz.addQuestion(question);
    }
    
    return quiz;
}

// QuizAnalyzer 구현
QuizAnalysis QuizAnalyzer::analyzeResults(const std::vector<QuizResult>& results) {
    QuizAnalysis analysis;
    
    if (results.empty()) {
        return analysis;
    }
    
    double totalScore = 0.0;
    double totalPercentage = 0.0;
    int bestScore = 0;
    int worstScore = INT_MAX;
    
    for (const auto& result : results) {
        totalScore += result.getScore();
        totalPercentage += result.getPercentage();
        
        if (result.getScore() > bestScore) {
            bestScore = result.getScore();
        }
        if (result.getScore() < worstScore) {
            worstScore = result.getScore();
        }
    }
    
    analysis.averageScore = totalScore / results.size();
    analysis.averagePercentage = totalPercentage / results.size();
    analysis.totalQuizzes = results.size();
    analysis.bestScore = bestScore;
    analysis.worstScore = worstScore;
    
    return analysis;
}

std::string QuizAnalyzer::getRecommendations(const std::vector<QuizResult>& results) {
    if (results.empty()) {
        return "퀴즈 결과가 없습니다.";
    }
    
    double averagePercentage = 0.0;
    for (const auto& result : results) {
        averagePercentage += result.getPercentage();
    }
    averagePercentage /= results.size();
    
    if (averagePercentage >= 90.0) {
        return "훌륭한 성과입니다! 더 높은 수준의 학습을 시도해보세요.";
    } else if (averagePercentage >= 80.0) {
        return "좋은 성과입니다! 약간의 개선이 필요합니다.";
    } else if (averagePercentage >= 70.0) {
        return "보통 수준입니다. 더 많은 연습이 필요합니다.";
    } else if (averagePercentage >= 60.0) {
        return "개선이 필요합니다. 기초를 다시 복습해보세요.";
    } else {
        return "많은 개선이 필요합니다. 체계적인 학습 계획을 세워보세요.";
    }
}

} // namespace learning 