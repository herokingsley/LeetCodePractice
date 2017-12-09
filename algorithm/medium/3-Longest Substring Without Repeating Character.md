## Longest Substring Without Repeating Character 

### 题目

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/



题意是给出一段字符串，请出最大长度的子字符串长度，要求子字符串中没有重复的字符。



### 解题思路

一开始走了挺多弯路去想，实际上这类问题可通过一次遍历就解决了。用两个变量a、b维护子字符串的左右下标，一个map维护各字符上一次出现的位置。每次遍历向右延伸b的值，同时判断该位置对应的字符上一次出现的位置t，如果t > a，则需要把a赋值为t+1，同时计算当前字符串的长度，与当前最大长度对比。

重复这个过程到结束即可，也可以理解为是动态规划。每次遍历向右表示最右当前的字符串最大值是多少。



### 示例代码

```
class Solution {
public:
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
            }
            int temp_result = i - left + 1;
            max_result = max_result > temp_result ? max_result: temp_result;
            index[s[i]] = i;
        }
        return max_result;
    }
};
```



### 注意细节

1. 字符串长度为0时候。
2. 要注意当前字符上次出现位置是否小于当前子字符串的左边界，如果小于则不能更改。