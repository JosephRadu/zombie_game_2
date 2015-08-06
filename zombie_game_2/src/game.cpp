#include "game.h"


Game::Game(sf::RenderWindow& w)
{
	selection.colour(22,222,22);
	initialiseEntities();
	scanForMaps();
	//generateMap(*maps[0]);
	m_GameState = eGameState::playing; 
	m_ModeState = eModeState::editor;
	cSelectedBrush = 'w';
	mapEditorInit();
}

void Game::mapEditorMapSelection()
{
	system("cls");
	int iSelection;
	bool bSelected = false;

	for (int i = 0; i < iMaxMaps; i++)
	{
		if (maps[i] != NULL)
		{
			cout<<"["<<i<<"] | "<<maps[i]->name()<<endl;
		}
		else
		{
			cout<<"["<<i<<"] | "<<"Return to home"<<endl;
			break;

		}
	}



	cout<<"Input map number."<<endl;

	while (bSelected == false)
	{
		cin>>iSelection;

		for (int i = 0; i < iMaxMaps; i++)
		{
			if (maps[i] != NULL && i == iSelection)
			{
				generateMap(*maps[i]);
				iSelectedMap = i;
				bSelected = true;
				break;
			}
			else
			{
				mapEditorHome();
			}
		}



		if (bSelected == false)
		{
			cout<<"Invalid selection."<<endl;
		}

	}
}

void Game::mapEditorInit()
{
	system("cls");
	mapEditorHome();
}

void Game::mapEditorHome()
{
	system("cls");
	cout<<"Map Editor | HOME |"<<endl;

	cout<<"[0] | Map selection"<<endl;
	cout<<"[1] | Exit"<<endl;

	cout<<"Input option"<<endl;

	int iInput;

	cin>>iInput;

	if (iInput == 0)
	{
		mapEditorMapSelection();
	}

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
				//std::cout << "Adding "<< file.cFileName << " ... ";
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
	maps[mapNumber] = creator->createMap();
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
					//cout<<line[i];
					maps[mapNumber]->setNode(j,i,line[i]);
				}
					maps[mapNumber]->setWidth(line.length());
				j++;
				//cout<<""<<endl;
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
					maps[mapNumber]->setName(b);
				}
				else if (a == "map_author")
				{
					maps[mapNumber]->setAuthor(b);
				}
				else if (a == "map_description")
				{
					maps[mapNumber]->setDescription(b);
				}
			}
		}
		maps[mapNumber]->setHeight(j);
    }
	
	//std::cout<<"map "<<maps[mapNumber]->name()<<" has been built."<<std::endl;

	modelfile.close();
}

void Game::generateMap(Map& map)
{
	cout<<"Generating "<<map.name()<<endl;
	for (int i = 0; i < map.width(); i++)
	{
		for ( int j = 0; j < map.height(); j++)
		{
			if (map.node(i,j) == 'w')
			{
				createBrush(i,j,'w');
			}
			else if (map.node(i,j) == 'b')
			{
				createBrush(i,j,'b');
			}
			else if (map.node(i,j) == 'h')
			{
				createBrush(i,j,'h');
			}
		}
	}

	cout<<"[Q] | Editor options"<<endl;
}

void Game::createBrush(int iNodeX, int iNodeY, char c)
{
	if (c == 'w')
	{
		for (int i = 0; i<iMaxWalls;i++)
		{
			if(walls[i] == NULL)
			{
				walls[i] = creator->createWall(iNodeX,iNodeY);
				return;
			}
		}
	}
	else if (c == 'b')
	{
		for (int i = 0; i<iMaxBreakables;i++)
		{
			if(breakables[i] == NULL)
			{
				breakables[i] = creator->createBreakable(iNodeX,iNodeY);
				return;
			}
		}
	}
	else if (c == 'h')
	{
		for (int i = 0; i<iMaxHumans;i++)
		{
			if(humans[i] == NULL)
			{
				humans[i] = creator->createHuman(iNodeX,iNodeY);
				return;
			}
		}
	}


}

void Game::initialiseEntities()
{
	for (int i = 0; i<iMaxWalls;i++)
	{
		walls[i] = NULL;
	}

	for (int i = 0; i<iMaxMaps;i++)
	{
		maps[i] = NULL;
	}

	for (int i = 0; i<iMaxBreakables;i++)
	{
		breakables[i] = NULL;
	}

	for (int i = 0; i<iMaxHumans;i++)
	{
		humans[i] = NULL;
	}
}

void Game::renderWorld(sf::RenderWindow &window)
{
	camera.update();

	for (int i = 0; i<iMaxWalls;i++)
	{
		if (walls[i] != NULL)
		{
			window.draw(*walls[i]);
		}
		//else break;
	}

	for (int i = 0; i<iMaxBreakables;i++)
	{
		if (breakables[i] != NULL)
		{
			window.draw(*breakables[i]);
		}
		//else break;
	}

	for (int i = 0; i<iMaxHumans;i++)
	{
		if (humans[i] != NULL)
		{
			window.draw(*humans[i]);
		}
		//else break;
	}



	window.draw(selection);
}

