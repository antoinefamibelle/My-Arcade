/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
}

extern "C"
{
    Ncurses *entryPoint()
    {
        std::cout << "ncurses" << std::endl;
        return new Ncurses;
    }

    void destroy_object(Ncurses* object)
    {
        delete object;
    }
}