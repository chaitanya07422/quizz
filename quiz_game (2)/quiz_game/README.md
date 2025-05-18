
# 🎮 Console-based Quiz Game in C++

## 📌 Overview

This project is a **terminal-based interactive quiz game** developed in C++. It provides a fun and educational way to answer multiple-choice questions. The game loads questions from a JSON file, interacts with the user, tracks time taken to answer each question, and provides instant feedback using sound. At the end of the quiz, it saves scores to a leaderboard file.

---

## 🧠 Features

✅ JSON-based dynamic question loading  
✅ Multiple-choice questions with 4 options  
✅ Tracks number of attempts and correct answers  
✅ Measures time taken per question  
✅ Audio feedback for correct and incorrect answers  
✅ Persistent leaderboard stored in a text file  
✅ Modular code with OOP principles (using `Quiz` class)

---

## 🧾 File Structure

```
quiz_game/
│
├── assets/
│   └── sounds/
│       ├── correct.wav              # Sound played on correct answer
│       └── wrong.wav                # Sound played on incorrect answer
│
├── data/
│   └── questions.json               # JSON file containing quiz questions
│
├── quiz.h                          # Quiz class header file
├── quiz.cpp                        # Quiz class implementation
├── utils.h                         # Utility function declarations
├── utils.cpp                       # Utility function definitions
├── main.cpp                        # Entry point of the application
├── leaderboard.txt                 # Stores scores of players
└── README.md                       # Project documentation (this file)
```

---

## 🧪 Technologies Used

| Tool/Library         | Purpose                          |
|----------------------|----------------------------------|
| C++17                | Core programming language        |
| nlohmann/json        | JSON parsing in C++              |
| PowerShell           | Audio playback on Windows        |
| Standard Libraries   | I/O, chrono, vector, iomanip     |

---

## 🔧 Setup Instructions

### 1. ✅ Prerequisites

- OS: Windows (recommended due to PowerShell-based sound)
- C++17 or later compiler (e.g., `g++`, `MSVC`)
- Install [nlohmann/json](https://github.com/nlohmann/json) or include the header-only file (`json.hpp`)

---

### 2. 📥 Clone or Download Project

```bash
git clone https://github.com/yourusername/quiz_game.git
cd quiz_game
```

---

### 3. 🏗️ Build the Project

Using `g++` (ensure you're using C++17):

```bash
g++ -std=c++17 main.cpp quiz.cpp utils.cpp -o quiz_game
```

If using `MSVC` on Windows:

```cmd
cl /std:c++17 main.cpp quiz.cpp utils.cpp
```

---

### 4. 🚀 Run the Game

```bash
./quiz_game
```

---

## 💡 Sample `questions.json`

Here is an example of how your `data/questions.json` file should look:

```json
[
  {
    "question": "Which planet is known as the Red Planet?",
    "options": ["Earth", "Mars", "Jupiter", "Saturn"],
    "answer": 1
  },
  {
    "question": "What is the capital of India?",
    "options": ["Mumbai", "New Delhi", "Kolkata", "Chennai"],
    "answer": 1
  }
]
```

📝 **Note:**  
- The `answer` field is **zero-indexed** (i.e., `1` = 2nd option).
- You can add as many questions as you want in the same format.

---

## 🔊 Sound Support

The game plays sounds using PowerShell commands:

```cpp
(New-Object Media.SoundPlayer 'path_to_file.wav').PlaySync();
```

Make sure:
- You're running the program on Windows.
- `correct.wav` and `wrong.wav` are placed under `assets/sounds/`.

---

## 📈 Leaderboard

After completing the quiz, the player's name and score are appended to `leaderboard.txt`:

```
Jaswanth 4
Priya 3
Anil 5
```

Leaderboard gets displayed at the end of the quiz.

---

## 🧼 Clean Code Principles Used

- Object-Oriented Programming (`Quiz` class)
- File I/O abstraction
- Modular design: logic is separated across `quiz.cpp`, `utils.cpp`, and `main.cpp`
- Usage of modern C++ features (`auto`, `chrono`, `vector`, smart types)

---

## 🧩 Potential Improvements

- [ ] Shuffle questions randomly  
- [ ] Add difficulty levels (easy/medium/hard)  
- [ ] Add support for Linux/macOS (e.g., using SDL or SFML for sound)  
- [ ] GUI version using Qt or wxWidgets  
- [ ] Timer-based scoring system  

---

## 👨‍💻 Author

**Kadavakollu  chaitanya**  
🎓 Electronics and Communication Engineering, Vignan's Institute of Information Technology  
🏅 NASA Hackton Finalist | AI & ML Enthusiast

---

## 📜 License

This project is open-source and free to use under the [MIT License](LICENSE).
