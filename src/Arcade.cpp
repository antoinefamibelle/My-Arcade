/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Arcade
*/

#include <filesystem>
#include <vector>
#include <string>
#include <dlfcn.h>
#include "Arcade.hpp"

using function_ptr_game = arcd::Arcade::Game *(*)(); // <- using en gros c'est un typedef https://stackoverflow.com/questions/20790932/what-is-the-logic-behind-the-using-keyword-in-c
using function_ptr_graphic = arcd::Arcade::Graphic *(*)();

namespace arcd {
    Arcade::Arcade()
    {
    }

    Arcade::~Arcade()
    {
    }

    size_t Arcade::getNbGraphics() const noexcept
    {
        int i = 0;

        for (auto &sl : _sharedLibs) {
            if (sl.second == GRAPHIC) {
                i++;
            }
        }
        return i;
    }

    size_t Arcade::getNbGames() const noexcept
    {
        int i = 0;

        for (auto &sl : _sharedLibs) {
            if (sl.second == GAME) {
                i++;
            }
        }
        return i; 
    }

    template <>
    void Arcade::deleteClassObject<Arcade::Game>()
    {
        delete _currentSharedLibGame.second;
        _currentSharedLibGame.second = nullptr;
    }

    template <>
    void Arcade::deleteClassObject<Arcade::Graphic>()
    {
        delete _currentSharedLibGraphic.second;
        _currentSharedLibGraphic.second = nullptr;
    }

    template <>
    void Arcade::setCurrent<Arcade::Game>(const std::string &sharedLib, Arcade::Game *ptr) 
    {
        _currentSharedLibGame = std::make_pair(sharedLib, ptr); 
    };

    template <>
    void Arcade::setCurrent<Arcade::Graphic>(const std::string &sharedLib, Arcade::Graphic *ptr) 
    {
        _currentSharedLibGraphic = std::make_pair(sharedLib, ptr); 
    };

    void Arcade::cleanAll()
    {
        if (_handleGame != nullptr) {
            deleteClassObject<Game>();
            closeSharedLib(_handleGame);
        }
        if (_handleGraphic != nullptr) {
            deleteClassObject<Graphic>();
            closeSharedLib(_handleGraphic);
        }
    }

    void Arcade::closeSharedLib(void *handle)
    {
        if (handle != nullptr) {
            dlclose(handle);
        }
    }

    void Arcade::setHandleGame(void *hndl) noexcept
    {
        if (_handleGame != nullptr) {
            deleteClassObject<Game>();
            closeSharedLib(_handleGame);
        }
        _handleGame = hndl;
    }

    void Arcade::setHandleGraphic(void *hndl) noexcept
    {
        if (_handleGraphic != nullptr) {
            deleteClassObject<Graphic>();
            closeSharedLib(_handleGraphic);
        }
        _handleGraphic = hndl;
    }

    void Arcade::setCurrentSharedLibGame(void *hndl, const std::string &sharedLib)
    {
        function_ptr_game func = nullptr;

        func = reinterpret_cast<function_ptr_game>(dlsym(hndl, "entryPoint"));
        if (func != NULL) {
            setHandleGame(hndl);
            setCurrent<Game>(sharedLib, func());
        }
    }

    void Arcade::setCurrentSharedLibGraphics(void *hndl, const std::string &sharedLib)
    {
        function_ptr_graphic func = nullptr;

        func = (function_ptr_graphic)(dlsym(hndl, "entryPoint"));
        if (func != NULL) {
            setHandleGraphic(hndl);
            setCurrent<Graphic>(sharedLib, func());
        }
    }

    void Arcade::openSharedLib(const std::string &sharedLib, sharedLibType type)
    {
        void *hndl = nullptr;
        char *error;

        output("opening " + sharedLib);
        hndl = dlopen(sharedLib.c_str(), RTLD_LAZY);
        dlerror();
        if (hndl != NULL) {
            output("opened: " + sharedLib);
            if (type == GAME) {
                output("set current lib game");
                setCurrentSharedLibGame(hndl, sharedLib);
            }
            else if (type == GRAPHIC) {
                output("set current lib graphic");
                setCurrentSharedLibGraphics(hndl, sharedLib);
            }
            if ((error = dlerror()) != NULL) {
                output(error);
            }
        }
    }

