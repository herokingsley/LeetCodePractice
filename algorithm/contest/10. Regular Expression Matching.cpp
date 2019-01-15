#include<iostream>

using namespace std;

bool singleMatch(char a, char b){
	if(a == '.'){
		return true;
	}else{
		return a == b;
	}
}

bool isMatch(string s, string p) {

	int l1 = s.length();
	int l2 = p.length();
	
	int index = 0;
	int i = 0;
	for (; i < l2; ++i){
		char ch = p[i];
		//cout<<ch<<endl;
		if( i + 1 < l2 && p[i + 1] == '*'){		
			while( true ){
				if(isMatch(s.substr(index, l1 - index), p.substr(i+2, l2 - i - 2))){
					return true;
				}

				if(index < l1 && singleMatch(ch, s[index])){
					index++;
				}else{
					break;
				}
			}
			//cout<<index<<endl;
			if(index >= l1){
				if(i + 1 == l2 - 1){
					return true;
				}else{
					return false;
				}
			}
			i++;
		}else{
			if(index >= l1){
				return false;
			}
			if(singleMatch(ch, s[index])){
				index++;
			}else{
				//cout<<"single false"<<endl;
				return false;
			}
		}
	}
	if(index == l1 && i == l2){
		return true;
	}else{
		return false;
	}
}


int main(){
	
	//cout<<isMatch("aa", "a")<<endl;
	
	//cout<<isMatch("aa", "a*")<<endl;
	
	//cout<<isMatch("ab", ".*")<<endl;
	
	//cout<<isMatch("aab", "c*a*b")<<endl;
	
	//cout<<isMatch("mississippi", "mis*is*p*.")<<endl;
	
	//cout<<isMatch("aaa", "a*a")<<endl;
	
	//cout<<isMatch("a", ".*..a*")<<endl;

	//cout<<isMatch("a", "ab*")<<endl;
	
	cout<<isMatch("", "c*c*")<<endl;
	return 0;
}
