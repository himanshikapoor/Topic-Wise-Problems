#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findMaxElement(int A[], int& size) {
        int maxi = A[0];
        for(int i = 1; i < size; ++i) 
            maxi = max(A[i], maxi);
        return maxi;
    }
    
    int findSum(int A[], int& size) {
        int sum = A[0];
        for(int i = 1; i < size; ++i) 
            sum += A[i];
        return sum;
    }
    
    bool isPossibleToAllocate(int A[], int size, int maxStudents, int pagesAllocatable) {
        int pagesAllocated = 0, students = 1;
        for(int i = 0; i < size; ++i) {
            if(pagesAllocated + A[i] <= pagesAllocatable) {
                pagesAllocated += A[i];
            } else {
                ++students;
                pagesAllocated = A[i];
                if(students > maxStudents)
                    return false;
            }
        }
        
        return (students <= maxStudents);
    }
    
    int findPages(int A[], int N, int M) {
        if(M > N) return -1;
        int l = findMaxElement(A, N);
        int h = findSum(A, N);
        int mid, ans = INT_MAX;
        
        while (l <= h) {
            mid = l + (h - l) / 2;
            if(isPossibleToAllocate(A, N, M, mid)) {
                ans = mid;
                h = mid - 1;
            } else 
                l = mid + 1;
        }
        if(ans == INT_MAX)
            return -1;
            
        return ans;
    }
};