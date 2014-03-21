#include "Manager.h"
#include <iostream>
#include <cstring>
using namespace std;

Manager::Manager(void)
{
}
void Manager::consol()
{
	int row, col;
	int result;
	G=new GameTree();//Generation gametree
	N=new GameTreeNode();//Generation game
	N->FillBoard();
	N->Setlevel(3);//level is setting of 3
	char c[20];
	cout<<"Please choose your color(White or Black)? ";//choose color
	cin>>c;
	if(strcmp(c,"Black")==0)// if c is Black, display
	{
		cout<<"BLACK : USER / WHITE : COMPUTER "<<endl;
		cout<<"INITIAL"<<endl;
		G->print(N);//print game state
		while(1)
		{
			N->Setlevel(3);
			result=G->MaxValue(N,"White",-1000,1000,1);
			cout<<"COMPUTER"<<endl;
			N=G->GetState(N);
			if(result==100)//result is 100
			{
				cout<<"it's your Turn!"<<endl;
				G->print(N);//print game state
				cout<<"First, which pawn do you want to move?"<<endl;//Enter pawn move
				cout<<"X(1~3)?";
				cin>>row;
				cout<<"Y(1~3)?";
				cin>>col;
				if(N->Getstate()[row-1][col-1]!='B')//if n's state[row-1][col-1] is not B, again Enter pawn move
				{
					cout<<"Again, which pawn do you want to move?"<<endl;//Enter pawn move
					cout<<"X(1~3)?";
					cin>>row;
					cout<<"Y(1~3)?";
					cin>>col;
				}
				N->Getstate()[row-1][col-1]=0;
				cout<<"which pawn do you want to move?"<<endl;//Enter x, y move on
				cout<<"X(1~3)?";
				cin>>row;
				cout<<"Y(1~3)?";
				cin>>col;
				N=G->input(N,c,row-1,col-1);//input,
				result=G->MaxValue(N,"White",-1000,1000,1);//result save MaxValue function' result 
				G->print(N);
				cout<<"White win"<<endl;//White win
				break;
			}
			else if (result==-100)//result is -100
			{
				cout<<"it's your Turn!"<<endl;
				G->print(N);
				cout<<"First, which pawn do you want to move?"<<endl;//Enter pawn move
				cout<<"X(1~3)?";
				cin>>row;
				cout<<"Y(1~3)?";
				cin>>col;
				if(N->Getstate()[row-1][col-1]!='B')//if n's state[row-1][col-1] is not B, again Enter pawn move
				{
					cout<<"Again, which pawn do you want to move?"<<endl;//Enter pawn move
					cout<<"X(1~3)?";
					cin>>row;
					cout<<"Y(1~3)?";
					cin>>col;
				}
				N->Getstate()[row-1][col-1]=0;
				cout<<"which pawn do you want to move?"<<endl;//Enter x, y move on
				cout<<"X(1~3)?";
				cin>>row;
				cout<<"Y(1~3)?";
				cin>>col;
				N=G->input(N,c,row-1,col-1);//input,
				result=G->MaxValue(N,"White",-1000,1000,1);//result save MaxValue function' result
				G->print(N);
				cout<<"Black win"<<endl;
				break;
			}
			cout<<"it's your Turn!"<<endl;
			G->print(N);
			cout<<"First, which pawn do you want to move?"<<endl;//Enter pawn move
			cout<<"X(1~3)?";
			cin>>row;
			cout<<"Y(1~3)?";
			cin>>col;
			if(N->Getstate()[row-1][col-1]!='B')//if n's state[row-1][col-1] is not B, again Enter pawn move
			{
				cout<<"Error!"<<endl;
				cout<<"The pawn ("<<row<<","<<col<<") is NOT yours."<<endl;//Enter pawn move
				cout<<"Again, which pawn do you want to move?"<<endl;
				cout<<"X(1~3)?";
				cin>>row;
				cout<<"Y(1~3)?";
				cin>>col;
				N->Getstate()[row-1][col-1]=0;
				cout<<"which pawn do you want to move?"<<endl;//Enter x, y move on
				cout<<"X(1~3)?";
				cin>>row;
				cout<<"Y(1~3)?";
				cin>>col;
			


				N=G->input(N,c,row-1,col-1);//input
				G->Evaluation(N,c);
				G->print(N);
				N->Setlevel(3);
			}
			else if(N->Getstate()[row-1][col-1]=='B')//else if n's state[row-1][col-1] is B, again Enter pawn move
			{
				N->Getstate()[row-1][col-1]=0;
				cout<<"which pawn do you want to move?"<<endl;//Enter x, y move on
				cout<<"X(1~3)?";
				cin>>row;
				cout<<"Y(1~3)?";
				cin>>col;


				N=G->input(N,c,row-1,col-1);//input
				G->Evaluation(N,c);
				G->print(N);
				N->Setlevel(3);//level  reset
			}
		}
	}
	else if(strcmp(c,"White")==0)//else if c is White, display
	{
		cout<<"BLACK : COMPUTER / WHITE : USER "<<endl;
		cout<<"it's your Turn!"<<endl;
		while(1)
		{
			G->print(N);
			cout<<"First, which pawn do you want to move?"<<endl;//Enter pawn move
			cout<<"X(1~3)?";
			cin>>row;
			cout<<"Y(1~3)?";
			cin>>col;
			
			if(N->Getstate()[row-1][col-1]=='W')//if n's state[row-1][col-1] is W, display
			{
				N->Getstate()[row-1][col-1]=0;
				cout<<"which pawn do you want to move?"<<endl;//Enter x, y move on
				cout<<"X(1~3)?";
				cin>>row;
			
				cout<<"Y(1~3)?";
				cin>>col;
				
				N=G->input(N,c,row-1,col-1);//input
				G->Evaluation(N,c);
				G->print(N);
				N->Setlevel(3);
				result=G->MaxValue(N,"Black",-1000,1000,1);//result save MaxValue function' result
				N=G->GetState(N);
				if(result==100)//if result is 100, display 
				{//Black win
					cout<<"it's your Turn!"<<endl;
					G->print(N);
					cout<<"First, which pawn do you want to move?"<<endl;//Enter pawn move
					cout<<"X(1~3)?";
					cin>>row;
					cout<<"Y(1~3)?";
					cin>>col;
					if(N->Getstate()[row-1][col-1]!='W')//else if n's state[row-1][col-1] is W, again Enter pawn move
					{
						cout<<"Again, which pawn do you want to move?"<<endl;//Enter pawn move
						cout<<"X(1~3)?";
						cin>>row;
						cout<<"Y(1~3)?";
						cin>>col;
					}
					N->Getstate()[row-1][col-1]=0;
					cout<<"which pawn do you want to move?"<<endl;//Enter x, y move on
					cout<<"X(1~3)?";
					cin>>row;
					cout<<"Y(1~3)?";
					cin>>col;
					N=G->input(N,c,row-1,col-1);
					result=G->MaxValue(N,"Black",-1000,1000,1);//result save MaxValue function' result
					G->print(N);
					cout<<"Black win"<<endl;
					break;
				}
				else if (result==-100)//else if result is -100, display
				{//white win
					cout<<"it's your Turn!"<<endl;
					G->print(N);
					cout<<"First, which pawn do you want to move?"<<endl;//Enter pawn move
					cout<<"X(1~3)?";
					cin>>row;
					cout<<"Y(1~3)?";
					cin>>col;
					if(N->Getstate()[row-1][col-1]!='W')//if n's state[row-1][col-1] is W, again Enter pawn move
					{
						cout<<"Again, which pawn do you want to move?"<<endl;//Enter pawn move
						cout<<"X(1~3)?";
						cin>>row;
						cout<<"Y(1~3)?";
						cin>>col;
					}
					N->Getstate()[row-1][col-1]=0;
					cout<<"which pawn do you want to move?"<<endl;//Enter x, y move on
					cout<<"X(1~3)?";
					cin>>row;
					cout<<"Y(1~3)?";
					cin>>col;
					N=G->input(N,c,row-1,col-1);
					result=G->MaxValue(N,"White",-1000,1000,1);//result save MaxValue function' result
					G->print(N);
					cout<<"White win"<<endl;
					break;
				}
			}
			else if(N->Getstate()[row-1][col-1]!='W')//else if n's state[row-1][col-1] is not W, again Enter pawn move
			{
				cout<<"Error!"<<endl;
				cout<<"The pawn ("<<row<<","<<col<<") is NOT yours."<<endl;
			}
		}
	}
}

