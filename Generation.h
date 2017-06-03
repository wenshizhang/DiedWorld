#ifndef __GENERATION_H
#define __GENERATION_H

#define UNCHANGE 0
#define TO_LIVE	2
#define TO_DIED	-2


#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef vector<vector<int>> matrix_int;

class Generation
{
	private:
		vector<vector<int> > cellWorld;
		int GenerationNum;
		int Row;
		int Col;
	public:
		Generation():GenerationNum(0),Row(0),Col(0){};
		Generation(vector<vector<int> > &cw):cellWorld(cw),GenerationNum(0){
			if(!cw.empty()&&!cw[0].empty()){
				Col = cw.size();
				Row = cw[0].size();
			}
			else
			{
				cout<<"matrix empty!";
				exit(1);
			}
		};
		

		void nextGeneration();
		matrix_int getDiedOrLive();
		int calcCellState(int x,int y);
		void update(matrix_int);

		int getGenerationNum(){return GenerationNum;}
		int getRow(){return Row;}
		int getCol(){return Col;}
		void resetCellWorld(vector<vector<int> > &cw){cellWorld = cw; GenerationNum = 0;}
		vector<vector<int> > getCellWorld(){return cellWorld;}
		void show();
};
#endif
