# python学习

## python stl

列表list[]

元组tuple（）

集合set{}

字典dict{'one': 1, 'two': 2, 'three': 3}



## python类

**关于类变量与实例变量**：类成员就是类变量，类方法中定义的变量叫实例变量--实例变量归结于一个具体的实例，类对象可以直接通过类来进行调用的，实例对象不可以。



## python函数

### Python函数值传递和引用传递（包括形式参数和实际参数的区别）

Python 中，根据实际参数的类型不同，函数参数的传递方式可分为 2 种，分别为值传递和引用（地址）传递：
1、值传递：适用于实参类型为不可变类型（字符串、数字、元组）；
2、引用（地址）传递：适用于实参类型为可变类型（列表，字典）；

python中没有引用符号的，只有列表字典会因为带入函数之后，数值发生改变呀

### Python函数可变参数（*args,**kwargs）详解

args 表示创建一个名为 args 的空元组，该元组可接受任意多个外界传入的非关键字实参

1) 可变参数：形参前添加一个 '**'*--对应列表
2) 可变参数：形参前添加两个'*'--对应字典--表明好key值
