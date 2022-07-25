# Link: https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

class Solution:
    def longestCommonPrefix(self, arr, n):
        # code here
        # s contains the minimum length string 
        s = arr[0] # initiailise with first string

        for i in range(1, n):
            # if current string length is less than the length of string s, then update 
            if len(arr[i]) < len(s):
                s = arr[i]
            
        end = 0
        
        while end < len(s):
            for i in range(n):
                # if current string end is same as that of s then continue 
                if arr[i][end] == s[end] :
                    continue
                else:
                    if end == 0:
                       return -1
                    return s[0: end] # returning max length prefix string
            end+=1
            
        #  s is the maximum length prefix string 
        return s 


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        n = int(input())
        arr = [x for x in input().strip().split(" ")]
        
        ob=Solution()
        print(ob.longestCommonPrefix(arr, n))
# } Driver Code Ends