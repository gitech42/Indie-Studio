/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_
#include "View.hpp"
#include "Sprite.hpp"
#include "Button.hpp"
#include <vector>
#include <tuple>

enum STATE {
    INTRO,
    MENU,
    GAME_CAMP,
    NEW_GAME,
    GAME_SURV,
    LOSE,
    WIN,
    QUIT
};

enum MENU_STATE {
    NOTHING,
    MAIN_SCR,
    CAMPAIGN_SCR,
    SURVIVAL_SCR,
    SETTINGS_SCR
};

class Menu {
    public:
        Menu();
        ~Menu();
        std::vector<Button> createAllButton();
        STATE menu_state(Vector2 mousePos, STATE state);
        bool checkClickButton(Vector2 mousePos, int i, Vector2 pos, Vector2 dim);
        void draw(void);
        std::tuple<int, int> getMapSize(void);
        std::tuple<int, int, int> getGameParam(void);

        bool _activate;
        Texture2D _bkg;
        View _view;
        int _line;
        int _col;
        int _number_real_player;
        int _cassable_wall;
        int _incassable_wall;
        int _false_player;
        int _random_generated;

    protected:
    private:
        std::vector<Button> createMainMenuButton();
        std::vector<Button> createCampaignButton();
        std::vector<Button> createSurvivalButton();
        std::vector<Button> createSettingsButton();
        void placeMainMenuButton(std::vector<Button> &button);
        void placeCampaignButton(std::vector<Button> &button);
        void placeSurvivalButton(std::vector<Button> &button);
        void placeSettingsButton(std::vector<Button> &button);
        STATE MainMenu(Vector2 mousePos, STATE state);
        STATE Campaign(Vector2 mousePos, STATE state);
        STATE Survival(Vector2 mousePos, STATE state);
        void Settings(Vector2 mousePos);
        void setScreen(MENU_STATE screen);
        void drawButtons(void);
        std::vector<Button> _button;
        MENU_STATE _screen;
        //std::tuple<int, int> _map_size;
        //std::tuple<int, int, int> _game_param;
};

#endif /* !MENU_HPP_ */