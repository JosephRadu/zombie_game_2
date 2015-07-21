#ifndef MAP_H
#define MAP_H

#include <iostream>

using namespace std;

class Map
{
protected:
	static const int iWorldSize = 64;
	char world[iWorldSize][iWorldSize];

	int iWidth;
	int iHeight;

	string sAuthor;
	string sName;
	string sDescription;
public:
	Map();
	void setNode(int x, int y, char c);
	char node(int x, int y);

	void setWidth(int width);
	void setHeight(int height);

	int width();
	int height();
	
	string name();
	string author();
	string description();

	void setName(string name);
	void setAuthor(string author);
	void setDescription(string description);


};

#endif
