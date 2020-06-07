/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurses
*/

#pragma once

#include "ILibraryModule.hpp"

class Ncurses : public arcd::LibraryModule
{
    public:
        Ncurses();
        ~Ncurses() {};

        void printWindow() final { output("print Ncurses window"); };
        void closeWindow() final { output("close Ncurses window"); };

    protected:
    private:
};
