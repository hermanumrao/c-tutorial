// DataStructure.cpp : Defines the entry point for the console application.
//
/*This is an array of pointers 


int *p[10]; 


This is a pointer to a 10 element array 

or 
int (*p)[10]; 
*/

multiple dimension array
int *p[10];
    for (i=0; i<10; i++)
         p[i] = (int *)malloc(c * sizeof(int));
/*

int myarray[NO_OF_ROWS][NO_OF_COLUMNS]; 
myfunc(myarray); 


then, the function's declaration must match: 


void myfunc(int myarray[][NO_OF_COLUMNS]) 

or 

void myfunc(int (*myarray)[NO_OF_COLUMNS]) 


Since the called function does not allocate space for the array, it does not need to know the overall size, so the number of rows, NO_OF_ROWS, can be omitted. The width of the array is still important, so the column dimension 
NO_OF_COLUMNS must be present. 




An array is never passed to a function, but a pointer to the first element of the array is passed to the function. Arrays are automatically allocated memory. They can't be relocated or resized later. Pointers must be assigned to allocated memory (by using (say) malloc), but pointers can be reassigned and made to point to other memory chunks. 



Why is sizeof() an operator and not a function? 
Discuss it!          
sizeof() is a compile time operator. To calculate the size of an object, we need  



myfunc(&myarray[0][0], NO_OF_ROWS, NO_OF_COLUMNS); 

void myfunc(int *array_pointer, int no_of_rows, int no_of_columns) 
{ 
  // myarray[i][j] is accessed as array_pointer[i * no_of_columns + j] 
} 
*/
//#include "stdafx.h"
//http://linux.wku.edu/~lamonml/algor/sort/merge.html


#include "string.h"
#include "stdio.h"

/* * This program is free software; you can redistribute it and/or modify * i
see * http://linux.wku.edu/~lamonml/kb.html * */

#define NUM_ITEMS 5
void print(int numbers[], int array_size);

/////////////////////////////////// complexity n2
void bubbleSort(int numbers[], int array_size);   // all are non recursive 
void selectionSort(int numbers[], int array_size); 
void insertionSort(int numbers[], int array_size); 
void shellSort(int numbers[], int array_size);
/////////////////////////////////// complexity n2

/////////////////////////////////// complexity n log n

void heapSort(int numbers[], int array_size); // no recursive 
void mergeSort(int numbers[], int temp[], int array_size); //recursive draw back extra storage array needed
void quickSort(int numbers[], int array_size); //recursive
/////////////////////////////////// complexity n log n




int numbers[NUM_ITEMS] = {5,4,3,2,1};
int numbers1[NUM_ITEMS] = {1,2,3,4,5}; 



int main(int argc, char* argv[])
{ 
	char str1[] = "Good Boy"; 
    char str2[] = "The earth is round"; 
    int width = strlen ( str1 )  + 20; 
    int prec  = strlen ( str2 )  + 30; 
    printf ( "%*.*s\n", width, prec, str1 ); 

	int i=0;
	int aa[NUM_ITEMS]={5,5,5};
	aa[i]= 
	// important
	//int x = i++ + i++; //0
	i = i++ + i++;  // 2
	i = i++;
    aa[i]= i++; // some time 3 some time  aa[2] =2 
	
	aa[i]= ++i; // some time 3 some time  aa[3] =3
	int array_size = sizeof( numbers)/ sizeof( numbers[0]);

	print( numbers, NUM_ITEMS);
	printf("start  sorting.\n"); 
	
	quickSort( numbers, NUM_ITEMS);
	//int temp[NUM_ITEMS];
	//mergeSort(numbers, temp, NUM_ITEMS);

	printf("Done with sort.\n"); 
	
	print( numbers, NUM_ITEMS);
	return 0;

} 

void swap( int &x , int &y )
{
	int tmp = x;
	x= y;
	y= tmp;
	
}


