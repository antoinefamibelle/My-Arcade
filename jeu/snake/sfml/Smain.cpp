/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Smain
*/

#include "Smain.hpp"

Smain::Smain()
{
    this->_Window.create(sf::VideoMode(1500,1200), "My arcade");
    this->_Window.setVerticalSyncEnabled(true);
    this->_Window.setFramerateLimit(60);
}

void Smain::closeWindow()
{
    this->_Window.close();   
}

void Smain::manageEvent()
{
    while (this->_Window.pollEvent(this->_Event)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

        }
        if (this->_Event.type == sf::Event::Closed)
            this->closeWindow();
    }
}

void Smain::displayEntity()
{
    Entity *tmp = nullptr;
    for(auto it = this->_Entity.begin(); it != this->_Entity.end(); it += 1) {
        tmp = *it;
        this->_Window.draw(tmp->GetSprite());
    }
}

void Smain::printWindow()
{
    sf::Event event;
    float i = 0;
    float y = 0;
    Entity *Object = new Entity;
    Entity *Object2 = new Entity;
    sf::Vector2f position(150, 250);
    sf::IntRect rect(0,0,50,50);
    sf::Vector2f position2(500, 800);

    Object->CreateEntity(position, "./sprite/snake.png", rect);
    this->_Entity.push_back(Object);

    while (this->_Window.isOpen()) { 
        this->_Window.clear();
        this->displayEntity();
        this->_Window.display();
        while (this->_Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->_Window.close();
        }
    }
}

int main(int ac, char **av,char **env)
{
    Smain *Object = nullptr;

    Object = new Smain;
    Object->printWindow();
}