void Game::updateKeyboardInput(char cKeyPressed)
{
	if (m_ModeState = eModeState::editor)
	{
		if (cKeyPressed == 'q') mapEditorOptions();
		else if (cKeyPressed == 'r') removeBrush(nodeFromPosition(selection.position().x(),selection.position().y()));
		else if (cKeyPressed == 1) switchBrush(1);
		else if (cKeyPressed == 2) switchBrush(2);
		else if (cKeyPressed == 3) switchBrush(3);
	}
}

void Game::render(sf::RenderWindow& window)
{
	if (m_GameState == eGameState::playing)
	{
		render(window);
	}	
}

vector2d Game::nodeFromPosition(int x, int y)
{
	vector2d v2dResult(x/_iNodeSize,y/_iNodeSize);
	return v2dResult;
}

void Game::updateMouseMove(float x, float y)
{
	mouse.setPosition(x,y);
	selection.setPosition(x,y);
}

void Game::removeBrush(vector2d v2d)
{
	for (int i = 0; i<iMaxWalls;i++)
	{
		if ( walls[i] != NULL)
		{
			if (v2d == walls[i]->nodePosition())
			{
				walls[i] = NULL;
				return;
			}
		}
	}

	for (int i = 0; i<iMaxBreakables;i++)
	{
		if ( breakables[i] != NULL)
		{
			if (v2d == breakables[i]->nodePosition())
			{
				breakables[i] = NULL;
				return;
			}
		}
	}

	for (int i = 0; i<iMaxHumans;i++)
	{
		if ( humans[i] != NULL)
		{
			if (v2d == humans[i]->nodePosition())
			{
				humans[i] = NULL;
				return;
			}
		}
	}
}

void Game::placeBrush(float x, float y, char c)
{
	vector2d pos(nodeFromPosition(x,y));


		for (int i = 0; i<iMaxWalls;i++)
		{
			if ( walls[i] != NULL)
			{
				if (pos == walls[i]->nodePosition())
				{
					//cout<<"wall already there."<<endl;
					return;
				}
			}
		}


		for (int i = 0; i<iMaxBreakables;i++)
		{
			if ( breakables[i] != NULL)
			{
				if (pos == breakables[i]->nodePosition())
				{
					//cout<<"wall already there."<<endl;
					return;
				}
			}
		}

		for (int i = 0; i<iMaxHumans;i++)
		{
			if ( humans[i] != NULL)
			{
				if (pos == humans[i]->nodePosition())
				{
					//cout<<"wall already there."<<endl;
					return;
				}
			}
		}
	vector2d v2d(nodeFromPosition(selection.position().x(),selection.position().y()));

	createBrush(v2d.x(),v2d.y(),c);

	//cout<<"wall created at node "<< pos.x() << " "<< pos.y()<<endl;

}

void Game::switchBrush(int i)
{
	//cout<<i<<endl;
	if (i == 1)
	{
		cSelectedBrush = 'w';
		cout<<"Brush | WALL | selected."<<endl;
	}
	else if (i == 2)
	{
		cSelectedBrush = 'b';
		cout<<"Brush | BREAKABLE | selected."<<endl;
	}
	else if (i == 3)
	{
		cSelectedBrush = 'h';
		cout<<"Brush | HUMAN | selected."<<endl;
	}


}
void Game::leftMouse(bool b)
{
	mouse.leftPressed(b);
}

void Game::leftMouseClick(float x, float y)
{
	mouse.setPosition(x,y);
	selection.setPosition(x,y);
	mouse.leftPressed(true);

	if (m_ModeState = eModeState::editor)
	{
		placeBrush(selection.position().x(),selection.position().y(),cSelectedBrush);
	}
}

void Game::rightMouse(bool b)
{
	mouse.rightPressed(b);
}

void Game::rightMouseClick(float x, float y)
{
	vector2d v2d(x,y);
	mouse.rightPressed(true);




	if (m_ModeState = eModeState::editor)
	{
		removeBrush(nodeFromPosition(selection.position().x(),selection.position().y()));
	}
}

void Game::updateMouseHold(float x, float y)
{
	mouse.setPosition(x,y);
	selection.setPosition(x,y);

	if (m_ModeState = eModeState::editor)
	{
		placeBrush(selection.position().x(),selection.position().y(),cSelectedBrush);
	}
}

void Game::saveToMap(Map& map)
{
	vector2d pos(0,0);

	for (int i = 0; i<iMaxWalls;i++)
	{
		if (walls[i] != NULL)
		{
			pos.set(walls[i]->nodePosition());
			map.setNode(pos.x(),pos.y(),'w');
		}
	}

	for (int i = 0; i<iMaxBreakables;i++)
	{
		if (breakables[i] != NULL)
		{
			pos.set(breakables[i]->nodePosition());
			map.setNode(pos.x(),pos.y(),'b');
		}
	}

	for (int i = 0; i<iMaxHumans;i++)
	{
		if (humans[i] != NULL)
		{
			pos.set(humans[i]->nodePosition());
			map.setNode(pos.x(),pos.y(),'h');
		}
	}
	
}

