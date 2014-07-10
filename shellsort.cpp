/* ShellSort 
algorithm source - WIKIPEDIA */




#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int a[100], n; // array containing the elements to be sorted and n is the number of elements

// this function sorts the subarrays by bubble sort
void subsort(int start, int gap)
{
    int i, j, temp;
    for(i=start; i<n; i+=gap)
    {
        for(j=start; j<n-i-1 && j+gap <n; j+=gap)
        {
            if(a[j]>a[j+gap])
            {
                temp=a[j];
                a[j]=a[j+gap];
                a[j+gap]=temp;
            }
        }
    }
}

int main()
{
    int  i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
        
    int gaps[10], l=0, k; // gaps array contains the gaps (intervals) to make subarrays

    for(i=0; i<n; i++)
    cout<<a[i]<<" ";
    cout<<"\n\n\n";


    for(i=0; (int)(n/(pow(2,i+1)) )!=0 ; i++)
    {
        gaps[i]= n/(pow(2,i+1)) ;
        l++;
        //cout<<(int)(n/(pow(2,i+1))) <<" ";
    }
// 'l' keeps the count of interval
// intervals are - n/(2^i) till this value becomes 1

    for(i=0; i<l ; i++ )
    {
        for(k=0; k+gaps[i]<n; k++)
            {
                subsort(k, gaps[i]); // sorting of subarray with the gap = gaps[i]
                
                for(int p=0; p<n; p++) // printing after each subarray sort
            cout<<a[p]<<" ";  
            cout<<"\n\n";
            }
        //for(int p=0; p<n; p++)
         //   cout<<a[p]<<" ";
          //  cout<<"\n\n";
    }

    for(i=0; i<n; i++) // final sorted array
    cout<<a[i]<<" ";

}
