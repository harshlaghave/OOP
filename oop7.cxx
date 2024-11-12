
#include <iostream>

using namespace std;

// Function template for Selection Sort
template <typename T>
void selectionSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;

		// Find the minimum element in the unsorted part of the array
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		// Swap the minimum element with the first element of the unsorted part
		T temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}
}

// Function template to print an array
template <typename T>
void printArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int size;
	cout << "Enter Array Size : " << endl;
	cin >> size;

	int intArray[size];
	float floatArray[size];

	// Input integer array
	cout << "Enter integer array elements: ";
	for (int i = 0; i < size; i++)
	{
		cin >> intArray[i];
	}

	// Input float array
	cout << "Enter float array elements: ";
	for (int i = 0; i < size; i++)
	{
		cin >> floatArray[i];
	}

	// Print original arrays
	cout << "Original Integer Array: ";
	printArray(intArray, size);

	cout << "Original Float Array: ";
	printArray(floatArray, size);

	// Sort arrays
	selectionSort(intArray, size);
	selectionSort(floatArray, size);

	// Print sorted arrays
	cout << "Sorted Integer Array: ";
	printArray(intArray, size);

	cout << "Sorted Float Array: ";
	printArray(floatArray, size);

	return 0;
}
