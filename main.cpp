#include <iostream>

using namespace std;

int main() {
    srand(time(0));

    const int SIZE = 4;

    string words[SIZE];

    cout << "Enter words:" << endl;

    for (int i = 0; i < SIZE; i++)
        cin >> words[i];

    string word = words[rand() % SIZE];

    string originalWord = word;
    for (int i = 0; i < word.length(); i++) {
        int randIndex = rand() % word.length();

        char a = word[i];
        word[i] = word[randIndex];
        word[randIndex] = a;
    }

    cout << "Letters in one word were shuffled, try to guess word:" << " " << word << endl;

    string result;

    int attempts;

    cout << "Guess word: " << endl;
    cin >> result;

    for (attempts = 2; attempts >= 0; attempts--) {
        if (result == originalWord) {
            cout << "You guessed!" << endl;
            break;
        }
        else {
            if (attempts > 0) {
                cout << "Your attempts:" << " " << attempts << endl;
                cout << "Guess again:" << " " << endl;
                cin >> result;
            }
        }
    }

    if (attempts == 0)
        cout << "You losed";

    return 0;
}