#include "Life.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<windows.h>
using namespace std;

Life::Life()
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            space[i][j] = 0;
        }
    }
}

Life::~Life()
{

}


int Life::Check_Rule(int i, int j)
{
    int Life_Count = 0;
    for (int k = i - 1; k < i + 2; k++)
    {
        for (int n =  j - 1; n < j + 2; n++)
        {
            Life_Count = Life_Count + space[k][n];
        }
    }
    Life_Count = Life_Count - space[i][j];

    if (Life_Count == 3 && space[i][j] == 0)
    {
        space[i][j] = 1;
    }
    if ((Life_Count < 2 || Life_Count > 3) && space[i][j] == 1)
        space[i][j] = 1;
    return 0;
}

void Life::Print_Space()
{
    for (int i = 1; i < a - 1; i++)
    {
        for (int j = 1; j < b - 1; j++)
        {
            if (space[i][j] == 1)
                cout << "@";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void Life::Generate_Life()
{
    for (int i = 1; i < a - 1; i++)
    {
        for (int j = 1; j < b - 1; j++)
        {
            space[i][j] = rand() % 4;
        }
    }
}

void Life::Run_Life()
{
    Generate_Life();
    Print_Space();
    Sleep(100);
    system("cls");
    while (1)
    {
        for (int i = 1; i < a - 1; i++)
        {
            for (int j = 1; j < b - 1; j++)
            {
                Check_Rule(i, j);
            }
        }
        Print_Space();
        Sleep(50);
        system("cls");
    }
}
