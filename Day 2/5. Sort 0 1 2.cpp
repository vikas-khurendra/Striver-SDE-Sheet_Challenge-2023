#include <bits/stdc++.h> 

void sort012(int *arr, int n)
{
   int count0=0, count1=0, count2=0;

   for(int i=0; i<n; i++)
   {
      if(arr[i] == 0)
         count0++;
      else if(arr[i] == 1)
         count1++;
      else
         count2++;
   }

   for(int i=0; i<count0; i++)
   {
      arr[i] = 0;
   }

   for(int j=count0; j<count0+count1; j++)
   {
      arr[j] = 1;
   }

   for(int k=count0+count1; k<n; k++)
   {
      arr[k] = 2;
   }
}