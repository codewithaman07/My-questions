class Solution {
public:
    long long eval(const string &s) {
        long long current = 0, last = 0;
        char op = '+';
        for (size_t i = 0, n = s.size(); i < n; ) {
            long long num = 0;
            while (i < n && isdigit(s[i]))
                num = num * 10 + (s[i++] - '0');
            if (op == '+') {
                current += num;
                last = num;
            } else if (op == '-') {
                current -= num;
                last = -num;
            } else { 
                current = current - last + last * num;
                last = last * num;
            }
            if (i < n) op = s[i++];
        }
        return current;
    }
    void solve(string &num,vector<string> &ans,int target,string temp,int i) {
        int n = num.size();
        long long val = eval(temp);
        if (i == n-1) {
            if (val == target) ans.push_back(temp);
            return;
        }
        int next = i + 1;
        solve(num, ans, target, temp + "+" + num[next], next);
        solve(num, ans, target, temp + "-" + num[next], next);
        solve(num, ans, target, temp + "*" + num[next], next);
        {
            auto p = temp.find_last_of("+-*");
            int chunkStart = (p == string::npos ? 0 : p+1);
            if (temp[chunkStart] != '0') {
                solve(num, ans, target, temp + num[next], next);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (!num.empty()) {
            solve(num, ans, target, num.substr(0, 1), 0);
        }
        return ans;
    }
};
