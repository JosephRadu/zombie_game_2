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

	sf::Clock clock;
	sf::Time frames = sf::seconds(0.0008f);
	//0.016
	sf::Time time;

	Game game(window);

	char cKeyPressed = ' ';

	vector2d v2dCamera(0, 0);


	bool bHoldingLeft = false;
	bool bHoldingRight = false;

	sf::View sfView(sf::FloatRect(0,0,512,512));
	sfView.setCenter(256,256);

	sf::Event event;
	vector2d v2dMousePos;


    while (window.isOpen())
    {
		//window.setMouseCursorVisible(false);
		cKeyPressed = ' ';
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
 
			if ((event.type == sf::Event::KeyPressed))
			{
				switch (event.key.code){
					case sf::Keyboard::V: cKeyPressed = 'v'; break;
					case sf::Keyboard::R: cKeyPressed = 'r'; break;
					case sf::Keyboard::A: cKeyPressed = 'a'; break;
					case sf::Keyboard::X: cKeyPressed = 'x'; break;                 
					case sf::Keyboard::P: cKeyPressed = 'p'; break;
					case sf::Keyboard::S: cKeyPressed = 's'; break;
					case sf::Keyboard::T: cKeyPressed = 't'; break;
					case sf::Keyboard::F: cKeyPressed = 'f'; break;
					case sf::Keyboard::Q: cKeyPressed = 'q'; break;

					case sf::Keyboard::Num1: cKeyPressed = 1; break;
					case sf::Keyboard::Num2: cKeyPressed = 2; break;
					case sf::Keyboard::Num3: cKeyPressed = 3; break;
					case sf::Keyboard::Num4: cKeyPressed = 4; break;
					case sf::Keyboard::Num5: cKeyPressed = 5; break;
					case sf::Keyboard::Escape: window.close(); break;
				}

					game.updateKeyboardInput(cKeyPressed);
			}  

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				game.leftMouse(true);
				game.leftMouseClick(v2dMousePos.x(),v2dMousePos.y());
				bHoldingLeft = true;
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				game.leftMouse(false);
				bHoldingLeft = false;
			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				game.rightMouse(true);
				game.rightMouseClick(v2dMousePos.x(),v2dMousePos.y());
				bHoldingRight = true;
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
			{
				game.rightMouse(false);
				bHoldingRight = false;
			}



			if (event.type == sf::Event::MouseMoved)
			{
				sf::Vector2i pixelpos(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
				sf::Vector2f worldPos = window.mapPixelToCoords(pixelpos);
				v2dMousePos.set(worldPos.x,worldPos.y);


				if (bHoldingLeft)
				{
					game.updateMouseHold(v2dMousePos.x(),v2dMousePos.y());
				}

				game.updateMouseMove(v2dMousePos.x(),v2dMousePos.y());
			}

			game.updateCameraControls(event);

		}

		//time = clock.getElapsedTime();

		//if (time.asMilliseconds() > frames.asMilliseconds())
		//{
			window.clear(sf::Color::Black);
			game.renderWorld(window);
			game.updateZoom(sfView);
			game.updateCamera(sfView);
			window.setView(sfView);
			window.display();

			//clock.restart();
		//}
    }
}

void mouseClockwork()
{

}