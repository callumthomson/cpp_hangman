#include <stdexcept>
#include <random>
#include <ctime>
#include "Hangman.h"

using std::string;

Hangman::Hangman()
{
    this->state = State::Playing;
    this->lives = 10;
    this->word = "BOTTLE";
}

void Hangman::load_words(vector<string> words)
{
    // static std::random_device rand_dev; Doesn't work for some reason
    static std::mt19937 generator(std::time(nullptr)); // time is less random, but good enough for this
    std::uniform_int_distribution<int> range(0, words.size() - 1);
    int rand_int = range(generator);

    vector<char> word_vector{};
    for(char c : words[rand_int]) {
        word_vector.push_back((char) toupper(c));
    }
    string word_string(word_vector.begin(), word_vector.end());

    this->word = word_string;
}

State Hangman::get_state()
{
    return this->state;
}

int Hangman::get_lives()
{
    return this->lives;
}

string Hangman::get_word()
{
    return this->word;
}

vector<char> Hangman::get_guesses()
{
    return this->guesses;
}

void Hangman::guess(char guess)
{
    guess = (char) toupper(guess);
    if(this->is_already_guessed(guess)) {
        throw std::invalid_argument("");
    } else {
        this->guesses.push_back(guess);
    }
    if(!this->is_guess_correct(guess)) {
        lives -= 1;
    }
    this->update_state();
}

bool Hangman::is_already_guessed(char guess)
{
    for(char g: this->guesses) {
        if (g == guess) {
            return true;
        }
    }
    return false;
}

bool Hangman::is_guess_correct(char guess)
{
    for(char w: this->word) {
        if (w == guess) {
            return true;
        }
    }
    return false;
}

void Hangman::update_state() {
    if (this->is_lost()) {
        this->state = State::Lost;
    } else if (this->is_won()) {
        this->state = State::Won;
    }
}

bool Hangman::is_lost()
{
    return this->lives <= 0;
}

bool Hangman::is_won()
{
    for(char w : this->word) {
        bool letter_guessed = false;
        for(char g : this->guesses) {
            if (w == g) {
                letter_guessed = true;
            }
        }
        if(!letter_guessed) {
            return false;
        }
    }
    return true;
}