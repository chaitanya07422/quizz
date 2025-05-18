#include "quiz.h"

int main() {
    Quiz quiz("data/questions.json");
    quiz.start();
    return 0;
}