/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Smain
*/

#pragma once

#include "Test.hpp"
#include "Entity.hpp"
#include <SFML/Window.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>
#include <SFML/Window.h>

class Smain : public Test {
    public:
        Smain();
        ~Smain() {};

        void printWindow();
        void closeWindow();
        void manageEvent();
        void displayEntity();
    protected:
        sf::RenderWindow _Window;
        sf::Event _Event;
        std::vector<Entity *> _Entity;
        
};