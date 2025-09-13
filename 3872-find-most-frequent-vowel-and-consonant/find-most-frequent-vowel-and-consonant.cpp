class Solution {
public:
    bool isVowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    int maxFreqSum(string s) {
        map<int,int>vowels, consonants;
        for(char &ch : s){
            if(isVowel(ch)) vowels[ch]++;
            else consonants[ch]++;
        }
        int maxConstFreq = 0, maxVowFreq = 0;
        for(auto &[ch, freq] : vowels){
            maxVowFreq = max(maxVowFreq, freq);
        }
        for(auto &[ch, freq] : consonants){
            maxConstFreq = max(maxConstFreq, freq);
        }
        int freqSum = maxConstFreq + maxVowFreq;
        return freqSum;
    }
};