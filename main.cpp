#include <iostream>
#include "Manager.h"
using namespace std;

int main()
{
	Manager M;
	int i;
	cout<<"Hexapawn"<<endl;//choose game mode
	cout<<"1. console game"<<endl;//interactive mode
	cout<<"2. file game"<<endl;//batch mode
	cout<<"choose:";
	cin>>i;
	if(i==1)
	{
		M.consol();
	}
	else if(i==2)
	{
		M.filegame();
	}
	return 0;
}
