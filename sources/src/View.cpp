/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** View
*/

#include "View.hpp"
#include <iostream>

View::View()
: _camera({0})
{
}

View::~View()
{
    std::cout << "View::~View" << std::endl;
}

void View::set(int nb_line, int nb_cols)
{
    std::cout << "View::View" << std::endl;
    _camera.position = {(float)(nb_cols-1)/2 , (float)nb_line*2, (float)nb_line*2};
    _camera.target = {(float)(nb_cols-1)/2, 0.0f, (float)(nb_line-1)/2};
    _camera.up = {0.0f, 1.0f, 0.0f };
    _camera.fovy = 30.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(_camera, CAMERA_PERSPECTIVE);
}

void View::update(void)
{
    UpdateCamera(&_camera);
}

void View::begin3d(void)
{
    BeginMode3D(_camera);
}
void View::end3d(void)
{
    EndMode3D();
}