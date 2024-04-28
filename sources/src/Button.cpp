/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Button
*/

#include "Button.hpp"
#include <iostream>
Button::Button(const std::string name)
: _name(name), _rec({0, 0, 390, 65}), _fontSize(70), _color(YELLOW), _textColor(BLACK), _textPos({800, 100})
{
}

Button::~Button()
{
}

//METHODS

//Display the button on the screen
void Button::draw()
{
    DrawRectangleRec(_rec, _color);
    DrawText(_name.c_str(), _textPos.x, _textPos.y, _fontSize, _textColor);
}

//GETTERS

//Get rectangle's position
Vector2 Button::getPosition()
{
    Vector2 pos = {_rec.x, _rec.y};
    return pos;
}

//Get text's position
Vector2 Button::getTextPosition()
{
    Vector2 pos = {_textPos.x, _textPos.y};
    return pos;
}

//Get rectangle's dimension
Vector2 Button::getDimension()
{
    Vector2 dim = {_rec.height, _rec.width};
    return dim;
}

//Get font size
int Button::getFontSize()
{
    return _fontSize;
}

//Get rectangle's color
Color Button::getColor()
{
    return _color;
}

//Get text's color
Color Button::getTextColor()
{
    return _textColor;
}

char const *Button::getText(int nb)
{
    std::cout << "INT " << nb << std::endl;
    std::string tmp = std::to_string(nb);
    std::cout << "STRING " << tmp << std::endl;
    char const *name = tmp.c_str();
    std::cout << "CHAR " << name << std::endl;
    return name;
}

//SETTERS

//Set rectangle's position
void Button::setPosition(float x, float y)
{
    _rec.x = x;
    _rec.y = y;
}

//Set text's position
void Button::setTextPosition(float x, float y)
{
    _textPos.x = x;
    _textPos.y = y;
}

//Set rectangle's dimension
void Button::setDimension(int width, int height)
{
    _rec.width = width;
    _rec.height = height;
}

//Set text's font size
void Button::setFontSize(int val)
{
    _fontSize = val;
}

//Set rectangle's color
void Button::setColor(Color color)
{
    _color = color;
}

//Set text's color
void Button::setTextColor(Color color)
{
    _textColor = color;
}

void Button::setText(std::string &name)
{
    //std::cout << "SET " << name << std::endl;
    _name = name;
}