/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Character
*/

#include "Character.hpp"
//_model("./assets/bomberman_character.iqm",
 //   "./assets/bomberman_anims.iqm", "./assets/bomberman_texture.png")
//{

Character::Character(char id, bool isReal)
:_id(id), _bomb_count(1), _isReal(isReal), _vect{0, 0}, _max_bombs(1),
_bomb_range(1), _move_target{0, 0}, isWalking(true), _time(0),
_framecount(0), _model("./assets/bomberman_character.iqm",
    "./assets/bomberman_anims.iqm", "./assets/bomberman_texture.png", 1, 2)
{
}

Character::~Character()
{
}

void Character::draw(int i, int j, int player)
{
    _model.updateAnimation();
    if (player != 2 && player != 1)
        _model.draw(Vector3({(float)j, 0, (float)i}), 1.0, RED);
    else
        _model.draw(Vector3({(float)j, 0, (float)i}), 1.0, WHITE);
}


void Character::drawBombs()
{
    for (int i = 0; i!= _bombs.size(); ++i)
        _bombs[i].get()->draw();
}

void Character::incrementMaxBomb()
{
    ++_max_bombs;
    ++_bomb_count;
}

Vector3 Character::updateBombs(int nbLines, int nbCols)
{
    Vector3 vect({-1, -1, -1});

    for (auto it = _bombs.begin(); it != _bombs.end(); it++)
        if (it->get()->isDead(nbLines, nbCols) == true) {
            vect.x = it->get()->_posx;
            vect.y = it->get()->_posy;
            vect.z = it->get()->_range;
            it = _bombs.erase(it);
            it--;
            ++_bomb_count;
            return vect;
        }
    return vect;
}

void Character::createBomb(Vector2 vect)
{
    --_bomb_count;
    _bombs.push_back(std::make_unique<Bomb>(vect.x, vect.y, _bomb_range));
}

void Character::setColor(Color color)
{
    _color = color;
}

void Character::setKey(KeyboardKey up,
KeyboardKey down, KeyboardKey right, KeyboardKey left, KeyboardKey bomb)
{
    _key_up = up;
    _key_down = down;
    _key_left = left;
    _key_right = right;
    _key_bomb = bomb;
}

Character::INPUT Character::handleInput()
{
    if (_framecount == 10) {
        if (IsKeyDown(_key_down)) {
            if (_dir != Map::DIRECTION::DOWN) {
                _dir = Map::DIRECTION::DOWN;
                _framecount = 0;
                return INPUT::NOTHING;
            }
            _dir = Map::DIRECTION::DOWN;
            _framecount = 0;
            return INPUT::DOWN;
        } else if (IsKeyDown(_key_left)) {
            if (_dir != Map::DIRECTION::LEFT) {
                _dir = Map::DIRECTION::LEFT;
                _framecount = 0;
                return INPUT::NOTHING;
            }
            _dir = Map::DIRECTION::LEFT;
            _framecount = 0;
            return INPUT::LEFT;
        } else if (IsKeyDown(_key_right)) {
            if (_dir != Map::DIRECTION::RIGHT) {
                _dir = Map::DIRECTION::RIGHT;
                _framecount = 0;
                return INPUT::NOTHING;
            }
            _dir = Map::DIRECTION::RIGHT;
            _framecount = 0;
            return INPUT::RIGHT;
        } else if (IsKeyDown(_key_up)) {
            if (_dir != Map::DIRECTION::UP) {
                _dir = Map::DIRECTION::UP;
                _framecount = 0;
                return INPUT::NOTHING;
            }
            _dir = Map::DIRECTION::UP;
            _framecount = 0;
            return INPUT::UP;
        }
    } else
        _framecount += 1;
    if (IsKeyPressed(_key_bomb))
        return INPUT::BOMB;
    return INPUT::NOTHING;
}

Vector2 Character::positionIA(std::vector<std::string> &map, int nbLines, int nbCol, char id)
{
    int lines = 0;

    Vector2 vect = {-1, -1};
    for (int i = 0; i != nbLines; ++i)
        for (int j = 0; j != nbCol; ++j)
            if (map[i][j] == id) {
                vect.y = i;
                vect.x = j;
                return vect;
            }
    return vect;
}

bool Character::checkDangerCase(std::vector<std::string> &map, Vector2 pos)
{
    if (pos.x >= 0 && pos.y >= 0 && pos.x <= 23 && pos.y <= 13)
        if (map[pos.y][pos.x] == 'b')
            return true;
    return false;
}

bool Character::checkDangerZone(std::vector<std::string> &map, Vector2 &pos)
{
    if (checkDangerCase(map, {pos.x+1, pos.y}))
        return true;
    else if (checkDangerCase(map, {pos.x-1, pos.y}))
        return true;
    else if (checkDangerCase(map, {pos.x+2, pos.y}))
        return true;
    else if (checkDangerCase(map, {pos.x-2, pos.y}))
        return true;
    else if (checkDangerCase(map, {pos.x, pos.y+1}))
        return true;
    else if (checkDangerCase(map, {pos.x, pos.y-1}))
        return true;
    else if (checkDangerCase(map, {pos.x, pos.y+2}))
        return true;
    else if (checkDangerCase(map, {pos.x, pos.y-2}))
        return true;
    return false;
}

