// class MedianFinder {
// public:
//     MedianFinder() {}
    
//     void addNum(int num) {
//         nums.insert(num);
//         is_even = !is_even;
//         if (it == nums.end() || (is_even && (*it) <= num)) it++;
//         if (!is_even && (*it) > num) it--;
//     }
    
//     double findMedian() {
//         return (!is_even)? *it : (*it + *prev(it)) / 2.0;
//     }
    
// private:
//     multiset<int> nums;
//     multiset<int>::iterator it = nums.begin();
//     bool is_even = true;
// };

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left_max;
    priority_queue<int, vector<int>, greater<int>> right_min;
    MedianFinder() 
    {
        //declaring median finder
    }
    
    void addNum(int num) 
    {
        if(left_max.empty() || num<=left_max.top()) left_max.push(num);
        else right_min.push(num);
        int a=left_max.size(), b=right_min.size();
        if(a>b+1)
        {
            num = left_max.top();
            left_max.pop();
            right_min.push(num);
        }
        if(b>a)
        {
            num = right_min.top();
            right_min.pop();
            left_max.push(num);
        }
    }
    
    double findMedian() 
    {
        if(left_max.size()==right_min.size()) 
        {
            double ans=left_max.top()+right_min.top();
            return ans/2.0;
        }
        return left_max.top();
    }
};
