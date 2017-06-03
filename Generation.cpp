#include "Generation.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void  Generation::nextGeneration()
{
	matrix_int newcellWorld;

	newcellWorld = getDiedOrLive();
	update(newcellWorld);
	GenerationNum++;

}

matrix_int Generation::getDiedOrLive()
{
	int i,j;

	matrix_int newcellWorld(Col,vector<int >(Row));

	for(i = 0; i < Row; i++)
	{
		for(j = 0; j < Col; j++){
			newcellWorld[i][j] = calcCellState(i,j);
		}
	}

	return newcellWorld;
}

int Generation::calcCellState(int cellRow, int cellCol)
{
	int i,j;
	int neighbor = 0;

	for (i = -1; i<2; i++)			//row
	{
		for (j = -1; j<2; j++)			//col
		{
			if(i == 0 && j == 0)
				continue;

			//out range check
			if(cellRow+i <0 || cellRow+i >= Row)
				continue;
			if(cellCol+j < 0 || cellCol+j >= Col)
				continue;

			neighbor += cellWorld[cellRow+i][cellCol+j];
		}
	}

	if (neighbor == 3)
		return TO_LIVE;
	else if (neighbor == 2)
		return UNCHANGE;
	else
		return TO_DIED;
}

void Generation::update(matrix_int newcellWorld)
{
	int i,j;

	for(i = 0;i < Row;i++)
	{
		for(j = 0;j < Col;j++)
		{
			if(!newcellWorld[i][j])
				continue;						//state UNCHANGE do nothing

			else if(newcellWorld[i][j] == TO_LIVE)
				cellWorld[i][j] = 1;

			else
				cellWorld[i][j] = 0;
		}
	}
}

void Generation::show()
{
	int i,j;

	system("clear");

	for(i = 0; i < Row; i++)
	{
		for(j = 0;j < Col; j++)
		{
			if(cellWorld[i][j])
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	this_thread::sleep_for(chrono::seconds(1));
	system("clear");

}
