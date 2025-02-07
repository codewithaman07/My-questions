
# class Solution {
# public:
#     vector<int> queryResults(int limit, vector<vector<int>>& queries) {
#         int n = queries.size();
#         unordered_map<int,int>mp, freq;
#         vector<int>ans(n,0);
#         int i = 0;
#         for(auto it : queries){
#             int x = it[0];
#             int y = it[1];
#             if(mp.count(x)){
#                 int temp = mp[x];
#                 if(--freq[temp] == 0) freq.erase(temp); 
#             }
#             mp[x] = y;
#             freq[y]++;
#             ans[i++] = freq.size();
#         }
#         return ans;
#     }
# };


class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        mp = {}
        freq = defaultdict(int)
        ans = []

        for x,y in queries:
            if x in mp:
                temp = mp[x]
                freq[temp] -= 1
                if freq[temp] == 0:
                    del freq[temp]

            mp[x] = y
            freq[y]+=1
            ans.append(len(freq))
        
        return ans