/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacmanTest
*/

#include "Test.hpp"
#include <SFML/Window.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>
//#include <SFML/Window.h>

class PacmanTest : public TestGraphic {
    public:
        PacmanTest();
        virtual ~PacmanTest() {};

        void printWindow();
        void closeWindow();
    protected:
        sf::RenderWindow _window = sf::RenderWindow(sf::VideoMode(800, 600), "My window");
};

PacmanTest::PacmanTest()
{
}

void PacmanTest::closeWindow()
{
    std::cout << "PacmanTest close" << std::endl;

}

void PacmanTest::printWindow()
{
    std::cout << "PacmanTest print" << std::endl;
    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (_window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (_window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                _window.close();
        }
    }
}

extern "C"
{
    TestGraphic *entryPoint()
    {
        std::cout << "sfml" << std::endl;
        return new PacmanTest;
    }

    void destroy_object(TestGraphic* object)
    {
        delete object;
    }
}