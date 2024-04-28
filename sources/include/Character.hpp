/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Bomb.hpp"
#include "Map.hpp"
#include <chrono>
#include <math.h>


class Character {
    public:
        Character(char id, bool isReal);
        ~Character();
        enum INPUT {
            NOTHING,
            UP,
            DOWN,
            RIGHT,
            LEFT,
            BOMB
        };
        Vector3 updateBombs(int nbLines, int nbCols);
        void drawBombs();
        void draw(int i, int j, int player);
        void setKey(KeyboardKey up, KeyboardKey down, KeyboardKey right, KeyboardKey left,KeyboardKey bomb);
        void setColor(Color color);
        void createBomb(Vector2 vect);
        void incrementMaxBomb();
        INPUT handleInput();
        std::vector<std::unique_ptr<Bomb>> _bombs;
        Vector2 positionIA(std::vector<std::string> &map, int nbLines, int nbCol, char id);
        INPUT moveIa(std::vector<std::string> &map, int nbLines, int nbCol);
        void computeTarget(std::vector<std::string> &map, int nbLines, int nbCol);
        bool checkDangerZone(std::vector<std::string> &map, Vector2 &pos);
        bool checkDangerCase(std::vector<std::string> &map, Vector2 pos);
        bool iaPlaceBomb(std::vector<std::string> &map);
        Vector2 moveTargetNearPlayer(Vector2 move_target, std::vector<std::string> &map);
        void recomputeNewTarget(std::vector<std::string> &map);
        char _id;
        Map::DIRECTION _dir;
        int _bomb_count;
        bool _isReal;
        int _max_bombs;
        int _bomb_range;
        Vector2 _vect;
        int _framecount;
        Sprite _model;
        bool isWalking;
    protected:
    private:
        Vector2 _move_target;
        int _time;
        int _posx;
        int _posy;
    protected:
    private:
        KeyboardKey _key_up;
        KeyboardKey _key_down;
        KeyboardKey _key_left;
        KeyboardKey _key_right;
        KeyboardKey _key_bomb;
        Color _color;
};

#endif /* !CHARACTER_HPP_ */
