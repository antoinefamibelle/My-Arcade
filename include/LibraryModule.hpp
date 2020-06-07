/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibraryModule
*/

#include "ILibraryModule.hpp"
#include "GamePlayEntity.hpp"
#include "vector"

#pragma once

class LibraryModule : public arcd::ILibraryModule
{
    public:
        LibraryModule();
        void SetGlobalSpeed(const float speed) { _globalSpeed = speed; };
        void SetName(const std::string &name) { _name = name; };
        void SetScore(unsigned int score) { _score = score; };
        void SetHighscore(unsigned int score) { _highscore = score; };

    protected:
        float _globalSpeed;
        std::vector<GamePlayEntity> _entities;
        std::string _name;
        unsigned int _score;
        unsigned int _highscore;
    private:
};
