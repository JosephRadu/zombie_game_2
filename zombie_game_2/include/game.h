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
	Mouse mouse;


	// Controls
	void renderWorld(sf::RenderWindow& ren);
	void updateCameraControls(sf::Event& eventIn);

	void updateKeyboardInput(char cKeyPressed);

	void leftMouse(bool b);
	void leftMouseClick(float x, float y);

	void rightMouse(bool b);
	void rightMouseClick(float x, float y);

	void updateMouseMove(float x, float y);
	void updateMouseHold(float x, float y);

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


	void createBrush(int iNodeX, int iNodeY, char c);
	void placeBrush(float x, float y, char c);
	void removeBrush(vector2d v2d);



	int createMap(string sName, string sAuthor, string sDescription);
	void mapToFile(Map& map);
	void saveToMap(Map& map);

	// Node handling
	vector2d nodeFromPosition(int x, int y);

	// Map editor
	Wall selection;

	char cSelectedBrush;
	int iSelectedMap;


	void mapEditorHome();
	void mapEditorOptions();
	void mapEditorMapSelection();
	void mapEditorSaveMap();
	void mapEditorInit();

	void switchBrush(int i);



	// Entity handling.
	Creator* creator;

	static const int iMaxWalls = 1024;
	static const int iMaxBreakables = 128;
	static const int iMaxHumans = 128;

	//drawable* entities[iMaxEntities];
	Wall* walls[iMaxWalls];
	Breakable* breakables[iMaxBreakables];
	Human* humans[iMaxHumans];

	void initialiseEntities();


protected:
	eGameState m_GameState;
	eModeState m_ModeState;
};

#endif