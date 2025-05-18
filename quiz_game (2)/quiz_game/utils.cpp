#include "utils.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Entry {
    string name;
    int score;
};

bool compare(const Entry& a, const Entry& b) {
    return b.score < a.score;
}

void printLeaderboard(const string& filename) {
    ifstream file(filename);
    vector<Entry> entries;
    string name;
    int score;

    while (file >> name >> score) {
        entries.push_back({name, score});
    }

    sort(entries.begin(), entries.end(), compare);

    cout << "\n=== Leaderboard ===\n";
    for (size_t i = 0; i < min(entries.size(), size_t(5)); ++i) {
        cout << i + 1 << ". " << entries[i].name << " - " << entries[i].score << "\n";
    }
}