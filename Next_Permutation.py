class Solution:
	# @param {integer[]} nums
	# @return {void} Do not return anything, modify nums in-place instead.
	def nextPermutation(self, nums):
		start_pos = len(nums) - 1
		for j in range(len(nums) - 2, -2, -1):
			if nums[j] < nums[start_pos]:
				start_pos = j
				break
			else:
				start_pos = j
				continue
		# if list is sorted
		if start_pos == -1:
			nums.reverse()
			#nums = nums[::-1]
		# else find rest elements
		else:
			exchange_pos = start_pos + 1
			for j in range(exchange_pos, len(nums)):
				if nums[exchange_pos] >= nums[j] and nums[j] > nums[start_pos]:
					exchange_pos = j
			# swap exchange_pos and start_pos
			nums[start_pos], nums[exchange_pos] = nums[exchange_pos], nums[start_pos]
			# reverse num[start_pos + 1 to the end]
			nums[start_pos + 1:] = nums[:start_pos:-1]
		print start_pos, exchange_pos
		print nums



if __name__ == '__main__':
	A = Solution()
	nums = [1,5,1]
	A.nextPermutation(nums)