void print(int numbers[], int array_size)
{
	for (int i = 0; i < array_size; i++) printf("%d ", numbers[i]); 
	printf("\n");
}




/*
5 4 3 2 1
start  sorting. n-1
4 3 2 1 5 m-1 
3 2 1 4 5 m-2
2 1 3 4 5 m-3
1 2 3 4 5 m-4
*/

void bubbleSort(int numbers[], int array_size)
{
  
  int i, j, indexElement;
  for (i=0; i < array_size-1; i++)
  {
	bool anySwap= false;	   
    for ( int j = 0 ; j < array_size-1 - i ; ++j )
    {
      if( numbers[j] > numbers[j+1] )
	  {
		anySwap = true;
		swap( numbers[j], numbers[j+1]);
	  }
    }
	
	print( numbers, array_size);
	if( !anySwap) break;

  }


}


//The selection sort works by selecting the smallest unsorted item remaining in the list, and then swapping it with the item in the next position to be filled. The selection sort has a complexity of O(n2). 
/*
5 4 3 2 1
start  sorting.
1 4 3 2 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
Done with sort.
1 2 3 4 5
*/

void selectionSort(int numbers[], int array_size)
{
  // you can not do sizeof( number) as it is pointer 
  int i, j;
  int min; 

  for (i = 0; i < array_size-1; i++)
  {
    min = i;
    for (j = i+1; j < array_size; j++)
    {
      if (numbers[j] < numbers[min])
        min = j;
    }
    swap(  numbers[i],  numbers[min]);
	print( numbers, array_size);
  }
	
}

/*start  sorting.
5 4 3 2 1
4 5 3 2 1
3 4 5 2 1
2 3 4 5 1
1 2 3 4 5
Done with sort.
*/
void insertionSort(int numbers[], int array_size)
{
  int i, j, indexElement;

  for (i=1; i < array_size; i++)
  {
    indexElement = numbers[i];
    j = i;
    while ((j > 0) && (numbers[j-1] > indexElement))
    {
      numbers[j] = numbers[j-1];
      j = j - 1;
    }
	numbers[j] = indexElement;
	print( numbers, array_size);
  }
}
/*
5 4 3 2 1
start  sorting.
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
2 4 3 5 1
2 1 3 5 4
 incrment Numbner 1
2 1 3 5 4
2 1 3 5 4
1 2 3 5 4
1 2 3 5 4
1 2 3 5 4
1 2 3 4 5
 incrment Numbner 0
1 2 3 4 5
Done with sort.
1 2 3 4 5
*/
//http://www.iti.fh-flensburg.de/lang/algorithmen/sortieren/shell/shellen.htm
void shellSort(int numbers[], int array_size)
{
    int i, j, increment, temp;

    increment = 3;
    while (increment > 0)
    {
        for (i=0; i < array_size; i++)
        {
            j = i;
            temp = numbers[i];
            while ((j >= increment) && (numbers[j-increment] > temp))
            {
                numbers[j] = numbers[j - increment];
                j = j - increment;
            }
            numbers[j] = temp;

            print( numbers, array_size);

        }
        if (increment/2 != 0)
            increment = increment/2;
        else if (increment == 1)
            increment = 0;
        else
            increment = 1;
		
		printf(" incrment Numbner %d \n", increment);
		print( numbers, array_size);
    }
}


/**********************************************************************************/

Please do not read this, chek heap.txt file for more clear details

// tutorial about heap sort;
// http://cis.stvincent.edu/html/tutorials/swd/heaps/heaps.html

void addtoHeap(int *, int);
void heapsort(int *, int, int);