Manager::~Manager(void)
{
}

void Manager::filegame()
{
	char *c;
	int x,y;
	int result;
	G=new GameTree();//Generation game
	N=new GameTreeNode();//Generation gametree
	N->FillBoard();
	N->Setlevel(3);//level is setting of 3
	f.readcommand();
	c=f.readcommand();
	if(strcmp(c,"B")==0)// if c is B, display
	{
		f.startmanu1();
		f.Savestate(N);
		while(1)
		{
			result=G->MaxValue(N,"White",-1000,1000,1);
			N=G->GetState(N);
			if(result==100)//if result is 100, display
			{//White win
				
				f.computermessage();
				f.Savestate(N);
				
				f.readchar();//Enter pawn move
				x=f.readnum();
				f.readchar();
				y=f.readnum();
				f.readchar();
				if(N->Getstate()[x-1][y-1]!='B')//else if n's state[row-1][col-1] is not B, again Enter pawn move
				{
					f.readchar();//Enter pawn move
					x=f.readnum();
					f.readchar();
					y=f.readnum();
					f.readchar();
				}
				N->Getstate()[x-1][y-1]=0;
				f.readchar();//Enter x, y move on
				x=f.readnum();
				f.readchar();
				y=f.readnum();
				f.readchar();
				N=G->input(N,c,x-1,y-1);
				result=G->MaxValue(N,"White",-1000,1000,1);//result save MaxValue function' result
				f.usermessage();
				f.Savestate(N);
				f.endmanu1();
				f.Savestring("White win");
				break;//end
			}
			else if (result==-100)//if result is -100, display
			{//Black win
				f.computermessage();
				f.Savestate(N);
				f.readchar();//Enter pawn move
				x=f.readnum();
				f.readchar();
				y=f.readnum();
				f.readchar();
				if(N->Getstate()[x-1][y-1]!='B')
				{
					f.readchar();//Enter pawn move
					x=f.readnum();
					f.readchar();
					y=f.readnum();
					f.readchar();
				}
				N->Getstate()[x-1][y-1]=0;
				f.readchar();//Enter x, y move on
				x=f.readnum();
				f.readchar();
				y=f.readnum();
				f.readchar();
				N=G->input(N,"Black",x-1,y-1);
				
				f.usermessage();
				f.Savestate(N);
				f.endmanu1();
				f.Savestring("Black win");
				break;//end
			}
			
			f.computermessage();
			f.Savestate(N);
			
			f.readchar();//Enter pawn move
			x=f.readnum();
			f.readchar();
			y=f.readnum();
			f.readchar();
			if(N->Getstate()[x-1][y-1]!='B')// if n's state[row-1][col-1] is not B, again Enter pawn move
			{
				f.errormessage(x,y);
				N->Getstate()[x-1][y-1]=0;
				f.readchar();//pass
				x=f.readnum();
				f.readchar();
				y=f.readnum();
				f.readchar();
				f.readchar();//Enter pawn move
				x=f.readnum();
				f.readchar();
				y=f.readnum();
				f.readchar();
				f.readchar();//Enter x, y move on
				x=f.readnum();
				f.readchar();
				y=f.readnum();
				f.readchar();
				N=G->input(N,c,x-1,y-1);
				G->Evaluation(N,c);
				f.usermessage();
				f.Savestate(N);
				N->Setlevel(3);
			}
			else if(N->Getstate()[x-1][y-1]=='B')//else if n's state[row-1][col-1] is B, display
			{
				N->Getstate()[x-1][y-1]=0;
				f.readchar();//Enter x, y move on
				x=f.readnum();
				f.readchar();
				y=f.readnum();
				f.readchar();
				N=G->input(N,"Black",x-1,y-1);
				f.usermessage();
				G->Evaluation(N,c);
				f.Savestate(N);
				N->Setlevel(3);
			}
		}
	}

	else if(strcmp(c,"W")==0)//else if c is W, display
	{
		f.startmanu2();
		while(1)
		{
			f.computermessage();
			f.Savestate(N);
			f.readchar();//Enter pawn move
			x=f.readnum();
			f.readchar();
			y=f.readnum();
			f.readchar();
			if(N->Getstate()[x-1][y-1]=='W')
			{
				N->Getstate()[x-1][y-1]=0;
				f.readchar();//Enter x, y move on
				x=f.readnum();
				f.readchar();
				y=f.readnum();
				f.readchar();
				N=G->input(N,"White",x-1,y-1);
				G->Evaluation(N,c);
				f.usermessage();
				f.Savestate(N);
				N->Setlevel(3);
				result=G->MaxValue(N,"Black",-1000,1000,1);//result save MaxValue function' result
				N=G->GetState(N);
				if(result==100)//if result is 100, display
				{
					f.computermessage();
					f.Savestate(N);
					f.readchar();//Enter pawn move
					x=f.readnum();
					f.readchar();
					y=f.readnum();
					f.readchar();
					if(N->Getstate()[x-1][y-1]!='W')//if n's state[row-1][col-1] is not W, display
					{
						f.readchar();//Enter pawn move
						x=f.readnum();
						f.readchar();
						y=f.readnum();
						f.readchar();
					}
					N->Getstate()[x-1][y-1]=0;
					f.readchar();//Enter x, y move on
					x=f.readnum();
					f.readchar();
					y=f.readnum();
					f.readchar();
					N=G->input(N,"White",x-1,y-1);
					result=G->MaxValue(N,"Black",-1000,1000,1);//result save MaxValue function' result
					f.computermessage();
					f.Savestate(N);
					f.endmanu1();
					f.Savestring("Black win");//black win
					break;
				}
				else if (result==-100)//else if result is -100,display
				{
					f.Savestate(N);
					f.readchar();
					x=f.readnum();
					f.readchar();
					y=f.readnum();
					f.readchar();
					if(N->Getstate()[x-1][y-1]!='W')//if n's state[row-1][col-1] is not W, display
					{
						f.readchar();
						x=f.readnum();
						f.readchar();
						y=f.readnum();
						f.readchar();
					}
					N->Getstate()[x-1][y-1]=0;
					f.readchar();//Enter x, y move on
					x=f.readnum();
					f.readchar();
					y=f.readnum();
					f.readchar();
					N=G->input(N,"White",x-1,y-1);
					result=G->MaxValue(N,"White",-1000,1000,1);//result save MaxValue function' result
					f.usermessage();
					f.Savestate(N);
					f.endmanu1();
					f.Savestring("White win");
					break;
				}
			}
			else if(N->Getstate()[x-1][y-1]!='W')// if n's state[row-1][col-1] is not B, again Enter pawn move
			{
				f.errormessage(x,y);
			}
		}
	}
	f.fileclose();//file close
	
}
