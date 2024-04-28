/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Game
*/

#include "Game.hpp"

Game::Game(int nb_false_player, int nb_real_player, int nb_line, int nb_cols, int destroyable_wall, int undestroyable_wall, int random_generated)
: _nb_real_player(nb_real_player), _isCamp(false)
{
    int x = 0;
    int y = 0;

    _map.createEmptyMap(nb_line, nb_cols);
    _map.fileMap(nb_false_player + nb_real_player, undestroyable_wall, destroyable_wall);
    _view.set(nb_line, nb_cols);

    if (nb_real_player == 2) {
        while (_map._map[y][x] != ' ') {
            x = (rand() % (_map._map[0].size()-1)) + 1;
            y = (rand() % (_map._map.size()-1)) + 1;
        }
        _map._map[y][x] = '2';
    }
    loadClasses(_nb_real_player, random_generated);
    //Set in settings;
    _players['1'].get()->setKey(KEY_W, KEY_S, KEY_D, KEY_A, KEY_SPACE);
    _players['1'].get()->setColor(RED);
    if (nb_real_player == 2) {
        _players['2'].get()->setKey(KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_ENTER);
        _players['2'].get()->setColor(GREEN);
    }
    _wall_texture = LoadTexture("./assets/wall_texture.png");
}

Game::Game(int nb_real_player, std::string filepath)
: _nb_real_player(nb_real_player), _isCamp(true)
{
    int y = 0;
    int x = 0;

    _map.set(filepath);
    _view.set(_map._map.size(), _map._map[0].size());
    if (nb_real_player == 2) {
        while (_map._map[y][x] != ' ') {
            x = (rand() % (_map._map[0].size()-1)) + 1;
            y = (rand() % (_map._map.size()-1)) + 1;
        }
        _map._map[y][x] = '2';
    }
    loadClasses(_nb_real_player, 4);
    //Set in settings;
    _players['1'].get()->setKey(KEY_W, KEY_S, KEY_D, KEY_A, KEY_SPACE);
    _players['1'].get()->setColor(RED);
    if (nb_real_player == 2) {
        _players['2'].get()->setKey(KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_ENTER);
        _players['2'].get()->setColor(GREEN);
    }
    _wall_texture = LoadTexture("./assets/wall_texture.png");
}

void Game::stackdelete(std::vector<char> &to_delete, std::vector<char> &totals)
{
    bool exist = false;
    for (int i = 0; i < to_delete.size(); i += 1) {
        for (int j = 0; j < totals.size(); j += 1)
            if (to_delete[i] == totals[j]) {
                exist = true;
                break;
            }
        if (exist == false)
            totals.push_back(to_delete[i]);
        else
            exist == false;
    }
}

void Game::updateBombs()
{
    Vector3 vect({-1, -1, -1});
    std::vector<char> to_delete;
    std::vector<char> total_delete;

    for (auto it = _players.begin(); it != _players.end(); ++it) {
        vect = it->second->updateBombs(_map._nbLines, _map._nbCol);
        to_delete = _map.checkCollisionFromVector(vect);
        it->second->drawBombs();
        stackdelete(to_delete, total_delete);
    }
    deleteCharacter(total_delete);
}

void Game::deleteCharacter(std::vector<char> &to_delete)
{
    for (int i = 0; i != to_delete.size(); ++i)
        if (_map.checkIfCharacter(to_delete[i])) {
            for (auto it = _players.begin(); it != _players.end(); ++it) {
                if (it->second.get()->_id == to_delete[i]) {
                    it = _players.erase(it);
                    --it;
                }
            }
        }
}

void Game::updateBricks()
{
    Brick::OBJECT obj = Brick::OBJECT::NOTHING;
    Vector2 pos({0, 0});

    for (auto it = _bricks.begin(); it != _bricks.end(); ++it) {
        pos = it->get()->get();
        if (!_map.isHere(pos, 'w')) {
            obj = it->get()->spawnObject();
            switch (obj) {
                case Brick::OBJECT::BOMB_RANGE: {
                    _map._map[pos.y][pos.x] = '*';
                } break;
                case Brick::OBJECT::BOMB_LIMIT: {
                    _map._map[pos.y][pos.x] = '+';
                } break;
            }
            it = _bricks.erase(it);
            --it;
            continue;
        }
        it->get()->draw();
    }
}

void Game::draw(void)
{
    Vector3 vect({-1, -1});

    _view.begin3d();
    updateBombs();
    updateBricks();
    DrawCube(Vector3({(float)(_map._nbCol-1)/2, -1, (float)(_map._nbLines-1)/2}), 1000, 1.0f, 1000, GRAY);
    for (int i = 0; i != _map._nbLines; ++i) {
        for (int j = 0; j != _map._nbCol; ++j) {
            switch (_map._map[i][j]) {
                case 'W': {
                    DrawCubeTexture(_wall_texture, Vector3({(float)j, 0, (float)i}), 1.0f, 1.0f, 1.0f, RED);
                } break;
                case '+': {
                    DrawCube(Vector3({(float)j, 0, (float)i}), 0.5f, 0.5f, 0.5f, GOLD);
                } break;
                case '*': {
                    DrawCube(Vector3({(float)j, 0, (float)i}), 0.5f, 0.5f, 0.5f, DARKBROWN);
                } break;
            }
            if (_map.checkIfCharacter(_map._map[i][j]))
                _players[_map._map[i][j]].get()->draw(i, j, (_map._map[i][j]-48));
        }
    }
    _view.end3d();
}

