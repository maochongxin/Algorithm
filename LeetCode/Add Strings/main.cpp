class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1=="0") return num2;
        if(num2=="0") return num1;
        
        string ans="";
        int m=num1.size(),n=num2.size();
        int charM,charN,sum,c=0;
        while(m||n)
        {
            if(m>0) charM=num1[--m]-'0';
            else charM=0;
            
            if(n>0) charN=num2[--n]-'0';
            else charN=0;
            
            sum=charM+charN+c;
            c= sum>9? 1:0;
            sum=sum%10;
            
            ans.push_back(char(sum+'0'));
        }
        
        if(c) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
