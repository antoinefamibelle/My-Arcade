/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IDisplayModule
*/

#pragma once

#include <string>

namespace arcd {
    class  IDisplayModule 
    {
        public:
            virtual ~IDisplayModule () = default;
            virtual void init() = 0; // work as __attribut__(constructor)
            virtual void launch() = 0;
            virtual void stop() = 0; // work as __attribut__(destructor)
            virtual const std::string &getName() const = 0;

            /*virtual void SetEnemySpeed() = 0;     // Set la vitesse de l'ennemi
            virtual void SetGlobalSpeed() = 0;    // Set la speed global du jeu (vitesse *1.5 par Exemple)
            virtual void SetHeroSpeed() = 0;     //  Set la vitesse du character
            virtual void SetImageCharacter() = 0; //  Set le path de l'image ou bien "p" pour les character
            virtual void SetImageEnemy() = 0;    // Set le path de l'image ou bien "p" pour l'ennemi
            virtual void SetDecorImage() = 0;   // plusieurs image ,une avec pacman, une avec un bonbon, une avec rien, une avec ennemi, Pacgum
            virtual void SetName() = 0;
            virtual void SetScore() = 0;
            virtual void SetHighscore() = 0;*/
    };
}