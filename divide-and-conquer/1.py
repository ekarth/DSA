# Maximum Subarray Problem
# Given an array, find the subarray which returns maximum sum

# DIVIDE AND CONQUER STRATEGY:
# 3 cases:
# 1. subarray lies on left side of mid 
# 2. subarray lies on right side of mid 
# 3. subarray lies on both sides of mid (i.e. crosses mid)
def find_max_crossing_subarray(arr, left, mid, right):
    left_sum = -(2**31)
    sum = 0
    left_index = mid
    for i in range(mid, left-1, -1):
        sum += arr[i]
        if sum > left_sum:
            left_sum = sum
            left_index = i
    sum = 0
    right_sum = -(2**31)
    right_index = mid
    for i in range(mid+1, right+1, 1):
        sum += arr[i]
        if sum > right_sum:
            right_sum = sum
            right_index = i
    return (left_index, right_index, left_sum+right_sum)

def find_max_subarray(arr, left, right):
    if left == right:
        return (left, right, arr[left])
    mid = int(left + (right-left)/2)
    # on left side 
    (left_left, right_left, sum_left) = find_max_subarray(arr, left, mid)
    # on right side 
    (left_right, right_right, sum_right) = find_max_subarray(arr, mid+1, right)
    # on both sides
    (left_mid, right_mid, sum_mid) = find_max_crossing_subarray(arr, left, mid, right)

    if sum_left >= sum_right:
        if sum_left >= sum_mid:
            return (left_left, right_left, sum_left)
        else:
            return (left_mid, right_mid, sum_mid)
    else:
        if sum_right >= sum_mid:
            return (left_right, right_right, sum_right)
        else:
            return (left_mid, right_mid, sum_mid)


print(find_max_subarray([13, -3, -25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7], 0, 15))