/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Brick
*/

#include "Brick.hpp"

Brick::Brick(int x, int y, int range_generated)
: _posx(x), _posy(y), _range_generated(range_generated)
{
}

Brick::OBJECT Brick::getRandomObject()
{
    int random = 0;

    while (random == 0)
        random = rand()%3;
    return (Brick::OBJECT)random;
}

void Brick::draw()
{
    DrawCube(Vector3({(float) _posx, 0, (float)_posy}), 1.0f, 1.0f, 1.0f, WHITE);
}

Brick::OBJECT Brick::spawnObject()
{
    int random = rand()%_range_generated;

    if (random == 0)
        return getRandomObject();
    return NOTHING;
}

const Vector2 Brick::get()
{
    const Vector2 vect({(float)_posx, (float)_posy});

    return vect;
}

Brick::~Brick()
{
}
