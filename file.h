#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "GameTreeNode.h"
using namespace std;

class file
{
private:
	ifstream fin;//file read
	ofstream fout;//file write
	char element[20];
public:
	file(void);//constructor
	~file(void);//deconstructor
	char* readcommand();// file contents input to element
	int readnum();//file contents input to element
	char readchar();//fuil contents input to element

	void Saveint(int n);//data input to file
	void Savechar(char c);//data input to file
	void Savestring(char *c);//data input to file
	void Savestate(GameTreeNode *g);//data input to file

	void startmanu1();//startmanu
	void startmanu2();//startmanu
	void usermessage();//usermessage
	void computermessage();//computermessage
	void endmanu1();//finish message

	void errormessage(int x, int y);//errormesage

	void fileclose();//close file
};