int main_heap()
{
    int arr[20];
    int i, j, size, tmp, k;
    printf("\n\t------- Heap sorting method -------\n\n");
    printf("Enter the number of elements to sort : ");
    scanf("%d", &size);
    for (i = 1; i <= size; i++)
    {
        printf("Enter %d element : ", i);
        scanf("%d", &arr[i]);
        addtoHeap(arr, i);
    }
    j = size;
    for (i = 1; i <= j; i++)
    {
        tmp = arr[1];
        arr[1] = arr[size]; // remove first biggest element from heap and replace it with last element of array 
        arr[size] = tmp;
        size--;
        heapsort(arr, 1, size); // heapify the remaining array - 1
    }
    printf("\n\t------- Heap sorted elements -------\n\n");
    size = j;
    for (i = 1; i <= size; i++)
        printf("%d ", arr[i]);
    //getch();
    return 0;
}

void addtoHeap(int *arr, int i)  // top most value should be at 
{
    int tmp;
    tmp = arr[i];
    while ((i > 1) && (arr[i / 2] < tmp))
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }
    arr[i] = tmp;
}

void heapsort(int *arr, int i, int size)
{
    int tmp, j;
    tmp = arr[i];
    j = i * 2;
    while (j <= size)
    {
        if ((j < size) && (arr[j] < arr[j + 1]))
            j++;
        if (arr[j] < arr[j / 2])
            break;
        arr[j / 2] = arr[j];
        j = j * 2;
    }
    arr[j / 2] = tmp;
}



/// /// tutorial 

//MergeSort is a sorting algorithm which is more on the advanced end. It is very fast, but unfortunately uses up a lot of memory due to the recursions. It works by recursively splitting the array into two parts (at the midpoint if even number of elements is even, otherwise the right half has one extra) and recursing onto each of the two halves. Afterwards, the two halves are merged together (merging explained below). Here is a visual example of how MergeSort recursively splits the array in half for sorting. I'm using a diagram of a binary tree to represent the steps in our recursion process.


/// Google search with Merge sort tutorial

from bottom

