class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()==0){
            return ans;
        }
        int i=0;
        while(i<nums.size()){
            
            while(i>0 && i<nums.size() && nums[i]==nums[i-1]){
                i++;
            }
            int pt1= i;
            int pt2 = i+1;
            int pt3 = nums.size()-1;
            
            while(pt2<pt3){
                if(nums[pt1]+nums[pt2]+nums[pt3]==0){
                    ans.push_back({nums[pt1],nums[pt2],nums[pt3]});
                    cout<<i<<"  ";
                    // if(nums[pt1]==nums[pt2]){
                    //     ans.push_back({nums[pt1],nums[pt2],nums[pt3]});
                    // }
                    pt2++;
                    while(pt2<nums.size() && nums[pt2]==nums[pt2-1]){
                        pt2++;
                    }
                    pt3--;
                    while(pt3>pt2 && nums[pt3]==nums[pt3+1]){
                        pt3--;
                    }
                    
                }
                else if(nums[pt1]+nums[pt2]+nums[pt3]>0){
                    pt3--;
                }else{
                    pt2++;
                }



                
            }
            i++;



            
        }
        return ans;
    }
};
