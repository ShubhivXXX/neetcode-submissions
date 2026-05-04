class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> s;
        vector<pair<int,int>> vec;
        for(int i=0;i<position.size();i++){
            vec.push_back({position[i],speed[i]});
        }
        // sort(vec.begin(),vec.end(),[](pair<int,int>a , pair<int,int> b ){
        //     if(a.first == b.first){
        //         return a.second<b.second;
        //     }
        //     return a.first<b.first;
        // });
        sort(vec.begin(),vec.end(),greater<>());
        int count=0;
        double in = 0;
        for(auto [q,w]:vec){
            double dis = ((double)(target-q)/(double)w);
            if(dis>in){
                in  = dis;
                count++;
            }
        }
        return count;

        
        
    }
};
