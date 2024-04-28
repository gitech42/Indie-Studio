/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_
#include "RayLib.hpp"
#include "raymath.h"
#include <map>

class Sprite {
    public:
        enum ANIMATION {
            NOTHING,
            UP,
            DOWN,
            RIGHT,
            LEFT,
        };
        Sprite(const std::string &modelFile, const std::string &animFile,
        const std::string &textureFile, int startAnim, int nbAnim);
        ~Sprite();
        void draw(Vector3 pos, float scale, Color color);
        void updateAnimation();
        void setAnimIndex(int anim, enum ANIMATION input);

        float _rotation;
    protected:
    private:
        int _animIndex;
        int _frameCount;
        unsigned int _nbAnim;
        Texture2D _texture;
        ModelAnimation * _anims;
        Model _model;
};

#endif /* !SPRITE_HPP_ */
