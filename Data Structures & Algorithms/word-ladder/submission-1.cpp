class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, int> m;
        for(auto it:wordList){
            m[it] = 1;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        if(m.find(endWord)==m.end()) return 0;
        if(beginWord.length()!=endWord.length()) return 0;
        while(!q.empty()){
            string top  = q.front().first;
            int count = q.front().second;
            if(top==endWord) return count+1;
            q.pop();
            int n=top.size();
            for(int i=0;i<n;i++){
                string temp =top;
                for(int j = 'a';j<='z';j++){
                    temp[i] = j;
                    
                    if(m.find(temp)!=m.end()){
                        q.push({temp,count+1});
                        m.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
