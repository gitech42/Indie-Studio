/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_
#include "RayLib.hpp"
#include "Audio.hpp"
#include "Sprite.hpp"

class Bomb {
    public:
        Bomb(int posx, int posy, int range);
        ~Bomb();
        void set_pos(int x, int y);
        void set_range(int range);
        void draw();
        bool isDead(int nbLines, int nbCols);
        void explode(int nbLines, int nbCols);

        int _posx;
        int _posy;
        int _range;
    protected:
    private:
        int _life_time;
        Audio _audio;
        Sprite _model;
};

#endif /* !BOMB_HPP_ */
