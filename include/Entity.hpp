/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#pragma once

#include <utility>

class Entity {
    public:
        enum spriteType
        {
            FILE,
            TEXT,
            NOTHING
        };

        using entitySprite = std::pair<spriteType, std::string>;

        Entity(int x = 0, int y = 0): _x(x), _y(y) {};
        ~Entity() {};

        void setX(int x) noexcept { _x = x; };
        void setY(int y) noexcept { _y = y; };
        void setPos(int x, int y) noexcept {    setX(x);
                                                setY(y); };

    protected:
        int _x;
        int _y;
};
