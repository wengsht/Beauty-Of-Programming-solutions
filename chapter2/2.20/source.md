### 问题1 ###
长整数仅不能被2到31中的两个连续的数整除

### 问题2 ###
存在
如果2到15之中，有数y不能整除x，那么2y也不能整除x。
故2到15到能整除x，对于2到15的奇数y，2y也必须能整除x，即6，10，14，18,22,26,30能整除x
28因4或7，24因8和3，20因4和5，都整除x
分析到这里，结果仅可能是16，17这对数

答案就是8*19*23*25*27*29*31*7*11*13=2123581660200


### 问题3 ###
2123581660200/(2*10^9) = 1061
1061s*每一层循环的计算次数
比较难搞。。