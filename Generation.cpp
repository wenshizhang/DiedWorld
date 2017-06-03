#include "Generation.h"
#include <iostream>

using namespace std;

vector<vector<int> > Generation::nextGeneration()
{
	matrix_int newcellWorld;

	newcellWorld = getDiedOrLive();
	update(newcellWorld);

}

matrix_int Generation::getDiedOrLive()
{
	int i,j;
	matrix_int newcellWorld(col,vector<int >(row));

	for(i = 0;i < row;i++)
		for(j = 0;j < col;j++)
			newcellWorld[i][j] = calaCellState(int cellRow, int cellCol);

	return newcellWorld;

}

int Generation::calaCellState(int cellRow, int cellCol )
{
	int i,j;
	int neighbor;

	for (i = -1; i<2;i++)			//row
		for (j = -1; j<2 ;j++)			//col
		{
			if ((-1<cellRow+i<global_row)&&(-1<cellCol+j<global_row))
				neighbor += cellWorld[cellRow+i][cellCol+j];
			if neighbor >= 3
				return LIVE;
			else if neighbor == 2
				return UNCHANGE;
			else
				return DIED;
		}
}

void update(matrix_int newcellWorld)
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

void show()
{
	int i,j;
	for(i = 0; i< Row;i++)
	{
		for(j = 0;j < Col;j++)
			cout >> cellWorld[i][j];
		cout>>"\n";
	}
	clrscr();

}
