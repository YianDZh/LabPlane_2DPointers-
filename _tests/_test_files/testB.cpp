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
  deallocate_twod <char> (letters, 7);
  if (debug)
  cout<<"Sucess in testing with chars \n";
return true;
}
bool test_search_nd_write (bool debug = false){
  int sizes [5]={2,3,4,6,-1};
  int ** grid = allocate_twod <int> (sizes);
  init_twod <int> (grid,sizes,0);
  if (debug)
  cout<<"Array Initialized\n";
    write_twod <int> (grid, 0,0,1);
  write_twod <int> (grid, 1, 0,2);
  write_twod <int> (grid, 2,0,3);
  write_twod <int> (grid, 3,0,4);
  write_twod <int> (grid, 3,2,5);

  write_twod <int> (grid, 3,2,5);
  if (debug)
  print_twod <int> (grid,sizes);
  int* condition = search_twod <int> (grid, sizes, 5);
  if (*condition!=5){
    cout<<"Expected 5, but found "<<*condition;
    return false; 
  }
  cout<<"Passed";
  deallocate_twod <int> (grid, 4);
  if (debug)
  cout<<"Deallocated array\n";
  char ** grid2= allocate_twod <char> (sizes);
  init_twod <char> (grid2,sizes,'a');
  write_twod<char> (grid2,2,1,'z');
  write_twod<char> (grid2,0,1,'y');
  write_twod<char> (grid2,1,2,'c');
  if (debug)
    print_twod (grid2,sizes);
  char* num1 = search_twod <char> (grid2,sizes,'z');
  char* num2 = search_twod <char> (grid2,sizes,'y');
  char* num3 = search_twod <char> (grid2,sizes,'c');
  if (*num1 !='z'){
      cout<<"Expected 'z', but found "<<*num1<<"\n";
      return false;
  }
  if (*num2 !='y'){
      cout<<"Expected 'y', but found "<<*num2<<"\n";
      return false;
  }
    if (*num3 !='c'){
      cout<<"Expected 'c', but found "<<*num3<<"\n";
      return false;
  }

  if (debug)
  cout<<"Sucess on testing multiple locations";
  return true;
}
TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_2D, TestInit) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_init(false));
}
TEST(TEST_2D, TestSearch1andWrite) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_search_nd_write(true));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

