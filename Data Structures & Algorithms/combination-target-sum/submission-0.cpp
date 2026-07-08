class Solution {
public:
    vector<vector<int>> fin;
    int n;
    void chk(vector<int>& nums,int& tar,int i,int sum,vector<int> res){
        if(sum==tar){
            fin.push_back(res);
            return;
        }
        if(sum>tar || i>=n){
            return;
        }
        res.push_back(nums[i]);
        chk(nums,tar,i,sum+nums[i],res); 
        res.pop_back();
        chk(nums,tar,i+1,sum,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n=nums.size();
        vector<int> res;
        chk(nums,target,0,0,res);

        return fin;
    }
};
