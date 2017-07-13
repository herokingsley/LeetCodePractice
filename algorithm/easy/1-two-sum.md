## Two Sum

### 题目

https://leetcode.com/problems/two-sum/#/description

题意是给出一个数组和一个目标数，求数组内哪两个数加起来刚好等于这个目标数，找出这两个数的下标。

另外，题目还有前提，输入用例中必定有解。

### 解题思路

很简单了，用嵌套循环即可，为了不让循环重复，让内层循环为外层循环的下一个数开始即可。复杂度为O(n^2)，实际最多运算n^2/2次

### 示例代码

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> rs;
        for(int i = 0; i < size - 1; ++i){
            for(int j = i + 1; j < size; ++ j){
                if(nums[i] + nums[j] == target){
                    rs.push_back(i);
                    rs.push_back(j);
                    return rs;
                }
            }
        }
    }
};
```

### 考察点

1. vector的基本操作 
2. 嵌套循环是否会有重复。