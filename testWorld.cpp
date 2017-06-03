#include "Generation.h"
#include <gtest/gtest.h>
#include "transVector.h"
TEST(newGeneration,test3){
	vector<vector<int > > vect(3,vector<int>(3));
    vect.push_back(pair<int,int>(1,0)); 	
    vect.push_back(pair<int,int>(1,1)); 	
    vect.push_back(pair<int,int>(1,2)); 	
	vector<vector<int > > vect_EXPECT(3,vector<int>(3));
    vect_EXPECT.push_back(pair<int,int>(0,1)); 	
    vect_EXPECT.push_back(pair<int,int>(1,1)); 	
    vect_EXPECT.push_back(pair<int,int>(2,1)); 	
	Generation nowGen(vect);
	nowGen.nextGeneration();
	EXPECT_EQ(nowGen.getCellWorld(),vect_EXPECT);
}
