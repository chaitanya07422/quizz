#include "quiz.h"               // Header file for Quiz class definition
#include "utils.h"              // Header file for utility functions (like sound)
#include <iostream>             // For input/output operations
#include <fstream>              // For file handling
#include <iomanip>              // For formatting output (e.g., fixed precision)
#include <nlohmann/json.hpp>    // JSON library for reading quiz questions
#include <cstdlib>              // For system commands (e.g., to play sounds)

using json = nlohmann::json;   // Alias for using nlohmann's json type
using namespace std;
using namespace std::chrono;   // For timing the user’s response

// Constructor: Initializes score and attempts, and loads questions from file
Quiz::Quiz(const std::string& filename) : score(0), attempts(0) {
    loadQuestions(filename); // Load quiz questions from the given JSON file
}

// Function to load quiz questions from a JSON file
void Quiz::loadQuestions(const std::string& filename) {
    ifstream file(filename);  // Open the JSON file
    json j;
    file >> j;                // Parse the JSON content

    // Loop through each item (question) in the JSON array
    for (const auto& item : j) {
        Question q;
        q.question = item["question"];                            // Extract question text
        q.options = item["options"].get<vector<string>>();        // Extract options as a vector
        q.answer = item["answer"];                                // Extract the correct answer index
        questions.push_back(q);                                   // Add the question to the list
    }
}

// Main quiz logic
void Quiz::start() {
    string name;
    cout << "Enter your name: ";
    cin >> name;  // Get player name

    // Loop through all questions
    for (const auto& q : questions) {
        attempts++;  // Increment total question attempts
        cout << "\nQ: " << q.question << "\n";

        // Display options
        for (size_t i = 0; i < q.options.size(); ++i) {
            cout << i + 1 << ") " << q.options[i] << "\n";
        }

        int choice;
        // Record time before and after user input to calculate response time
        auto start = high_resolution_clock::now();
        cout << "Your choice (1-4): ";
        cin >> choice;
        auto end = high_resolution_clock::now();

        // Calculate time taken to answer
        double timeTaken = duration<double>(end - start).count();

        // Check if the user's choice is correct
        if (choice - 1 == q.answer) {
            cout << "Correct!\n";
            playSound(true);  // Play correct answer sound
            score++;          // Increment score
        } else {
            cout << "Wrong! Correct answer: " << q.options[q.answer] << "\n";
            playSound(false); // Play wrong answer sound
        }

        // Display time taken for this question
        cout << "Time taken: " << fixed << setprecision(2) << timeTaken << " seconds\n";
    }

    // Show final results
    cout << "\n=== Quiz Over ===\n";
    cout << "Player: " << name << "\n";
    cout << "Score: " << score << "/" << attempts << "\n";

    // Save the player's score and print the leaderboard
    updateLeaderboard(name);
    printLeaderboard("leaderboard.txt");
}

// Function to play a sound for correct or wrong answer
void Quiz::playSound(bool correct) {
    // Choose the appropriate sound file
    string file = correct ? "assets/sounds/correct.wav" : "assets/sounds/wrong.wav";

    // Use PowerShell command to play the sound synchronously
    string cmd = "powershell -c (New-Object Media.SoundPlayer '" + file + "').PlaySync();";
    system(cmd.c_str());  // Execute the command
}

// Function to update the leaderboard file with the user's name and score
void Quiz::updateLeaderboard(const string& username) {
    ofstream file("leaderboard.txt", ios::app);  // Open leaderboard file in append mode
    file << username << " " << score << "\n";    // Write name and score
    file.close();                                // Close the file
}
