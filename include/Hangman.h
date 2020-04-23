#include <string>
#include <vector>
#include "State.h"

using std::string;
using std::vector;

#ifndef CPP_HANGMAN_HANGMAN_H
#define CPP_HANGMAN_HANGMAN_H

class Hangman {
    public:
        Hangman();
        void load_words(vector<string>);
        State get_state();
        int get_lives();
        string get_word();
        vector<char> get_guesses();
        void guess(char);

    private:
        State state;
        int lives;
        string word{};
        vector<char> guesses{};
        bool is_already_guessed(char);
        bool is_guess_correct(char);
        void update_state();
        bool is_lost();
        bool is_won();
};


#endif //CPP_HANGMAN_HANGMAN_H
