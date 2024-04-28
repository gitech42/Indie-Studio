/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Audio
*/

#include "Audio.hpp"
#include <iostream>

Audio::Audio()
{
    std::cout << "Audio::Audio" << std::endl;
}

Audio::~Audio()
{
    std::cout << "Audio::~Audio" << std::endl;
}

void Audio::load(const std::string &file)
{
    _sound = LoadSound(file.c_str());
}

void Audio::play()
{
    PlaySound(_sound);
}

void Audio::init()
{
    InitAudioDevice();
}

void Audio::close()
{
    CloseAudioDevice();
}