#include "transVector.h"

using namespace std;

vector<vector<int> > transVector(vector<pair<int,int>> vect_pair,int row, int col)
{
	vector<vector<int>> retVect(col,vector<int>(row));

	for(auto iter = vect_pair.begin();iter!=vect_pair.end();iter++)
	{
		retVect[iter->first][iter->second] = 1;
	}

	return retVect;
}
