# Link: https://leetcode.com/problems/contains-duplicate/

# Time and Space Complexity: O(n)
def containsDuplicate(nums) -> bool:
    unique_numbers = set()
    for i in nums:
        unique_numbers.add(i)
    print(unique_numbers)
    if len(nums) == len(unique_numbers):
        return False
    return True

containsDuplicate([1,2,3,1])