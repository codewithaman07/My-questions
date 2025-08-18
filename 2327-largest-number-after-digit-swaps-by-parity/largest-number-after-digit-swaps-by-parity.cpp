class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num); //first covert the num into a string for easy traversal
        priority_queue<int> odd, even; // then take 2 priority queue odd & even
        for(auto x: s){
            int tmp=x-'0'; // covert char to int
            if(tmp%2==0) even.push(tmp); // if tmp is even the push it into even priority queue
            else odd.push(tmp); // else tmp is odd &  the push it into odd priority queue
        }
		// now traverse the string and find whether it is a odd no.'s position or even no.'s position
        for(auto& x: s){
            int tmp=x-'0'; // converting char to int
            if(tmp%2==0) x= even.top()+'0', even.pop(); // if it is even no.'s position then put there, even priority queue's top element & pop that element
            else x= odd.top()+'0', odd.pop();  // else it is odd no.'s position so put there, odd priority queue's top element & pop that element
        }
        return stoi(s); // finally convert the string into int and return it!
    }
};