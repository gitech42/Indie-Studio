/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include <iostream>

Bomb::Bomb(int posx, int posy, int range)
: _posx(posx), _posy(posy), _life_time(0), _range(range), _audio(), _model("./assets/bomberman_character.iqm", "", "", 0, 0)
{
    _audio.load("./assets/fuse_burning.mp3");
    _audio.play();
    std::cout << "Bomb::Bomb" << std::endl;
}

void Bomb::draw()
{
    if (_life_time < 80)
        _model.draw(Vector3({(float)_posx, 0, (float)_posy}), 1.0, BLACK);
        //DrawSphere(Vector3({(float)_posx, 0, (float)_posy}), 0.5, BLACK);
}

void Bomb::set_range(int range)
{
    _range = range;
}

void Bomb::set_pos(int x, int y)
{
    _posx = x;
    _posy = y;
}

bool Bomb::isDead(int nbLines, int nbCols)
{
    ++_life_time;
    if (_life_time >= 80)
        explode(nbLines, nbCols);
    if (_life_time >= 100)
        return true;
    return false;
}

void Bomb::explode(int nbLines, int nbCols)
{
    DrawCube(Vector3({(float)(_posx), 0, (float)_posy}), 0.8f, 0.8f, 0.8f, RED);
    for (auto i = _range; i != 0; --i) {
        if (_posx + i <= nbLines)
            DrawCube(Vector3({(float)(_posx + i), 0, (float)_posy}), 0.8f, 0.8f, 0.8f, RED);
        if (_posx - i > 0)
            DrawCube(Vector3({(float)(_posx - i), 0, (float)_posy}), 0.8f, 0.8f, 0.8f, RED);
        if (_posy - i > 0)
            DrawCube(Vector3({(float)_posx, 0, (float)(_posy - i)}), 0.8f, 0.8f, 0.8f, RED);
        if (_posy + i <= nbCols)
            DrawCube(Vector3({(float)_posx, 0, (float)(_posy + i)}), 0.8f, 0.8f, 0.8f, RED);
    }
}

Bomb::~Bomb()
{
    _audio.load("./assets/fire_sound.wav");
    _audio.play();
    std::cout << "Bomb::~Bomb" << std::endl;
}