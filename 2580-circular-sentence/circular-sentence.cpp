class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string>arr;
        stringstream ss(sentence);
        string word;
        while(ss >> word){
            arr.push_back(word);
        }
        int n = arr.size();
        char temp = arr[n-1][arr[n-1].size()-1];
        for(int i = 0; i<n; i++){
            if(arr[i][0] != temp) return 0;
            else temp = arr[i][arr[i].size()-1];
        }
        return 1;
    }
};