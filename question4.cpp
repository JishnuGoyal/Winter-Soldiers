#include<iostream>
#include<stdlib.h>
using namespace std;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void targetSum(int arr[], int n, int target)
{
    qsort(arr, n, sizeof(int), cmpfunc);
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum > target)
        {
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            cout << arr[left] << " and " << arr[right] << endl;
            left++;
            right--;
        }
    }
}

int main() {
	// int n;
	// cin>>n;
	// int arr[n];
	// for(int i=0;i<n;i++){
	// 	cin>>arr[i];
	// }
	// int x;
	// cin>>x;

int arr[] = {1,3,4,2,5} ;
	targetSum(arr,5,5);
	return 0;
}