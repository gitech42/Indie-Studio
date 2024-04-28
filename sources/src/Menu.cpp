/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    _bkg = LoadTexture("assets/bomberman.png");
    _screen = MAIN_SCR;
    _button = createAllButton();
    _line = 15;
    _col = 15;
    _number_real_player = 1;
    _cassable_wall = 10;
    _incassable_wall = 10;
    _random_generated = 3;
    _false_player = 3;
    //_map_size = std::make_tuple(15, 15);
    //_game_param = std::make_tuple(1, 10, 10);
}

Menu::~Menu()
{
    //UnloadTexture(_bkg);
}

std::vector<Button> Menu::createAllButton()
{
    if (!_button.empty())
        _button.clear();
    switch (_screen) {
    case MAIN_SCR:
        return createMainMenuButton();
    case CAMPAIGN_SCR:
        return createCampaignButton();
    case SURVIVAL_SCR:
        return createSurvivalButton();
    case SETTINGS_SCR:
        return createSettingsButton();
    }
    return {};
}

std::vector<Button> Menu::createMainMenuButton()
{
    std::vector<Button> button;

    for (int i = 0; i < 4; i++) {
        switch (i) {
        case CAMPAIGN:
            button.push_back(Button("CAMPAIGN"));
            break;
        case SURVIVAL:
            button.push_back(Button("SURVIVAL"));
            break;
        case EXIT:
            button.push_back(Button("EXIT"));
            break;
        }
    }
    placeMainMenuButton(button);
    return button;
}

void Menu::placeMainMenuButton(std::vector<Button> &button)
{
    button[0].setPosition(795, 350);
    button[0].setTextPosition(800, 350);
    button[1].setPosition(795, 450);
    button[1].setDimension(390, 65);
    button[1].setTextPosition(800, 450);
    button[2].setPosition(795, 650);
    button[2].setDimension(190, 65);
    button[2].setTextPosition(800, 650);
}

std::vector<Button> Menu::createCampaignButton()
{
    std::vector<Button> button;

    for (int i = 0; i < 3; i++) {
        switch (i) {
        case CONTINUE:
            button.push_back(Button("CONTINUE"));
            break;
        case NEW_CAMPAIGN:
            button.push_back(Button("NEW CAMPAIGN"));
            break;
        case BACK_CAMP:
            button.push_back(Button("BACK"));
            break;
        }
    }
    placeCampaignButton(button);
    return button;
}

void Menu::placeCampaignButton(std::vector<Button> &button)
{
    button[0].setPosition(795, 350);
    button[0].setTextPosition(800, 350);
    button[1].setPosition(795, 450);
    button[1].setDimension(590, 65);
    button[1].setTextPosition(800, 450);
    button[2].setPosition(795, 550);
    button[2].setDimension(200, 65);
    button[2].setTextPosition(800, 550);
}

std::vector<Button> Menu::createSurvivalButton()
{
    std::vector<Button> button;

    for (int i = 0; i < 23; i++) {
        switch (i) {
            case PLAYER_PLUS:
               button.push_back(Button("+ PLAYERS"));
               break;
            case PLAYER_MINUS:
               button.push_back(Button("- PLAYERS"));
               break;
            case PLAYER_NB:
               button.push_back(Button(std::to_string(_number_real_player).c_str()));
               break;
            case DEST_PLUS:
               button.push_back(Button("+ DESTRUCTIBLE"));
               break;
            case DEST_MINUS:
               button.push_back(Button("- DESTRUCTIBLE"));
               break;
            case DEST_NB:
               button.push_back(Button(std::to_string(_cassable_wall).c_str()));
               break;
            case INDEST_PLUS:
               button.push_back(Button("+ INDESTRUCTIBLE"));
               break;
            case INDEST_MINUS:
               button.push_back(Button("- INDESTRUCTIBLE"));
               break;
            case INDEST_NB:
               button.push_back(Button(std::to_string(_incassable_wall).c_str()));
               break;
            case LINES_PLUS:
               button.push_back(Button("+ LINES"));
               break;
            case LINES_MINUS:
               button.push_back(Button("- LINES"));
               break;
            case LINES_NB:
               button.push_back(Button(std::to_string(_line).c_str()));
               break;
            case COLS_PLUS:
               button.push_back(Button("+ COLS"));
               break;
            case COLS_MINUS:
               button.push_back(Button("- COLS"));
               break;
            case COLS_NB:
               button.push_back(Button(std::to_string(_col).c_str()));
               break;
            case PLAY:
               button.push_back(Button("PLAY"));
               break;
            case BACK_SURV:
               button.push_back(Button("BACK"));
               break;
            case RANDOM_PLS:
                button.push_back(Button("+Drop Object"));
                break;
            case RANDOM_MIN:
                button.push_back(Button("-Drop Object"));
                break;
            case RANDOM_NB:
                button.push_back(Button(std::to_string(_random_generated).c_str()));
                break;
            case NB_FALSE_MIN:
                button.push_back(Button("-Number IA"));
                break;
            case NB_FALSE_PLS:
                button.push_back(Button("+Number IA"));
                break;
            case NB_FALSE:
                button.push_back(Button(std::to_string(_false_player).c_str()));
                break;
        }
    }
    placeSurvivalButton(button);
    return button;
}

