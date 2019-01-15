#include<iostream>
#include<vector>
#include<string>

using namespace std;

char alpha[10][4] = {};
int size_arr[11] = {0, 0 , 3, 3, 3, 3, 3 ,4 ,3 ,4};

void init(char alpha[][4]){
	alpha[2][0] = 'a';
	alpha[2][1] = 'b';
	alpha[2][2] = 'c';
	alpha[3][0] = 'd';
	alpha[3][1] = 'e';
	alpha[3][2] = 'f';
	alpha[4][0] = 'g';
	alpha[4][1] = 'h';
	alpha[4][2] = 'i';
	alpha[5][0] = 'j';
	alpha[5][1] = 'k';
	alpha[5][2] = 'l';
	alpha[6][0] = 'm';
	alpha[6][1] = 'n';
	alpha[6][2] = 'o';
	alpha[7][0] = 'p';
	alpha[7][1] = 'q';
	alpha[7][2] = 'r';
	alpha[7][3] = 's';
	alpha[8][0] = 't';
	alpha[8][1] = 'u';
	alpha[8][2] = 'v';
	alpha[9][0] = 'w';
	alpha[9][1] = 'x';
	alpha[9][2] = 'y';
	alpha[9][3] = 'z';
	
}

void recurGetStr(vector<string>& result, string digits, string nowStr, int index, int l){
	//cout<<nowStr<<endl;
	//cout<<nowStr<<" "<<index<<" "<<l<<endl; 
	if(index == l){
		result.push_back(nowStr);
		return;
	}
	int number = digits[index] - '0';
	//cout<<"number"<<number<<endl;
	for(int i = 0; i < size_arr[number]; ++ i){
		//string  temp =   alpha[number][i] + "";
		//cout<<"alpha: "<<temp<<", "<<alpha[number][i]<<endl;
		recurGetStr(result, digits, nowStr + alpha[number][i], index + 1, l);
	}
}


// 递归 
vector<string> letterCombinations(string digits) {
	init(alpha);
	vector<string> result;
	int len = digits.length();
	if(len == 0){
		return result;
	}
	string nowStr = "";
	recurGetStr(result, digits, nowStr, 0, len);
	return result;
}


void printLog(vector<string>& rs){
	int a = rs.size();
	for(int i = 0; i < a; ++i){
		cout<<rs[i]<<endl;
	}
}


/*
//非递归 
vector<string> letterCombinations(string digits) {
	init(alpha);
	vector<string> result;
	int index[100] = {0}; //用来标记当前进行的下标 
	int len = digits.length();
	if(len == 0){
		return result;
	}
	string first = "";
	for(int i = 0; i < len; ++ i){
		cout<<digits[i] - '0'<<endl;
		first += alpha[digits[i] - '0'][0];
	}
	result.push_back(first);
	int nowIndex = len - 1;
	int nowOffset = 1;
	int leftIndex = len - 2;
	while(true){
		if(nowOffset == size[first[nowIndex] - '0']){
			// 当前offset完成
			nowOffset = 1;
			nowIndex --;
			if(nowIndex < 0){
				//已经完成 
				break;
			}
		}
		
		nowOffset ++;
	}
	cout<<first<<endl;
	return result;
}*/

int main(){
	vector<string> rs = letterCombinations("23");
	printLog(rs);
	return 0;
}