void Game::loadClasses(int nb_real_players, int random_generated)
{
    int count = 0;

    for (int i = 0; i != _map._nbLines; ++i)
        for (int j = 0; j != _map._nbCol; ++j)
            if (_map._map[i][j] >= '1' && _map._map[i][j] <= '9') {
                if (count != nb_real_players && (_map._map[i][j] == '1' || _map._map[i][j] == '2')) {
                    _players.insert({_map._map[i][j], std::make_unique<Character>(_map._map[i][j], true)});
                    ++count;
                } else {
                    _players.insert({_map._map[i][j], std::make_unique<Character>(_map._map[i][j], false)});
                }
            } else if (_map._map[i][j] == 'w') {
                _bricks.push_back(std::make_unique<Brick>(j, i, random_generated));
            }

}

void Game::givePlayerBonus(Vector2 pos, Character *player)
{
    if (_map._map[pos.y][pos.x] == '+') {
        player->incrementMaxBomb();
    } else if (_map._map[pos.y][pos.x] == '*') {
        ++player->_bomb_range;
    }
}

Game::END Game::endCondition()
{
    if (_nb_real_player == 1) {
        if (_map.positionTarget('1').x == -1) {
            return Game::LOSE;
        } else if (!_map.isEnemiesInside('2')) {
            if (_isCamp == false)
                return Game::WIN;
            else
                return Game::WIN_CAMP_NEXT;
        }
    } else if(_nb_real_player == 2) {
        if (!_map.isEnemiesInside('3')) {
            if (_isCamp == false)
                return Game::WIN;
            else
                return Game::WIN_CAMP_NEXT;
        } else if (_map.positionTarget('2').x == -1 &&
                    _map.positionTarget('1').x == -1)
                    return Game::LOSE;
    }
    return Game::NOTHING;
}

void Game::inputPlayers()
{
    Vector2 vect;
    Character::INPUT input;

    for (auto it = _players.begin(); it != _players.end(); ++it) {
        if (it->second.get()->_isReal == true) {
            input = it->second.get()->handleInput();
            vect = _map.positionTarget(it->second.get()->_id);
        }else if (it->second.get()->_framecount == 10) {
            vect = it->second.get()->_vect = it->second.get()->positionIA(_map._map, _map._nbLines, _map._nbCol, it->second.get()->_id);
            input = it->second.get()->moveIa(_map._map, _map._nbLines, _map._nbCol);
        }
        if (it->second.get()->_isReal == true || (it->second.get()->_isReal == false && it->second.get()->_framecount == 10)) {
            switch (it->second.get()->_dir) {
                case Map::DIRECTION::LEFT: {
                    it->second->_model.setAnimIndex(2, Sprite::ANIMATION::LEFT);
                } break;
                case Map::DIRECTION::RIGHT: {
                    it->second->_model.setAnimIndex(2, Sprite::ANIMATION::RIGHT);
                } break;
                case Map::DIRECTION::UP: {
                    it->second->_model.setAnimIndex(2, Sprite::ANIMATION::UP);
                } break;
                case Map::DIRECTION::DOWN: {
                    it->second->_model.setAnimIndex(2, Sprite::ANIMATION::DOWN);
                } break;
            }
            switch (input) {
                case Character::INPUT::LEFT: {
                    givePlayerBonus(Vector2({vect.x - 1, vect.y}), it->second.get());
                    _map.characterMovement(it->first, Map::LEFT, 1);
                } break;
                case Character::INPUT::RIGHT: {
                    givePlayerBonus(Vector2({vect.x + 1, vect.y}), it->second.get());
                    _map.characterMovement(it->first, Map::RIGHT, 1);
                } break;
                case Character::INPUT::UP: {
                    givePlayerBonus(Vector2({vect.x, vect.y - 1}), it->second.get());
                    _map.characterMovement(it->first, Map::UP, 1);
                } break;
                case Character::INPUT::DOWN: {
                    givePlayerBonus(Vector2({vect.x, vect.y + 1}), it->second.get());
                    _map.characterMovement(it->first, Map::DOWN, 1);
                } break;
                case Character::INPUT::BOMB: {
                    if (it->second.get()->_bomb_count > 0) {
                        vect.x = -1;
                        vect = _map.placeBomb(it->first, it->second.get()->_dir);
                        if (vect.x != -1) {
                            it->second.get()->createBomb(vect);
                            it->second->_model.setAnimIndex(0, Sprite::ANIMATION::NOTHING);
                        }
                    }
                } break;
            }
            if (it->second.get()->_isReal == false) {
                it->second.get()->_vect = it->second.get()->positionIA(_map._map, _map._nbLines, _map._nbCol, it->second.get()->_id);
                if (it->second.get()->iaPlaceBomb(_map._map) == true) {
                    if (it->second.get()->_bomb_count > 0) {
                        vect = _map.placeBomb(it->first, it->second.get()->_dir);
                        if (vect.x != -1)
                            it->second.get()->createBomb(vect);
                    }
                    it->second.get()->isWalking = false;
                }
                it->second.get()->_framecount = 0;
            }
        } else
            it->second.get()->_framecount+=1;
    }
}

Game::~Game()
{
    //UnloadTexture(_wall_texture);
    std::cout << "Game::~Game" << std::endl;
}