void Menu::placeSurvivalButton(std::vector<Button> &button)
{
    button[0].setPosition(495, 150);
    button[0].setDimension(420, 65);
    button[0].setTextPosition(500, 150);
    button[1].setPosition(1095, 150);
    button[1].setDimension(420, 65);
    button[1].setTextPosition(1100, 150);
    button[2].setPosition(955, 100);
    button[2].setDimension(100, 65);
    button[2].setTextPosition(975, 100);
    button[2].setColor(GREEN);
    //button[2].setText(button[2].getText(_line));
    button[3].setPosition(260, 275);
    button[3].setDimension(650, 65);
    button[3].setTextPosition(270, 275);
    button[4].setPosition(1095, 275);
    button[4].setDimension(650, 65);
    button[4].setTextPosition(1100, 275);
    button[5].setPosition(955, 225);
    button[5].setDimension(100, 65);
    button[5].setTextPosition(975, 225);
    button[5].setColor(GREEN);
    //button[5].setText(button[5].getText(_col));
    button[6].setPosition(190, 400);
    button[6].setDimension(720, 65);
    button[6].setTextPosition(195, 400);
    button[7].setPosition(1095, 400);
    button[7].setDimension(720, 65);
    button[7].setTextPosition(1100, 400);
    button[8].setPosition(955, 400);
    button[8].setDimension(100, 65);
    button[8].setTextPosition(975, 400);
    button[8].setColor(GREEN);
    //button[8].setText(button[8].getText(_number_real_player));
    button[9].setPosition(620, 525);
    button[9].setDimension(290, 65);
    button[9].setTextPosition(625, 525);
    button[10].setPosition(1095, 525);
    button[10].setDimension(290, 65);
    button[10].setTextPosition(1100, 525);
    button[11].setPosition(955, 525);
    button[11].setDimension(100, 65);
    button[11].setTextPosition(975, 525);
    button[11].setColor(GREEN);
    //button[11].setText(button[11].getText(_cassable_wall));
    button[12].setPosition(620, 650);
    button[12].setDimension(290, 65);
    button[12].setTextPosition(625, 650);
    button[13].setPosition(1095, 650);
    button[13].setDimension(290, 65);
    button[13].setTextPosition(1100, 650);
    button[14].setPosition(955, 650);
    button[14].setDimension(100, 65);
    button[14].setTextPosition(975, 650);
    button[14].setColor(GREEN);
    //button[14].setText(button[14].getText(std::get<1>(_map_size)));
    button[15].setPosition(495, 955);
    button[15].setDimension(300, 65);
    button[15].setTextPosition(560, 955);
    button[16].setPosition(1195, 955);
    button[16].setDimension(300, 65);
    button[16].setTextPosition(1260, 955);
    button[17].setPosition(450, 750);
    button[17].setDimension(450, 70);
    button[17].setTextPosition(450, 750);
    button[19].setPosition(955, 755);
    button[19].setDimension(100, 65);
    button[19].setTextPosition(975, 755);
    button[19].setColor(GREEN);
    button[18].setPosition(1100, 750);
    button[18].setDimension(450, 70);
    button[18].setTextPosition(1100, 750);
    button[20].setPosition(450, 845);
    button[20].setDimension(450, 70);
    button[20].setTextPosition(450, 845);
    button[21].setPosition(1110, 845);
    button[21].setDimension(450, 70);
    button[21].setTextPosition(1110, 845);
    button[22].setPosition(955, 850);
    button[22].setDimension(100, 65);
    button[22].setTextPosition(975, 850);
    button[22].setColor(GREEN);
}

