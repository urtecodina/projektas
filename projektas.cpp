#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

vector<char> wrongGuesses;
void drawHangman(int incorrectGuesses) {

    string hangmanParts[] = {
        "  _____\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "______|______\n",
        "  _____\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "______|______\n",
        "  _____\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "______|______\n",
        "  _____\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "______|______\n",
        "  _____\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "______|______\n",
        "  _____\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "______|______\n",
        "  _____\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "______|______\n"
    };

    cout << hangmanParts[incorrectGuesses];





}

void guessLetter(char letter, const string& word, int& incorrectGuesses, vector<char>& wrongGuesses, string& guessedWord) {
    bool found = false;

    cout << "Guess a letter: ";
    cin >> letter;

    for (size_t i = 0; i < word.size(); ++i) {
        if (letter == word[i]) {
            cout << "You guessed a letter!" << endl ;
            cout << endl;
            found = true;
             guessedWord[i] = letter;
        }
    }

    if (!found) {
       wrongGuesses.push_back(letter);
        incorrectGuesses++;
        drawHangman(incorrectGuesses);
    }
    cout << "Guessed word: " << guessedWord << endl;
    cout << "Wrong guesses: ";
    for (char wrongGuess : wrongGuesses) {
        cout << wrongGuess << " ";
    }
    cout << endl;
}

void play() {
    srand(time(0));
    const string wordlist[10] = {
        "bicycle",
        "umbrella",
        "elephant",
        "adventure",
        "sunshine",
        "chocolate",
        "keyboard",
        "butterfly",
        "fireworks",
        "mountain"
    };

    string word = wordlist[rand() % 10];
    string guessedWord(word.size(), '_');

    char letter;
    int incorrectGuesses = 0;

    while (incorrectGuesses < 6 && guessedWord != word) {
        guessLetter(letter, word, incorrectGuesses, wrongGuesses, guessedWord);
    }

    if (guessedWord == word) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "Sorry, you couldn't guess the word. The correct word was: " << word << endl;
    }
}



int main() {

cout << "                                            HANGMAN                                                   " << endl;
cout <<"________________________________________________________________________________________________________" << endl;

    play();

cout << endl;
cout << "                                            PLAY AGAIN?                                                " << endl;
cout <<"________________________________________________________________________________________________________" << endl;
cout << endl;
cout << "Yes = 1                                             No = 0" << endl;
int answer;
cin >> answer;
if (answer==0){
    cout << "Bye bye!";
} else if (answer == 1) {
}else {
cout << ">:/";

}
    return 0;
}
