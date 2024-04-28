/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Bomb.hpp"
#include "RayLib.hpp"
#include "Sprite.hpp"

class Map {
    public:
    enum DIRECTION {
        UP,
        LEFT,
        DOWN,
        RIGHT
    };
        Map();
        ~Map();
        std::vector<std::string> &get();
        void set(const std::string &filepath);
        void draw();
        const std::string openFile(const std::string &file);
        void characterMovement(const char target, const DIRECTION &dir, int nb_case);
        int positionTargetX(const char target);
        int positionTargetY(const char target);
        bool canWalk(int x, int y, int nb_case, const DIRECTION &dir);
        void createEmptyMap(int lines, int col);
        void fileMap(int nb_player, int nb_walls, int nb_destroyable_walls);
        void fileMapWithTarget(const char target, int nb);
        Vector2 placeBomb(const char target, const DIRECTION &dir);
        std::vector<char> checkCollisionFromVector(Vector3 vect);
        bool isEnemiesInside(int id_first_bot);

        Vector2 positionTarget(const char target);
        bool checkIfCharacter(char target);
        bool isHere(Vector2 pos, char target);
        std::vector<std::string> _map;
        int _nbLines;
        int _nbCol;
    protected:
    private:
};

#endif /* !MAP_HPP_ */
