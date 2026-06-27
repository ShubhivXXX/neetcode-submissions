class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int>  m;
        for(int i=0;i<s1.length();i++){
            m[s1[i]]++;
        }
        int n = s1.length();
        int left = 0;
        for(int i=0;i<s2.length();i++){
            if(m.empty()){
                        return true;
                    }
                if(i-left<n){
                    m[s2[i]]--;
                    if(m[s2[i]] ==0){
                        m.erase(s2[i]);
                    }
                }else{
                    m[s2[i]]--;
                    if(m[s2[i]] ==0){
                        m.erase(s2[i]);
                    }
                    m[s2[left]]++;
                    if(m[s2[left]] ==0){
                        m.erase(s2[left]);
                    }
                    left++;
                    
                }
        }
        if(m.empty()){
                        return true;
                    }
        return false;
        }
};
