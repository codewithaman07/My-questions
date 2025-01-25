// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n;
        while(l<h){
            int mid = l+(h-l)/2;
            bool f = isBadVersion(mid);
            if(f) h = mid;
            else l = mid+1;
        }
        return l;
    }
};