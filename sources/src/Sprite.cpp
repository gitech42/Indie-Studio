/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Sprite.cpp
*/

#include "Sprite.hpp"
#include "iostream"
#include "Character.hpp"


Sprite::Sprite(const std::string &modelFile, const std::string &animFile,
const std::string &textureFile, int startAnim, int nbAnim)
: _rotation(0), _animIndex(startAnim), _frameCount(0), _nbAnim(nbAnim)
{

    _model = LoadModel(modelFile.c_str());
    _model.transform = MatrixRotateXYZ({DEG2RAD*90,0,0});

    if (animFile.size() > 0)
        _anims =  LoadModelAnimations(animFile.c_str(), &_nbAnim);
    if (textureFile.size() > 0) {
        _texture = LoadTexture(textureFile.c_str());
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
        SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
    }
}

Sprite::~Sprite()
{
    std::cout << "Sprite::~Sprite" << std::endl;
    //UnloadTexture(_texture);
    //UnloadModelAnimations(_anims["idle"], _animCount["idle"].first);
    //UnloadModelAnimations(_anims["walk"], _animCount["walk"].first);
    //UnloadModel(_model);
}

void Sprite::draw(Vector3 pos, float scale, Color color)
{
        DrawModel(_model, pos, scale, color);
}

void Sprite::setAnimIndex(int anim, enum ANIMATION input)
{
    if (_frameCount != 0 && _animIndex != anim)
        _animIndex = anim;
    _model.transform = MatrixRotateXYZ({0,0,0});

    switch (input) {
    case Sprite::ANIMATION::UP: {
        _rotation = 180;
    }break;
    case Sprite::ANIMATION::LEFT: {
        _rotation = 90;
    }break;
    case Sprite::ANIMATION::RIGHT: {
        _rotation = 270;
    }break;
    case Sprite::ANIMATION::DOWN: {
        _rotation = 0;
    }break;
    }
    _model.transform = MatrixRotateXYZ({DEG2RAD*90,DEG2RAD*_rotation,0});
}

void Sprite::updateAnimation()
{
    _frameCount += 1;
    UpdateModelAnimation(_model, _anims[_animIndex], _frameCount);
    if (_frameCount >= _anims[_animIndex].frameCount)
        _frameCount = 0;
}