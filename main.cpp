#include <iostream>
#include <stdexcept>
#include <fstream>

#include "include/Hangman.h"
#include "include/State.h"
#include "include/Renderer.h"

using std::cin;


int main() {
    std::fstream file("words.txt");
    vector<string> words{};
    Hangman game{};
    Renderer renderer(&game);
    char guess{};

    std::string file_line{};
    while(file >> file_line) {
        words.push_back(file_line);
    }
    game.load_words(words);

    while(game.get_state() == State::Playing)
    {
        renderer.fresh();
        renderer.dashed_word();
        renderer.guesses();
        renderer.lives();
        renderer.ask_input();
        cin >> guess;
        try {
            game.guess(guess);
        } catch (std::invalid_argument& e) {
            renderer.err_already_guessed(guess);
        }
    }

    switch (game.get_state())
    {
        case State::Won:
            renderer.win_message();
            break;
        case State::Lost:
            renderer.loss_message();
            break;
        case State::Playing:
        default:
            break;
    }
}
