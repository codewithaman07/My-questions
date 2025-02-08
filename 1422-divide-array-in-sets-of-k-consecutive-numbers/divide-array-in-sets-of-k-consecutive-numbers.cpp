class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        for(int num : nums) mp[num]++;
        while(mp.size()>0){
            int num = mp.begin()->first;
            for(int i = num; i<num+k; i++){
                if(!mp.count(i)) return 0;
                mp[i]--;
                if(mp[i] == 0) mp.erase(i);
            }
        }
        return 1;
    }
};

        // int n = nums.size();
        // if(n%k) return 0;
        // multiset<int>st(nums.begin(), nums.end());
        // while(!st.empty()){
        //     int num = *st.begin();
        //     st.erase(st.begin());
        //     num++;
        //     for(int i = 1; i<k; i++){
        //         if(!st.count(num)) return 0;
        //         st.erase(st.find(num));
        //         num++;
        //     }
        // }
        // return 1;