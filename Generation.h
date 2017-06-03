#include <vector>
#include <string>

using namespace std;

class Generation
{
	private:
		vector<vector<int> > cellWorld;
		int GnrtNum;
	public:
		Generation():GnrtNum(0){};
		Generation(vector<vector<int> > &cw):cellWorld(cw),GnrtNum(0){};
		
		vector<vector<int> > nextGeneration();
		vector<vector<int> > getCellWorld(){return cellWorld;}
		int getGnrtNum(){return GnrtNum;}
		void resetCellWorld(vector<vector<int> > &cw){cellWorld = cw; GnrtNum = 0;}
		void show();
}
