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

}

matrix_int Generation::getDiedOrLive()
{
	int i,j;
	matrix_int newcellWorld(Col,vector<int >(Row));

	for(i = 0;i < Row;i++)
		for(j = 0;j < Col;j++)
			newcellWorld[i][j] = calcCellState(i,j);

	return newcellWorld;

}

int Generation::calcCellState(int cellRow, int cellCol )
{
	int i,j;
	int neighbor;

	for (i = -1; i<2;i++)			//row
		for (j = -1; j<2 ;j++)			//col
		{
			if ((-1<cellRow+i<Row)&&(-1<cellCol+j<Col))
				neighbor += cellWorld[cellRow+i][cellCol+j];
			if (neighbor >= 3)
				return LIVE;
			else if (neighbor == 2)
				return UNCHANGE;
			else
				return DIED;
		}
}

void Generation::update(matrix_int newcellWorld)
{
	int i,j;

	for(i = 0;i < Row;i++)
		for(j = 0;j < Col;j++)
		{
			if(!newcellWorld[i][j])
				continue;						//state UNCHANGE do nothing

			else if(newcellWorld[i][j]== LIVE)
				cellWorld[i][j] = 1;
			else
				cellWorld[i][j] = 0;
		}
}

void Generation::show()
{
	int i,j;
	system("clear");
	for(i = 0; i< Row;i++)
	{
		for(j = 0;j < Col;j++)
			cout << cellWorld[i][j];
		cout<<"\n";
	}
	this_thread::sleep_for(chrono::seconds(1));
	system("clear");

}
