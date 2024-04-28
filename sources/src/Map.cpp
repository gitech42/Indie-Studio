/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
}

Map::~Map()
{
}

const std::string Map::openFile(const std::string &file)
{
    std::stringstream buffer;
    std::ifstream map_file(file);

    if (map_file.is_open() == false)
        std::cout << "Error openFile: File is not readable" << std::endl;
    else {
        buffer << map_file.rdbuf();
        map_file.close();
    }
    return buffer.str();
}

void Map::set(const std::string &filepath)
{
    std::ifstream map_file;
	std::string inputString;

	map_file.open(filepath);
	while(getline(map_file, inputString, '\n'))
		_map.push_back(inputString);
	map_file.close();
    _nbCol = _map[0].size();
    _nbLines = _map.size();
}

int Map::positionTargetY(const char target)
{
    int lines = 0;

    for (int i = 0; i != _nbLines; ++i)
        for (int j = 0; j != _nbCol; ++j)
            if (_map[i][j] == target) {
                lines = i;
                return lines;
            }
    return 0;
}

int Map::positionTargetX(const char target)
{
    int col = 0;

    for (int i = 0; i != _nbLines; ++i)
        for (int j = 0; j != _nbCol; ++j)
            if (_map[i][j] == target) {
                col = j;
                return col;
            }
    return 0;
}

Vector2 Map::positionTarget(const char target)
{
    Vector2 vect({-1, -1});

    for (int i = 0; i != _nbLines; ++i)
        for (int j = 0; j != _nbCol; ++j)
            if (_map[i][j] == target) {
                vect.x = (float)j;
                vect.y = (float)i;
                return vect;
            }
    return vect;
}

bool Map::canWalk(int x, int y, int nb_case, const DIRECTION &dir)
{
    switch (dir) {
        case LEFT: {
            if ((x - nb_case) >= 0 && _map[y][x - nb_case] != 'W' && _map[y][x - nb_case] != 'w' &&
                !checkIfCharacter(_map[y][x - nb_case]))
                return true;
            else return false;
        } break;
        case RIGHT: {
            if ((x + nb_case) < (_map[0].size() - 1) && _map[y][x + nb_case] != 'W' && _map[y][x + nb_case] != 'w' &&
                !checkIfCharacter(_map[y][x + 1]))
                return true;
            else return false;
        } break;
        case UP: {
            if ((y - nb_case) >= 0 && _map[y - nb_case][x] != 'W' && _map[y - nb_case][x] != 'w' &&
                !checkIfCharacter(_map[y - 1][x]))
                return true;
            else return false;
        } break;
        case DOWN: {
            if ((y + nb_case) < (_map.size() - 1) && _map[y + nb_case][x] != 'W' && _map[y + nb_case][x] != 'w' &&
            !checkIfCharacter(_map[y + 1][x]))
                return true;
            else return false;
        } break;
    }
    return false;
}

void Map::characterMovement(const char target, const DIRECTION &dir, int nb_case)
{
    int x = positionTargetX(target);
    int y = positionTargetY(target);

    switch (dir) {
        case LEFT: {
            if ((canWalk(x, y, nb_case, dir)) == true) {
                _map[y][x] = ' ';
                _map[y][x - nb_case] = target;
            }
        } break;
        case RIGHT: {
            if ((canWalk(x, y, nb_case, dir)) == true) {
                _map[y][x] = ' ';
                _map[y][x + nb_case] = target;
            }
        } break;
        case UP: {
            if ((canWalk(x, y, nb_case, dir)) == true) {
                _map[y][x] = ' ';
                _map[y - nb_case][x] = target;
            }
        } break;
        case DOWN: {
            if ((canWalk(x, y, nb_case, dir)) == true) {
                _map[y][x] = ' ';
                _map[y + nb_case][x] = target;
            }
        } break;
    }
}

