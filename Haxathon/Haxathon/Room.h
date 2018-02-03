#ifndef Room_h
#define Room_h

#include <iostream>
#include <vector>

#include "Shelf.h"

using namespace std;
class Room
{
public:
	vector<Shelf> Shelves;
	int RoomID;
	vector<string> History;
};
#endif