Vector2 Character::moveTargetNearPlayer(Vector2 move_target, std::vector<std::string> &map)
{
    if (move_target.x == -1)
        return move_target;
    if (move_target.x > 0 && move_target.y > 0 && map[move_target.y -1][move_target.x - 1] == ' ')
        return {move_target.x - 1, move_target.y - 1};
    else if (move_target.y > 0 && move_target.x < (map[0].size() - 1) && map[move_target.y -1][move_target.x + 1] == ' ')
        return {move_target.x + 1, move_target.y - 1};
    else if (move_target.x < (map[0].size() - 1) && move_target.y < (map.size() -1) && map[move_target.y + 1][move_target.x + 1] == ' ')
        return {move_target.x + 1, move_target.y + 1};
    else if (move_target.y < (map.size() -1) && move_target.x > 0 && map[move_target.y + 1][move_target.x - 1] == ' ')
        return {move_target.x - 1, move_target.y + 1};
    else if (move_target.x > 1 && map[move_target.y][move_target.x - 2] == ' ')
        return {move_target.x - 2, move_target.y};
    else if (move_target.x < (map[0].size() - 2) && map[move_target.y][move_target.x + 2] == ' ')
        return {move_target.x + 2, move_target.y};
    else if (move_target.y < (map.size() - 2) && map[move_target.y + 2][move_target.x] == ' ')
        return {move_target.x, move_target.y + 2};
    else if (move_target.y > 1 && map[move_target.y - 2][move_target.x] == ' ')
        return {move_target.x, move_target.y - 2};
    return {-1, -1};
}

void Character::computeTarget(std::vector<std::string> &map, int nbLines, int nbCol)
{
    Vector2 temp_target1 = moveTargetNearPlayer(positionIA(map, nbLines, nbCol, '1'), map);
    Vector2 temp_target2 = moveTargetNearPlayer(positionIA(map, nbLines, nbCol, '2'), map);

    if(temp_target2.x != -1 && temp_target1.x != -1) {
        if(checkDangerZone(map, temp_target2) && !checkDangerZone(map, temp_target1)) {
            _move_target = temp_target1;
            return;
        }
        else if(checkDangerZone(map, temp_target1) && !checkDangerZone(map, temp_target2)) {
            _move_target = temp_target2;
            return;
        }
        else if (sqrt((pow((temp_target1.x - _vect.x), 2) + pow((temp_target1.y - _vect.y), 2)))
        < sqrt(pow((temp_target2.x - _vect.x), 2) + pow((temp_target2.y - _vect.y), 2))) {
            _move_target = temp_target1;
            return;
        } else {
            _move_target = temp_target2;
            return;
        }
    }
    else if (temp_target1.x == -1 && temp_target2.x != -1 && !checkDangerZone(map, temp_target2)) {
        _move_target = temp_target2;
        return;
    }
    else if (temp_target2.x == -1 && temp_target1.x != -1 && !checkDangerZone(map, temp_target1)) {
        _move_target = temp_target1;
        return;
    }
    _move_target.x = (rand() % (nbCol-1)) + 1;
    _move_target.y = (rand() % (nbLines-1)) + 1;
    while (map[_move_target.y][_move_target.x] != ' ') {
        _move_target.x = (rand() % (nbCol-1)) + 1;
        _move_target.y = (rand() % (nbLines-1)) + 1;
    }
    return;
}

bool Character::iaPlaceBomb(std::vector<std::string> &map)
{
    int x = pow((_move_target.x - _vect.x), 2);
    int y = pow((_move_target.y - _vect.y), 2);
    int temp = sqrt(x + y);
    if (temp < 3 && isWalking == true)
        return true;
    else
        return false;
}

void Character::recomputeNewTarget(std::vector<std::string> &map)
{
    if (_time == 0)
        _move_target = {float((rand() % (map[0].size()-1)) + 1), float((rand() % (map.size()-1)) + 1)};
    if (_time == 7) {
        isWalking = true;
        _time = 0;
    } else
        _time+=1;
}

Character::INPUT Character::moveIa(std::vector<std::string> &map, int nbLines, int nbCol)
{
    if (isWalking == false)
        recomputeNewTarget(map);
    if (isWalking == true)
        computeTarget(map, nbLines, nbCol);
    if (_move_target.x > _vect.x &&  (map[_vect.y][_vect.x + 1] == ' ' || _move_target.x > _vect.x &&  map[_vect.y][_vect.x + 1] == '+' || _move_target.x > _vect.x &&  map[_vect.y][_vect.x + 1] == '*' || _move_target.x > _vect.x &&  map[_vect.y][_vect.x + 1] == 'h')) {
        _dir = Map::DIRECTION::RIGHT;
        return INPUT::RIGHT;
    }
    else if (_move_target.x < _vect.x &&  (map[_vect.y][_vect.x - 1] == ' ' || map[_vect.y][_vect.x - 1] == '+' || map[_vect.y][_vect.x - 1] == 'h' || map[_vect.y][_vect.x - 1] == '*')) {
        _dir = Map::DIRECTION::LEFT;
        return INPUT::LEFT;
    }
    else if (_move_target.y > _vect.y  && (map[_vect.y + 1][_vect.x] == ' ' || map[_vect.y + 1][_vect.x] == '+' || map[_vect.y + 1][_vect.x] == '*' || map[_vect.y + 1][_vect.x] == 'h')) {
        _dir = Map::DIRECTION::DOWN;
        return INPUT::DOWN;
    }
    else if (_move_target.y < _vect.y &&  (map[_vect.y - 1][_vect.x] == ' ' || map[_vect.y - 1][_vect.x] == '+' || map[_vect.y - 1][_vect.x] == '*' || map[_vect.y - 1][_vect.x] == 'h')) {
        _dir = Map::DIRECTION::UP;
        return INPUT::UP;
    }
    return INPUT::NOTHING;
}
