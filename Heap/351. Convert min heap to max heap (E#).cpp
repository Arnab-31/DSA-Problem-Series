https://www.geeksforgeeks.org/convert-min-heap-to-max-heap/

Approach - heapify every element starting from the bottom most
TC - O(n)

// C# program to convert
// min Heap to max Heap
using System;

class GFG
{
	// To heapify a subtree with
	// root at given index
	static void MaxHeapify(int []arr,
						int i, int n)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int largest = i;
		if (l < n && arr[l] > arr[i])
			largest = l;
		if (r < n && arr[r] > arr[largest])
			largest = r;
		if (largest != i)
		{
			// swap arr[i] and arr[largest]
			int temp = arr[i];
			arr[i] = arr[largest];
			arr[largest] = temp;
			MaxHeapify(arr, largest, n);
		}
	}

	// This function basically
	// builds max heap
	static void convertMaxHeap(int []arr,
							int n)
	{
		// Start from bottommost and
		// rightmost internal mode and
		// heapify all internal modes
		// in bottom up way
		for (int i = (n - 2) / 2; i >= 0; --i)
			MaxHeapify(arr, i, n);
	}

	// A utility function to print
	// a given array of given size
	static void printArray(int []arr,
						int size)
	{
		for (int i = 0; i < size; ++i)
			Console.Write(arr[i]+" ");
	}
	
	// Driver Code
	public static void Main ()
	{
		// array representing Min Heap
		int []arr = {3, 5, 9, 6, 8,
					20, 10, 12, 18, 9};
		int n = arr.Length;

		Console.Write("Min Heap array : ");
		printArray(arr, n);

		convertMaxHeap(arr, n);

		Console.Write("\nMax Heap array : ");
		printArray(arr, n);
	}
}

// This code is contributed by nitin mittal.