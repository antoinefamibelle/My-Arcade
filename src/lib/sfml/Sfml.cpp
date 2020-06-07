/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sfml
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
}

extern "C"
{
    Sfml *entryPoint()
    {
        std::cout << "sfml" << std::endl;
        return new Sfml;
    }

    void destroy_object(Sfml* object)
    {
        delete object;
    }
}