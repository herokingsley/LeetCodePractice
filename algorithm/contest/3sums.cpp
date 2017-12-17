#include<iostream>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> lastVector;
        for(int i = 0; i < size - 2; ++i){
            if(nums[i] > 0){
                break;
            }
            for(int j = i + 1; j < size - 1; ++j){
                if(nums[i] + nums[j] > 0){
                    break;
                }
                for(int k = j + 1; k < size; ++k){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        if(lastVector[i] == nums[i] && lastVector[j] == nums[j]) {
                            continue;
                        }
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        result.push_back(temp);
                        lastVector = temp;
                    }
                }
            }
        }
        return result;
    }

int main(){
	vector<int> number;
	number.push_back(-1);
	number.push_back(0);
	number.push_back(1);
	number.push_back(2);
	number.push_back(-1);
	number.push_back(-4);
	
	vector<vector<int>> threeSum(vector<int>& nums);
}
