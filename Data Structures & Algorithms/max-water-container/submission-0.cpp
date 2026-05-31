class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int maxx=INT_MIN;
        while(i<=j){
            maxx=max(maxx,(j-i)*(min(nums[i],nums[j])));
            if(nums[i]<=nums[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxx;
    }
};