    template <>
    void Arcade::loopFunctions<Arcade::Game>()
    {
        auto aGame = _currentSharedLibGame.second;
        
        (void)aGame;
    }

    template <>
    void Arcade::loopFunctions<Arcade::Graphic>()
    {
        auto aGraphic = _currentSharedLibGraphic.second;

        (void)aGraphic;
        aGraphic->printWindow();
        aGraphic->closeWindow();
    }

    void Arcade::callFunctions(sharedLibType type)
    {
        if (type == GAME) {
            loopFunctions<Game>();
        }
        else if (type == GRAPHIC) {
            loopFunctions<Graphic>();
        }
    }

    void Arcade::addSharedLibrary(const std::string &filePath, sharedLibType type)
    {
        if (type != UNKNOW)
            _sharedLibs.push_back(makeSharedLibConf(filePath, type));
    }

    void Arcade::readGamesDirectory()
    {
        for (const auto &entry : std::filesystem::directory_iterator(_gameDirPath)) {
            std::cout << entry.path() << std::endl;
            addSharedLibrary(entry.path(), GAME);
        }
    }

    void Arcade::readGraphicsDirectory()
    {
        for (const auto &entry : std::filesystem::directory_iterator(_graphicDirPath)) {
            std::cout << entry.path() << std::endl;
            addSharedLibrary(entry.path(), GRAPHIC);
        }
    }

    std::list<Arcade::sharedLibConf> Arcade::readDirectories()
    {
        _sharedLibs.clear();
        readGamesDirectory();
        readGraphicsDirectory();
        return _sharedLibs;
    }

    std::list<Arcade::sharedLibConf> Arcade::getGameSharedLibs() const noexcept
    {
        std::list<Arcade::sharedLibConf> gamesPath;

        for (auto &sl: _sharedLibs) {
            if (sl.second == GAME) {
                gamesPath.push_back(sl);
            }
        }
        return gamesPath;
    }

    std::list<Arcade::sharedLibConf> Arcade::getGraphicSharedLibs() const noexcept
    {
        std::list<Arcade::sharedLibConf> graphicsPath;

        for (auto &sl: _sharedLibs) {
            if (sl.second == GRAPHIC) {
                graphicsPath.push_back(sl);
            }
        }
        return graphicsPath;
    }





    void Arcade::launchAGame()
    {

    }

    void Arcade::launchAGame(const std::string &gameName)
    {
        (void)gameName;
    }

    void Arcade::launchAGraphic()
    {

    }

    void Arcade::launchAGraphic(const std::string &graphicName)
    {
        (void)graphicName;
    }

    void switchGraphicLib()
    {

    }

    void switchGraphicLib(const std::string &graphicName)
    {
        (void)graphicName;
    }

    void switchGameLib()
    {

    }

    void switchGameLib(const std::string &gameName)
    {
        (void)gameName;
    }
}

std::ostream &operator<<(std::ostream &stream, const arcd::Arcade &arcade)
{
    return stream << arcade.getSharedLibs();
}

std::ostream &operator<<(std::ostream &stream, const std::list<arcd::Arcade::sharedLibConf> &sharedLibs)
{
    std::string sharedLibTypeString;

    for (const auto &sharedLib : sharedLibs) {
        if (sharedLib.second == arcd::Arcade::GAME) {
            sharedLibTypeString = "Game shared Lib";
        }
        else if (sharedLib.second == arcd::Arcade::GRAPHIC) {
            sharedLibTypeString = "Graphical shared Lib";
        }
        else {
            sharedLibTypeString = "Unknow shared lib type";
        }
        stream << sharedLib.first << ": " << sharedLibTypeString << std::endl;
    }
    return stream;
}