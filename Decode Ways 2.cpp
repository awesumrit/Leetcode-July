#define mod 1000000007

class Solution {
public:
    
    int oneDigit(char a){
        // a: current character 
        if (a=='*')
            return 9;
        else if(a>='1')
            return 1;
        return 0;
    }
    int twoDigit(char b, char a){
        // a: current character
        // b: last character
        if (b=='*'){
            if (a=='*')
                return 15;
            else
                return (a>='0' && a<='6')? 2: 1;
        }
        else if (b=='1')
            return a=='*'? 9: 1;
        else if (b=='2'){
            if (a=='*')
                return 6;
            else
                return (a>='0' && a<='6')? 1: 0;
        }
        return 0;
    }
    
    int numDecodings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // To store number of permutations;
        long long int prev2, prev1, curr;
        if (s[0]=='0')
            return 0;
        
        int n=s.size();
        prev1 = s[0]=='*'? 9: 1;
        prev2 = 1;
        
        for (int i=1; i<n; i++){
            curr = ((prev1*oneDigit(s[i])) + (prev2*twoDigit(s[i-1], s[i])))%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
