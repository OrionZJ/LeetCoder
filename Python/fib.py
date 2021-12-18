def fib(num):
    data = [1,]
    for i in range(num - 1):
        if num < 2:data.append(num)
        else:data.append(sum(data[-2:]))
    return data

print(fib(10))