/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GraphicWordConfiguration
*/

#pragma once

#include <cstddef>

namespace arcd {

    class GraphicWordConfiguration {
        public:
            GraphicWordConfiguration(size_t wordSize = 1): _wordSize(wordSize) {};
            ~GraphicWordConfiguration() {};

        protected:
            size_t _wordSize;
    };
}
