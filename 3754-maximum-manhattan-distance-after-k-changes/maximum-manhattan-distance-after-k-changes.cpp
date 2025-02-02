class Solution {
public:
    int maxDistance(string str, int k) {
        int n = 0, s = 0, e = 0, w = 0, ans = 0;
        for(char &ch : str){
            if(ch == 'N') n++;
            else if(ch == 'S') s++;
            else if(ch == 'E') e++;
            else w++;
            int a = max(n,s);
            int b = max(e,w);
            int c = min(n,s);
            int d = min(e,w);
            int x = min(c+d, k);
            ans = max(a+b-c-d+2*x, ans);
        }
        return ans;
    }
};