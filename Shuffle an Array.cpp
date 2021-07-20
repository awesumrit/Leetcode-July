// O(1) time, O(N) space sol

class Solution {
public:
    
    vector<int> orig, shuff;
    Solution(vector<int>& nums) {
        orig = nums;
        shuff = nums;        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {        
        int n = orig.size();        
        swap(shuff[rand()%n], shuff[rand()%n]);
        return shuff;        
    }
};

//Fisher-Yates Algorithm - O(N) time

class Solution {
    
    vector<int> original;
    
public:
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled = original;
        int n = shuffled.size();

        for(int i=0; i<n; i++)
        {
            int j = rand()%(i+1);
            swap(shuffled[i], shuffled[j]);
        }
        
        return shuffled;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
