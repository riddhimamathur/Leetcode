class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i=0;i<nums.size();i++)
        {
            if (i>0 && nums[i] == nums[i-1])
            continue;

            for (int j=i+1; j<nums.size(); j++) {
             if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                for (int k = j + 1; k < nums.size(); k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                        continue;

                    for (int l = k + 1; l < nums.size(); l++) {
                        if (l > k + 1 && nums[l] == nums[l - 1])
                            continue;

                    if ((long long)nums[i]+nums[j]+nums[k]+nums[l] == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k],nums[l]});
                    }
        }
                }}}
                return ans;
    }
};