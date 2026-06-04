class Solution {
public:
    int findMin(vector<int> &nums) {
        int minn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            minn=min(minn,nums[i]);
        }
        return minn;
    }
};
