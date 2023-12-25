class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
		if(n == 0 || s[0] == '0') 
            return 0;
        int answer = 1;
        int decode_1 = 1;
        int decode_2 = 1;
        for(int i = 2; i <= n; i++){
            answer = 0;
    
            if(s[i-1] > '0')
                answer += decode_1;
            
            if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7')
                answer += decode_2;
            
            decode_2 = decode_1;
            decode_1 = answer;   
        }
        return answer;
    }
};