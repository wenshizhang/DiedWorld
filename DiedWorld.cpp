#include "Generation.h"
#include "transVector.h"

int main()
{
	vector<pair<int,int>> vect;
    vect.push_back(pair<int,int>(1,0)); 	
    vect.push_back(pair<int,int>(1,2)); 	
    vect.push_back(pair<int,int>(2,0)); 	
//    vect.push_back(pair<int,int>(1,2)); 	
 //   vect.push_back(pair<int,int>(2,1)); 	
	auto ret = transVector(vect,3,3);
	Generation world(ret);

	world.show();
	while(world.getGnrtNum()<10000){
		world.nextGeneration();
		world.show();
	}
	return 0;
}


