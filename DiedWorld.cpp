#include "Generation.h"
#include "transVector.h"

#define ITER_GENERATE	10000

matrix_int InitGeneration();


int main()
{
	matrix_int ret = InitGeneration();
	Generation world(ret);

	world.show();
	while(world.getGenerationNum() < ITER_GENERATE)
	{
		world.nextGeneration();
		world.show();
	}

	return 0;
}

matrix_int InitGeneration()
{
	vector<pair<int,int>> vect;

    vect.push_back(pair<int,int>(0,0)); 	
    vect.push_back(pair<int,int>(0,2)); 	
    vect.push_back(pair<int,int>(0,5)); 	
    vect.push_back(pair<int,int>(1,1)); 	
    vect.push_back(pair<int,int>(1,4)); 	
    vect.push_back(pair<int,int>(1,7)); 	
    vect.push_back(pair<int,int>(1,9)); 	
    vect.push_back(pair<int,int>(2,0)); 	
    vect.push_back(pair<int,int>(2,2)); 	
    vect.push_back(pair<int,int>(2,5)); 	
    vect.push_back(pair<int,int>(2,7)); 	
    vect.push_back(pair<int,int>(3,4)); 	
    vect.push_back(pair<int,int>(4,1)); 	
    vect.push_back(pair<int,int>(4,3)); 	
    vect.push_back(pair<int,int>(4,5)); 	
    vect.push_back(pair<int,int>(4,7)); 	
    vect.push_back(pair<int,int>(4,9)); 	
    vect.push_back(pair<int,int>(5,0)); 	
    vect.push_back(pair<int,int>(5,2)); 	
    vect.push_back(pair<int,int>(5,4)); 	
    vect.push_back(pair<int,int>(5,6)); 	
    vect.push_back(pair<int,int>(5,8)); 	
    vect.push_back(pair<int,int>(6,5)); 	
    vect.push_back(pair<int,int>(7,4)); 	
    vect.push_back(pair<int,int>(7,8)); 	
    vect.push_back(pair<int,int>(8,0)); 	
    vect.push_back(pair<int,int>(8,1)); 	
    vect.push_back(pair<int,int>(8,2)); 	
    vect.push_back(pair<int,int>(8,5)); 	
    vect.push_back(pair<int,int>(8,7)); 	
    vect.push_back(pair<int,int>(8,8)); 	
    vect.push_back(pair<int,int>(8,9)); 	
    vect.push_back(pair<int,int>(9,4)); 	
    vect.push_back(pair<int,int>(9,8)); 	

	auto ret = transVector(vect,10,10);
	return ret;
}
