/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_
#include "Game.hpp"
#include "Audio.hpp"
#include "Menu.hpp"
#include "string.h"

class Window {
    public:
        Window();
        ~Window();
        void start(void);
        Vector2 _mousePos;

    protected:
    private:
        STATE _state;
        std::unique_ptr<Audio> _audio;
        std::unique_ptr<Menu> _menu;
        std::unique_ptr<Game> _game;
        int _width;
        int _height;
        int _frameCount;
        int _current_level;

        void draw();
        void change_state(void);

        void intro_state(void);
        void menu_state(void);
        void game_state(void);
        void end_state(void);
        void draw_intro(void);
        void draw_menu(void);
        void draw_lose(void);
        void draw_win(void);
};

std::string get_last_level_in_file();

#endif /* !WINDOW_HPP_ */
