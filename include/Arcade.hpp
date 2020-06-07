/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Arcade
*/

#pragma once

#include <list>
#include <functional>
#include <iostream>
#include "ILibraryModule.hpp"
#include "IDisplayModule.hpp"
#include "Logs.hpp"

namespace arcd {
    class Arcade : public log::Logs
    {
        public:
            enum sharedLibType
            {
                GAME,
                GRAPHIC,
                UNKNOW
            };

            using sharedLibPath = std::string;
            using sharedLibConf = std::pair<sharedLibPath, sharedLibType>;
            using Game = arcd::IDisplayModule;
            using Graphic = arcd::ILibraryModule;

            Arcade();
            ~Arcade();

            size_t getNbGraphics() const noexcept;
            size_t getNbGames() const noexcept;
            std::list<sharedLibConf> getSharedLibs() const noexcept { return _sharedLibs; };
            std::list<sharedLibConf> getGameSharedLibs() const noexcept;
            std::list<sharedLibConf> getGraphicSharedLibs() const noexcept;

            void refresh(); // call read directory and refresh _graphics and _games

            std::list<sharedLibConf> readDirectories(); // read directories and call setGraphics and setGames 

            void launchAGame();
            void launchAGame(const std::string &gameName);

            void launchAGraphic();
            void launchAGraphic(const std::string &graphicName);

            void switchGraphicLib();
            void switchGraphicLib(const std::string &graphicName);

            void switchGameLib();
            void switchGameLib(const std::string &gameName);

            void switchSharedLib();

            void openSharedLib(const std::string &sharedLib, sharedLibType type);
            void cleanAll();
            void closeSharedLib(void *handle);

            void callFunctions(sharedLibType type);

            template<typename T>
            void deleteClassObject()
            {}

            template <typename T>
            void setCurrent(const std::string &sharedLib, T *ptr)
            {
                std::make_pair(sharedLib, ptr);
            }

            // Static methods
            static sharedLibConf makeSharedLibConf(const std::string &filePath, sharedLibType type) noexcept { return std::make_pair(filePath, type); }

        private:
            std::pair<std::string, Game*> _currentSharedLibGame;
            std::pair<std::string, Graphic*> _currentSharedLibGraphic;
            std::list<sharedLibConf> _sharedLibs = std::list<sharedLibConf>();
            void *_handleGame = nullptr;
            void *_handleGraphic = nullptr;

            const static inline std::string _graphicDirName = "lib";
            const static inline std::string _graphicDirPath = "lib/";
            const static inline std::string _gameDirName = "games";
            const static inline std::string _gameDirPath = "games/";

            void addSharedLibrary(const std::string &filePath, sharedLibType type);
            void readGraphicsDirectory(); // read graphics directory
            void readGamesDirectory(); // read games directory

            void setCurrentSharedLibGame(void *hndl, const std::string &sharedLib);
            void setCurrentSharedLibGraphics(void *hndl, const std::string &sharedLib);

            void setHandleGraphic(void *hndl) noexcept;
            void setHandleGame(void *hndl) noexcept;

            void openSharedLibGraphic(const std::string &sharedLib);
            void openSharedLibGame(const std::string &sharedLib);

            template <typename T>
            void loopFunctions()
            {}
    };
}

std::ostream &operator<<(std::ostream &stream, const arcd::Arcade &arcd);
std::ostream &operator<<(std::ostream &stream, const std::list<arcd::Arcade::sharedLibConf> &sharedLibs);
