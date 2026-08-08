class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3)
          return 0;
        int sum = nums[0] + nums[1] + nums[2];
        if (n == 3 || target == sum)
          return sum;
        int j, k;
        int dk = 2, dj = 2;
        for (int i = 0; i < n - 2; i++) {
            j = i + 1;
            k = n - 1;
            while(j < k) {
                int cur_sum = nums[i] + nums[j] + nums[k];
                if (abs(cur_sum - target) < abs(sum - target))
                  sum = cur_sum;
                if (cur_sum > target) {
                  if ((k - j) > 2 * dk - 1 && nums[i] + nums[j] + nums[k - (k - j) / 2] > target)
                    k -= (k - j) / dk;
                  else {
                    k--;
                    if (dk < k - j)
                      dk <<= 1;
                  }
                } else if (cur_sum < target) {
                  if (k - j > 2 * dj - 1 && nums[i] + nums[j + (k - j) / 2] + nums[k] < target)
                    j += (k - j) / dj;
                  else {
                    j++;
                    if (dj < k - j)
                      dj <<= 1;
                  }
                } else
                  return target;
            }
        }
        return sum;
    }
};