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
  int sizes [5]={4,2,7,6,-1};
  int ** bd2= allocate_twod <int> (sizes);
  if (debug){
  cout<<"Initializing all the values to -1\n";
  }
  init_twod <int> (bd2,sizes,-1);
  int** walker =bd2;
  int count = array_size (sizes);
  int* walkman_jr = *walker;
  int current_size=*sizes;
  string test = array_string <int> (walkman_jr, current_size);
  if (debug){
  print_twod (bd2, sizes);
  cout<<test<<"\n";
  }
  if (test!="-1-1-1-1"){
    cout<<"Expected (-1-1-1-1), but found "<< test<< "\n";
    return false;
  }
  if (debug){
    cout<<"Sucess testing with ints\n";
  }
  walkman_jr = *(walker + 2);
  current_size= *(sizes+2);
  test = array_string <int> (walkman_jr, current_size);
  if (debug)
  cout<<test<<"\n";
  if (test!= "-1-1-1-1-1-1-1"){
    cout<<"Expected (-1-1-1-1-1-1-1), but found "<< test<< "\n";
    return false;
  }

  if (debug){
    cout<<"Sucess testing with ints 2\n";
  }

bd2=deallocate_twod <int> (bd2,4);
int caps [8]={5,6,7,2,4,3,1,-1};
char ** letters = allocate_twod <char> (caps);
init_twod <char> (letters, caps, 'a');
char* reference= *(letters+2);
int current_cap = *(caps+2);
test = array_string <char> (reference, current_cap);
  if (debug)
  cout<<test<<"\n";
  if (test!=  "aaaaaaa"){
    cout<<"Expected (aaaaaaa), but found "<< test<< "\n";
    return false;
  }
  if (debug)
  cout<<"Sucess in testing with chars \n";
return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_STUB, TestInit) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_init(false));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

