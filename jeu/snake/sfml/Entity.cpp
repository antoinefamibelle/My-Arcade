/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#include "Entity.hpp"

void Entity::SetImage()
{
    //Cette fonction set le sprite ainsi que la texture neccessaire et 
    // elle charge le tout avec un petit setsmooth aussi 
    this->_Texture.loadFromFile(this->_ImageUrl);
    this->_Texture.setSmooth(true);
    this->_Sprite.setTexture(this->_Texture);
    this->_Sprite.setTextureRect(this->_Rect);
    this->_Sprite.setPosition(this->_Position);
}

void Entity::UpdateImageRect()
{
    //Cette fonction change le rect de l'objet et reactualise la texture
    this->_Sprite.setTexture(this->_Texture);
    this->_Sprite.setTextureRect(this->_Rect);
}

void Entity::CreateEntity(sf::Vector2f position, std::string url, sf::IntRect Rect)
{
    //Cette fonction permet de creer une entity ! Elle est a appeler uniquement
    //lorsque l'on creer un objet entity pour la premiere fois !
    this->_Position = position;
    this->_Rect = Rect;
    this->SetImageUrl(url);
    this->SetImage();
}