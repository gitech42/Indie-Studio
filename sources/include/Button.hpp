/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_
#include "RayLib.hpp"

enum MainButtonList {
    CAMPAIGN,
    SURVIVAL,
    SETTINGS,
    EXIT
};

enum CampaignButtonList {
    CONTINUE,
    NEW_CAMPAIGN,
    BACK_CAMP
};

enum SurvivalButtonList {
    PLAYER_PLUS,
    PLAYER_MINUS,
    PLAYER_NB,
    DEST_PLUS,
    DEST_MINUS,
    DEST_NB,
    INDEST_PLUS,
    INDEST_MINUS,
    INDEST_NB,
    LINES_PLUS,
    LINES_MINUS,
    LINES_NB,
    COLS_PLUS,
    COLS_MINUS,
    COLS_NB,
    PLAY,
    BACK_SURV,
    RANDOM_PLS,
    RANDOM_MIN,
    RANDOM_NB,
    NB_FALSE_PLS,
    NB_FALSE_MIN,
    NB_FALSE
};

enum SettingsButtonList {
    VOLUME_UP,
    VOLUME_DOWN,
    BACK_SET
};

class Button {
    public:
        Button(const std::string name);
        ~Button();
        void draw();
        Vector2 getPosition();
        Vector2 getTextPosition();
        Vector2 getDimension();
        int getFontSize();
        Color getColor();
        Color getTextColor();
        char const *getText(int nb);
        void setPosition(float x, float y);
        void setTextPosition(float x, float y);
        void setDimension(int height, int width);
        void setFontSize(int val);
        void setColor(Color color);
        void setTextColor(Color color);
        void setText(std::string &name);

    protected:
    private:
        std::string _name;
        Rectangle _rec;
        int _fontSize;
        Color _color;
        Color _textColor;
        Vector2 _textPos;
};

#endif /* !BUTTON_HPP_ */