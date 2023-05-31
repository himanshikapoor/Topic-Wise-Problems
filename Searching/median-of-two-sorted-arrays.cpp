#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0) {
            if (n2 % 2 == 0)
                return (nums2[n2/2 - 1] + nums2[n2/2]) / 2.0;
            else
                return nums2[n2/2];
        }
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int l = 0;
        int h = n1;

        int cut1, cut2; // store the number of elements that are a part of the left sorted array
        int l1, r1; // last and first elements of the first (partitioned) array
        int l2, r2; // last and first elements of the second (partitioned) array

        while (l <= h) {
            cut1 = l + (h - l) / 2;
            cut2 = (n + 1) / 2 - cut1;
            l1 = (cut1 == 0 ? INT_MIN : nums1[cut1 - 1]);
            l2 = (cut2 == 0 ? INT_MIN : nums2[cut2 - 1]);
            r1 = (cut1 == n1 ? INT_MAX : nums1[cut1]);
            r2 = (cut2 == n2 ? INT_MAX : nums2[cut2]);

            if (l1 <= r2 && l2 <= r1)
                return (n & 1) ? max(l1, l2) : (max(l1, l2) + min(r1, r2)) / 2.0;
            else if (l1 > r2)
                h = cut1 - 1;
            else
                l = cut1 + 1;
        }

        return 0.0;
    }
};