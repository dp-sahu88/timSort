//Author:DEADPOOL
//User@DEADPOOL
//Device name:LAPTOP-MGJPSU5N
//***************************
#include<bits/stdc++.h>
#define RUN 4
using namespace std;



void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void MERGE(int arr[], int l, int m, int r)
{

    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;


    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
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

    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}


void timSort(int arr[], int n)
{

    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+RUN-1),
                                    (n-1)));


    for (int SIZE = RUN; SIZE < n;
                             SIZE = 2*SIZE)
    {

        for (int left = 0; left < n;
                             left += 2*SIZE)
        {



            int mid = left + SIZE - 1;
            int right = min((left + 2*SIZE - 1),
                                            (n-1));


              if(mid < right)
                MERGE(arr, left, mid, right);
        }
    }
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
       cout<<arr[i]<<" " ;
    cout<<endl;
}

int main()
{
    int n;
    cout <<endl<<"enter the number of element in array : ";
    cin>>n;
    int arr[n];

    cout << "enter array elements ."<<endl;
    for(int m =0; m<n;m++){
        cin >> arr[m];
    }


    timSort(arr, n);

    cout<<"After Sorting Array is"<<endl;
    printArray(arr, n);
    return 0;
}
