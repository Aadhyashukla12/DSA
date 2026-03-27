class Solution {
public:
    int minimumCost(vector<int>& nums) {
        


        int sum=nums[0];

        int min=INT_MAX;
        int index=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < min){
                min=nums[i];
                index=i;
            }
        }
        sum+=min;
        min=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(i==index){
                continue;
            }
            if(nums[i] < min){
                min=nums[i];
            }
        }
        sum+=min;

        return sum;
    }
};