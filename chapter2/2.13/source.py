# -*- coding: utf-8 -*-
####################################################
#
#   2.13 子数组的最大乘积
#    
####################################################

from random import randint

MAX = 10000

# O(2*N) 线性计算从头扫到尾 再扫回来
def solution1(arr, n):
    if n <= 1:
        return 0
    tmp = [arr[0]]
    for i in range(1, n-1):
        tmp.append(tmp[i-1] * arr[i])

    tmp.append(arr[n-1])
    res = tmp[n-2]

    for i in range(n-2, 0, -1):
        res_tmp = tmp[i-1] * tmp[i+1]
        if res_tmp > res:
            res = res_tmp

        tmp[i] = tmp[i+1] * arr[i]

    if tmp[1] > res:
        res = tmp[1]
    return res

# O(N)   利用正负零判断优化速度
def solution2(arr, n):
    res = 0

    p = 1
    q = 1

    # 绝对值最大负数 绝对值最小负数 绝对值最小正数
    a = b = c = 0

    # 0 和 正数个数
    zero = posi = 0
    
    for i in range(0, n):
        if arr[i] != 0:
            p *= arr[i]
        if arr[i] == 0:
            zero += 1
        if arr[i] > 0:
            posi += 1

        if arr[c] <= 0 or arr[i] > 0 and arr[i] < arr[c]:
            c = i

        if arr[b] >= 0 or arr[i] < 0  and arr[i] > arr[b]:
            b = i

        if arr[a] >= 0 or arr[i] < 0 and arr[i] < arr[a]:
            a = i

    if zero >= 2:
        return 0
    if zero == 1:
        return max(0, p)

    m = a
    if p < 0:
        m = b
    else:
        if posi > 0:
            m = c
        else:
            m = a

    res = 1
    for i in range(0, m):
        res *= arr[i]
    for i in range(m+1, n):
        res *= arr[i]

    return res
def main():
    import datetime
    global MAX
    test = []

    # 减少生成0的机会
    for i in range(0, MAX-MAX/100):
        test.append(randint(-100,100))
        while test[i] == 0:
            test[i] = randint(-100, 100)

    for i in range(MAX-MAX/100, MAX):
        test.append(randint(-100,100))

    st = datetime.datetime.now()
    res = solution1(test, MAX)
    ed = datetime.datetime.now()

    print '最大乘积：%d' % res

    t1 = ed - st

    st = datetime.datetime.now()
    res = solution2(test, MAX)
    ed = datetime.datetime.now()

    print '最大乘积：%d' % res

    print '第一种方法耗时：', t1
    print '第二种方法耗时：', ed-st


if __name__ == '__main__':
    main();
