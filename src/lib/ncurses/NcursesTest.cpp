/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** NcursesTest
*/

#include <ncurses.h>
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "Test.hpp"
#include "Arcade.hpp"

class NcursesTest : public TestGraphic {
    public:
        NcursesTest();
        virtual ~NcursesTest() {};

        void printWindow();
        void closeWindow();
    protected:
};

NcursesTest::NcursesTest()
{
}

void NcursesTest::closeWindow()
{
    std::cout << "ncurces close" << std::endl;
}

void NcursesTest::printWindow()
{
    std::cout << "ncurces print" << std::endl;
    initscr();

    printw("Ceci est la fenetre du _window");  
    refresh();
    getch();
    endwin();
}

extern "C"
{
    TestGraphic *entryPoint()
    {
        std::cout << "ncurces" << std::endl;
        return new NcursesTest;
    }
    void destroy_object(TestGraphic* object)
    {
        delete object;
    }
}
