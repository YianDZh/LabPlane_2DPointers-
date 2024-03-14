#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/two_d_functions/two_d_functions.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}
bool test_init (bool debug= false){
  int size =5;
  int sizes [size]={4,2,7,6,1};
  int ** bd2= allocate_twod <int> (sizes);
  cout<<"Created 2D array\n";
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

