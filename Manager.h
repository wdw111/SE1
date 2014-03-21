#pragma once
#include "GameTree.h"
#include "file.h"
class Manager
{
private:
	GameTree *G;
	GameTreeNode *N;//game state
	file f;

public:
	Manager(void);
	~Manager(void);
	void consol();//interactive mode
	void filegame();//batch mode
};

