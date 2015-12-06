/*
	subset sum : given n elements in array, find if it's possible to get sum s, and also find how many ways to make sum out of elements
*/

#include <string>
#include <vector>

#define LEN(x)	(sizeof(x) / sizeof((x)[0]))

using namespace std;

class SubsetSum1
{
public:
	SubsetSum1();
	~SubsetSum1();

	bool equalSum(int *array, int targetSum) {
		if (array == NULL) {
			return false;
		}

		int retSub = getSubset(array, targetSum, 0, 0, LEN(array));
		return retSub > 0 ? true : false;
	}	

	int getSubset(int *array, int targetSum, int currentSum, int beginPos, int endPos) {
		if (beginPos > endPos) {
			return -1;
		}

		quickSort(array, 0, LEN(array));
		int nWays = 0;
		currentSum = array[0];

		int midPos = (beginPos + endPos) / 2;
		if (array[midPos] == targetSum) { 
			nWays += 1;
		}
		else if (array[midPos] < targetSum) {
			if (currentSum == targetSum) {
				nWays	+= 1;
			}
			else if (currentSum < targetSum) {
				int remain = targetSum - currentSum;
				getSubset(array, remain, currentSum, beginPos + 1, midPos);
			}
		}
		else if (array[midPos] > targetSum) {
			getSubset(array, targetSum, 0, midPos - 1);
		}
	}

	void swap(int* a, int* b)
	{
	    int t = *a;
	    *a = *b;
	    *b = t;
	}
	 
	int partition (int arr[], int l, int h) {
	    int x = arr[h];    // pivot
	    int i = (l - 1);  // Index of smaller element
	 
	    for (int j = l; j <= h- 1; j++)
	    {
	        if (arr[j] <= x)
	        {
	            i++;    // increment index of smaller element
	            swap(&arr[i], &arr[j]);  // Swap current element with index
	        }
	    }
	    swap(&arr[i + 1], &arr[h]);  
	    return (i + 1);
	}
	 
	void quickSort(int arr[], int l, int h) {
	    if (l < h)
	    {
	        int p = partition(arr, l, h); /* Partitioning index */
	        quickSort(arr, l, p - 1);
	        quickSort(arr, p + 1, h);
	    }
	}
 
};