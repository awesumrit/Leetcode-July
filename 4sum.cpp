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
