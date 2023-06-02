#include<bits/stdc++.h>
using namespace std;

class TimeMap {
    unordered_map <string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";
        auto& v = mp[key];
        int l = 0, h = v.size() - 1, mid, ans = -1;
        while(l <= h) {
            mid = l + (h - l) / 2;
            if(v[mid].first <= timestamp) {
                ans = mid;
                l = mid + 1;
            } else
                h = mid - 1;
        }
        return ans == -1 ? "" : v[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */