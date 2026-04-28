class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(auto it: strs){
            string temp = it;
            sort(temp.begin(),temp.end());
            m[temp].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it:m){
            vector<string>  temp;
            for(auto in: it.second){
                temp.push_back(in);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
