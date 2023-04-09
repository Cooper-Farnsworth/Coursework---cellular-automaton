#pragma once
#define space_X 20
#define space_Y 20
 
const int a = space_X + 2;
const int b = space_Y + 2;

class Life
{
	int space[a][b];
	int Check_Rule(int i, int j);
	void Print_Space();
	void Generate_Life();
public:
	Life();
	~Life();
	void Run_Life();
};