int Game::createMap(string sName, string sAuthor, string sDescription)
{
	for (int i=0; i<iMaxMaps;i++)
	{
		if (maps[i] == NULL)
		{
			maps[i]=creator->createMap();
			vector2d pos;
			for (int j = 0; j<iMaxWalls;j++)
			{
				if ( walls[j] != NULL)
				{
						if (maps[i]->width() <= walls[j]->nodePosition().x())
						{
							maps[i]->setWidth(walls[j]->nodePosition().x());
						}

						if (maps[i]->height() <= walls[j]->nodePosition().y())
						{
							maps[i]->setHeight(walls[j]->nodePosition().y());
						}
				}
			}

			for (int j = 0; j<iMaxBreakables;j++)
			{
				if ( breakables[j] != NULL)
				{
						if (maps[i]->width() <= breakables[j]->nodePosition().x())
						{
							maps[i]->setWidth(breakables[j]->nodePosition().x());
						}

						if (maps[i]->height() <= breakables[j]->nodePosition().y())
						{
							maps[i]->setHeight(breakables[j]->nodePosition().y());
						}
				}
			}

			for (int j = 0; j<iMaxHumans;j++)
			{
				if ( humans[j] != NULL)
				{
						if (maps[i]->width() <= humans[j]->nodePosition().x())
						{
							maps[i]->setWidth(humans[j]->nodePosition().x());
						}

						if (maps[i]->height() <= humans[j]->nodePosition().y())
						{
							maps[i]->setHeight(humans[j]->nodePosition().y());
						}
				}
			}


			maps[i]->setHeight(maps[i]->height()+1);
			maps[i]->setWidth(maps[i]->width()+1);

			maps[i]->setName(sName);
			maps[i]->setAuthor(sAuthor);
			maps[i]->setDescription(sDescription);

			return i;

		}
	}
}

void Game::mapToFile(Map& map)
{
  ofstream modelFile;
  modelFile.open ("maps/" +map.name() + ".txt");

  cout<<"Writing "<<map.name()<<" to a txt file"<<endl;

  //if (modelFile.is_open)
 // {
	modelFile << "map_info_start\n";

	modelFile << "map_name "+map.name()+"\n";
	modelFile << "map_author "+map.author()+"\n";
	modelFile << "map_description "+map.description()+"\n";
	modelFile << "map_info_end\n";


	for (int i = 0; i < map.width(); i++)
	{
		for ( int j = 0; j < map.height(); j++)
		{
			if (map.node(i,j) == 'w')
			{
				modelFile << "w";
			}
			else if (map.node(i,j) == 'b')
			{
				modelFile << "b";
			}
			else if (map.node(i,j) == 'h')
			{
				modelFile << "h";
			}
			else
			{
				modelFile << "-";
			}
		}
			modelFile << "\n";
	}


	 modelFile.close();
  //}

  cout<<"Finished writing map"<<endl;
}

void Game::updateCameraControls(sf::Event& eventIn)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		camera.setXPanAmount(-camera.cameraSpeed());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		camera.setXPanAmount(camera.cameraSpeed());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		camera.setYPanAmount(-camera.cameraSpeed());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		camera.setYPanAmount(camera.cameraSpeed());
	}


	if (eventIn.type == sf::Event::MouseWheelMoved)
	{
		camera.setZoom(camera.zoom()+(-1*(eventIn.mouseWheel.delta*0.005)));
	}

}

void Game::updateZoom(sf::View& sfView)
{
	sfView.zoom(camera.zoom());
}

void Game::updateCamera(sf::View& sfView)
{
	camera.setPosition(camera.position().x()+camera.xPanAmount(),camera.position().y()+camera.yPanAmount());
	sfView.setCenter(camera.position().x(),camera.position().y());
}

void Game::mapEditorOptions()
{
	system("cls");

	cout<<"Map Editor | Editor |"<<endl;

	cout<<"[0] | Save map"<<endl;
	cout<<"[1] | Clear map"<<endl;
	cout<<"[2] | Exit to map editor home"<<endl<<endl;

	cout<<"Input option"<<endl;

	int iInput;

	cin>>iInput;

	if (iInput == 0)
	{
		mapEditorSaveMap();
	}
	else if (iInput == 1)
	{
		initialiseEntities();
	}
	else if (iInput == 2)
	{
		mapEditorHome();
	}
	else
	{
		mapEditorHome();
	}
}

void Game::mapEditorSaveMap()
{
	system("cls");
	string sName;
	string sAuthor;
	string sDescription;

	cout<<"Enter map name"<<endl;
	cin>>sName;
	cout<<"Enter author name"<<endl;
	cin>>sAuthor;
	cout<<"Enter description name"<<endl;
	cin>>sDescription;

	int iMap = createMap(sName,sAuthor,sDescription);
	saveToMap(*maps[iMap]);
	mapToFile(*maps[iMap]);	
}