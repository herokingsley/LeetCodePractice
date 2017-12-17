#include<iostream>
#include<string>
#include<vector>

using namespace std;

int nextOne(int num, int size, bool up){
        if(up){
            return num + 1;
        }else{
            return num - 1;
        }
    }
    
    string convert(string s, int numRows) {
        vector<string> rows;
        int l = s.length();
        if (l == 0){
            return "";
        }
        if(numRows == 1){
        	return s;
		}
        int tempRow = 0;
        bool up = true;
        for(int i = 0; i < l; ++i){

            if(tempRow == numRows - 1){
            	up = false;
			}else if(tempRow == 0){
				up = true;
			}
            int nextRow = nextOne(tempRow, numRows, up);
            cout<<tempRow<<" "<<nextRow<<endl;
            if(tempRow + 1 > rows.size()){
                string row = "";
                row +=  s[i];
                rows.push_back(row);
            }else{
            	//cout<<s[i]<<endl;
                rows[tempRow] += s[i];
            }
            tempRow = nextRow;
        }
        string r = "";
        for(int i=0; i < numRows; ++i){
        	cout<<rows[i]<<endl;
            r += rows[i];
        }
        return r;
    }

int main(){
	string s = "PAYPALISHIRING";
	s = "ABC";
	string r = convert(s, 1);
	cout<<r<<endl;
}
