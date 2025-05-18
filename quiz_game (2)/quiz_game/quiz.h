#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>
#include <chrono>

struct Question {
    std::string question;
    std::vector<std::string> options;
    int answer;
};

class Quiz {
public:
    Quiz(const std::string& filename);
    void start();
private:
    std::vector<Question> questions;
    int score;
    int attempts;
    void loadQuestions(const std::string& filename);
    void playSound(bool correct);
    void updateLeaderboard(const std::string& username);
};

#endif