Vector2 Map::placeBomb(const char target, const DIRECTION &dir)
{
    Vector2 vect;
    int x = positionTargetX(target);
    int y = positionTargetY(target);

    switch (dir) {
        case LEFT: {
            if ((canWalk(x, y, 1, dir)) == true) {
                _map[y][x - 1] = 'b';
                vect = {(float)(x - 1), (float) y};
                return vect;
            }
        } break;
        case RIGHT: {
            if ((canWalk(x, y, 1, dir)) == true) {
                _map[y][x + 1] = 'b';
                vect = {(float)(x + 1), (float)y};
                return vect;
            }
        } break;
        case UP: {
            if ((canWalk(x, y, 1, dir)) == true) {
                _map[y - 1][x] = 'b';
                vect = {(float)x, (float)(y - 1)};
                return vect;
            }
        } break;
        case DOWN: {
            if ((canWalk(x, y, 1, dir)) == true) {
                _map[y + 1][x] = 'b';
                vect = {(float)x, (float)(y + 1)};
                return vect;
            }
        } break;
    }
    return Vector2({-1, -1});
}

void Map::createEmptyMap(int lines, int col)
{
    std::string top_and_bottom;
    std::string inside;

    _nbCol = col;
    _nbLines = lines;
    if (_map.size())
        _map.clear();
    for (int i = 0; i != col; ++i) {
        if (i == 0 || i == (col - 1)) {
            inside.append("W");
        } else
            inside.append(" ");
        top_and_bottom.append("W");
    }
    for (int i = 0; i != lines; ++i) {
        if (i == 0 || i == (lines - 1)) {
            _map.push_back(top_and_bottom);
        } else
            _map.push_back(inside);
    }
}

void Map::fileMap(int nb_player, int nb_walls, int nb_destroyable_walls)
{

    for (int i = '1'; i != ('1' + nb_player); ++i) {
        if (i == '2') {
            nb_player += 1;
            continue;
        }
        fileMapWithTarget(i, 1);
    }
    fileMapWithTarget('W', nb_walls);
    fileMapWithTarget('w', nb_destroyable_walls);
}

void Map::fileMapWithTarget(const char target, int nb)
{
    int posx = 0;
    int posy = 0;

    for (int i = 0; i != nb; ++i) {
        while(_map[posx][posy] != ' ') {
            posx = rand()%(_nbLines-1);
            posy = rand()%(_nbCol-1);
        }
        _map[posx][posy] = target;
    }
}

std::vector<std::string> &Map::get()
{
    return _map;
}

bool Map::checkIfCharacter(char target)
{
    for (int i = '1'; i != ':'; ++i)
        if (target == i)
            return true;
    return false;
}

std::vector<char> Map::checkCollisionFromVector(Vector3 vect)
{
    int x = vect.x;
    int y = vect.y;
    int range = vect.z;
    std::vector<char> ids;

    if (vect.x == -1)
        return ids;
    if (_map[y][x] == 'w' || checkIfCharacter(_map[y][x])) {
        ids.push_back(_map[y][x]);
        _map[y][x] = ' ';
    }
    for (int i = 0; i != range + 1; ++i) {
        if ((i + x) >= _nbCol)
            break;
        if (_map[y][x + i] == 'w' || checkIfCharacter(_map[y][x + i])) {
            ids.push_back(_map[y][x + 1]);
            _map[y][x + i] = ' ';
        }
    }
    for (int i = 0; i != range + 1; ++i) {
        if ((i + y) >= _nbLines)
            break;
        if (_map[y + i][x] == 'w' || checkIfCharacter(_map[y + i][x])) {
            ids.push_back(_map[y + 1][x]);
            _map[y + i][x] = ' ';
        }
    }
    for (int i = 0; i != range + 1; ++i) {
        if ((x - i) < 1)
            break;
        if (_map[y][x - i] == 'w' || checkIfCharacter(_map[y][x - i])) {
            ids.push_back(_map[y][x - 1]);
            _map[y][x - i] = ' ';
        }
    }
    for (int i = 0; i != range + 1; ++i) {
        if ((y - i) < 1)
            break;
        if (_map[y - i][x] == 'w' || checkIfCharacter(_map[y - i][x])) {
            ids.push_back(_map[y - 1][x]);
            _map[y - i][x] = ' ';
        }
    }
    return ids;
}

bool Map::isEnemiesInside(int id_first_bot)
{
    for (int i = 0; i != _nbLines; ++i) {
        for (int j = 0; j != _nbCol; ++j) {
            for (int id = id_first_bot; id != '9'; ++id) {
                if (_map[i][j] == id)
                    return true;
            }
        }
    }
    return false;
}

bool Map::isHere(Vector2 pos, char target)
{
    if (_map[pos.y][pos.x] == target)
        return true;
    return false;
}

void Map::draw()
{
}