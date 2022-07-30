// CPP PROGRAM TO IMPLEMENT 
// BINARY SEARCH IN 
// STANDARD TEMPLATE LIBRARY (STL)
#include <algorithm>
#include <iostream>

using namespace std;

void show(int a[], int arraysize)
{
	for (int i=0; i < arraysize; ++i)
		cout << a[i] << ",";
}

int main ()
{
	int a[] = {1,5,8,9,6,7,3,4,2,0};
	int asize = sizeof(a) / sizeof (a[0]);
	cout << "\n the array is : \n";
	show(a, asize);
	
	cout << "\n\n Lets say we want to search for ";
	cout << "\n2 in the array so, we first sort the array";
	sort(a, a + asize);
	cout << "\n\nThe array after sorting is : \n";
	show(a, asize);
	cout << "\n\n Now, we do the binary search";
	if (binary_search(a, a + 10, 2)){
		cout << "\n Element found in the array";
	}else {
		cout << "\n Element not found in the array";
	}
	
	cout << "\n\n Now, say we want to search for 10";
	if (binary_search(a, a + 10, 10)){
		cout << "\nElement found in the array";
	}else {
		cout<< "\n Element is not found in the array";
	}
	
	return 0;
}