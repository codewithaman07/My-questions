#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        // Ensure firstPlayer has the smaller initial index
        if (firstPlayer > secondPlayer) swap(firstPlayer, secondPlayer);

        // State = bitmask of survivors (player i alive ⇢ bit i-1 = 1)
        unordered_set<int> cur;
        cur.insert((1 << n) - 1);              // all players alive

        int earliest = INT_MAX;
        int latest   = INT_MIN;
        int round    = 1;

        while (!cur.empty()) {
            unordered_set<int> next;           // survivors after current round

            for (int mask : cur) {
                // Build the ordered list of alive players for this mask
                vector<int> alive;
                for (int i = 0; i < n; ++i)
                    if (mask & (1 << i)) alive.push_back(i + 1);

                int m = alive.size();
                int posA = find(alive.begin(), alive.end(), firstPlayer) - alive.begin();
                int posB = find(alive.begin(), alive.end(), secondPlayer) - alive.begin();

                // If they meet this round (mirror positions)
                if (posA + posB == m - 1) {
                    earliest = min(earliest, round);
                    latest   = max(latest,   round);
                    continue;                  // do not branch further
                }

                // Enumerate all ways to pick winners for the ⌊m/2⌋ pairs
                dfsPairs(alive, 0, m - 1, 0, firstPlayer, secondPlayer, next);
            }
            cur.swap(next);
            ++round;
        }
        return {earliest, latest};
    }

private:
    // Depth-first enumeration of winners for one round
    void dfsPairs(const vector<int>& row, int l, int r, int newMask,
                  int A, int B, unordered_set<int>& next) {

        if (l >= r) {               // finished the pair enumeration
            if (l == r) {           // odd length: middle survivor
                newMask |= 1 << (row[l] - 1);
            }
            next.insert(newMask);
            return;
        }

        int left  = row[l];
        int right = row[r];

        // Rule: if one favourite is in the pair, they must win
        if (left == A || left == B) {
            dfsPairs(row, l + 1, r - 1, newMask | (1 << (left - 1)), A, B, next);
        } else if (right == A || right == B) {
            dfsPairs(row, l + 1, r - 1, newMask | (1 << (right - 1)), A, B, next);
        } else {
            // Either side can win – branch
            dfsPairs(row, l + 1, r - 1, newMask | (1 << (left  - 1)), A, B, next);
            dfsPairs(row, l + 1, r - 1, newMask | (1 << (right - 1)), A, B, next);
        }
    }
};
