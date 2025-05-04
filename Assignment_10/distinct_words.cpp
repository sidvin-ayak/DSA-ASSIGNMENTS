#include <iostream>
#include <string>
using namespace std;

#define MAX_N 1000
#define WORD_LEN 3
#define MAX_WORDS (3 * MAX_N)

string allWords[MAX_WORDS];
int wordCounts[MAX_WORDS];
int totalWords = 0;

void addWord(const string &word) {
    for (int i = 0; i < totalWords; i++) {
        if (allWords[i] == word) {
            wordCounts[i]++;
            return;
        }
    }
    allWords[totalWords] = word;
    wordCounts[totalWords] = 1;
    totalWords++;
}

int getWordCount(const string &word) {
    for (int i = 0; i < totalWords; i++) {
        if (allWords[i] == word) {
            return wordCounts[i];
        }
    }
    return 0;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the number of words per player: ";
        cin >> n;

        totalWords = 0;
        string words[3][MAX_N];
        int scores[3] = {0, 0, 0};

        // Read words
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> words[i][j];
                addWord(words[i][j]);
            }
        }

        // Compute scores
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                int count = getWordCount(words[i][j]);
                if (count == 1)
                    scores[i] += 3;
                else if (count == 2)
                    scores[i] += 1;
            }
        }

        cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;
    }

    return 0;
}
