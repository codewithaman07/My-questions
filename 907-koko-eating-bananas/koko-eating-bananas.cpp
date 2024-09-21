class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        int low = 1;
        int high = INT_MAX;
        int minSpeed = -1;
        while(low<=high){
            int time = 0;
            int mid = low+(high-low)/2;
            for(int pile : piles){
                time+=((pile+mid-1)/mid);
            }
            if(time<=h){
                minSpeed = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return minSpeed;
    }
};

// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int size = piles.size();
//         int maxLimit = *max_element(piles.begin(), piles.end());
//         int minLimit = 1;
//         int time = 0;
//         int minspeed = maxLimit;
//         for(int speed = minLimit; speed<=maxLimit; speed++){
//             time = 0;
//             for(int pile : piles){
//                 time+= (pile+speed-1)/speed;
//             }
//             if(time<=h){
//                 minspeed = speed;
//                 break;
//             }
//         }
//         return minspeed;
//     }
// }; Brute force tc - O(n*maxi) 