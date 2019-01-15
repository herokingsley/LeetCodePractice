#include<iostream>

using namespace std;

int myAtoi(string str) {
	long long result = 0;
	int l = str.length();
	int i = 0;
	int min_int = -2147483648;
	int max_int = 2147483647;
	int sign = 1;
	for(; i < l; ++i){
		if(str[i] == ' '){
			continue;
		}
		break;
	}
	if(str[i] == '-'){
		i ++;
		sign = -1;
	}else if(str[i] == '+'){
		i++;
	}
	
	for ( ;i < l; ++i){
		if(str[i] > '9' || str[i] < '0'){
			break;
		}
		result = result * 10 + (str[i] - '0');
		if(result * sign  > max_int){
			return max_int;
		}else if(result * sign < min_int){
			return min_int;
		}
	}
	result  = result * sign;
	if(result > max_int){
		result = max_int;
	}else if(result < min_int){
		result = min_int;
	}
	int rs = (int)result;
	return rs;         
}

int main(){
	cout<<myAtoi("42")<<endl;
	
	cout<<myAtoi("    -42")<<endl;
		
	cout<<myAtoi("4193 with words ")<<endl;

	cout<<myAtoi("words and 987")<<endl;
	
	cout<<myAtoi("-91283472332")<<endl;
	
	cout<<myAtoi("9223372036854775808")<<endl;
	return 0;
}
