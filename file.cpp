#include "file.h"
#include <iostream>
#include <cstring>
using namespace std;
file::file(void)//constructor
{
	fin.open("input.txt");//input.txt file open
	fout.open("output.txt");//output.txt file open
}

file::~file(void)//deconstructor
{
}

char* file::readcommand()// read to file
{
	if(!fin.eof())// if file is not end, display
		fin>>element;//file contents input to element
	else//else
		strcpy(element,"END");//"END" input to element
	return element;//return element
}
int file::readnum()// read to file
{
	int element;
	if(!fin.eof())// if file is not end, display
		fin>>element;//file contents input to element
	else//else
		element=0;//"END" input to element
	return element;//return element
}
char file::readchar()// read to file
{
	char element;
	if(!fin.eof())// if file is not end, display
		fin>>element;//file contents input to element
	else//else
		element=0;//"END" input to element
	return element;//return element
}
void file::startmanu1()//start manu
{
	fout<<"================================"<<endl;
	fout<<"BLACK : USER / WHITE : COMPUTER "<<endl;
	fout<<"INITIAL"<<endl;
}
void file::startmanu2()//start manu
{
	fout<<"================================"<<endl;
	fout<<"BLACK : COMPUTER / WHITE : USER "<<endl;
	fout<<"INITIAL"<<endl;
}
void file::errormessage(int x, int y)//error message
{
	fout<<"Error!"<<endl;
	fout<<"The pawn ("<<x<<","<<y<<") is NOT yours."<<endl;
	return;
}

void file::Saveint(int n)//data input to file
{
	fout<<n<<endl;
	return;
}
void file::Savechar(char c)//data input to file
{
	fout<<c<<endl;
	return;
}
void file::Savestring(char *c)//data input to file
{
	fout<<c<<endl;
	return;
}
void file::usermessage()//user message
{
	fout<<"================================"<<endl;
	fout<<"USER"<<endl;
}
void file::computermessage()//computer message
{
	fout<<"================================"<<endl;
	fout<<"COMPUTER"<<endl;
}	
void file::endmanu1()//finish
{
	fout<<"================================"<<endl;
	fout<<"GAME FINISH"<<endl;
}	

void file::Savestate(GameTreeNode *g)//data input to file
{
	fout<<"------ "<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<" ";
		for(int j=0;j<3;j++)
		{
			if(g->Getstate()[i][j]==0)
			{
				fout<<"_"<<"|";
			}
			else
				fout<<g->Getstate()[i][j]<<"|";
		}
		fout<<endl;
	}
	fout<<"------ "<<endl;
}
void file::fileclose()//close the file
{
	fin.close();
	fout.close();
}
