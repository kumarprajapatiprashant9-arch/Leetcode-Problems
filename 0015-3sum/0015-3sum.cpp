class Solution {
public:
    bool track[200007];
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector <vector <int> > ans;
        int j = 0, k = nums.size() - 1;
        int sum = 0;
        for (int i = 0 ; i < nums.size()-2 ; i++){
            if (track[nums[i]+100000]) continue;
            j = i + 1;
            k = nums.size() - 1;
            sum = nums[i] + nums[j] + nums[k];
            while (j < k){
                if (sum > 0){
                    sum -= nums[k];
                    k--;
                    sum += nums[k];
                }
                else if (sum < 0) {
                    sum -= nums[j];
                    j++;
                    sum += nums[j];
                } else{
                    if (!ans.size()){
                        ans.push_back({nums[i],nums[j],nums[k]});
                        sum -= nums[k];
                        k--;
                        sum += nums[k];
                        continue;
                    }
                    int s = ans.size()-1;
                    if (ans[s][0] != nums[i] || ans[s][1] != nums[j] || ans[s][2] != nums[k]){
                        ans.push_back({nums[i],nums[j],nums[k]});
                    }
                    sum -= nums[k];
                    k--;
                    sum += nums[k];
                }
            }
            track[nums[i]+100000] = 1;
        }

        return ans;
    }
};