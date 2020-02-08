
[![在这里插入图片描述](https://img-blog.csdnimg.cn/20200112174144539.png?x-oss-process=image,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9icnljZTEwMTAuYmxvZy5jc2RuLm5ldA==,size_16,color_FFFFFF,t_70)](https://bryce1010.github.io/YangXian/)







## Ref
- KuangBin的ACM模板 [[github]](https://github.com/kuangbin/ACM-ICPC)  
- f-zyj/ACM 模板 [[github]](https://github.com/f-zyj/ACM)


## STL  
1. 顺序容器      
	- vector：后部插入/删除，直接访问   
    - deque：前/后部插入/删除，直接访问  
    - list：双向链表，任意位置插入/删除
    
2. 关联容器  
	- set：快速查找，无重复元素  
    - multiset ：快速查找，可有重复元素  
    - map：一对一映射，无重复元素，基于关键字查找
    - multimap ：一对一映射，可有重复元素，基于关键字查找  
前2者合称为第一类容器  


3. 容器适配器  
	- stack：LIFO
    - queue：FIFO
    - priority_queue：优先级高的元素先出  

### 1. 共有成员函数
相当于按词典顺序比较两个容器大小的运算符：   
- =, < , <= , >  , >=, == , !=
- empty : 判断容器中是否有元素
- max_size: 容器中最多能装多少元素
- size:   容器中元素个数
- swap: 交换两个容器的内容

### 2. 只在第一类容器中的函数
- begin  返回指向容器中第一个元素的迭代器
- end     返回指向容器中最后一个元素后面的位置的迭代器
- rbegin  返回指向容器中最后一个元素的迭代器
- rend    返回指向容器中第一个元素前面的位置的迭代器
- erase   从容器中删除一个或几个元素
- clear   从容器中删除所有元素

### 3. STL通用算法
STL中提供能在各种容器中通用的算法，比如插入，删除，查找，排序等。大约有70种标准算法。
- find
```cpp
find(InIt first, InIt last, const T& val); 
first 和 last 这两个参数都是容器的迭代器，它们给出了容器中的查找区间起点和终点。
val参数是要查找的元素的值
函数返回值是一个迭代器。如果找到，则该迭代器指向被找到的元素。如果找不到，则该迭代器指向查找区间终点。
```

- copy
```cpp
OutIt copy(InIt first, InIt last, OutIt x); 
copy (v.begin(),v.end(),output);
对于copy (v.begin(),v.end(),output);
first 和 last 的类型是  vector<int>::const_iterator
output 的类型是 ostream_iterator<int> 
```

### 4. 顺序容器成员函数  
- front()  :返回容器中第一个元素的引用  
- back() : 返回容器中最后一个元素的引用
- push_back(): 在容器末尾增加新元素
- pop_back(): 删除容器末尾的元素

### 5. STL数据结构
查询[[f_zyj模板]](https://github.com/f-zyj/ACM/blob/master/ACM%20%E6%A8%A1%E7%89%88-f_zyj%20%E6%9B%B4%E6%96%B0%E8%87%B3%20v%202.1/v%202.1/ACM%E6%A8%A1%E6%9D%BF-f_zyj%20v%202.1.pdf)



## 递归回溯
教程:  [[递归与回溯的理解]](https://cloud.tencent.com/developer/article/1434886)  [[手把手教怎么写递归和回溯]](https://leetcode-cn.com/circle/article/GV6eQ2/)   

递归回溯一般模板：
```cpp
'''
backtracking使用dfs的模板，基本跟dfs的模板一模一样
'''
class Backtracking(object):

    def backtracking(self, input):

        self.res = []

        def dfs(input, temp, [index]):
            # 边界
            if 非法数据：
                return

            # 终止条件
            if len(input) == len(temp)：
                self.res.append(temp[:])
                return

            # for循环
            for i range(len(input)):
                ##1. 修改path
                temp.append(input[i])
                ##2. backtracking
                dfs(input, temp, [index])
                ##3. 退回原来状态，恢复path
                temp.pop()
        # 执行
        dfs(input, [], 0)
        return self.res
```

- [x] (中等)Leetcode 17 电话号码的字母组合[[problem]](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)
- [x] (中等)Leetcode 22 括号生成[[problem]](https://leetcode-cn.com/problems/generate-parentheses/)
- [x] (中等)Leetcode 46 全排列[[problem]](https://leetcode-cn.com/problems/permutations/)
- [x] (中等)Leetcode 47 全排列II[[problem]](https://leetcode-cn.com/problems/permutations-ii/)  



## String 字符串  
- [x] 编辑距离 (f-zjy) 


## 搜索

参考如下：    
- 夜深人静写算法-搜索 [[blog]](http://www.cppblog.com/menjitianya/archive/2015/10/09/211980.html)  


### 1. DFS    
**算法描述**  
DFS的算法具体描述为选择一个起点v作为当前节点，执行如下操作：  
a. 访问当前节点，并且标记当前节点已被访问过，然后跳转到b；  
b. 如果存在一个和**当前节点**相邻并且尚未被访问的节点u，则将节点u设为当前节点，继续执行a；  
c. 如果不存在这样的u，则进行回溯，回溯的过程就是回退**当前节点**；  
上述**当前节点**需要用一个栈来维护，每次访问到得到节点入栈，回溯的时候出栈（也可以用递归来实现，更佳直观和方便）。    

- DFS实现  
```python
def DFS(v):
    vistited[v]=true
    dosomething()
    for u in adjcent_list[v]:
        if visited[v] is false:
            DFS(u) 
//其中dosomething 表示访问时具体要干的事，根据情况而定，并DFS是可以有返回值的；
```

**基础应用**   
- 求N的阶乘；   
```cpp
//f(n)=n*f(n-1), n>0
```
- 求斐波那契数列的第N项  
```cpp
//f(n)=f(n-1)+f(n-2), n>2,f(0)=f(1)=1  
//记忆化搜索
```
- 求n个数的全排列   
```cpp
//建立全连接图
```

**DFS高级应用**    
- 枚举    
数据较小的排列、组合的穷举；  
- 容斥原理  
利用深搜计算一个公式，本质上还是枚举；  	
- 基于状态压缩的动态规划    
一般解决棋盘摆放问题，k进制表示状态，然后利用深搜进行状态转移；  
- 记忆化搜索  
某个状态被计算过了，就将它cache住，下次要用到的时候就不需要再一次计算；  
- 有向图的强连通分量   
经典的Tarjan算法；  
求解2-sat问题的基础；   
- 无向图割边割点和双连通分量  
经典的Tarjan算法；  
- LCA   
最近公共祖先递归求解；  
- 博弈  
利用深搜计算SG值；   
- 二分图最大匹配  
经典的匈牙利算法；  
最小顶点覆盖，最大独立集，最小值支配集向二分图的转化；  
- 欧拉回路  
经典的圈套圈算法；  
- K短路   
依赖数据，数据不卡的话可以采用二分答案+深搜或者广搜+A*;  
- 线段树   
二分经典思想，配合枚举深搜左右子树；  
- 最大团  
极大完全子图的优化算法；  
- 最大流   
EK算法求任意路径中有涉及；  
- 树形DP   
即树形动态规划；父节点的值由各子节点计算得出；  

#### 1.1 基于DFS的记忆化搜索  

#### 1.2 基于DFS的剪枝    
好的剪枝可以大大提升程序的运行效率，那么问题来了，如何进行剪枝？我们先来看剪枝需要满足什么原则：  
a. 正确性  
剪掉的子树中如果存在可行解（或最优解），那么在其它的子树中很可能搜不到解导致搜索失败，所以剪枝的前提必须是要正确；  
b. 准确性  
剪枝要“准”。所谓“准”，就是要在保证在正确的前提下，尽可能多得剪枝。  
c. 高效性  
剪枝一般是通过一个函数来判断当前搜索空间是否是一个合法空间，在每个结点都会调用到这个函数，所以这个函数的效率很重要。    

- 可行性剪枝  
可行性剪枝一般是处理可行解的问题，如一个迷宫，问能否从起点到达目标点之类的。


- 最优化剪枝    
最优性剪枝一般是处理最优解的问题。以求两个状态之间的最小步数为例，搜索最小步数的过程：一般情况下，需要保存一个“当前最小步数”，这个最小步数就是当前解的一个下界d。在遍历到搜索树的叶子结点时，得到了一个新解，与保存的下界作比较，如果新解的步数更小，则令它成为新的下界。搜索结束后，所保存的解就是最小步数。而当我们已经搜索了k歩，如果能够通过某种方式估算出当前状态到目标状态的理论最少步数s时，就可以计算出起点到目标点的理论最小步数，即估价函数h = k + s，那么当前情况下存在最优解的必要条件是h < d，否则就可以剪枝了。最优性剪枝是不断优化解空间的过程。     



#### 1.3 基于DFS的A*算法 (迭代加深IDA*) 
**1) 算法原理**  
迭代加深分两步走：  
- 枚举深度。  
- 根据限定的深度进行DFS，并且利用估价函数进行剪枝。  

- [ ] [Red and Black](http://poj.org/problem?id=1979)        ★☆☆☆☆   FloodFill

- [ ] [The Game](http://poj.org/problem?id=1970)          ★☆☆☆☆   FloodFill

- [ ] [Frogger](http://poj.org/problem?id=2253)           ★☆☆☆☆   二分枚举答案 + FloodFill  

- [ ] [Nearest Common Ancestors](http://poj.org/problem?id=1330)  ★☆☆☆☆   最近公共祖先 

- [ ] [Robot Motion](http://poj.org/problem?id=1573)        ★☆☆☆☆   递归模拟

- [ ] [Dessert](http://poj.org/problem?id=1950)           ★☆☆☆☆   枚举

- [ ] [Matrix](http://poj.org/problem?id=2078)           ★☆☆☆☆   枚举

- [ ] [Frame Stacking](http://poj.org/problem?id=1128)       ★☆☆☆☆   枚举

- [ ] [Transportation](http://poj.org/problem?id=1040)       ★☆☆☆☆   枚举

- [ ] [Pairs of Integers](http://poj.org/problem?id=1117)          ★★☆☆☆   枚举

- [ ] [方程的解数](http://poj.org/problem?id=1186)                   ★★☆☆☆   枚举 + 散列HASH

- [ ] [Maze](http://poj.org/problem?id=1103)                       ★★☆☆☆  建完图后FloodFill

- [ ] [Trees Made to Order](http://poj.org/problem?id=1095)        ★★☆☆☆  递归构造解

- [ ] [Cycles of Lanes](http://poj.org/problem?id=3895)            ★★☆☆☆  简单图最长环

- [ ] [The Settlers of Catan](http://poj.org/problem?id=2258)      ★★☆☆☆  简单图最长链

- [ ] [Parity game](http://poj.org/problem?id=1733)                ★★☆☆☆  简单图判奇环(交错染色)

- [ ] [Increasing Sequences](http://poj.org/problem?id=1239)       ★★☆☆☆  枚举

- [ ] [Necklace Decomposition](http://poj.org/problem?id=2639)     ★★☆☆☆  枚举

- [ ] [Rikka with Tree](http://acm.hdu.edu.cn/showproblem.php?pid=5423)      ★★☆☆☆   统计

- [ ] [Mahjong tree](http://acm.hdu.edu.cn/showproblem.php?pid=5379)        ★★★☆☆   统计

- [ ] [Machine Schedule](http://poj.org/problem?id=1325)           ★★★☆☆  二分图最大匹配

- [ ] [Chessboard](http://poj.org/problem?id=2446)                 ★★★☆☆  棋盘覆盖问题

- [ ] [Air Raid](http://poj.org/problem?id=1422)                   ★★★☆☆  DAG图 最小路径覆盖

- [ ] [Entropy](http://poj.org/problem?id=1898)                    ★★★☆☆  枚举 + 适当剪枝

- [ ] [Dropping the stones](http://poj.org/problem?id=3400)        ★★★☆☆  枚举 + 适当剪枝

- [ ] [Dreisam Equations](http://poj.org/problem?id=1100)          ★★★☆☆  表达式求值

- [ ] [Firefighters](http://poj.org/problem?id=1460)               ★★★☆☆  表达式求值 

- [ ] [Cartesian Tree](http://poj.org/problem?id=2201)             ★★★☆☆  笛卡尔树的构造

- [ ] [Binary Stirling Numbers](http://poj.org/problem?id=1430)    ★★★☆☆  分形

- [ ] [Obfuscation](http://poj.org/problem?id=3504)                ★★★☆☆  字符串匹配

- [ ] [Graph Coloring](http://poj.org/problem?id=1419)       ★★★☆☆   最大团

- [ ] [Pusher](http://acm.hdu.edu.cn/showproblem.php?pid=2821)           ★★★☆☆   暴力搜索

- [ ] [Self-Replicating Numbers](http://poj.org/problem?id=2205)   ★★★★☆  枚举

- [ ] [Last Digits](http://poj.org/problem?id=2720)                ★★★★☆  DFS + 欧拉函数  

- [ ] [Secret Code](http://poj.org/problem?id=1381)                ★★★★☆  实复数进制转化

- [ ] [Anniversary Cake](http://poj.org/problem?id=1020)           ★★★★☆  矩形填充

- [ ] [A Puzzling Problem](http://poj.org/problem?id=1544)         ★★★★☆  枚举摆放

- [ ] [Vase collection](http://poj.org/problem?id=1632)            ★★★★☆  图的完美匹配

- [ ] [Packing Rectangles](http://poj.org/problem?id=1169)         ★★★★☆  枚举摆放

- [ ] [Missing Piece 2001](http://poj.org/problem?id=2224)         ★★★★☆  N*N-1 数码问题，强剪枝


**IDA\***(确定是迭代加深后就一个套路，枚举深度，然后 暴力搜索+强剪枝)
- [ ] [Addition Chains](http://poj.org/problem?id=2248)            ★★☆☆☆   

- [ ] [DNA sequence](http://acm.hdu.edu.cn/showproblem.php?pid=1560)        ★★☆☆☆   

- [ ] [Booksort](http://poj.org/problem?id=3460)                   ★★★☆☆  

- [ ] [The Rotation Game](http://acm.hdu.edu.cn/showproblem.php?pid=1667)     ★★★☆☆   迭代加深的公认经典题，理解“最少剩余步数”      

- [ ] [Paint on a Wall](http://acm.hdu.edu.cn/showproblem.php?pid=4012)       ★★★☆☆   [The Rotation Game](http://acm.hdu.edu.cn/showproblem.php?pid=1667) 的简单变形

- [ ] [Escape from Tetris](http://acm.hdu.edu.cn/showproblem.php?pid=1813)     ★★★★☆   

- [ ] [Maze](http://poj.org/problem?id=2644)            ★★★★☆ 

- [ ] [Rubik 2×2×2](http://acm.hdu.edu.cn/showproblem.php?pid=3459)         ★★★★★   编码麻烦的魔方题




### 2. BFS
BFS的具体算法描述为选择一个起始点v放入一个先进先出的队列中，执行如下操作：    
a. 如果队列不为空，弹出一个队列首元素，记为当前结点，执行b；否则算法结束；  
b. 将与 当前结点 相邻并且尚未被访问的结点的信息进行更新，并且全部放入队列中，继续执行a；  
维护广搜的数据结构是队列和HASH，队列就是官方所说的open-close表，HASH主要是用来标记状态的，比如某个状态并不是一个整数，可能是一个字符串，就需要用字符串映射到一个整数，可以自己写个散列HASH表，不建议用STL的map，效率奇低。   


**算法实现**  
广搜一般用队列维护状态，写成伪代码如下：  
```python
def BFS(v):
    resetArray(visited,false)
    visited[v] = true
    queue.push(v)
    while not queue.empty():
        v = queue.getfront_and_pop()
        for u in adjcent_list[v]:
            if visited[u] is false:
                dosomething(u)
                queue.push(u)
```

**基础应用**    
-  最短路：bellman-ford最短路的优化算法SPFA，主体是利用BFS实现的。    
绝大部分四向、八向迷宫的最短路问题。     
- 拓扑排序：  
首先找入度为0的点入队，弹出元素执行“减度”操作，继续将减完度后入度为0的点入队，循环操作，直到队列为空，经典BFS操作；   
- FloodFill：  
经典洪水灌溉算法；  


**高级应用**  
- 差分约束：   
数形结合的经典算法，利用SPFA来求解不等式组。  
- 稳定婚姻：   
二分图的稳定匹配问题，试问没有稳定的婚姻，如何有心思学习算法，所以一定要学好BFS啊；                
- AC自动机：   
字典树 + KMP + BFS，在设定失败指针的时候需要用到BFS。     
详细算法参见：http://www.cppblog.com/menjitianya/archive/2014/07/10/207604.html  
- 矩阵二分：   
矩阵乘法的状态转移图的构建可以采用BFS；   
- 基于k进制的状态压缩搜索：   
这里的k一般为2的幂，状态压缩就是将原本多维的状态压缩到一个k进制的整数中，便于存储在一个一维数组中，往往可以大大地节省空间，又由于k为2的幂，所以状态转移可以采用位运算进行加速，HDU1813和HDU3278以及HDU3900都是很好的例子；   




#### 2.1 基于BFS的A*算法  
在搜索的时候，结点信息要用堆（优先队列）维护大小，即能更快到达目标的结点优先弹出。




- [ ] [Pushing Boxes](http://poj.org/problem?id=1475)        ★☆☆☆☆   经典广搜 - 推箱子

- [ ] [Jugs](http://poj.org/problem?id=1606)            ★☆☆☆☆   经典广搜 - 倒水问题

- [ ] [Space Station Shielding](http://poj.org/problem?id=1096)  ★☆☆☆☆   FloodFill

- [ ] [Knight Moves](http://poj.org/problem?id=1915)        ★☆☆☆☆   棋盘搜索

- [ ] [Knight Moves](http://poj.org/problem?id=2243)        ★☆☆☆☆   棋盘搜索    

- [ ] [Eight](http://poj.org/problem?id=1077)            ★★☆☆☆   经典八数码

- [ ] [Currency Exchange](http://poj.org/problem?id=1860)      ★★☆☆☆   SPFA

- [ ] [The Postal Worker Rings](http://poj.org/problem?id=1237)  ★★☆☆☆   SPFA

- [ ] [ROADS](http://poj.org/problem?id=1724)           ★★☆☆☆   优先队列应用 

- [ ] [Ones](http://poj.org/problem?id=2551)            ★★☆☆☆   同余搜索

- [ ] [Dogs](http://acm.hdu.edu.cn/showproblem.php?pid=2822)            ★★☆☆☆

- [ ] [Lode Runner](http://acm.hdu.edu.cn/showproblem.php?pid=2851)        ★★☆☆☆
  
- [ ] [Hike on a Graph](http://acm.hdu.edu.cn/showproblem.php?pid=1252)      ★★☆☆☆

- [ ] [Find The Multiple](http://poj.org/problem?id=1426)      ★★☆☆☆   同余搜索

- [ ] [Different Digits](http://poj.org/problem?id=2283)      ★★★☆☆   同余搜索

- [ ] [Magic Multiplying Machine](http://poj.org/problem?id=2206) ★★★☆☆   同余搜索

- [ ] [Remainder](http://poj.org/problem?id=2426)          ★★★☆☆   同余搜索

- [ ] [Escape from Enemy Territory](http://poj.org/problem?id=3501)★★★☆☆   二分答案 + BFS

- [ ] [Will Indiana Jones Get](http://poj.org/problem?id=1292)   ★★★☆☆   二分答案 + BFS

- [ ] [Fast Food](http://poj.org/problem?id=1485)          ★★★☆☆   SPFA

- [ ] [Invitation Cards](http://poj.org/problem?id=1511)      ★★★☆☆   SPFA

- [ ] [Galactic Import](http://poj.org/problem?id=1545)       ★★★☆☆   SPFA

- [ ] [XYZZY](http://poj.org/problem?id=1932)            ★★★☆☆   最长路判环

- [ ] [Intervals](http://poj.org/problem?id=1201)          ★★★☆☆   差分约束

- [ ] [King](http://poj.org/problem?id=1364)            ★★★☆☆   差分约束

- [ ] [Integer Intervals](http://poj.org/problem?id=1716)      ★★★☆☆   差分约束

- [ ] [Sightseeing trip](http://poj.org/problem?id=1734)      ★★★☆☆   无向图最小环

- [ ] [N-Credible Mazes](http://poj.org/problem?id=1522)      ★★★☆☆   多维空间搜索，散列HASH

- [ ] [Spreadsheet](http://poj.org/problem?id=1420)         ★★★☆☆   建立拓扑图后广搜

- [ ] [Frogger](http://poj.org/problem?id=3000)           ★★★☆☆   同余搜索

- [ ] [Ministry](http://poj.org/problem?id=2353)          ★★★☆☆   需要存路径

- [ ] [Gap](http://poj.org/problem?id=2046)             ★★★☆☆   A*

- [ ] [Maze](http://poj.org/problem?id=2157)            ★★★☆☆  二进制压缩钥匙的状态  

- [ ] [Hike on a Graph](http://poj.org/problem?id=2415)      ★★★☆☆   

- [ ] [All Discs Considered](http://poj.org/problem?id=1778)    ★★★☆☆

- [ ] [Roads Scholar](http://poj.org/problem?id=1097)        ★★★☆☆   SPFA

- [ ] [Holedox Moving](http://poj.org/problem?id=1324)       ★★★☆☆

- [ ] [昂贵的聘礼](http://poj.org/problem?id=1062)          ★★★☆☆

- [ ] [Maze Stretching](http://poj.org/problem?id=3897)       ★★★☆☆

- [ ] [Treasure of the Chimp](http://poj.org/problem?id=3346)   ★★★☆☆

- [ ] [Is the Information Reliable](http://poj.org/problem?id=2983)★★★☆☆   最长路判环

- [ ] [It's not a Bug, It's a](http://poj.org/problem?id=1482)   ★★★☆☆

- [ ] [Warcraft](http://acm.hdu.edu.cn/showproblem.php?pid=300Warcraft)          ★★★☆☆

- [ ] [Escape](http://acm.hdu.edu.cn/showproblem.php?pid=30Escape)                         ★★★☆☆

- [ ] [Bloxorz I](http://poj.org/problem?id=3322)          ★★★☆☆   当年比较流行这个游戏

- [ ] [Up and Down](http://poj.org/problem?id=3912)             ★★★★☆   离散化 + BFS

- [ ] [Sightseeing](http://poj.org/problem?id=3463)         ★★★★☆   SPFA

- [ ] [Cliff Climbing](http://poj.org/problem?id=3328)       ★★★★☆   日本人的题就是这么长 

- [ ] [Cheesy Chess](http://poj.org/problem?id=3455)        ★★★★☆   仔细看题

- [ ] [The Treasure](http://poj.org/problem?id=1924)        ★★★★☆            

- [ ] [Chessman](http://poj.org/problem?id=3702)          ★★★★★   弄清状态同余的概念

- [ ] [Puzzle](http://acm.hdu.edu.cn/showproblem.php?pid=3278)           ★★★★★   几乎尝试了所有的搜索 -_-||| 让人欲仙欲死的题

- [ ] [Unblock Me](http://acm.hdu.edu.cn/showproblem.php?pid=3900)         ★★★★★   8进制压缩状态，散列HASH，位运算加速



#### 2.2 双向广搜  (适用于起始状态都给定的问题，一般一眼就能看出来，固定套路，很难有好的剪枝)
初始状态 和 目标状态 都知道，求初始状态到目标状态的最短距离;    
利用两个队列，初始化时初始状态在1号队列里，目标状态在2号队列里，并且记录这两个状态的层次都为0，然后分别执行如下操作：   
a.若1号队列已空，则结束搜索，否则从1号队列逐个弹出层次为K(K >= 0)的状态；    
i.  如果该状态在2号队列扩展状态时已经扩展到过，那么最短距离为两个队列扩展状态的层次加和，结束搜索；   
ii. 否则和BFS一样扩展状态，放入1号队列，直到队列首元素的层次为K+1时执行b；   
b.若2号队列已空，则结束搜索，否则从2号队列逐个弹出层次为K(K >= 0)的状态；   
i.  如果该状态在1号队列扩展状态时已经扩展到过，那么最短距离为两个队列扩展状态的层次加和，结束搜索；   
ii. 否则和BFS一样扩展状态，放入2号队列，直到队列首元素的层次为K+1时执行a；    




- [ ] [Solitaire](http://poj.org/problem?id=1198)         ★★★☆☆

- [ ] [A Game on the Chessboard](http://poj.org/problem?id=1735)  ★★★☆☆

- [ ] [魔板](http://acm.hdu.edu.cn/showproblem.php?pid=1430)            ★★★★☆
- [ ] [Tobo or not Tobo](http://acm.hdu.edu.cn/showproblem.php?pid=2918)      ★★★★☆

- [ ] [Eight II](http://acm.hdu.edu.cn/showproblem.php?pid=3567)          ★★★★★










## 动态规划 DP



## 精选技巧
### 1. 双指针  
- [x] (中等)leetcode 16. 最接近的三数之和[[problem]](https://leetcode-cn.com/problems/3sum-closest/)  


### 2. 二分  
[[二分讲解参考]](https://blog.csdn.net/CCSGTC/article/details/80586181)  

- 左闭右开  
[l,r）  
```cpp
int l=0,r=n;
while(l<r)
{
	r=middle;
	l=middle+1;
}
```



- 左闭右闭  
[l,r]   
```cpp
int l=0,r=n-1;
while(l<=r)
{
	r=middle-1;
	l=middle+1;
}
```

- 左开右开  
(l,r)   
```cpp
int l=-1,r=n;
while(l+1!=r)
{
	r=middle;
	l=middle;
}
```
- 二分模板 (求非下降序列的首次首次出现的位置) 
```cpp
int binary(int array[],int n,int target)
{
    int left,right,middle;
    left=-1,right=n;
    while(left+1!=right){
        middle=left+(right-left)/2;
        if(array[middle]>=target){
            right=middle;
        }else{
            left=middle;
        }
    }
    if(right==n||array[right]!=target)
        return -1;
    return right;
}
```

#### 快速幂(也算是二分的一种思想)  

```cpp
Matrix quickPower(Matrix A, int k){
    Matrix result=I;
    while(k>0)
    {
        if(k%1==1)result=result*A;
        k=k/2;
        result=result*result;
    }
    return result;
}
```






- 二分搜索题集 [[leetcode]](https://leetcode-cn.com/tag/binary-search/)     
- [ ] (困难)Leetcode 4. 寻找两个有序数组的中位数 [[problem]](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)    
- [x] (中等)Leetcode 29. 两数相除 [[problem]](https://leetcode-cn.com/problems/divide-two-integers/)  
- [x] (中等)Leetcode 33.搜索旋转排序数组  [[problem]](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) [[题解]](https://blog.csdn.net/Fire_to_cheat_/article/details/104196694)    
- [x] (中等)Leetcode 34. 在排序数组中查找元素的第一个和最后一个位置 [[problem]](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)    
- [x] (中等)Leetcode 50. Pow(x, n) [[problem]](https://leetcode-cn.com/problems/powx-n/)  
- [ ] (中等)Leetcode 74. 搜索二维矩阵 [[problem]](https://leetcode-cn.com/problems/search-a-2d-matrix/)    
- [ ] (中等)Leetcode 81. 搜索旋转排序数组 II [[problem]](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)  
- [ ] (中等)Leetcode 153. 寻找旋转排序数组中的最小值 [[problem]](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)   
- [ ] (困难)Leetcode 154. 寻找旋转排序数组中的最小值 II [[problem]](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)   
- [ ] (中等)Leetcode 162. 寻找峰值 [[problem]](https://leetcode-cn.com/problems/find-peak-element/)   








### 3. 排序

- **归并排序**  
时间复杂度： O(nlogn)   
归并排序是基于分治思想的排序方法。  
归并排序a[l,r]的算法，简要描述为：  
（1）将a[l,r]拆成a[l,mid],a[mid+1,r]两部分  
（2）调用MergeSort(l,mid)和MerSort(mid+1,r),将这两部分分别排好序  
（3）合并排好序的两部分，覆盖a[l,r]  
关于合并过程：  
（1）如果A取完，那么直接从B中取；  
（2）如果B取完，那么直接从A中取；  
（3）如果A，B都没取完，那么从A，B的头部，取更小的那个；    
```cpp
int source[100],target[100];
void merge(int left,int mid,int right)
{
    int i=left,j=mid+1,k=left;
    while(i<=mid&&j<=right)
    {
        if(source[i]<source[j])
        {
            target[k++]=source[i++];
        }
        else
        {
            target[k++]=source[j++];
        }
    }
    while(i<=mid)
    {
       target[k++]=source[i++];
    }
    while(j<=right)
    {
        target[k++]=source[j++];
    }
    for(int ss=left;ss<=right;++ss)
        source[left]=target[left];

}
void MergeSort(int left,int right)
{
    int mid=(left+right)/2;
    MergeSort(left,mid);
    MergeSort(mid+1,right);
    merge(left,mid,right);
}

```
 
- **快排**     
时间复杂度：O(nlogn)   
以身高排序为例：  
（1）选择一个人  
（2）将比这个人矮的放到左边去  
（3）将比这个人高的放到右边去  
（4）对这个人坐便和右边分别进行相似的递归排序  
```cpp
template<class Type>
int partition(Type array[],int left,int right)
{
    int flag=array[left];
    while(left<right)
    {
        //put all x < flag to left
        while(left<right&&array[right]>=flag)
        {
            right--;
        }
        if(left<right)
        {
            array[left]=array[right];
            left++;
        }
        //put all x>flag to right
        while(left<right&&array[left]<=flag)
        {
            left++;
        }
        if(left<right)
        {
            array[right] = array[left];
            right--;
        }
    }
    //left and right 重合时，将flag放置中间
    array[left]=flag;
    return left;
}
template<class Type>
void quick_sort(Type array[],int left,int right)
{
    if(left<right)
    {
        int position=partition(array,left,right);
        quick_sort(array,left,position-1);
        quick_sort(array,position+1,right);
    }
}
```








## Leetcode

### 在线平台   
- [力扣](https://leetcode-cn.com/problemset/all/)
- [leetcode食用指南](https://github.com/azl397985856/leetcode)
- [牛客网](https://www.nowcoder.com/)
- [LibreOJ(算法竞赛一本通——提高篇)](https://loj.ac)
- [Comet OJ](https://www.cometoj.com/contests)
- [HDU](http://acm.hdu.edu.cn/)
- [HihoCoder](https://hihocoder.com/)
- [洛谷](https://www.luogu.org/)
- [《算法竞赛进阶指南》题目练习](https://ac.nowcoder.com/acm/archive/oi-advance/problem)



### 教程  
- [KuangBin ACM模板](https://kuangbin.github.io/2018/08/01/ACM-template/#more)  
- [算法竞赛入门经典](https://github.com/dzsky/fucksky/blob/master/%E7%AE%97%E6%B3%95%E7%AB%9E%E8%B5%9B%E5%85%A5%E9%97%A8%E7%BB%8F%E5%85%B8%EF%BC%88%E7%AC%AC2%E7%89%88%EF%BC%89%20(%E7%AE%97%E6%B3%95%E8%89%BA%E6%9C%AF%E4%B8%8E%E4%BF%A1%E6%81%AF%E5%AD%A6%E7%AB%9E%E8%B5%9B).pdf) 
- [学习资源](https://oi-wiki.org/intro/resources/)  
- [OI wiki](https://oi-wiki.org/)
- [[OI & ACM 课件分享]](https://github.com/hzwer/shareOI)  


## 找工作


### 算法岗

- [深度学习面试宝典](https://github.com/amusi/Deep-Learning-Interview-Book)

- [知识星球讨论组](https://wx.zsxq.com/dweb2/index/group/init)

- 算法/深度学习/NLP面试笔记:
  [[github]](https://github.com/HarleysZhang/2019_algorithm_intern_information
  https://github.com/imhuay/Algorithm_Interview_Notes-Chinese)
- AI Jobs Notes
  https://github.com/amusi/AI-Job-Notes
  **公式：刷题+背题+项目+实习(可选)+竞赛(可选)+顶会/顶刊(可选)**
- Deep Learning interview book
  https://github.com/amusi/Deep-Learning-Interview-Book

- 机器学习/算法校招面试考点
  https://www.nowcoder.com/discuss/165930

- 介绍 CRF和HMM - 用Python实现 K-Means  - 解释一下精确率和召回率 
- Transformer为什么要加残差 - 对比介绍 CNN，RNN和 LSTM 
- 朴素贝叶斯为什么被称为“朴素”？ 
- 高频题：XGBoost和LightGBM的区别 
- 高频题：Bagging和Boosting的概念与区别 
- 解释一下支持向量机（SVM）如何学习非线性边界？ 
- XGBoost里面不同参数主要是什么作用，有哪些参数可以调节？ 
- 思考题：假设你在 Reddit 数据集上使用循环神经网络或长短时记忆神经网络设计了一个聊天机器人，它能够提供 10 种可能的回复，如何选择最佳回复，或者说如何删除其他的回复？

- [RF、GBDT、XGBOOST常见面试算法整理](https://zhuanlan.zhihu.com/p/85995153)



- [一个双非渣硕的自我救赎之路](https://www.nowcoder.com/discuss/328830?type=0&order=4&pos=1&page=4)




### 研发岗
- CS-Notes:
  https://github.com/CyC2018/CS-Notes
- Linux后台CPP学习之路 & 面经知识点收录
  https://www.nowcoder.com/discuss/78222

- 后台开发/基础架构方向 学习路线
  https://www.nowcoder.com/discuss/188367?type=0&order=4&pos=29&page=3

- C++后台开发面试考点汇总
  https://www.nowcoder.com/discuss/164721?type=0&order=0&pos=16&page=0

- [看开发大神如何只用5个月，拿下美团ssp顶薪offer](https://www.nowcoder.com/discuss/331574?toCommentId=4824987)

- [秋招总结：非机器学习科班学生漫长的算法工程师上岸之旅](https://www.nowcoder.com/discuss/326300)

- [ACMer的秋招总结与经验分享](https://www.nowcoder.com/discuss/338853?type=0&order=4&pos=10&page=2)









