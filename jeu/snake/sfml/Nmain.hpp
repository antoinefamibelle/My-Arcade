/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Nmain
*/

#pragma once

#include <ncurses.h>
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "Test.hpp"

class Nmain : public Test {
    public:
        Nmain();
        ~Nmain();

        void printWindow();
        void closeWindow();
    protected:
        WINDOW *_window;
};