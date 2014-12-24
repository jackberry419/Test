#include <string.h>
#include <iostream>
#include <cassert>
#include <cstring>
#include <list>
//#include "sort.h"
//#include <stack>
//#include "copy_constructor.h"
//#include "use_static.h"
//#include "use_operator_overload.h"
//#include "node.h"
//#include <map>
//#include "use_template.cpp"
using namespace std;

//stl test 


int main(){
	list<int> my_list;
	my_list.push_back(111);
	my_list.push_back(22);
	my_list.push_back(33);
	my_list.sort();

	list<int>::iterator it;

	  for (it=my_list.begin(); it!=my_list.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';



}