std::vector<Button> Menu::createSettingsButton()
{
    std::vector<Button> button;

    for (int i = 0; i < 3; i++) {
        switch (i) {
        case VOLUME_UP:
            button.push_back(Button("VOLUME UP"));
            break;
        case VOLUME_DOWN:
            button.push_back(Button("VOLUME DOWN"));
            break;
        case BACK_SET:
            button.push_back(Button("BACK"));
            break;
        }
    }
    placeSettingsButton(button);
    return button;
}

void Menu::placeSettingsButton(std::vector<Button> &button)
{
    button[0].setPosition(795, 350);
    button[0].setTextPosition(800, 350);
    button[1].setPosition(795, 450);
    button[1].setDimension(390, 65);
    button[1].setTextPosition(800, 450);
    button[2].setPosition(795, 550);
    button[2].setDimension(399, 65);
    button[2].setTextPosition(800, 550);
}

STATE Menu::menu_state(Vector2 mousePos, STATE state)
{
    switch (_screen) {
    case MAIN_SCR:
        return MainMenu(mousePos, state);
    case CAMPAIGN_SCR:
        return Campaign(mousePos, state);
    case SURVIVAL_SCR:
        return Survival(mousePos, state);
    case SETTINGS_SCR:
        Settings(mousePos);
    }
    return MENU;
}

STATE Menu::MainMenu(Vector2 mousePos, STATE state)
{
    if (!_button.empty()) {
        if (checkClickButton(mousePos, 0, _button[0].getPosition(), _button[0].getDimension())) {
             setScreen(CAMPAIGN_SCR);
             _button = createAllButton();
            //state = GAME_CAMP;
        }
        if (checkClickButton(mousePos, 1, _button[1].getPosition(), _button[1].getDimension())) {
            setScreen(SURVIVAL_SCR);
            _button = createAllButton();
            // state = GAME_CAMP;
        }
        if (checkClickButton(mousePos, 2, _button[2].getPosition(), _button[2].getDimension()))
            state = QUIT;
        return state;
    }
    return {};
}

STATE Menu::Campaign(Vector2 mousePos, STATE state)
{
    if (checkClickButton(mousePos, 0, _button[0].getPosition(), _button[0].getDimension()))
        state = GAME_CAMP;
    if (checkClickButton(mousePos, 1, _button[1].getPosition(), _button[1].getDimension()))
        state = NEW_GAME;
    if (checkClickButton(mousePos, 2, _button[2].getPosition(), _button[2].getDimension())) {
        setScreen(MAIN_SCR);
        _button = createAllButton();
    }
    return state;
}

