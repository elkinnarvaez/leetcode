/*
    LeetCode: Two Sum   https://leetcode.com/problems/two-sum/

    Author: Elkin Narváez
    Email: elkinnarvaez2406@gmail.com
    Last submission: 12/07/2021
*/

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> twoSumNaive(vector<int>& nums, int target) {
            vector<int> ans(2);
            for(int i = 0; i < nums.size(); i++){
                for (int j = i + 1; j < nums.size(); j++){
                    if(nums[i] + nums[j] == target){
                        ans[0] = i;
                        ans[1] = j;
                    }
                }
            }
            return ans;
        }

        vector<int> twoSumTwoPass(vector<int>& nums, int target) {
            vector<int> ans(2, -1);
            unordered_map<int, int> hashmap;
            int i;
            for(i = 0; i < nums.size(); i++){
                hashmap[target - nums[i]] = i;
            }
            for(i = 0; i < nums.size() && ans[0] == -1; i++){
                if(hashmap.find(nums[i]) != hashmap.end()){
                    if(hashmap[nums[i]] != i){
                        ans[0] = i;
                        ans[1] = hashmap[nums[i]];
                    }
                }
            }
            return ans;
        }

        vector<int> twoSumOnePass(vector<int>& nums, int target) {
            vector<int> ans(2, -1);
            unordered_map<int, int> hashmap;
            int i;
            for(i = 0; i < nums.size() && ans[0] == -1; i++){
                if(hashmap.find(nums[i]) != hashmap.end()){
                    ans[0] = i;
                    ans[1] = hashmap[nums[i]];
                }
                hashmap[target - nums[i]] = i;
            }
            return ans;
        }

        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ans(2, -1);
            unordered_map<int, int> hashmap;
            int i;
            for(i = 0; i < nums.size() && ans[0] == -1; i++){
                if(hashmap.find(nums[i]) != hashmap.end()){
                    ans[0] = i;
                    ans[1] = hashmap[nums[i]];
                }
                hashmap[target - nums[i]] = i;
            }
            return ans;
        }
};

int main(){
    Solution solution;
    int n;
    int tc = 1;
    while(scanf("%d", &n) != EOF){
        if(n == -1){
            continue;
        }
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }
        int target;
        scanf("%d", &target);
        vector<int> sol = solution.twoSum(nums, target);
        printf("Case %d: ", tc);
        printf("%d", sol[0]);
        for(int i = 1; i < sol.size(); i++){
            printf(" %d", sol[i]);
        }
        printf("\n");
        tc++;
    }
    return 0;
}