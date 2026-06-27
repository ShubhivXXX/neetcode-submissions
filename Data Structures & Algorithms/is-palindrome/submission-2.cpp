class Solution {
public:
    bool isPalindrome(string s) {
        int pt1 = 0;
        int pt2 = s.length()-1;
        while(pt1<pt2){
            char ch1 = s[pt1];
            char ch2= s[pt2];
            if((ch1 >='A' && ch1<='Z') || (ch1 >='a' && ch1<='z') || (ch1 >='0' && ch1<='9') ){
                if(ch1 >='A' && ch1<='Z'){
                    ch1+=32;
                }
            }else{
                pt1++;
                continue;
            }
            if((ch2 >='A' && ch2<='Z') || (ch2 >='a' && ch2<='z' )||( ch2 >='0' && ch2<='9') ){
                if(ch2 >='A' && ch2<='Z'){
                    ch2+=32;
                }
            }else{
                pt2--;
                continue;
            }
            if(ch1 != ch2 ){
                cout<<ch1<<"  "<<ch2;
                return false;}
            pt1++;
            pt2--;

        }
        return true;
    }
};
