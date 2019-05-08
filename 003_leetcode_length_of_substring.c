 /*
 要求：
Given a string, find the length of the longest substring without repeating characters. 
For example, 
"abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.

给定一个字符串，找出不含有重复字符的最长子串的长度。
示例 1:  
输入: "abcabcbb"   
输出: 3   
解释: 无重复字符的最长子串是 "abc"，其长度为 3。

示例 2:  
输入: "bbbbb"  
输出: 1.     
解释: 无重复字符的最长子串是 "b"，其长度为 1。

示例 3:    
输入: "pwwkew"  
输出: 3  
解释: 无重复字符的最长子串是 "wke"，其长度为 3。    
请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。

解析：
建立一个256位大小的整型数组freg，用来建立字符和其出现位置之间的映射。
维护一个滑动窗口，窗口内的都是没有重复的字符，去尽可能的扩大窗口的大小，窗口不停的向右滑动。
（1）如果当前遍历到的字符从未出现过，那么直接扩大右边界；
（2）如果当前遍历到的字符出现过，则缩小窗口（左边索引向右移动），然后继续观察当前遍历到的字符；
（3）重复（1）（2），直到左边索引无法再移动；
（4）维护一个结果res，每次用出现过的窗口大小来更新结果res，最后返回res获取结果。
 */

#include <iostream>    
#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
    int subString(string s) {
        int freq[256] = {0};    //用来记录是否有重复，类似map
        int left = 0, right = -1; //滑动窗口为s[l...r]
        int res = 0;

        while(left < s.size()){
            
            if(right + 1 < s.size() && freq[s[right+1]] == 0){
                right++;
                freq[s[right]]++;
            }else {   //r已经到头 || freq[s[r+1]] == 1
                freq[s[left]]--;
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};

int main(){
    char string[]="abccbcde";
    int ret=0;

    Solution obj;
    ret= obj.subString(string);

    cout<<"ret= "<<ret<<endl;  

    return 0;  
}