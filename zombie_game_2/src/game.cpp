#include "game.h"


Game::Game(sf::RenderWindow& w)
{
	selection.colour(22,222,22);
	scanForMaps();
	initialiseEntities();
	generateMap(maps[0]);
	m_GameState = eGameState::playing; 
	m_ModeState = eModeState::editor;
}

void Game::scanForMaps()
{
	iCurrentMaps = 0;

	WIN32_FIND_DATA file;
    HANDLE search_handle=FindFirstFile("maps/*",&file);
    if (search_handle)
    {
        do
		{
			// Ignore empty files basically.
			if ( file.nFileSizeLow > 0)
			{
				std::cout << "Adding "<< file.cFileName << " ... ";
				sMaps[iCurrentMaps] = file.cFileName;
				buildMap(iCurrentMaps);
				iCurrentMaps++;
			}

        }while(FindNextFile(search_handle,&file));
    }
}

void Game::buildMap(int mapNumber)
{
	string fileName = "maps/" + sMaps[mapNumber];
	ifstream modelfile(fileName);
	bool bMapReadingHeader = false;
	bool bMapReadingLevel = false;

	if (modelfile.is_open())
	{
		string line;
		int j = 0;
		int width = 0;
		stringstream ss;
		string s;

		while(getline(modelfile,line))
		{
			if (line == "map_info_start")
			{
				bMapReadingHeader = true;
			}
			else if (line == "map_info_end")
			{
				bMapReadingLevel = true;
				bMapReadingHeader = false;
				getline(modelfile,line);
			}

			if (bMapReadingLevel == true)
			{
				for (int i = 0; i < line.length(); i++)
				{
					cout<<line[i];
					maps[mapNumber].setNode(j,i,line[i]);
				}
					maps[mapNumber].setWidth(line.length());
				j++;
				cout<<""<<endl;
			}

			if (bMapReadingHeader == true)
			{
				std::istringstream iss(line);
				string a, b;
				if (!(iss >> a >> b))
				{
				}
				if (a == "map_name")
				{
					maps[mapNumber].setName(b);
				}
				else if (a == "map_author")
				{
					maps[mapNumber].setAuthor(b);
				}
				else if (a == "map_description")
				{
					maps[mapNumber].setDescription(b);
				}
			}
		}
		maps[mapNumber].setHeight(j);
    }
	
	std::cout<<"map "<<maps[mapNumber].name()<<" has been built."<<std::endl;

	modelfile.close();
}

void Game::generateMap(Map& map)
{
	for (int i = 0; i < map.width(); i++)
	{
		for ( int j = 0; j < map.height(); j++)
		{
			if (map.node(i,j) == 'w')
			{
				createWall(i,j);
			}
		}
	}
}

void Game::createWall(int iNodeX, int iNodeY)
{
	for (int i = 0; i<iMaxEntities;i++)
	{
		if(walls[i] == NULL)
		{
			walls[i] = creator->createWall(iNodeX,iNodeY);
			return;
		}
	}
}

void Game::initialiseEntities()
{
	for (int i = 0; i<iMaxEntities;i++)
	{
		walls[i] = NULL;
	}
}

void Game::render(sf::RenderWindow &window)
{
	for (int i = 0; i<iMaxEntities;i++)
	{
		if ( walls[i] != NULL)
		{
			window.draw(*walls[i]);
		}
	}

	window.draw(selection);
}

void Game::updateGameState(char cKeyPressed, sf::RenderWindow& window)
{
	if (m_GameState == eGameState::playing)
	{
		//update();
		render(window);


		if (cKeyPressed == 0)
			m_GameState = eGameState::paused; 


		if (cKeyPressed == 'W')
		{

		}


	}	
}

vector2d Game::nodeFromPosition(int x, int y)
{
	vector2d v2dResult(x/_iNodeSize,y/_iNodeSize);
	return v2dResult;
}

void Game::updateMouseClick(int x, int y)
{
	if (m_ModeState = eModeState::editor)
	{
		placeWall(x,y);
	}
}

void Game::updateMouseMove(int x, int y)
{
	selection.setNodePosition(x/16,y/16);
}

void Game::placeWall(int x, int y)
{
	vector2d pos(nodeFromPosition(x,y));

	for (int i = 0; i<iMaxEntities;i++)
	{
		if ( walls[i] != NULL)
		{
			if (pos == walls[i]->nodePosition())
			{
				cout<<"wall already there."<<endl;
				return;
			}
		}
	}
	
	cout<<"wall created at node "<< pos.x() << " "<< pos.y()<<endl;
	createWall(pos.x(),pos.y());
}

void Game::holdingLeft(bool b)
{
	bHoldingLeft = b;
}

void Game::updateMouseHold(int x, int y)
{
	if (m_ModeState = eModeState::editor)
	{
		placeWall(x,y);
	}
}