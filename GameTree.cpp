#include "GameTree.h"
#include <iostream>
#include <cstring>
using namespace std;

GameTree::GameTree(void)
{
}
GameTree::~GameTree(void)
{
}
int GameTree::MaxValue(GameTreeNode *s,char *c,int alpha, int beta, int a)
{
	
	GameTreeNode g=*s;//g is s
	g.Setlevel(s->Getlevel());//g's level is s's level
	GameTreeNode n[10];//n save the next state node 
	int count=0;//count
	if(Terminal_Test(&g,c)==0)//if g's level is 0, display
	{ 
		g.SetEval_value(Evaluation(&g,c));//g's eval_value setting 
		return g.GetEval_value();//return g's eval_value
	}
	if(strcmp(c,"Black")==0)//if c is Black, display 
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(g.Getstate()[i][j]=='B')//if g's state[i][j] is 'B', display
				{
					if(i-1>=0 && g.Getstate()[i-1][j]==0)//pawn move go
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i-1][j]='B';
						count++;//count increase
					}
					if(j-1>=0 && g.Getstate()[i][j-1]==0)//pawn move left
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i][j-1]='B';
						count++;//count increase
					}
					if(j+1<3 && g.Getstate()[i][j+1]==0)//pawn move right
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i][j+1]='B';
						count++;//count increase
					}
					if(i-1>=0 && j-1>=0 && g.Getstate()[i-1][j-1]=='W')//pawn move left kill
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i-1][j-1]='B';
						count++;//count increase
					}
					if(i-1>=0 && j+1<3 && g.Getstate()[i-1][j+1]=='W')//pawn move right kill
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i-1][j+1]='B';
						count++;//count increase
					}
				}
			}
		}	
	}
	if(strcmp(c,"White")==0)//if c is White, display
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(g.Getstate()[i][j]=='W')//if g's state[i][j] is 'W', display
				{
					if(i+1<3 && g.Getstate()[i+1][j]==0)//pawn move go
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i+1][j]='W';
						count++;//count increase
					}
					if(j-1>=0 && g.Getstate()[i][j-1]==0)//pawn move left
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i][j-1]='W';
						count++;//count increase
					}
					if(j+1<3 && g.Getstate()[i][j+1]==0)//pawn move right
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i][j+1]='W';
						count++;//count increase
					}
					if(i+1<3 && j+1<3 && g.Getstate()[i+1][j+1]=='B')//pawn move left kill
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i+1][j+1]='W';
						count++;//count increase
					}
					if(i+1<3 && j-1>=0 && g.Getstate()[i+1][j-1]=='B')//pawn move right kill
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i+1][j-1]='W';
						count++;//count increase
					}
				}
			}	
		}	
	}
	for(int k=0;k<count;k++) //repeat until k is count
	{	
		int Temp=MinValue(&n[k],c,alpha, beta);//temp is MinValue function's result
		//max
		if(Temp>alpha)//if temp is large than alpha
		{
			alpha=Temp;//alpha is temp
			if(a==1)//if a is 1
			{
				cur=n[k];//cur is n
			}
		}
		//aplha, beta pruning
		if(alpha>=beta)//if aplha is large beta, display
		{	
			return beta;//return beta
		}
	}
	return alpha;//return alpha
}
int GameTree::MinValue(GameTreeNode *s,char *c,int alpha, int beta)
{
	GameTreeNode g=*s;//g is s
	g.Setlevel(s->Getlevel());//g's level is s's level
	GameTreeNode n[10];//n save the next state node
	int count=0;//count
	if(Terminal_Test(&g,c)==0)//if g's level is 0, display
	{ 
		g.SetEval_value(Evaluation(&g,c));//g's eval_value setting 
		return g.GetEval_value();//return g's eval_value
	}
	if(strcmp(c,"Black")==0)//if c is Black, display
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(g.Getstate()[i][j]=='W')//if g's state[i][j] is 'W', display
				{
					if(i+1<3 && g.Getstate()[i+1][j]==0)//pawn move go
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i+1][j]='W';
						count++;//count increase
					}
					if(j-1>=0 && g.Getstate()[i][j-1]==0)//pawn move left
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i][j-1]='W';
						count++;//count increase
					}
					if(j+1<3 && g.Getstate()[i][j+1]==0)//pawn move right
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i][j+1]='W';
						count++;//count increase
					}
					if(i+1<3 && j+1<3 && g.Getstate()[i+1][j+1]=='B')//pawn move left kill
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i+1][j+1]='W';
						count++;//count increase
					}
					if(i+1<3 && j-1>=0 && g.Getstate()[i+1][j-1]=='B')//pawn move right kill
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i+1][j-1]='W';
						count++;//count increase
					}
				}
			}	
		}	
	}
	else if(strcmp(c,"White")==0)//if c is White, display
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(g.Getstate()[i][j]=='B')//if g's state[i][j] is 'B', display
				{
					if(i-1>=0 && g.Getstate()[i-1][j]==0)//pawn move go
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i-1][j]='B';
						count++;//count increase
					}
					if(j-1>=0 && g.Getstate()[i][j-1]==0)//pawn move left
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i][j-1]='B';
						count++;//count increase
					}
					if(j+1<3 && g.Getstate()[i][j+1]==0)//pawn move right
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i][j+1]='B';
						count++;//count increase
					}
					if(i-1>=0 && j-1>=0 && g.Getstate()[i-1][j-1]=='W')//pawn move left kill
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i-1][j-1]='B';
						count++;//count increase
					}
					if(i-1>=0 && j+1<3 && g.Getstate()[i-1][j+1]=='W')//pawn move rigth kill
					{
						n[count]=g;//n save g's state
						n[count].Getstate()[i][j]=0;
						n[count].Getstate()[i-1][j+1]='B';
						count++;//count increase
					}
				}
			}
		}	
	}
	
	for(int k=0;k<count;k++) //repeat until k is count
	{

		int Temp=MaxValue(&n[k],c, alpha, beta,0);//temp is MinValue function's result
		//min
		if(Temp<beta)//if temp is small than beta
		{
			beta=Temp;//beta is temp
		}
		//Alpha-Beta pruning
		if(alpha>=beta)//if alpha is large than beta
		{
			return alpha;//return alphay
		}
	}
	return beta;//return beta
}
int GameTree::Terminal_Test(GameTreeNode *g,char *c)//check the end of the game
{
	g->SetEval_value(Evaluation(g,c));//g's eval_value is setting
	if(g->GetEval_value()==100 || g->GetEval_value()==-100 || g->Getlevel()==0)//if g's eval_value is 100, -100 or g's level is 0, display
	{
		return 0;//return 0
	}
	else //else
		g->Setlevel(g->Getlevel()-1);//g's level decrease 1
	return -1;//return -1
}
int GameTree::Evaluation(GameTreeNode *g,char *c)//evaluation fuction
{
	int rw=0,rb=0;
	if(strcmp(c,"White")==0)//if c is "White", display
	{//evalue for W
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(g->Getstate()[2][j]=='W')//if g'state[2][j] is W,  
				{
					g->SetEval_value(100);//Eval_value is 100, White win
					return g->GetEval_value();
				}
				else if(g->Getstate()[0][j]=='B')//if g'state[0][j] is B, 
				{
					g->SetEval_value(-100);//Eval_value is -100, Black win
					return g->GetEval_value();
				}
				else//else
				{
					if(g->Getstate()[i][j]=='W')//if g'state[i][j] is W,  
						rw+=(i+1)*(i+1);//rw=(i+1)^2
					else if(g->Getstate()[i][j]=='B')//else if g'state[0][j] is B, 
						rb+=((3-i)*(3-i));//rb=(3-i)^2
				}
			}
		}
		g->SetEval_value(rw-rb);//Eval_value is rw-rb
	}
	else if(strcmp(c,"Black")==0)//else if c is "Black", display
	{//evalue for B
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(g->Getstate()[2][j]=='W')//if g'state[2][j] is W,
				{
					g->SetEval_value(-100);//Eval_value is -100, White win
					return g->GetEval_value();
				}
				else if(g->Getstate()[0][j]=='B')//if g'state[0][j] is B, 
				{
					g->SetEval_value(100);//Eval_value is 100, Black win
					return g->GetEval_value();
				}
				else
				{
					if(g->Getstate()[i][j]=='W')//if g'state[i][j] is W,
						rw+=(i+1)*(i+1);//rw=(i+1)^2
					else if(g->Getstate()[i][j]=='B')//else if g'state[0][j] is B, 
						rb+=((3-i)*(3-i));//rb=(3-i)^2
				}
			}
		}
		g->SetEval_value(rb-rw);//Eval_value is rb-rw
	}
	return g->GetEval_value();//return 
}
GameTreeNode *GameTree::input(GameTreeNode *g,char *c,int row,int col)
{
	if(strcmp(c, "White")==0)//if c is "White",display
	{
		if(g->Getstate()[row][col]==0 || g->Getstate()[row][col]=='B')//if g's state[row][col] is empty or B, 
			g->Getstate()[row][col]='W';//g's state[row][col] is W
	}
	else if(strcmp(c, "Black")==0)//else if c is "Black", display
	{
		if(g->Getstate()[row][col]==0 || g->Getstate()[row][col]=='W')//if g's state[row][col] is empty or W,
			g->Getstate()[row][col]='B';//g's state[row][col] is B
	}
	return g;//return g
}

GameTreeNode* GameTree::GetState(GameTreeNode *a)//copy function
{
	a=&cur;//a is cur
	return a;//return a
}
void GameTree::print(GameTreeNode *g)//print function
{
	cout<<" ------ "<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<" ";
		for(int j=0;j<3;j++)
		{
			if(g->Getstate()[i][j]==0)
			{
				cout<<" "<<g->Getstate()[i][j]<<"|";
			}
			else
				cout<<g->Getstate()[i][j]<<"|";
		}
		cout<<endl;
	}
	cout<<" ------ "<<endl;
}
