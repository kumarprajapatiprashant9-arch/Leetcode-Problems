#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> left(26, n);
        vector<int> right(26, -1);
        
        // Step 1: Record the leftmost and rightmost index for each character
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            left[idx] = min(left[idx], i);
            right[idx] = i;
        }
        
        vector<string> ans;
        int max_right = -1; // Tracks the end of the last added substring
        
        // Step 2 & 3: Iterate through the string and greedily process valid intervals
        for (int i = 0; i < n; ++i) {
            // We only need to check intervals beginning at a character's true first occurrence
            if (i != left[s[i] - 'a']) continue;
            
            int new_right = checkInterval(s, i, left, right);
            
            if (new_right != -1) {
                // If the new valid interval starts after the last chosen substring ends
                if (i > max_right) {
                    ans.push_back(""); // Placeholder to be filled or replaced
                    max_right = new_right;
                }
                // If it is completely nested inside the last chosen substring, 
                // replace it to minimize total length and leave room for more splits.
                if (new_right <= max_right) {
                    max_right = new_right;
                    ans.back() = s.substr(i, new_right - i + 1);
                }
            }
        }
        
        return ans;
    }

private:
    // Helper function to find the valid end of an interval starting at index 'i'
    int checkInterval(const string& s, int i, const vector<int>& left, const vector<int>& right) {
        int right_boundary = right[s[i] - 'a'];
        
        for (int j = i; j <= right_boundary; ++j) {
            int idx = s[j] - 'a';
            // If an interior character appeared before our starting boundary 'i',
            // this starting boundary cannot yield a valid separate substring.
            if (left[idx] < i) {
                return -1;
            }
            // Expand the right boundary to include all occurrences of the nested character
            right_boundary = max(right_boundary, right[idx]);
        }
        return right_boundary;
    }
};