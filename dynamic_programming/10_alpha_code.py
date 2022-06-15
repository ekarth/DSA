mod = 10**9 + 7
def num_codes(number):
    answer = [0] * (len(number)+1)
    answer[0] = 1
    answer[1] = 1
    for i in range(2, len(answer)):
        answer[i] = answer[i-1]
        if(int(number[i-2]) * 10 + int(number[i-1]) <= 26):
            answer[i] += answer[i-2]
    return answer[-1]

print(num_codes(str(25114)))
print(num_codes(str(1111111111)))
print(num_codes(str(3333333333)))