/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** InterfaceEntity
*/

#pragma once

#include <string>
#include "Entity.hpp"

namespace arcd {
    class InterfaceEntity : public Entity
    {
        public:
            enum entityContentType
            {
                TEXT,
                NUMBER,
                IMAGE,
                UNDEFINED
            };

            InterfaceEntity(const std::string &content = "", entityContentType contentType = UNDEFINED, int x = 0, int y = 0);
            ~InterfaceEntity();

        private:
            std::string _content;
            entityContentType _contentType;
            entitySprite _sprite;
    };
}
