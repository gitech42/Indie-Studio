/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Window
*/

#include "Window.hpp"
#include "iostream"

Window::Window()
: _width(1920), _height(1080), _state(INTRO), _frameCount(0), _audio(nullptr), _menu(nullptr), _game(nullptr), _current_level(1)
{
    _current_level = atoi(get_last_level_in_file().c_str());
    InitWindow(_width, _height, "Bomberman");
    SetTargetFPS(60);
}

void write_in_file(std::string level)
{
    std::ofstream myfile;
    myfile.open("assets/level.txt");
    myfile << level;
    myfile.close();
}

void Window::start(void)
{
    _audio = std::make_unique<Audio>();
    _audio->init();
    _audio->load("assets/intro.wav");
    _audio->play();
    while (!WindowShouldClose()) {
        _mousePos = GetMousePosition();
        change_state();
        draw();
    }
    if (_game != nullptr)
        if (_game->_isCamp == true)
            write_in_file(std::to_string(_current_level));
}


void Window::change_state(void)
{
    switch (_state) {
        case INTRO: {
            intro_state();
        } break;
        case MENU: {
            menu_state();
        } break;
        case GAME_CAMP:
        case NEW_GAME:
        case GAME_SURV: {
            game_state();
        } break;
        case LOSE:
        case WIN: {
            end_state();
        } break;
        case QUIT: {
            exit(0);
        }
    }
}

void Window::intro_state(void)
{
    _frameCount++;
    if (_frameCount > 10) {
        _menu = std::make_unique<Menu>();
        _state = MENU;
        _audio->load("assets/menu.mp3");
        //_audio->play();
    }
}

std::string get_last_level_in_file()
{
    std::stringstream str;
    std::ifstream f("assets/level.txt", std::ios_base::binary);
    str << f.rdbuf();
    return str.str();
}

std::string return_last_level()
{
    std::string str = get_last_level_in_file();
    std::cout << "str========222222 " << str << std::endl;
    if ((strncmp("1", str.c_str(), 1)) == 0)
        return "assets/map_1.txt";
    else if ((strncmp("2", str.c_str(), 1)) == 0)
        return "assets/map_2.txt";
    else if ((strncmp("3", str.c_str(), 1)) == 0)
        return "assets/map_3.txt";
    //else if ((strncmp("4", str.c_str(), 1)) == 0)
    //    return "assets/map_4.txt";
    //else if ((strncmp("5", str.c_str(), 1)) == 0)
    //    return "assets/map_5.txt";
    else
        return "assets/map_1.txt";
}

std::string return_map_from_int(int level)
{
    std::string str("assets/map_" + std::to_string(level) + ".txt");
    return str;
}

void Window::menu_state(void)
{
    _state = _menu->menu_state(_mousePos, _state);
    if (_state == GAME_CAMP) {
        //_current_level = atoi(get_last_level_in_file().c_str());
        _game = std::make_unique<Game>(1, return_last_level());
    } else if (_state == GAME_SURV) {
        _game = std::make_unique<Game>(_menu->_false_player, _menu->_number_real_player, _menu->_line, _menu->_col, _menu->_cassable_wall, _menu->_incassable_wall, _menu->_random_generated);
    }
    else if (_state == NEW_GAME) {
        _current_level = 1;
        _game = std::make_unique<Game>(1, return_map_from_int(_current_level));
    }
}

void Window::game_state(void)
{
    Game::END state;

    _game->inputPlayers();
    state = _game->endCondition();
    if (state == Game::WIN) {
        _state = WIN;
    } else if (state == Game::WIN_CAMP_NEXT) {
        ++_current_level;
        if (_current_level == 6)
            _current_level = 1;
         _game = std::make_unique<Game>(1, return_map_from_int(_current_level));
    } else if (state == Game::LOSE) {
        _state = LOSE;
    }
}

void Window::end_state(void)
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        _state = MENU;
}

void Window::draw(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    switch (_state) {
        case INTRO: {
           draw_intro();
        } break;
        case MENU: {
            _menu->draw();
        } break;
        case GAME_CAMP: {
            _game->draw();
        } break;
        case GAME_SURV: {
            _game->draw();
        } break;
        case NEW_GAME: {
            _game->draw();
        } break;
        case LOSE: {
            draw_lose();
        } break;
        case WIN: {
            draw_win();
        } break;
    }
    EndDrawing();
}

void Window::draw_intro(void)
{
    DrawText("Sacha LLISO", 800, 100, 30, BLACK);
    DrawText("Bilel BARKALLAH", 10, 100, 30, BLACK);
    DrawText("Divin BADIABO", 10, 1000, 30, BLACK);
    DrawText("Teo GICQUEL", 1600, 100, 30, BLACK);
    DrawText("Virgile COURTIAL", 1600, 1000, 30, BLACK);
    DrawText("BOMBERMAN", 600, 500, 80, BLACK);
}

void Window::draw_lose(void)
{
    DrawText("YOU LOSE", 330, 400, 60, BLACK);
}

void Window::draw_win(void)
{
    DrawText("YOU WIN", 330, 400, 60, BLACK);
}

Window::~Window()
{
    _audio->close();
    std::cout << "Window::~Windows" << std::endl;
    CloseWindow();
}