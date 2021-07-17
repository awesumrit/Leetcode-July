class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<4)
            return {};
        vector<vector<int>>ans;
        for(int first = 0; first <n-3; first++){
            
            if(first>0 && nums[first]==nums[first-1])
            {
                continue;
            }
            int target2 = target - nums[first];
            for(int i=first+1;i<n-2;i++)
            {
                if(i>first+1 && nums[i]==nums[i-1])
                {
                    continue;
                }
                int j=i+1,k=n-1;
                while(j<k)
                {
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum==target2)
                    {
                        ans.push_back({nums[first],nums[i],nums[j],nums[k]});
                    }
                    if(sum>target2)
                    {
                        int val=nums[k];
                        k--;
                        while(k>=0 && val==nums[k])
                        {
                            k--;
                        }
                    }
                    else
                    {
                        int val=nums[j];
                        j++;
                        while(j<n && val==nums[j])
                        {
                            j++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     sort(begin(nums), end(nums));
//     return kSum(nums, target, 0, 4);
// }
// vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
//     vector<vector<int>> res;
//     if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
//         return res;
//     if (k == 2)
//         return twoSum(nums, target, start);
//     for (int i = start; i < nums.size(); ++i)
//         if (i == start || nums[i - 1] != nums[i])
//             for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
//                 res.push_back({nums[i]});
//                 res.back().insert(end(res.back()), begin(set), end(set));
//             }
//     return res;
// }
// vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
//     vector<vector<int>> res;
//     int lo = start, hi = nums.size() - 1;
//     while (lo < hi) {
//         int sum = nums[lo] + nums[hi];
//         if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
//             ++lo;
//         else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
//             --hi;
//         else
//             res.push_back({ nums[lo++], nums[hi--]});
//     }
//     return res;
// }
