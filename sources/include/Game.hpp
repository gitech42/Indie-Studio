/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_
#include "View.hpp"
#include "Sprite.hpp"
#include "Map.hpp"
#include "Character.hpp"
#include <map>
#include "Brick.hpp"

class Game {
    public:
        enum END {
            NOTHING,
            WIN,
            WIN_CAMP_NEXT,
            LOSE
        };
        Game(int nb_false_player, int nb_real_player, int nb_line, int nb_cols, int destroyable_wall, int undestroyable_wall, int random_generated);
        Game(int nb_real_player, std::string filepath);
        ~Game();
        void draw(void);
        void loadClasses(int nb_real_players, int random_generated);
        void inputPlayers();
        void updateBricks();
        void updateBombs();
        void givePlayerBonus(Vector2 pos, Character *player);
        void deleteCharacter(std::vector<char> &to_delete);
        void stackdelete(std::vector<char> &to_delete, std::vector<char> &totals);
        END endCondition();

        int zebi(void); //ici//


        Map _map;
        View _view;
        std::map<char, std::unique_ptr<Character>> _players;
        std::vector<std::unique_ptr<Brick>> _bricks;
        bool _isCamp;
    protected:
    private:
        int _nb_real_player;
        //Temporaire (a changer)
        Texture2D _wall_texture;
};
#endif /* !GAME_HPP_ */
