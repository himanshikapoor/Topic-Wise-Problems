#include<bits/stdc++.h>
using namespace std;

int getSecondLargest(vector<int> arr){
    int second_largest_index = -1, largest_index = 0;
        
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > arr[largest_index]){
            second_largest_index = largest_index;
            largest_index = i;
        }
        else if(arr[i] != arr[largest_index]){
            if(second_largest_index == -1 or arr[i] >  arr[second_largest_index])
                second_largest_index = i;
        }
    }
    
    if(second_largest_index != -1)
        return arr[second_largest_index];
    return second_largest_index;
}