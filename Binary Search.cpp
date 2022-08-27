#include <bits/stdc++.h>
// return -1 if not found
// else return  index
using namespace std;

class Solution {
public:
    int search(vector<int> nums, int target) {
        int start=0,end=nums.size()-1,mid=0;
        if(nums[start] == target){ return start; }
        if(nums[end] == target){ return end; }
        do{
            if (target < nums[start] || target > nums[end]) return -1;
            mid=(start+end)/2;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]){start=mid+1;}
            else if(target < nums[mid]){end=mid-1;}
            
        }while(target != nums[mid]);
        
        if(nums[start] == target){ return start; }
        return -1;
    }
};
int main()
{
    Solution sol;
    cout<<sol.search({-1,0,3,5,9,12},9)<<endl; //4
    cout<<sol.search({5},5)<<endl; //0
    cout<<sol.search({-1,0,3,5,9,12},-1)<<endl; //0
    cout<<sol.search({-1,0,3,5,9,12},12)<<endl; //5
    cout<<sol.search({-1,0,3,5,9,12},10)<<endl; //-1
    cout<<sol.search({-1,0,3,5,9,12},13)<<endl; //-1
    cout<<sol.search({-1,0,3,5,9,12},-2)<<endl; //-1

    return 0;
}
