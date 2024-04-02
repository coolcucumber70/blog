//3.31
篮球：
    学习篮球技术，爱爱步的步骤
    背身晃一下，即踏步即走，多练

leetcode:
   合并链表的题目，最后再合并剩余的项
   合并的变相题目：k重遍历，涉及到了优先级队列，本质上是堆与堆排序的延伸--在此基础上写了二分排序
   二叉树递归：
   一个难的题目，最大的序列和，首先考虑必然是后续，但是必然每一个都遍历，延伸出只算一个边的递归算法。
   递归解决的子问题，能否体现在函数参数上呢？
   回溯算法：
   最简单的全排列，考虑结束的条件，continue排除了重复的方法，for（内部的便利）
c++：
   访函数的用法，本质是写一个public成员函数的类，函数是operate（）的重载，搭配stl来使用，要比函数做参数更加实用，适用泛型编程
   ：这里没完全明白
   https://blog.csdn.net/JMW1407/article/details/107130600/?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-4--blog-115462144.235^v43^pc_blog_bottom_relevance_base3&spm=1001.2101.3001.4242.3&utm_relevant_index=7
   https://blog.csdn.net/JMW1407/article/details/107130600/?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-4--blog-115462144.235^v43^pc_blog_bottom_relevance_base3&spm=1001.2101.3001.4242.3&utm_relevant_index=7
   https://blog.csdn.net/jay_zzs/article/details/106549621
   

   c语言中文网：温故了类的用法，const的初始化列表方法、堆上的释放内存的方法。

   操作符运载，到底有多少分类呢？？

   //4.1

   leetcode:
       回溯全排列
       1、无重复、c而非a 通过for中的i限制住，以前出现过的就不会再去访问
       2、无重复，a 全排列--直接用用visit来限制就好了
       3、有重复，全排列：剪枝
       4、无重复，可重复选择：剪枝结束状态的环境，选了后面就不需要再选

       bfs:
       框架：入队列，while判空，定义size，出队列，for循环进队列-->涉及到选择问题
       解密码锁的题目

       二分查找：
       细节在于【】while中<= 然后扣掉mid  以及定义mid left+（right-left）/2；
   
   投递公司：
       增加了一家阿里的游戏；
       快手过了初筛选，先准备c++；
   关于java：
       看了数据结构：
       int []marry= new arry[]
       List<int>l= new Linkedlist<>();
       Queue<int>=new Linkedlist<>();
       srack
       map
       set-->两种
       这里明天要复习了

    //4.2
    二分查找：
       如果用作者给的模版，是没有问题，但是特定的题型要去考虑是否越界等问题
       如果是左边界的话，right=mid-1？右边届，left=mid+1；

    滑动窗口：
    滑动窗口是两个while循环，第一个用来遍历，第二个用来优化答案

    图的遍历：
    dfs与回溯的区别，就在于第一个点不遍历
    细节：visit数组，记录是否访问。onpath记录访问路径

    dp问题：
    化简成重复子问题，动态表达式子能写出，这个问题就解决了。
    比如选硬币那个问题，本质就是那个回溯的暴力解问题。
    化简子问题：
    dp【n】=sub（）+1；
    可以考虑迭代，亦可考虑递归，递归的话，可以记录一个array，然后递归。

    握紧天，二分查找刷了一个题，图的dfs刷了一个，滑动窗口的异位，以及dp的硬币；
     明天要继续把dp看完了。之后就是贪心算法，我的算法思路就结束了。


      
