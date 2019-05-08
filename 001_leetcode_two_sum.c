 /*
 要求：
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9  
所以返回 [0, 1]

解法：
使用一个哈希表来解，第一遍扫描，保存到哈希表中：
mapping:2, 0
mapping:11,1
mapping:7, 2
mapping:15,3

第二遍扫，看target-n在不在哈希表中，

时间复杂度为O(n)。
 */

#include <iostream>    
#include <vector>    
#include <map> 

using namespace std;  

vector<int> twoSum(vector<int> arr,int target)  
{  
    map<int,int> mapping;  //map的第一个参数一般为key，第二个为地址
    vector<int> result;  
    for(int i=0;i<arr.size();i++){
        mapping[arr[i]]=i; //此处的arr数组成员就是map的key，arr成员的下标值作为map的key对应的地址，简直完美适配。
    }
    for(int i=0; i<arr.size(); i++){

        int gap=target-arr[i];

        if(mapping.find(gap)!=mapping.end())// find 返回迭代器指向当前查找元素（也就是gap）的位置，否则返回end()位置
        {
            result.push_back(i);  //push_back()会在result的最后一个向量之后插入一个元素（i+1）
            result.push_back(mapping[gap]);
            break;  
        }
    }  
    return result;  
}

int main(){
    int a[4]={2,11,7,15};    
    vector<int> arr(a,a+4);  //定义了一个向量存储容器arr,其相当于a[4]。vector 是向量类型，它可以容纳许多类型的数据
    
    vector<int> index = twoSum(arr, 17);

    cout<<"index1= "<<index[0]<<endl<<"index2= "<<index[1]<<endl;  

    return 0;  
}