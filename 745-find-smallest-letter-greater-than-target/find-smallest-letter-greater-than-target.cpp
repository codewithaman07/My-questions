class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // int idx = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        // if(idx == letters.size()) return letters[0];
        // return letters[idx];
        int l = 0, h = letters.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(letters[mid]<=target) l = mid+1;
            else h = mid-1;
        }
        return letters[l%letters.size()];
    }
};