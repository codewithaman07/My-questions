class Solution {
public:
    int maxi;
    void solve(int i, vector<string>& words, vector<int>& score, int curr, vector<int>& freq) {
        if (i >= words.size()) {
            maxi = max(maxi, curr);
            return;
        }
        int temp = 0;
        bool canInclude = true;
        vector<int> tempfreq = freq;
        for (char ch : words[i]) {
            tempfreq[ch - 'a']--;
            temp += score[ch - 'a'];
            if (tempfreq[ch - 'a'] < 0) {
                canInclude = false;
                break;
            }
        }
        if (canInclude) {
            solve(i + 1, words, score, curr + temp, tempfreq);
        }
        solve(i + 1, words, score, curr, freq);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        maxi = 0;
        for (char ch : letters) {
            freq[ch - 'a']++;
        }
        solve(0, words, score, 0, freq);
        return maxi;
    }
};
