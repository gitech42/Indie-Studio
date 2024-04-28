/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Brick
*/

#ifndef BRICK_HPP_
#define BRICK_HPP_
#include "cstdlib"
#include "RayLib.hpp"

class Brick {
    public:
        Brick(int x, int y, int range_generated);
        ~Brick();
        enum OBJECT {
            NOTHING,
            BOMB_RANGE,
            BOMB_LIMIT
        };
        OBJECT getRandomObject();
        OBJECT spawnObject();
        void updateBrick();
        void draw();
        const Vector2 get();


    protected:
    private:
        int _posx;
        int _posy;
        int _range_generated;
};

#endif /* !BRICK_HPP_ */
