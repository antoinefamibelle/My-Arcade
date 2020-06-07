/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#pragma once

#include "string"
#include "iostream"
#include "vector"
#include "memory"

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

class Entity {
    public:
        Entity() {};
        ~Entity() {};

        //Getter//
        float GetSpeed() { return this->_Speed; };
        sf::Sprite GetSprite() { return this->_Sprite; };
        sf::Sprite GetImage() { return this->_Sprite; };
        sf::Vector2f GetPosition() { return this->_Position; };

        //Setter//
        void UpdateImageRect();
        void SetRect(sf::IntRect x) { this->_Rect = x; };
        void SetImageUrl(std::string url) { this->_ImageUrl = url;};
        void SetImage();

        //Creation//
        void CreateEntity(sf::Vector2f, std::string, sf::IntRect);

    protected: 
        float _Speed;
        std::string _ImageUrl;

        sf::Texture _Texture;
        sf::Image _Image;
        sf::Sprite _Sprite;
        sf::IntRect _Rect;
        sf::Vector2f _Position;
};
