class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid= r+l/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid]>=arr[l]){
                if(target>=arr[l] && target<=arr[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
                continue;
            }
            if(arr[mid]<=arr[r]){
                if(target>=arr[mid] && target<=arr[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
                continue;
            }
        }
        return -1;
    }
};
