/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GraphicConfiguration
*/

#pragma once

#include "GraphicWordConfiguration.hpp"

namespace arcd {

    class GraphicConfiguration: public GraphicWordConfiguration
    {
        public:
            GraphicConfiguration(size_t xOring = 0, size_t yOring = 0, size_t blockSize = 1, size_t wordSize = 1): GraphicWordConfiguration(wordSize), _xOring(xOring), _yOring(yOring), _blockSize(blockSize) {};
            ~GraphicConfiguration() {};

        protected:
            size_t _xOring;
            size_t _yOring;
            size_t _blockSize;
    };
}