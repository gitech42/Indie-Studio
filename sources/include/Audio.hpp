/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_
#include "RayLib.hpp"

class Audio {
    public:
        Audio();
        ~Audio();

        void load(const std::string &file);
        void play();
        void init();
        void close();

        Sound _sound;
    protected:
    private:
};

#endif /* !AUDIO_HPP_ */
