class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        
        int n = matrix.size()-1;
        if(n+1==0){
            return false;
        }
        int m  = matrix[0].size()-1;
        int row = -1;
        while(i<=n){
            int mid = (i+n)/2;
            if(matrix[mid][0]==target){
                return true;
            }
            else if(matrix[mid][0]>target){
                n = mid-1;
            }else{
                if(matrix[mid][m]>=target){
                    row = mid;
                    cout<<row;
                    break;
                }
                i = mid+1;

            }
        }
        if(row == -1){
            return false;
        }
        i=0;
        while(i<=m){
            int mid = (i+m)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]>target){
                m = mid-1;
            }
            else {
                i = mid+1;
            }
        }
        return false;
        
    }
};
