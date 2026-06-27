class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        for(int i=0;i<n;i++){
            int curr= numbers[i];
            int toFind = target  -curr;
            int start = i+1;
            int end = n-1;
            while(start<=end){
                int mid = (start + end)/2;
                if(numbers[mid] == toFind){
                    return {i+1, mid+1};
                }
                else if(numbers[mid] > toFind){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }
        }
        
    }
};
