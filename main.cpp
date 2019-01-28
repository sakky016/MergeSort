#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;

/* Display array */
void displayArray(int *arr, int total)
{
    int i = 0;
    while (i < total)
    {
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
}

/***************************************************************************
 Merges 2 sub-arrays 'left' and 'right' into another array 'arr' in
   a sorted way.
   @param left  : Left subarray
   @param nL    : size of left subarray
   @param left  : right subarray
   @param nL    : size of right subarray
   @param arr   : final array that has to be constructed.
   @param n     : size of final array.
 ***************************************************************************/
void merge(int *left, int nL, int *right, int nR, int *arr, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nL && j < nR)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    /* If either of left or right subarray has some elements left */
    while (i < nL)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < nR)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

/* Composes left and right subarray recursively and calls merger() */
void mergeSort(int *arr, int n)
{
    int mid = n/2;
    int left[mid];
    int right[mid];
    int i = 0;
    int nL = 0;
    int nR = 0;

    /* Only 1 element, return */
    if (n < 2)
    {
        return;
    }

    /* Compose left subarray */
    while (i< mid)
    {
        left[i] = arr[i];
        i++;
        nL++;
    }

    /* Compose right subarray */
    while (i < n)
    {
        right[i - mid] = arr[i];
        i++;
        nR++;
    }

    mergeSort(left, nL);
    mergeSort(right, nR);
    merge(left, nL, right, nR, arr, n);
}



/* MAIN */
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Enter atleast 1 value in command line argument!\n");
        return 0;
    }

    int i = 0;
    int total = argc - 1;
    int arr[total];
    memset(arr, 0, total);

    while (i < total)
    {
        arr[i] = atoi(argv[i+1]);
        i++;
    }

    cout<<"Initial: "<<endl;
    displayArray(arr, total);
    mergeSort(arr, total);
    cout<<"\nAfter sorting:"<<endl;
    displayArray(arr, total);

    return 0;
}
