#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector< vector<int> > fourSum(vector<int>& nums, int target) {
	int size = nums.size();
	sort(nums.begin(), nums.end());
	vector< vector<int> > result ;
	if(size < 3){
		return result;
	}
	for (int i = 0 ; i < size; ++i){
		if(i > 0 && nums[i] == nums[i - 1]){
			continue;
		}
		for( int j = i + 1; j < size; ++j){
			if(j > i + 1 && nums[j] == nums[j - 1]){
				continue;
			}
			for ( int k = j + 1; k < size; ++ k){
				if(k > j + 1 && nums[k] == nums[k - 1]){
					continue;
				}
				int lef = j + 1;
				int right = size;
				int temp_result = nums[i] + nums[j] + nums[k];
				while(lef < right){
					int mid = (lef + right)/2;
					if(temp_result + nums[mid] == target){
						// 组装结果
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);	
						temp.push_back(nums[mid]);
						result.push_back(temp);
						break;
					}else if(temp_result + nums[mid] > target){
						right = mid;
					}else{
						lef = mid + 1;
					}
					
				}
			}
			
		}
	}
	return result;
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
