// Problem :

You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.
An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

// Code : 

************** Using Two Pointer Approach *********************************

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    
    int i,j,k;
    for(i=0; i<n-2; i++){
        int s=i+1, e=n-1;
        while(s<e){
            int sum = arr[i] + arr[s] + arr[e];
            if(sum == K){
                vector<int> triplet = {arr[i], arr[s], arr[e]};
                //triplet.push_back(arr[i]);
                //triplet.push_back(arr[s]);
                //triplet.push_back(arr[e]);
                
                ans.push_back(triplet);
                
                while(s<e && arr[s] == arr[s+1])    //handling duplicate from left
                    s++;
                while(s<e && arr[e] == arr[e-1])    //handling duplicate from left
                    e--;
                
                s++;
                e--;
            }else if(sum < K){
                s++;
            }else{
                e--;
            }
        }
        
        while(i+1<n && arr[i] == arr[i+1])  //Handling duplicate for the first element
            i++;
    }
    
	return ans;
}