/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ILibraryModule
*/

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Entity.hpp"
#include "GraphicConfiguration.hpp"
#include "GamePlayEntity.hpp"
#include "Logs.hpp"

// ARTHUR:
namespace arcd {

    class ILibraryModule
    {
        public:
            virtual ~ILibraryModule() {};
            virtual void printWindow() = 0;
            virtual void closeWindow() = 0;
    };

    class GraphicEntity // Example class just to make an example of a graphic library class
    {
        public:
            GraphicEntity(size_t id): _id(id) {};
            ~GraphicEntity() {};
    
            size_t _id;
    };

    // je fais l'abstract class car besoins d'args
    class LibraryModule : public GraphicConfiguration, public log::Logs, public ILibraryModule
    {
        public:
            LibraryModule(): GraphicConfiguration(0, 0, 1, 1), Logs(ARCADE_FILE) {};
            virtual ~LibraryModule() {};

            virtual void printWindow() { output("print window"); };
            virtual void closeWindow() { output("close window"); };

            /*virtual void move(GamePlayEntity &anEntity, std::vector<std::unique_ptr<GamePlayEntity>> &aMap);

            virtual void refreshDisplay(Entity &anEntity); // Like when you have change the sprite
            virtual void refreshDisplay(std::vector<std::unique_ptr<Entity>> &aMap); // like when map have change and you just want to update entities

            virtual void updateDisplay(GamePlayEntity &anEntity, std::vector<std::unique_ptr<GamePlayEntity>> &aMap); // logic between anEntity that have a new place in the map
            virtual void updateDispkay(Entity &anEntity, std::vector<std::unique_ptr<Entity>> &aMap); // logic between anEntity that have a new place in the map*/

        private:
            std::vector<std::unique_ptr<GamePlayEntity>> _gamePlayMap;
            std::vector<std::unique_ptr<Entity>> _map;
        };
}