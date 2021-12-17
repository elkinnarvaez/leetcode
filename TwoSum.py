"""
    1. Two Sum - https://leetcode.com/problems/two-sum/

    Author: Elkin Narváez
    Email: elkinnarvaez2406@gmail.com
    Last submission: 12/16/2021
"""

from sys import stdin
from typing import *

class Solution:
    def twoSumNaive(self, nums: List[int], target: int) -> List[int]:
        ans = [None, None]
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if(nums[i] + nums[j] == target):
                    ans[0] = i
                    ans[1] = j
        return ans
    
    def twoSumTwoPass(self, nums: List[int], target: int) -> List[int]:
        ans = [None, None]
        hashmap = dict()
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        i = 0
        while(i < len(nums) and ans[0] == None):
            complement = target - nums[i]
            if complement in hashmap and i != hashmap[complement]:
                ans[0] = i
                ans[1] = hashmap[complement]
            i += 1
        return ans

    def twoSumOnePass(self, nums: List[int], target: int) -> List[int]:
        ans = [None, None]
        hashmap = dict()
        i = 0
        while(i < len(nums) and ans[0] == None):
            complement = target - nums[i]
            if complement in hashmap:
                ans[0] = i
                ans[1] = hashmap[complement]
            hashmap[nums[i]] = i
            i += 1
        return ans

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = [None, None]
        hashmap = dict()
        i = 0
        while(i < len(nums) and ans[0] == None):
            complement = target - nums[i]
            if complement in hashmap:
                ans[0] = i
                ans[1] = hashmap[complement]
            hashmap[nums[i]] = i
            i += 1
        return ans

def main():
    solution = Solution()
    lines = stdin.readlines()
    curr_line = 0
    tc = 1
    while(curr_line < len(lines)):
        n = int(lines[curr_line])
        curr_line += 1
        if(n == -1):
            continue
        nums = [None for _ in range(n)]
        for i in range(n):
            nums[i] = int(lines[curr_line])
            curr_line += 1
        target = int(lines[curr_line])
        curr_line += 1
        sol = solution.twoSum(nums, target)
        print(f"Case {tc}: {sol[0]} {sol[1]}")
        tc += 1


if __name__ == '__main__':
    main()