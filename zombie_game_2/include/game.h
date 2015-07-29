#ifndef GAME_H
#define GAME_H

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp" 

#include <fstream>
#include <sstream>

#include <Windows.h>

#include "mouse.h";
#include "camera.h";
#include "map.h"
#include "creator.h"

class Game
{
public:
	static enum eGameState{initialise, playing, paused, end};
	static enum eModeState{game,editor};
	Game(sf::RenderWindow& rw);

	void render(sf::RenderWindow &window);
	void update();


	// Core game
	vector2d v2dCamera;
	vector2d v2dMouse;

	Mouse mouse;


	// Controls
	void updateGameState(char cKeyPressed, sf::RenderWindow& ren);
	void updateInput(sf::Event& eventIn);

	void leftMouse(bool b);
	void leftMouseClick(int x, int y);

	void rightMouse(bool b);
	void rightMouseClick(int x, int y);

	void updateMouseMove(int x, int y);
	void updateMouseHold(int x, int y);

	// Camera Control
	Camera camera;
	void updateCamera(sf::View& sfView);
	void updateZoom(sf::View& sfView);

	// Map handling.
	int iCurrentMaps;
	static const int iMaxMaps = 10;
	string sMaps[iMaxMaps];
	Map* maps[iMaxMaps];

	void scanForMaps();
	void buildMap(int mapNumber);
	void generateMap(Map& map);
	void createWall(int iNodeX, int iNodeY);
	int createMap(string sName, string sAuthor, string sDescription);
	void mapToFile(Map& map);
	void saveToMap(Map& map);


	// Node handling
	vector2d nodeFromPosition(int x, int y);


	// Map editor
	Wall selection;
	void placeWall(int x, int y);
	void removeWall(vector2d v2d);
	void mapEditor();

	// Entity handling.
	Creator* creator;
	int iCurrentEntities;
	static const int iMaxEntities = 512;
	drawable* entities[iMaxEntities];
	Wall* walls[iMaxEntities];

	void initialiseEntities();


protected:
	eGameState m_GameState;
	eModeState m_ModeState;
};

#endif