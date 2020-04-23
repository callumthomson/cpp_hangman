#include "Hangman.h"

#ifndef CPP_HANGMAN_RENDERER_H
#define CPP_HANGMAN_RENDERER_H


class Renderer {
    public:
        explicit Renderer(Hangman* game);
        void fresh();
        void dashed_word();
        void guesses();
        void lives();
        void ask_input();
        void err_already_guessed(char);
        void win_message();
        void loss_message();

    private:
        Hangman* game;
};


#endif //CPP_HANGMAN_RENDERER_H
