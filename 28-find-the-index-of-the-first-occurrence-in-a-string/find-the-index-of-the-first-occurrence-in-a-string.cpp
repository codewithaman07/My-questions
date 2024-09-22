class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0, n = haystack.size(), m = needle.size(), ans = -1;
        while(i<n && j<m){
            if(haystack[i] == needle[j]){
                if(ans == -1) ans = i;
                i++; j++;
            }
            else{
                i = i-j+1; 
                j = 0;
                ans = -1;
            }
        }
        return j == m ? ans : -1;
    }
};