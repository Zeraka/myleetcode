class Solution:
    def twosum(self, nums, target):
        n = len(nums)
        print(n)
        lookup={} # Dictionary
        for i in range(n):
            lookup.update()
        
        for i in range(n):
            num_to_find=target - nums[i]
            if num_to_find in lookup:
                return [nums[i],lookup[num_to_find]]

nums=[2,11,7,5,12]
target=9
sl = Solution()
print(sl.twosum(nums,target))
