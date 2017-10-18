/*******************************************************************************
* TestHeap.cpp
*
* author: Rikk Anderson
* date created: 10/16/2017
* last updated: 10/17/2017
*
* This files is used to test the class TreeHeap.
*
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#include "TreeHeap.h"

using std::cout;
using std::endl;

bool s_descending(std::string i, std::string j) { return (i>j); }


int main(void) {
  int item = 0;
  std::string ret = "";
  std::string c_ret = "";
  std::string s_ret = "";
  int count = 0, false_cnt = 0;

  TreeHeap *heap   = new TreeHeap();  // heap that store string representations of numbers
  TreeHeap *c_heap = new TreeHeap();  // heap that store string representations of characters
  TreeHeap *s_heap = new TreeHeap();  // string heap

  std::vector<std::string> small(16,"-1");
  std::vector<std::string> c_small(16, "y");

  small[0]  = "6";
  small[1]  = "15";
  small[2]  = "4";
  small[3]  = "12";
  small[4]  = "3";
  small[5]  = "22";
  small[6]  = "37";
  small[7]  = "9";
  small[8]  = "1";
  small[9]  = "7";
  small[10] = "43";
  small[11] = "57";
  small[12] = "73";
  small[13] = "17";
  small[14] = "13";
  small[15] = "11";

  c_small[0]  = "w";
  c_small[1]  = "a";
  c_small[2]  = "c";
  c_small[3]  = "e";
  c_small[4]  = "d";
  c_small[5]  = "f";
  c_small[6]  = "h";
  c_small[7]  = "s";
  c_small[8]  = "b";
  c_small[9]  = "v";
  c_small[10] = "z";
  c_small[11] = "x";
  c_small[12] = "g";
  c_small[13] = "t";
  c_small[14] = "q";
  c_small[15] = "m";

  cout << "***Testing small Heap #1 Insert\n";
  for(int i = 0, size = small.size(); i < size; i++) {
    heap->Insert(small[i]);
  }
  cout << "Inorder traversal: ";
  heap->print_heap();
  cout << endl << endl;

  cout << "***Testing small Heap #2 Insert\n";
  for(int i = 0, size = c_small.size(); i < size; i++) {
    c_heap->Insert(c_small[i]);
  }
  cout << "Inorder traversal: ";
  c_heap->print_heap();
  cout << endl << endl;

  cout << "***Testing small Heap #3 Insert\n";
  s_heap->Insert("15");
  s_heap->Insert("11");
  s_heap->Insert("13");
  s_heap->Insert("43");
  s_heap->Insert("cat");
  s_heap->Insert("dog");
  s_heap->Insert("MSU");
  s_heap->Insert("CSE");
  s_heap->Insert("EE");
  s_heap->Insert("CPE");

  cout << "Inorder traversal: ";
  s_heap->print_heap();
  cout << endl << endl;

  cout << "\n*Deleting Heap #1, numbers listed in chronological order\n";
  std::vector<std::string> temp(small);
  std::sort(temp.begin(), temp.end(), s_descending);
  for(int i = 0, size = small.size(); i < size; i++) {
    if(heap->Delete(ret) == false) {
      if(false_cnt < 5) cout << "Delete returned false when it should not have\n";
      false_cnt += 1;
    }
    if(ret != temp[i]) {
      cout << "Deleted value " << ret << " doesn't match expected value of " << temp[i] << endl;
      count += 1;
    }
    else {
      cout << ret << " ";
    }
  }
  cout << endl << endl;

  cout << "*Deleting Heap #2\n";
  std::vector<std::string> c_temp(c_small);
  std::sort(c_temp.begin(), c_temp.end(), s_descending);
  count = false_cnt = 0;
  for(int i = 0, size = c_small.size(); i < size; i++) {
    if(c_heap->Delete(c_ret) == false) {
      if(false_cnt < 5) cout << "Delete returned false when it should not have\n";
      false_cnt += 1;
    }
    if(c_ret != c_temp[i]) {
      cout << "Deleted value " << c_ret << " doesn't match expected value of " << c_temp[i] << endl;
      count += 1;
    }
    else {
      cout << c_ret << " ";
    }
  }
  cout << endl << endl;

  cout << "*Deleting Heap #3\n";
  std::vector<std::string> s_temp;
  s_temp.push_back("15");
  s_temp.push_back("11");
  s_temp.push_back("13");
  s_temp.push_back("43");
  s_temp.push_back("cat");
  s_temp.push_back("dog");
  s_temp.push_back("MSU");
  s_temp.push_back("CSE");
  s_temp.push_back("EE");
  s_temp.push_back("CPE");
  std::sort(s_temp.begin(), s_temp.end(), s_descending);

  count = false_cnt = 0;
  for(int i = 0, size = s_temp.size(); i < size; i++) {
    if(s_heap->Delete(s_ret) == false) {
      if(false_cnt < 5) cout << "Delete returned false when it should not have\n";
      false_cnt += 1;
    }
    if(s_ret != s_temp[i]) {
      cout << "Deleted value " << s_ret << " doesn't match expected value of " << s_temp[i] << endl;
      count += 1;
    }
    else {
      cout << s_ret << " ";
    }
  }
  cout << endl << endl;

} // end to main


