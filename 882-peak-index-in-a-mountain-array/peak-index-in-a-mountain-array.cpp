class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0,end=arr.size()-1,mid;
        while(start<=end){
            mid=start+(end-start)/2;
               if (mid > 0 && mid < arr.size() - 1){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]>arr[mid-1]){
            start=mid+1;
            }
            else end=mid-1;
        }
         else {
                // If mid is 0 or n-1, move pointers inward
                if (mid == 0) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};