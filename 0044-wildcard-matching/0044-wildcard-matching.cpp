class Solution {
public:

    bool isMatch(string s, string p) {
        int i = s.length();
        int j = p.length();

        vector<vector<int>> dp(i + 1, vector<int>(j + 1, false));
        dp[0][0] = true;

        for(int n = 1; n <= i; n++){
            dp[n][0] = false;
        }

        for(int m = 1; m <= j; m++){
            bool flag = true;

            for(int k = 1; k <= m; k++){
                if(p[k - 1] != '*'){
                    flag = false;
                    break;
                }
            }

            dp[0][m] = flag;
        }

        for(int n = 1; n <= i; n++){
            for(int m = 1; m <= j; m++){

                if(p[m - 1] == s[n - 1] || p[m - 1] == '?') {
                    dp[n][m] = dp[n - 1][m - 1];
                }

                else if(p[m - 1] == '*') {
                    dp[n][m] = dp[n - 1][m] | dp[n][m - 1];
                }
                else {
                    dp[n][m] = false;
                }
            }
        }

        return dp[i][j];
    }
};