class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]-1)!=m.end()){
                continue;
            }
            else{
                int c = 1;
                int num = nums[i]+1;
                while(m.find(num)!=m.end()){
                    c++;
                    num++;
                }
                count=max(count,c);


            }
        }
        return count;
    }
};
