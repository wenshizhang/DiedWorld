#include <vector>
#include <string>

using namespace std;

class Generation
{
	private:
		vector<vector<int> > cellWorld;
		int GnrtNum;
		int Row;
		int Col;
	public:
		typedef vector<vector<int>> matrix_int;
		Generation():GnrtNum(0),Row(0),Col(0){};
		Generation(vector<vector<int> > &cw):cellWorld(cw),GnrtNum(0){
			if(!cw.empty()&&!cw[0].empty()){
				Col = cw.size();
				Row = cw[0].size();
			}
		};
		

		void nextGeneration();
		matrix_int getDiedOrLive();
		int calcCellState(int x,int y);
		void update(matrix_int);

		int getGnrtNum(){return GnrtNum;}
		int getRow(){return Row;}
		int getCol(){return Col;}
		void resetCellWorld(vector<vector<int> > &cw){cellWorld = cw; GnrtNum = 0;}
		vector<vector<int> > getCellWorld(){return cellWorld;}
		void show();
}
