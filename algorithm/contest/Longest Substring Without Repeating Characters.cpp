#include<iostream>
#include<map>

using namespace std;;

int lengthOfLongestSubstring(string s) {
        int l = s.length();
        if(l == 0){
            return 0;
        }
        map<char,int> index;
        int max_result = 0;
        int left = 0;
        for(int i = 0; i < l; ++i){
            if(index.find(s[i]) != index.end()){
                int temp_left = index[s[i]] + 1;
                if(temp_left > left){
                	left = temp_left;
				}
                cout<<"left "<<left<<endl;
            }
            int temp_result = i - left + 1;
            max_result = max_result > temp_result ? max_result: temp_result;
            index[s[i]] = i;
        }
        return max_result;
    }

int main(){
	
	string s;
	cin>>s;
	int r = lengthOfLongestSubstring(s);
	cout<<r<<endl;
}
