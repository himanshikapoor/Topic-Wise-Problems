#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& tasks, int workersReqd, int minTime) {
    int workers = 1, sum = 0;
    for(int time : tasks) { 
        sum += time;
        if(sum > minTime) {
            sum = time;
            workers++;
        }

        if(workers > workersReqd)
            return false;
    }

    return true;
}

int findMinTime(vector<int> &tasks, int workers) {
    int l = *max_element(tasks.begin(), tasks.end()), h = accumulate(tasks.begin(), tasks.end(), 0), mid, ans = -1;
    while(l <= h) {
        mid = l + (h - l) / 2;
        if(isValid(tasks, workers, mid)) {
            ans = mid;
            h = mid - 1;
        } else
            l = mid + 1;
    }

    return ans;
}

int main() {
    int n, workers;
    cin >> n >> workers;
    vector<int> tasks(n);

    for(int& time : tasks)
        cin >> time;

    cout << findMinTime(tasks, workers);
    return 0;
}