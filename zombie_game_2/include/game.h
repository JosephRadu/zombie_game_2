#ifndef GAME_H
#define GAME_H

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp" 

#include <fstream>
#include <sstream>

#include <Windows.h>
#include "vector2d.h"

#include "map.h"

#include "creator.h"

class Game
{
public:
	static enum eGameState{initialise, playing, paused, end};
	static enum eModeState{game,editor};
	Game(sf::RenderWindow& rw);
	void updateGameState(char cKeyPressed, sf::RenderWindow& ren);
	void render(sf::RenderWindow &window);

	void update();
	void initialiseEntities();

	// Map handling.
	int iCurrentMaps;
	static const int iMaxMaps = 10;
	void scanForMaps();
	void buildMap(int mapNumber);
	string sMaps[iMaxMaps];
	Map maps[iMaxMaps];

	void generateMap(Map& map);
	vector2d nodeFromPosition(int x, int y);

	void updateMouseClick(int x, int y);
	void updateMouseMove(int x, int y);
	void updateMouseHold(int x, int y);

	vector2d v2dCamera;

	// Map editor
	Wall selection;
	void placeWall(int x, int y);

	// Mouse handling
	bool bHoldingLeft;
	void holdingLeft(bool b);

	// Entity handling.
	Creator* creator;
	int iCurrentEntities;
	static const int iMaxEntities = 512;
	drawable* entities[iMaxEntities];
	Wall* walls[iMaxEntities];

		// Walls
		void createWall(int iNodeX, int iNodeY);


protected:
	eGameState m_GameState;
	eModeState m_ModeState;
};

#endif