{1}, {4}, 1}, {6, {8}, {5}, {3}, {7}

{1,4}   {1,6}   {5,8}  {3,7}

{ 1,1,4,6}    R= {3,5,7,8}
 

good algo of merge shot
please write algo for mergesort  for A={1,4,1,6,8, 5, 3, 7}

A= {}
k=0
Firt write algo  for merging two shorted  array
L={ 1,1,4,6}  R={3,5,7,8}
i=0              j=0

LRA are vectors
merge( L  R , A )
{
  int i,j,k=0
  int nL = strlen(L);
  int nR = strlen(R);
  
  while( i < nL  && j < nR)
  {
     if( L[i ] < R[j]
      A[k] = L[i]; k=k+1; i=i+1
     else
     A[k] = R[j]; k=k+1; j=j+1
  }
  while( i < nL )
  {
    A[k] = L[i]; k=k+1; i=i+1
  }

  while(  j < nR)
  {
     A[k] = R[j]; k=k+1; j=j+1
  }

}


sort( A)
{
  mid = LA/2
 
  for( ; i <mid ; ++i)
   L[i] =A[i] 
  
  for (j=mid; j <LA, ++j) 
   R[ j -mid] =A[j]
  sort(L)
  sort(R)

 merge( L,R A) 
}





void merge( V L, V R , V &A  )
{
    int ls = L.size();
    int rs = R.size();

    int l=0;
    int r=0;
    int a=0;
    while( r < rs && l < ls )
    {
        if( L[l]  > R[r] )
        {
            A[a++] = R[r];
            //A.push_back(R[r]);
             ++r;
        }  
        else
        {
            A[a++] = L[l];
           // A.push_back(L[l]);
            ++l;
        }
    }
    
    while( r < rs  )
    {
        //A.push_back(R[r]);
            A[a++] = R[r];
            ++r;
    }
    
    while(  l < ls )
    {
        //A.push_back(L[l]);
            A[a++] = L[l];
            ++l;
    }
    
}

void Display( const V & A)
{
    for(int i=0; i< A.size() ; ++ i)
    {
        cout << A[ i] << " " ;
    }
    
    cout << endl << flush; ;
}

void sort( V &A )
{
     int mid = A.size()/2;
     if( mid < 1) return ;
     
     V L;
     V R;
     for( int i=0; i < mid ; ++i)
     {
        L.push_back(A[i]); 
     }
     for( int i=mid; i <  A.size(); ++i)
     {
         R.push_back(A[i]); 
     }
    
     sort(L);
     sort(R);
     //A.clear();
     merge(L,R, A);
    Display(A );
}




int main(int argc, char**argv) 
{
    V A = { 5,4,3,2,1};
    V L = { 1, 2, 4};
    V R = { 3,5};

}



Partition sort
/*quick sort is an in-place, divide-and-conquer, massively recursive sort. As a normal person would say, it's essentially a faster in-place version of the merge sort. The quick sort algorithm is simple in theory, but very difficult to put into code (computer scientists tied themselves into knots for years trying to write a practical implementation of the algorithm, and it still has that effect on university students). 

The recursive algorithm consists of four steps (which closely resemble the merge sort): 

If there are one or less elements in the array to be sorted, return immediately. 
Pick an element in the array to serve as a "pivot" point. (Usually the left-most element in the array is used.) 
Split the array into two parts - one with elements larger than the pivot and the other with elements smaller than the pivot. 
Recursively repeat the algorithm for both halves of the original array. 
The efficiency of the algorithm is majorly impacted by which element is choosen as the pivot point. The worst-case efficiency of the quick sort, O(n2), occurs when the list is sorted and the left-most element is chosen. Randomly choosing a pivot point rather than using the left-most element is recommended if the data to be sorted isn't random. As long as the pivot point is chosen randomly, the quick sort has an algorithmic complexity of O(n log n). 
*/

 // quick short tutorila
// http://www.dreamincode.net/forums/showtopic31409.htm


/// 5 4 3 2 1 
    //mid = (0+4)
//


int binarySearch(int[] a, int fromInclusive, int toExclusive, int key) {
    int low = fromInclusive;
    int high = toExclusive - 1;
    while (low <= high) {
        int mid = (low + high) >>> 1;
        int midVal = a[mid];
        if (midVal < key)
            low = mid + 1;
        else if (midVal > key)
            high = mid - 1;
        else
            return mid; // key found
    }
    return -(low + 1); // key not found
}

Implement quick sort
void qSort(int[] a, int fromInclusive, int toInclusive) {
    int i = fromInclusive;
    int j = toInclusive;
    if (i >= j) return;
    int separator = a[i + random.nextInt(j - i + 1)];
    do {
        while (a[i] < separator) ++i;
        while (a[j] > separator) --j;
        if (i > j) break;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        ++i;
        --j;
    } while (i <= j);
    qSort(a, fromInclusive, j);
    qSort(a, i, toInclusive);
}


int pivotFn(int numbers[], int left, int right)
{
	int mid = (left + right)/2;
	int pivot =numbers[mid] ;
	swap(  numbers[mid], numbers[right]);
	return pivot;
}

void q_sort(int numbers[], int left, int right)
{

  if( left >= right )
  {
		return;
  }

  int pivot;
  
  pivot = pivotFn( numbers , left , right   );
  
  printf(" pivot Numbner %d , left %d , right %d \n", pivot, left ,right);


  int i =left; 
  int j =right-1;

  
 ///int array_size = sizeof( numbers)/ sizeof( numbers[0]); //error 
			
  
  while (1)
  {
	  for(;  numbers[i] < pivot ; ++i );

	  for(;  numbers[j] > pivot ; --j );

	  if( i < j)
		  swap( numbers[i] , numbers[j]);
	  else
	  {
		  swap( numbers[i] , numbers[right]);
			  break;
	  }


	  print( numbers, NUM_ITEMS);


	 
  }
  
  q_sort(numbers, left, i-1);
  q_sort(numbers, i+1, right);
   
}

void quickSort(int numbers[], int array_size)
{
  q_sort(numbers, 0, array_size - 1);
}