STATE Menu::Survival(Vector2 mousePos, STATE state)
{
     if (checkClickButton(mousePos, 0, _button[0].getPosition(), _button[0].getDimension())) {
            if (_number_real_player == 2)
                _number_real_player = 1;
            else
                _number_real_player += 1;
            std::string str = std::to_string(_number_real_player);
            _button[2].setText(str);
     }
     if (checkClickButton(mousePos, 1, _button[1].getPosition(), _button[1].getDimension())) {
        if (_number_real_player == 1)
            _number_real_player = 2;
        else
            _number_real_player -= 1;
        std::string str = std::to_string(_number_real_player);
        _button[2].setText(str);
     }
     if (checkClickButton(mousePos, 3, _button[3].getPosition(), _button[3].getDimension())) {
            _cassable_wall += 1;
            std::string str = std::to_string(_cassable_wall);
            _button[5].setText(str);
     }
     if (checkClickButton(mousePos, 4, _button[4].getPosition(), _button[4].getDimension())) {
            _cassable_wall -= 1;
            std::string str = std::to_string(_cassable_wall);
            _button[5].setText(str);
     }
     if (checkClickButton(mousePos, 6, _button[6].getPosition(), _button[6].getDimension())) {
            _incassable_wall += 1;
            std::string str = std::to_string(_incassable_wall);
            _button[8].setText(str);
     }
     if (checkClickButton(mousePos, 7, _button[7].getPosition(), _button[7].getDimension())) {
            _incassable_wall -= 1;
            std::string str = std::to_string(_incassable_wall);
            _button[8].setText(str);
     }
     if (checkClickButton(mousePos, 9, _button[9].getPosition(), _button[9].getDimension())) {
        if (_line == 100)
            _line = 10;
        else
            _line += 1;
        std::string str = std::to_string(_line);
        _button[11].setText(str);
     }
     if (checkClickButton(mousePos, 10, _button[10].getPosition(), _button[10].getDimension())) {
        if (_line == 10)
            _line = 100;
        else
            _line -= 1;
        std::string str = std::to_string(_line);
        _button[11].setText(str);
     }
     if (checkClickButton(mousePos, 12, _button[12].getPosition(), _button[12].getDimension())) {
        if (_col == 100)
            _col = 10;
        else
            _col += 1;
        std::string str = std::to_string(_col);
        _button[14].setText(str);
     }
     if (checkClickButton(mousePos, 13, _button[13].getPosition(), _button[13].getDimension())) {
        if (_col == 10)
            _col = 100;
        else
            _col -= 1;
        std::string str = std::to_string(_col);
        _button[14].setText(str);
     }
    if (checkClickButton(mousePos, 16, _button[16].getPosition(), _button[16].getDimension())) {
        setScreen(MAIN_SCR);
        _button = createAllButton();
        return state;
    }
    if (checkClickButton(mousePos, 17, _button[17].getPosition(), _button[17].getDimension())) {
        if (_random_generated == 10)
            _random_generated = 1;
        else
            _random_generated += 1;
        std::string str = std::to_string(_random_generated);
        _button[19].setText(str);
    }
    if (checkClickButton(mousePos, 18, _button[18].getPosition(), _button[18].getDimension())) {
        if (_random_generated == 1)
            _random_generated = 10;
        else
            _random_generated -= 1;
        std::string str = std::to_string(_random_generated);
        _button[19].setText(str);
    }
    if (checkClickButton(mousePos, 20, _button[20].getPosition(), _button[20].getDimension())) {
        if (_false_player == 7)
            _false_player = 1;
        else
            _false_player += 1;
        std::string str = std::to_string(_false_player);
        _button[22].setText(str);
    }
    if (checkClickButton(mousePos, 21, _button[21].getPosition(), _button[21].getDimension())) {
        if (_false_player == 1)
            _false_player = 7;
        else
            _false_player -= 1;
        std::string str = std::to_string(_false_player);
        _button[22].setText(str);
    }
    if (checkClickButton(mousePos, 15, _button[15].getPosition(), _button[15].getDimension())) {
       state = GAME_SURV;
    }
    return state;
}

void Menu::Settings(Vector2 mousePos)
{
    // if (checkClickButton(mousePos, 0, _button[0].getPosition(), _button[0].getDimension()))
        // setScreen(MAIN_SCR);
    // if (checkClickButton(mousePos, 0, _button[0].getPosition(), _button[0].getDimension()))
        // VOLUME UP
    // if (checkClickButton(mousePos, 1, _button[1].getPosition(), _button[1].getDimension()))
        // VOLUME DOWN
    // if (checkClickButton(mousePos, 2, _button[2].getPosition(), _button[2].getDimension()))
        // SET MOVE UP KEY
    // if (checkClickButton(mousePos, 0, _button[0].getPosition(), _button[0].getDimension()))
        // SET MOVE DOWN KEY
    // if (checkClickButton(mousePos, 1, _button[1].getPosition(), _button[1].getDimension()))
        // SET MOVE LEFT KEY
    // if (checkClickButton(mousePos, 2, _button[2].getPosition(), _button[2].getDimension()))
        // SET MOVE RIGHT KEY
}

bool Menu::checkClickButton(Vector2 mousePos, int i, Vector2 pos, Vector2 dim)
{
    if (mousePos.x > pos.x && mousePos.x < (pos.x + dim.y)
    && mousePos.y > pos.y && mousePos.y < (pos.y + dim.x)) {
        _button[i].setColor(BLUE);
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            return true;
    } else
        _button[i].setColor(YELLOW);
    return false;
}

void Menu::draw(void)
{
    DrawTexture(_bkg, 0 ,0, WHITE);
    switch (_screen) {
    case MAIN_SCR:
        drawButtons();
        break;
    case CAMPAIGN_SCR:
        drawButtons();
        break;
    case SURVIVAL_SCR:
        drawButtons();
        break;
    case SETTINGS_SCR:
        drawButtons();
        break;
    }
}

void Menu::drawButtons(void)
{
    for (int i = 0; i < _button.size(); i++)
        _button[i].draw();
}

//GETTER

//std::tuple<int, int> Menu::getMapSize(void)
//{
//    return _map_size;
//}
//
//std::tuple<int, int, int> Menu::getGameParam(void)
//{
//    return _game_param;
//}

//SETTER
void Menu::setScreen(MENU_STATE screen)
{
    _screen = screen;
}