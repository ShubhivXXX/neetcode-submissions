class Solution {
public:
    int toNum(string curr){
        int n = curr.size();
        int num=curr[0]-'0';
        for(int i=1;i<n;i++){
            int num = (num*10) + curr[i];
        }
        return num;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            string curr= tokens[i];
            if(curr == "+"){
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.pop();
                s.push(top1+top2);
            }
            else if(curr == "-"){
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.pop();
                s.push(top2 - top1);
            }
            else if(curr == "*"){
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.pop();
                s.push(top2 * top1);
            }
            else if(curr == "/"){
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.pop();
                s.push(top2 / top1);
            }
            else{
                int num = stoi(curr);
            s.push(num);
            }
            
        }
        return s.top();
    }
};
