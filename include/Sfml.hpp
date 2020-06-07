/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sfml
*/

#pragma once

#include "ILibraryModule.hpp"

class Sfml : public arcd::LibraryModule
{
    public:
        Sfml();
        virtual ~Sfml() {};

        void printWindow() final { output("print SFML window"); };
        void closeWindow() final { output("close SFML window"); };


    protected:
    private:
};
