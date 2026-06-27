class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int n=s.length();
        int windowMin = 0;
        int maxi = 0;
        int curr= 0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(m.find(ch) == m.end()){
                curr++;
            }else{
                int idx = m[ch];
                
                
                
                windowMin = max(idx + 1, windowMin);
                curr = i - windowMin+1;
            }
            maxi = max(maxi , curr);
            m[ch] = i;
        }
        return maxi;
    }
};
