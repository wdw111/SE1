#include "GameTreeNode.h"

GameTreeNode::GameTreeNode(void)
{ 
	level=0;//level initialization
	Eval_value=0;//Eval_value initialization
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			state[i][j]=0;//state initialization
		}
	}
}

GameTreeNode::~GameTreeNode(void)
{
}
void GameTreeNode::FillBoard()//state fill basic state 
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==0)
			{
				state[i][j]='W';
			}
			else if(i==2)
			{
				state[i][j]='B';
			}
			else 
				state[i][j]=0;
		}
	}
}

