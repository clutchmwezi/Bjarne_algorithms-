//C++ code to lineaarly search x in arr[].if x 
// is present then return its location , otherwise 
// return -1 

#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
	int i;
	for(int i = 0; i < n; i++)
		if(arr[i] == x)
			return i;
	return -1;
}

// driver code 
int main()
{
	int arr[] = {2, 3, 4, 10, 40};
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	
	
	// function call
	int result = search(arr, n, x);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index" <<result;
	return 0;
}