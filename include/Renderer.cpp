#include <iostream>
#include "Renderer.h"

using std::cout;
using std::endl;

Renderer::Renderer(Hangman* game)
{
    this->game = game;
}

void Renderer::fresh()
{
    cout << "###############################################################" << endl;
}

void Renderer::dashed_word()
{
    cout << ">>>>>> Word: ";
    for(char c: this->game->get_word()) {
        int show_character { false };
        for(char g:  this->game->get_guesses()) {
            if(c == g) {
                show_character = true;
            }
        }
        if(show_character) {
            cout << c << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << " <<<<<<" << endl;
}

void Renderer::guesses()
{
    cout << "Guesses: ";
    for(char g : this->game->get_guesses()) {
        cout << "'" + string(1, g) << "' ";
    }
    cout << endl;
}

void Renderer::lives()
{
    cout << "Lives: " << this->game->get_lives() << endl;
}

void Renderer::ask_input()
{
    cout << "Guess a letter: ";
}

void Renderer::err_already_guessed(char guess)
{
    cout << "You already guessed '" << string(1, guess) << "'!" << endl;
}

void Renderer::win_message()
{
    cout << "You won! Congratulations! The word was: '" + this->game->get_word() << "'" << endl;
}

void Renderer::loss_message()
{
    cout << "You Lost! The word was: '" + this->game->get_word() << "'" << endl;
}
