# 最大公约数问题
# 为什么用python你们懂得。。模拟一下

import random
count = 0
def gcd(a, b):
    global count
    count += 1
    if a < b:
        a, b = b, a
    if b == 0:
        return a

    moda = a%2
    modb = b%2
    if moda == 0 and modb == 0:
        return 2*gcd(a/2, b/2)
    if moda == 0:
        return gcd(a/2, b)
    if modb == 0:
        return gcd(a, b/2)
    return gcd(b, a-b)

def bad_gcd(a, b):
    global count
    count += 1
    if a < b:
        a, b = b, a
    if b == 0:
        return a
    return bad_gcd(b, a-b)

def main():
    a = 1100100210001
    b = 120200021
    global count

    count_good = 0
    count_bad  = 0
    for i in range(1, 100):
        a = random.randint(200, 10000)
        b = random.randint(200, 10000)
        count = 0
        print 'gcd(%d, %d) is %d' % (a, b, gcd(a,b))
        print 'beauty gcd for %d times' % count

        count_good += count
        count = 0
        bad_gcd(a, b)
        count_bad  += count
        print 'and bad gcd for %d times\n' % count

    print 'good: %lf bad: %lf' %(count_good/99.0, count_bad/99.0)



if __name__ == '__main__':
    main();
