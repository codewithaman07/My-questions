class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>freq(26,0);
        for(char ch : word) freq[ch-'a']++;
        vector<int>temp;
        for(int num : freq) if(num) temp.push_back(num);
        sort(temp.begin(),temp.end());
        int ans = INT_MAX, n = temp.size();
        for(int i = 0; i<n; i++){
            int cnt = 0, num = temp[i];
            for(int j = 0; j<n; j++){
                if(temp[j] > num+k) cnt+=(temp[j]-num-k);
                else if(temp[j] < num) cnt+=temp[j];
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};
