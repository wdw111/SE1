#pragma once
#include "GameTreeNode.h"

class GameTree
{
private:
	GameTreeNode cur;//cur is next state node
public:
	GameTree(void);//construct
	~GameTree(void);
	int MinValue(GameTreeNode *s,char *c,int alpha, int beta);//MinValue function
	int MaxValue(GameTreeNode *s,char *c,int alpha, int beta,int a);//MaxValue function, if a is 1, cur save next state node
	int Terminal_Test(GameTreeNode *g,char *c);//function is check the end of the game 
	int Evaluation(GameTreeNode *g,char *c);//eval value function
	void print(GameTreeNode *g);//output function
	GameTreeNode* input(GameTreeNode *g,char *c,int row,int col);//W move for user
	GameTreeNode* GetState(GameTreeNode *a); //state copy
};


