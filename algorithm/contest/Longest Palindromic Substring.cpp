  #include<iostream>
  #include<string>
  
  using namespace std;
  
  
  string longestPalindrome(string s) {
        int l = s.length();
        if(l == 0){
            return "";
        }
        int maxl = 1;
        int st = 0;
        for(int i = 0 ; i < l; ++i){
            for(int j=0; j < 2;++j){
            int tempLen;
            string tempMax;
            int tl,tr;
            if(j == 0){
                tempLen = 1;
                tl = tr = i;
            }else{
                if(i+j >= l || s[i] != s[i+j]){
                    continue;
                }
                tempLen = 2;
                tl =  i;
                tr =  i + 1;
            }
            if(tempLen > maxl){
                    maxl = tempLen;
                    st = tl;
                }
            
            while(--tl >= 0 && ++tr < l && s[tl] == s[tr]){
            	cout<<tl<<" "<<tr<<endl;  
                tempLen += 2; 
                if(tempLen > maxl){
                    maxl = tempLen;
                    st = tl;
                }
           	}
            	
            }
        }
        cout<<st<<" and "<<maxl<< endl;
        return s.substr(st, maxl);
    }
    
    int main(){
    	string s = "babad";
    	cout<<longestPalindrome(s)<<endl;
    	return 0;
	}
