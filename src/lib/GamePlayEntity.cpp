/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#include "GamePlayEntity.hpp"

namespace arcd 
{
    GamePlayEntity::GamePlayEntity(entityType type,
        size_t id, 
        int x,
        int y,
        const std::string &name, 
        entityDirections direction, 
        entityStatus currentState,
        int speedMult,
        int life,
        entityGraphics behavior):
                            Entity(x, y),
                            _name(name),
                            _id(id),
                            _type(type),
                            _direction(direction),
                            _currentStatus(currentState),
                            _speedMult(speedMult),
                            _life(life),
                            _behavior(behavior)
    {
    }
}