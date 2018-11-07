// C++ program for implementation of Heap Sort 
#include <iostream> 
  
using namespace std; 
void pHeap(int arr[], int n,int i ) 
{
    int l;
    int r;

	    if ( i >=n) return;
	    if ( i == 0 ) 
std::cout << "     " << arr[i] << '\n';

     l = 2*i + 1; // left = 2*i + 1 
     r = 2*i + 2; // right = 2*i + 2 
     if( l < n )
	    std::cout << arr[l] << "       ";
     if( r < n )
	    std::cout << arr[r] << '\n';


pHeap(arr,n,l);
pHeap(arr,n,r);
}
  
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
	std::cout << "Swap " << arr[i] << " " << arr[largest] << std::endl;
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
void printArray(int arr[], int n) ;
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
	    std::cout << "call heapify \n";
        printArray(arr, n); 
        heapify(arr, n, i); 
    }
    std::cout << "-- Start sort step ----------------------------\n";
        printArray(arr, n); 
    std::cout << "-- Start sort step ----------------------------\n";
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  
/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = {3,19,1,14,8,7};       
    int n = sizeof(arr)/sizeof(arr[0]); 
    pHeap(arr, n,0); 

    if ( 0 )
    {
    cout << "Unsorted array  \n"; 
    printArray(arr, n); 
    cout << "----------\n"; 
    }  
    heapSort(arr, n); 

  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
} 
