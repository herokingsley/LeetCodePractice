#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int mydistance(int a, int b){
	if(a > b){
		return a-b;
	}else{
		return b - a;
	}
	
}

int threeSumClosest(vector<int>& nums, int target) {
	int size = nums.size();
	sort(nums.begin(), nums.end());
	int minDistance = -1;
	int s = -1;
	for (int i = 0 ; i < size; ++i){
		if(i > 0 && nums[i] == nums[i - 1]){
			continue;
		}
		for( int j = i + 1; j < size; ++j){
			if(j > i + 1 && nums[j] == nums[j - 1]){
				continue;
			}
			int lef = j + 1;
			int right = size;
			int temp_result = nums[i] + nums[j];
			while(lef < right){
				int mid = (lef + right)/2;
				int d = mydistance(temp_result + nums[mid]
					, target);
				if(d > 0 && (minDistance == -1 || 
					minDistance > d)){
					minDistance = d;
					s = temp_result + nums[mid];
				}
				
				if(temp_result + nums[mid] == target){
					// 组装结果
					return target;
				}else if(temp_result + nums[mid] > target){
					right = mid;
				}else{
					lef = mid + 1;
				}
			}
			
		}
	}
	return s;
}




void printLog(vector<int>& rs){
	for(int i = 0; i < rs.size(); ++i){
		cout<<rs[i]<<endl;
	}
}

int main(){
	vector<int>  arr;
	arr.push_back(2);
	arr.push_back(1);
	//sort(arr.begin(), arr.end());
	//printLog (arr) ;
	//vector<int> result = threeSum(arr);
	return 0;
}

/*
for(int k = j + 1; k < size; ++k){
				// 这里可以优化成二分搜索 
				
				if(temp_result + nums[k] == 0){
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					result.push_back(temp);
					break;
				}
			}*/
