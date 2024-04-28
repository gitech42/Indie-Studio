/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-sacha.lliso
** File description:
** View
*/

#ifndef VIEW_HPP_
#define VIEW_HPP_
#include "RayLib.hpp"

class View {
    public:
        View();
        ~View();
        void set(int nb_line, int nb_cols);
        void update(void);
        void begin3d(void);
        void end3d(void);
        Camera3D _camera;
    protected:
    private:
};

#endif /* !VIEW_HPP_ */
