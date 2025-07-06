class FindSumPairs {
public:
    vector<int>arr, brr;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr = nums1;
        brr = nums2;
        for(int i = 0; i<nums2.size(); i++) mp[nums2[i]]++;
    }
    
    void add(int index, int val) {
        mp[brr[index]]--;
        if(mp[brr[index]] == 0) mp.erase(brr[index]);
        brr[index]+=val;
        mp[brr[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i = 0; i<arr.size(); i++){
            int num = arr[i];
            if(mp.count(tot-num)) ans+=mp[tot-num];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */