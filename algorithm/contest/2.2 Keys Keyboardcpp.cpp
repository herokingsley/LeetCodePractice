#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[1005] = {-1};
	for(int i = 0; i < 1005;++i)a[i] = -1;
        a[1] = 1;
        for(int i = 1; i <= 500 ; ++i){
            int temp = i;
            for (int j = 1; (j * i + i) <= 1000; ++j){
                int t = j * i + i;
                int temp = j + a[i];
                if(a[t] == -1 || temp < a[t]){
                    a[t] = temp;
                }
            }
        }
    cout<<a[n]<<endl;
	return 0;
}
