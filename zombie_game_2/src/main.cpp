#include <SFML/Graphics.hpp>
#include <iostream>
#include "global.h"

#include <string>

#include <Windows.h>
#include "game.h"

using namespace std;

int main()
{
	
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");
	Game game(window);
	char cKeyPressed = ' ';

	vector2d v2dCamera(0, 0);

	bool bHoldingLeft = false;

    while (window.isOpen())
    {
		sf::Event event;
        cKeyPressed = ' ';
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
 
            if ((event.type == sf::Event::KeyPressed))
            {
                switch (event.key.code){
                    case sf::Keyboard::W: cKeyPressed = 'w'; break;
                    case sf::Keyboard::A: cKeyPressed = 'a'; break;
                    case sf::Keyboard::S: cKeyPressed = 's'; break;
                    case sf::Keyboard::D: cKeyPressed = 'd'; break;        

						                    
					
					case sf::Keyboard::R: cKeyPressed = 'r'; break;  

					case sf::Keyboard::Escape: window.close(); break;
                }
            }  






			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				game.holdingLeft(true);
				game.updateMouseClick(event.mouseButton.x,event.mouseButton.y);
				bHoldingLeft = true;
			}

			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				game.holdingLeft(false);
				bHoldingLeft = false;
			}


			if (event.type == sf::Event::MouseMoved)
			{
				if (bHoldingLeft)
				{
					game.updateMouseHold(event.mouseMove.x,event.mouseMove.y);
				}

				game.updateMouseMove(event.mouseMove.x,event.mouseMove.y);
			}



        }
		window.clear(sf::Color::Black);
        game.updateGameState(cKeyPressed, window);
        window.display();
    }
}