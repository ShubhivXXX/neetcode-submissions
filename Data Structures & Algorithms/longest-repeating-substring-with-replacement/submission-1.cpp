class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> m;
        int i = 0;
        int n = s.length();
        int left = 0;
        int maxFreq = 0;
        m['0'] = 0;
        int maxi = 0;
        while(i<n){
            m[s[i]]++;
            if(m[s[i]] > maxFreq){
                maxFreq = m[s[i]];
            }
            while((i-left + 1) - maxFreq > k ){
                m[s[left]]--;
                left++;
            }
            maxi = max(maxi, i-left + 1);


            i++;

        }
        return maxi;
    }
};
