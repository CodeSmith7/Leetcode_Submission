class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        nums =[i*i for i in nums]
        print (nums)
        return sorted(nums)