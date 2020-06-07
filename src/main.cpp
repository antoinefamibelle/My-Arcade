/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include <dlfcn.h>
#include "Arcade.hpp"

int main()
{
    //Test *object = nullptr;
    log::Logs loging(ARCADE_FILE);
    arcd::Arcade arcade;
    std::list<arcd::Arcade::sharedLibConf> games;
    std::list<arcd::Arcade::sharedLibConf> graphics;

    arcade.readDirectories();
    std::cout << "arcade: " << std::endl << arcade;
    games = arcade.getGameSharedLibs();
    graphics = arcade.getGraphicSharedLibs();
    for (auto &graphic : graphics) {
        arcade.openSharedLib(graphic.first, graphic.second);
        arcade.callFunctions(arcd::Arcade::GRAPHIC);
    }
    // arcade.callTestFunction(arcd::Arcade::GAME);

    return 0;
}