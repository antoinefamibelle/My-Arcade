/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Character
*/

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "Entity.hpp"

namespace arcd {
    class GamePlayEntity : public Entity
    {
        public:
            enum entityType
            {
                HERO,
                ENEMY,
                DECOR,
                EDIBLE,
                SPECIAL_EDIBLE,
                UNDEFINED
            };

            enum entityDirections
            {
                LEFT,
                RIGHT,
                UP,
                DOWN,
                NONE
            };

            enum entityState {
                BASIC,
                SPECIAL,
                END
            };

            using entityStatus = std::pair<entityState, std::string>;
            using entityGraphics = std::unordered_map<entityState, entitySprite>;

            GamePlayEntity( entityType type,
                    size_t id,
                    int x = 0,
                    int y = 0,
                    const std::string &name = "",
                    entityDirections direction = entityDirections::NONE,
                    entityStatus currentState = std::make_pair<entityState, std::string>(BASIC, ""),
                    int speedMult = 0,
                    int life = 1,
                    entityGraphics behavior = std::unordered_map<entityState, entitySprite>());
            ~GamePlayEntity() {};

            void updateState(entityState aState); 
            void updateDirection(entityDirections aDirection);

            void setName(const std::string &name) noexcept { _name = name; };
            void setId(int newId) noexcept { _id = newId; };
            void setSpeedMult(int aSpeedMult) noexcept { _speedMult = aSpeedMult; };
            void setLife(int life) noexcept { _life = life; };
            void updateLife(size_t damage) noexcept { _life -= damage; };

            std::string getName() const noexcept { return _name; };
            size_t getId() const noexcept { return _id; };
            int getSpeedMult() const noexcept { return _speedMult; };
            int getLife() const noexcept { return _life; };

            entitySprite getSpriteForState(entityState state) noexcept { return _behavior[state]; };

            void setBehavior(const entityGraphics &behavior) { _behavior = behavior; };
            void setStateSpriteForBehavior(const entityState &aState, const std::string &aSprite);

        private:
            std::string _name;
            size_t _id;

        public:
            entityType _type;
            entityDirections _direction;
            entityStatus _currentStatus;
            
        private:
            int _speedMult;
            int _life;
            entityGraphics _behavior; // quel sprite pour quel state
    };
}