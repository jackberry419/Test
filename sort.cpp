#include <string.h>
#include <time.h>
#include <iostream>
#include <cassert>
#include <cstring>
#include <ctime>
//#include <stack>
//#include "copy_constructor.h"
//#include "use_static.h"
//#include "use_operator_overload.h"
//#include "node.h"
//#include <map>
//#include "use_template.cpp"
using namespace std;

#define SORT_NUM 40000


void checkSort(int *number, int max){
	for(int i=0; i<max-1; i++){
		if(number[i+1]<number[i]){
			cout<<"Sorting is incorrect" <<endl;		
		}
	}
	cout<<"Sorting is correct"<<endl;
}


int partition(int *number, int l, int r){
	int pivot, i, j, tmp;
	// select the last number in the array as the pivot
	pivot = number[r];
    i = l; 
	j = r-1;

	while (1){
	  while(number[i] <= pivot && i < r) i++;
	  while(number[j] > pivot) j--;
	  if( i >= j) break;
	  tmp = number[i]; 
	  number[i] = number[j];
	  number[j] = tmp;
	}
	//insert the pivot into the array
	tmp = number[r]; 
	number[r] = number[i];
	number[i] = tmp;
	return i;
}

void quickSort(int *number, int l, int r){
	if (l>r) return;
	int m; 
	m = partition(number,l,r);
	quickSort(number, l, m-1);
	quickSort(number, m+1, r);
}


void bubbleSort(int *number, int max){
	int tmp;
	for(int i=0;i<max-1;i++){
		for(int j=0;j<max-1-i;j++){
			if(number[j] > number[j+1]){
			tmp = number[j];
			number[j] = number[j+1];
			number[j+1] = tmp;
			}
		}
	}
}

void insertionSort(int *number, int max){
	int tmp;
	//current index 
	int c_i;
	for(int i=1;i<max;i++){
		c_i= i;
		while(number[c_i]<number[c_i-1] && c_i > 0){
			tmp=number[c_i];
			number[c_i] = number[c_i-1];
			number[c_i-1] = tmp;
			c_i -- ;
		}
	}
}


int main(){
	int *number = new int[SORT_NUM];
	srand(time(NULL));

	for (int i=0;i<SORT_NUM;i++){
		number[i] = rand();
		//cout<<number[i]<<"  ";
	}
	clock_t begin = clock();
	//bubbleSort(number, SORT_NUM);
	//insertionSort(number,SORT_NUM);
	quickSort(number,0, SORT_NUM-1);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "sorting time is:  " << elapsed_secs<<" seconds"<<endl;

/*	
	for (int i=0;i<SORT_NUM;i++){
		cout<<number[i]<<endl; 
	}*/

	checkSort(number, SORT_NUM);

	delete number;
}

