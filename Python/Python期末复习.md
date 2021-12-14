内容整合自互联网，如侵犯您的著作权请联系我删除

# CH1

知晓Python为解释型语言、面向对象的语言，是一种跨平台、开源、免费的高级动态编程语言，其自带的开发环境是IDLE。

# CH2

## 标识符的命名规则

1. 标识符是由字符（A~Z 和 a~z）、下划线和数字组成，但**第一个字符不能是数字**；

2. 标识符不能和 Python 中的保留字相同；

3. Python标识符中，不能包含空格、@、% 以及 $ 等特殊字符。

```
UserID
name
mode12
user_age
```

## Python语句的基本规则

- 注释符：

```python
# 单行注释

'''
使用 3 个单引号分别作为注释的开头和结尾
可以一次性注释多行内容
这里面的内容全部是注释内容
'''

"""
使用 3 个双引号分别作为注释的开头和结尾
可以一次性注释多行内容
这里面的内容全部是注释内容
"""
```
注意：
1. 多行注释不支持嵌套
2. 当注释符作为字符串的一部分出现时，就不能再将它们视为注释标记，而应该看做正常代码的一部分
```python
print('''Hello,World!''')
print("""http://c.biancheng.net/cplus/""")
print("#是单行注释的开始")
```
```
Hello,World!
http://c.biancheng.net/cplus/
#是单行注释的开始
```
- 续行符：
```python
hello = "This is a rather long string containing\n\

several lines of text just as you would do in C.\n\

    Note that whitespace at the beginning of the line is\

 significant."

print(hello)
```
```
This is a rather long string containing

several lines of text just as you would do in C.

    Note that whitespace at the beginning of the line is significant.
```
```python
print("""\

Usage: thingy [OPTIONS]

     -h                        Display this usage message

     -H hostname               Hostname to connect to

""")
```
```
Usage: thingy [OPTIONS]

     -h                        Display this usage message

     -H hostname               Hostname to connect to
```
- 代码组（块）：代码块可以使得一段python代码作为一个单元、一个整体执行。
- 分号的作用：如果要在一行中书写多条句，就必须使用分号分隔每个语句，否则Python无法识别语句之间的间隔。

## 四种数值类型
- int
- float
- complex:
- bool：True和False。（注意：首字母都是大写）

```python
aa=123-12j
print aa.real  # output 实数部分 123.0 
print aa.imag  # output虚数部分 -12.0
```
```
123.0
-12.0
```

## 六种内建数据结构

不可变：
> 当数据发生改变后，变量的内存地址发生了改变

1. Number（数字）表示数据组成为数字 **（不可变）**

2. String（字符串）表示数据组成是字符 **（不可变）**
3. List（列表）:用来表示一组有序元素 **（可变）**
4. Tuple（元组）：用来表示一组有序元素 **（不可变）**
5. Sets（集合）：一组数据无序不重复元素 **（可变）**
6. Dictionary（字典）：用键值对的形式保存一组元素 **（可变）**

- 有序序列：列表、元组、字符串
- 无序序列：字典、集合

> 变量使用前无须声明

## 运算符
- “ // ” 表示整数除法，返回整数 比如 7/3 结果为2
- “ / ” 表示浮点数除法，返回浮点数 （即小数） 比如 8/2 结果为4.0
- “ %” 表示取余数 比如7/4 结果为3
- “x**y” 幂，返回x的y次幂
> ++不能用；a=(b=c=0)非法
- “+”和“*”针对字符串、列表、元组的用法:"+"组合，*重复

## 字符串
### 字符串的定界方法
```
+---+---+---+---+---+---+
| P | y | t | h | o | n |
+---+---+---+---+---+---+
  0   1   2   3   4   5
 -6  -5  -4  -3  -2  -1
```
```
demo = 'Hello, world!'
print(demo[0]) # 'H'
print(demo[-1]) # '!'
```

### 子串的切片运算
```
 +---+---+---+---+---+---+
 | P | y | t | h | o | n |
 +---+---+---+---+---+---+
 0   1   2   3   4   5   6
-6  -5  -4  -3  -2  -1
```
```python
demo = 'Hello, world!'
print(demo[0:5]) # 'Hello'
print(demo[:5]) # 'Hello'
print(demo[5:13]) # ', world!'
print(demo[5:]) # ', world!'
```

### 字符串的连接
```python
first_name = 'An'
last_name = 'Jing'

name = first_name + last_name
```

### 字符串运算符
- 连接（+）
- 是否存在（in\not in）
```python
str1 = 'abcdefghijk'
print('b' in str1)  # b 存在str1 结果True
print('b' not in str1) # b 存在str1 结果False
print('cdf' in str1)   # cdf 不存在str1 结果False
print('cdf' not in str1) # cdf 不存在str1 结果True
```
- 原始字符串（r/R）
```python
# 与转义的对比，你会发现所有的\ 转义都不起作用了
print(r'Hello\''
      ' World！')  
print(r'C:\Windows\System32\')
print('C:\\Windows\\System32\\') # 如果文件地址不使用原始字符串，需要在\前加上\转义   
print(r'I\'am woodman')
print(r"我要学习\"Python\"")
print(R'linux\b')
print(R'linux\ngood!')
print(R'Python\vgood!')
print(R'Python\t good!')
print(R'woodman\r good!')
print(R'woodman\f good!')
```

## 列表
### 切片
```
 +-----+-----+-----+-----+-----+-----+-----+
 | 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' |
 +-----+-----+-----+-----+-----+-----+-----+
 0     1     2     3     4     5     6     7
-7    -6    -5    -4    -3    -2    -1
```
```python
a = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
print(a[0:5]) # ['a', 'b', 'c', 'd', 'e']
print(a[::2]) # ['a', 'c', 'e', 'g']
print(a[:5]) # ['a', 'b', 'c', 'd', 'e']
print(a[5:]) # ['f', 'g']
print(a[-6:-3]) #[]
```
### 更新
```python
a = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
a[1] = '666'  # ['a', '666', 'c', 'd', 'e', 'f', 'g']
print(a[1]) # 666
```
### 删除
```python
>>> str=[1,2,3,4,5,2,6]
>>> del str[1]
>>> str
[1, 3, 4, 5, 2, 6]
```
`append()`,`count()`,`remove()`,`reverse()`,`copy()`,`sorted()`方法以及删除列表元素的各种方法。 
```python
>>> a = [5,7,6,3,4,1,2]
>>> b = sorted(a)       # 保留原列表
>>> a 
[5, 7, 6, 3, 4, 1, 2]
>>> b
[1, 2, 3, 4, 5, 6, 7]
```
sort 与 sorted 区别：

sort 是应用在 list 上的方法，sorted 可以对所有可迭代的对象进行排序操作。

list 的 sort 方法返回的是对已经存在的列表进行操作，无返回值，而内建函数 sorted 方法返回的是一个新的 list，而不是在原来的基础上进行的操作。
```python
# 初始选课的同学
students = [20190001 + x for x in range(10)]

# 新增一位
students.append(20191234)

# 新增一批
students.extend(range(20192020, 20192030))

# 把某位同学加到最前面
students.insert(0, 20190000)

# 替换，被替换的长度可以不等于替换内容的长度
students[5:15] = range(20192333, 20192340)

# 有步长的替换则要求两边的序列长度一样
students[0:5:2] = [20195333, 20196333, 20197333]

# 排序和反序
students.sort()
students.reverse()

if 20195333 in students:
  print('你选上了，同学。')

students.remove(20195333)

print('你又退了，同学。')

del students[:]

print(students)

del students

print(students)
```

## 元组
### 创建方法
```python
tup = ('a', 'b', 'c', 'd', 'e', 'f', 'g')
emptyTup = ()
```
### 切片运算

### 方法
```python
# 元组中可以只有一项内容，单独使用元组时括号可以省略，但逗号是不能省略的
teachers = 'anjing',

# 元组支持拼接操作
more_teachers = teachers + ('Tom', 'Jerry')

# 支持全切片复制元组，但不支持 .copy()
same_teachers = more_teachers[:]

# 支持查找，但不支持排序 .sort()
same_teachers.index('anjing')

# 支持哈希
print(hash(same_teachers))

# 可以整体删除但不支持部分删除
del more_teachers
del teachers
```
## 字典

### 元素的添加、修改、删除，字典的访问。

```python
import random

scores = [random.randint(60, 100) for x in range(10)]
students = [20190001 + x for x in range(10)]

transcript = dict(zip(students, scores))

# 传统写法
ranking = sorted(transcript.items(), key=lambda x: x[1], reverse=True)
ranked_transcript = dict(ranking)

# python 3.6+
ranked_transcript = {
    k: v
    for k, v in sorted(
        transcript.items(), key=lambda item: item[1], reverse=True)
}

print(ranked_transcript)
```
键不可变，值可变

通过两个列表创建字典的方法:
```python
>>> keys = ['a', 'b', 'c']
>>> values = [1, 2, 3]
>>> dictionary = dict(zip(keys, values))
>>> print(dictionary)
{'a': 1, 'b': 2, 'c': 3}
```
### 集合

创建方法set(seq)

交、并、补（差）。
1. 集合的交集& ,s.intersection()
```python
# 集合的交集  & ,s.intersection()
s1={"a","mia","hebut","tute"}
s2={"trtvc","hebut","yc","mia"}
s33=s1&s2               #{'hebut', 'mia'}  符号的方法
s44=s1.intersection(s2) #{'hebut', 'mia'}  函数的方法
print(s33)
print(s44)
```
2. 集合的并集 | ,s. union()
```python
# 集合的并集 | union
s1={"a","mia","hebut","tute"}
s2={"trtvc","hebut","yc","mia"}
s33=s1|s2 #{'trtvc', 'tute', 'hebut', 'mia', 'yc', 'a'}
s44=s1.union(s2) #{'tute', 'a', 'trtvc', 'yc', 'mia', 'hebut'}
print(s33)
print(s44)
```
3. 集合的差集  s1.difference(s2) 将集合s1里去掉和s2交集的部分
```python
#集合的差集 s1.difference(s2) 将集合s1里去掉和s2交集的部分
s1={"a","mia","hebut","tute"}
s2={"trtvc","hebut","yc","mia"}
s33=s1.difference(s2)#s33= {'tute', 'a'} 将集合s1里去掉和s2交集的部分
s44=s2.difference(s1)#s44= {'trtvc', 'yc'} 将集合s2里去掉和s1交集的部分
print("s33=",s33) 
print("s44=",s44)
```
4. 集合的交叉补集  s.symmetric_difference() 并集里去掉交集的部分
```python
# 集合的交叉补集 s.symmetric_difference()  并集里去掉交集的部分
s1={"a","mia","hebut","tute"}
s2={"trtvc","hebut","yc","mia"}
s=s1.symmetric_difference(s2) #{'yc', 'trtvc', 'a', 'tute'}  
print(s)
```
集合与其他数据结构的转换。
（正则表达式不考）
```python
# 签到的学生
checkin = [20190001, 20190002, 20190003, 20190004, 20190002]

# 一键去重
unique_checkin = list(set(checkin))

# 所有学生名单
all_students = [20190001, 20190002, 20190003, 20190004, 20190005, 20190006]

# 没来的，抓住你了
nauty_kids = set(all_students) - set(checkin)

print(nauty_kids)
```

|操作类型	|  列表	|  元组	   |   range   |
|:----:   |:----: |  :----: |   :----:  |
| 取值	  |支持	   |支持	  |    支持    |
| 切片	  |支持	   |支持	  |    支持    |
| 查找	  |支持	   |不支持    |   不支持    |
| 增加	  |支持	   |不支持    |	  不支持    |
| 更新	  |支持	   |不支持	  |   不支持    |
| 删除	  |支持	   |部分支持*  |  部分支持*  |

id()函数的用法
> id(object)函数是返回对象object在其生命周期内位于内存中的地址，id函数的参数类型是一个对象

删除各种数据结构的通用命令：del

# CH3

## 结构化程序设计的三种结构
1. 顺序结构：即语句从上到下按顺序执行
2. 分支结构：在python常用if..elif..else判断语句
3. 循环结构：在python常用while循环或是for循环

条件语句的各种形式。
```python
condition = input('请输入一个数字:')
if condition == 1:
    print("I'm one year old.")
elif condition == 2:
    print("I'm two years old.")
else:
    print("I'm a man now.")
```

## 三元运算符

     exp1 if contion else exp2

condition 是判断条件，exp1 和 exp2 是两个表达式。如果 condition 成立（结果为真），就执行 exp1，并把 exp1 的结果作为整个表达式的结果；如果 condition 不成立（结果为假），就执行 exp2，并把 exp2 的结果作为整个表达式的结果。

比如：
```python
max = a if a>b else b
```
- 如果 a>b 成立，就把 a 作为整个表达式的值，并赋给变量 max；
- 如果 a> b 不成立，就把 b 作为整个表达式的值，并赋给变量 max。

## 逻辑表达式的求值（and, or, not）

- `x and y` 布尔"与" - 若 x 为 False，x and y 返回 False，否则返回 y 的计算值
  > 一旦遇到 bool 逻辑为 False 的 “假货”，则返回它；如果一直遇到 “真货” 直至结束，则返回最后一个值 
- `x or y` 布尔"或" - 若 x 为非 0，则返回 x 的值，否则返回 y 的计算值
  > 一旦遇到 bool 逻辑为 True 的 “真货”，则返回它；如果一直遇到 “假货” 直至结束，则返回最后一个值
- `not x` 布尔"非" - 若 x 为 True，返回 False；若 x 为 False，返回 True

> 运算优先级：() > not > and > or
> 
详解：[逻辑运算符 (and / or / not) + 布尔逻辑 (bool)](https://blog.csdn.net/qq_39478403/article/details/105654170)

## 短路

```python
>>> 0 and 2
0
>>> [] and 2
[]
>>> 2 and {}
{}
>>> [] and {}
[]
>>> 2 and 5
5
>>> 5 and 2
2
>>> 0 or 2
2
>>> 2 or []
2
>>> False or 5
5
>>> [] or {}
{}
>>> {} or False or []
[]
```

## 利用for循环遍历各种数据结构
```python
for char in "Python":
    print(char) # P, y, t, h, o, n

for i in [1, 2, 3]:
    print(i) # 1, 2, 3

for i in (1, 2, 3):
    print(i) # 1, 2, 3

for i in range(8):
    print(i) # 0, 1, 2, 3, 4, 5, 6, 7

for i in range(0, 10)
    print(i) # 0, 1, 2, 3, 4, ,5, 6, 7, 8, 9

for i in range(0, 10, 2)
    print(i) # 0, 2, 4, 6, 8
```
## range函数
     range(start, stop[, step])

- start: 计数从 start 开始。默认是从 0 开始。例如range（5）等价于range（0， 5）;
- stop: 计数到 stop 结束，但不包括 stop。例如：range（0， 5） 是[0, 1, 2, 3, 4]没有5
- step：步长，默认为1。例如：range（0， 5） 等价于 range(0, 5, 1)
  
列表解析式,如
```python
a = []
for i in range(1,10):
    if i %2==0:
        a2.append(i)
    else:
        pass
print(a)
```

```python
a = [i for i in range(10) if i%2==0]
```

## while循环
## break、continue的用法

break 用于跳出循环。continue 用于忽略当次循环剩下的语句直接进行下一次循环。

## else 在for循环、while循环中的用法

Python 中循环也可以 else，在执行完整个循环以后会执行 else中的内容，如果 break 跳出循环，则不会执行。

## 循环嵌套

# CH4
## 函数的作用

降低编程复杂性，增强代码的可读性，实现代码的可复用性

## 函数的定义方法

     def functionname( parameters ):
          "函数_文档字符串"
          function_suite
          return [expression]

## 函数参数的传递方法（4种）
1. 必需参数
```python
def f(a,b,c)
     return a+b+c

print(f(1,2,3))
```
2. 关键字参数
```python
def f(a,b,c)
     return a+b+c

print(f(1,c=3,b=2))
```
3. 默认参数
```python
def f(a,b,c=10):
     return a+b+c

print(f(3,2))
print(f(3,2,1))
```

4. 不定长参数
```python
def func(*name):
     print type(name)
     print name
 
func(1,4,6)
func(5,6,7,1,2,3)
```
## 参数传递的副作用
```python
def foo(li=[]):
    li.append(1)
    print(li)

foo()
foo()
foo()
```

```python
[1]
[1, 1]
[1, 1, 1]
```
当 `foo` 函数被创建时，它的 默认参数 就已经被保存在它的 `__defaults__` 属性中了。而函数只会被创建一次，以后每次执行 foo() 的时候，都只会调用函数，并不会去重新创建一个函数。所以函数的 默认参数 也只会计算一次，无论之后被调用多少次，默认参数 始终都是同一个对象。

## return语句的返回值

## 函数的递归调用

## 格式化输出的实现（{}，%，format函数）

```python
>>> name = "Li hua"
>>> age = 24
>>> print("Hello "+name+", you are " + str(age) + " years old")
Hello Li hua, you are 24 years old
```

```python
>>> print('{}:"{}!"'.format('hello', 'python'))
hello:"python!"
>>> print('{1} and {0}'.format('hello', 'python'))
python and hello
```

## 匿名函数lambda
```python
>>> func = lambda x,y:x*y
>>> func(2,3)
6
>>> func_2 = lambda x:x^2 
>>> func_2(3)
9
```

## 模块导入方法（import, from … import …）

1. import 模块名1 [as 别名1], 模块名2 [as 别名2]，…：使用这种语法格式的 import 语句，会导入指定模块中的所有成员（包括变量、函数、类等）。不仅如此，当需要使用模块中的成员时，需用该模块名（或别名）作为前缀，否则 Python 解释器会报错。
2. from 模块名 import 成员名1 [as 别名1]，成员名2 [as 别名2]，…： 使用这种语法格式的 import 语句，只会导入模块中指定的成员，而不是全部成员。同时，当程序中使用该成员时，无需附加任何前缀，直接使用成员名（或别名）即可。

# CH5

## 打开文件、关闭文件所用的函数

```python
demo1=open("D:\python\pyDemo1.txt",'rt',encoding='UTF-8')
print("文件的文本形式打开方式内容是:{}".format(demo1.readline()))
demo1.close()
demo2=open("D:\python\pyDemo1.txt",'rb')
print("文件的二进制打开方式内容是:{}".format(demo2.readline()))
demo2.close()
```

## 文件打开模式（含组合模式）

r 以只读方式打开文件。文件的指针将会放在文件的开头。这是默认模式。

w 打开一个文件只用于写入。如果该文件已存在则将其覆盖。如果该文件不存在，创建新文件。

a 打开一个文件用于追加。如果该文件已存在，文件指针将会放在文件的结尾。也就是说，新的内容将会被写入到已有内容之后。如果该文件不存在，创建新文件进行写入。

rb 以二进制格式打开一个文件用于只读。文件指针将会放在文件的开头。这是默认模式。

wb 以二进制格式打开一个文件只用于写入。如果该文件已存在则将其覆盖。如果该文件不存在，创建新文件。

ab 以二进制格式打开一个文件用于追加。如果该文件已存在，文件指针将会放在文件的结尾。也就是说，新的内容将会被写入到已有内容之后。如果该文件不存在，创建新文件进行写入。

r+ 打开一个文件用于读写。文件指针将会放在文件的开头。

w+ 打开一个文件用于读写。如果该文件已存在则将其覆盖。如果该文件不存在，创建新文件。

a+ 打开一个文件用于读写。如果该文件已存在，文件指针将会放在文件的结尾。文件打开时会是追加模式。如果该文件不存在，创建新文件用于读写。

rb+ 以二进制格式打开一个文件用于读写。文件指针将会放在文件的开头。

wb+ 以二进制格式打开一个文件用于读写。如果该文件已存在则将其覆盖。如果该文件不存在，创建新文件。

ab+ 以二进制格式打开一个文件用于追加。如果该文件已存在，文件指针将会放在文件的结尾。如果该文件不存在，创建新文件用于读写。

## 读取数据的三种方法
- read() : 读取文件全部内容，该方法返回字符串。
- readline() : 每次读出一行内容，所以，读取时占用内存小，比较适合大文件，该方法返回一个字符串对象。
- readlines() : 取整个文件所有行，保存在一个列表(list)变量中，每次读取一行，但读取大文件会比较占内存。

## 写入数据的两种方法
- write()

```python
txt_data = open('txt_file.txt',encoding='utf-8',mode='a+')
print(txt_data.write('Hello world'))    #11
```
- writelines()
```python
txt_data = open('txt_file.txt', encoding='utf-8', mode='a+')
txt_data.writelines(["\n"+'python', '程序开发'])
```

## 文本文件的读写操作

- seek(n)	将文件指针移动到指定字节的位置
- tell()	获取当前文件指针所在字节位置

```
1:www.runoob.com
2:www.runoob.com
3:www.runoob.com
4:www.runoob.com
5:www.runoob.com
```

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-

# 打开文件
fo = open("runoob.txt", "rw+")
print "文件名为: ", fo.name

line = fo.readline()
print "读取的数据为: %s" % (line)

# 获取当前文件位置
pos = fo.tell()
print "当前位置: %d" % (pos)


# 关闭文件
fo.close()
```

```
文件名为:  runoob.txt
读取的数据为: 1:www.runoob.com

当前位置: 17
```

## 异常处理的执行流程

```python
try:
    #正常的操作

except:
    #发生以上多个异常中的一个，执行这块代码
   
else:
    #如果没有异常执行这块代码

finally:
    #退出try时总会执行
```

## 显式抛出异常：raise

```python
def mye( level ):
    if level < 1:
        raise Exception,"Invalid level!"
        # 触发异常后，后面的代码就不会再执行
try:
    mye(0)            # 触发异常
except Exception,err:
    print 1,err
else:
    print 2
```

## pdb:调试程序模块（具体调试命令不做要求）

pdb 是 python 自带的一个包，为 python 程序提供了一种交互的源代码调试功能，主要特性包括设置断点、单步调试、进入函数调试、查看当前代码、查看栈片段、动态改变变量的值等。pdb 提供了一些常用的调试命令

# CH6

## 面向对象编程的特点
- 封装
- 继承
- 多态

## 定义类\实例化

```python
class Person :
    '这是一个学习Python定义的一个Person类'
    # 下面定义了一个类变量
    hair = 'black'
    def __init__(self, name = 'Charlie', age=8):
        # 下面为Person对象增加2个实例变量
        self.name = name
        self.age = age
    # 下面定义了一个say方法
    def say(self, content):
        print(content)

person = Person('mike', 12)
person.say('hahaha')
```

## self参数的使用

类内方法的第一个参数self用来表示对象本身，在类的外部通过对象名来调用方法时不需要为该参数传值。

理解公有属性、私有属性、保护属性的概念。

知道公有方法、私有方法、保护方法何时用。

下划线的使用。

构造函数、析构函数，前者完成对象的初始化操作，后者在释放对象时使用。

类的单继承（多继承不考）

子类、父类的概念，所有类之父为object（ **注意全小写** ）。

方法的重写。注意代码重用（调用父类的构造方法，调用父类的公有方法）。

重点掌握（会应用）：类的定义与继承，方法的重写，类的实例化，方法的调用。

```python
class Pet:
    nickName = ""
    health = 0
    def __init__(self, name, health) -> None:
        self.nickName = name
        self.health = health

    def show(self):
        print("Name:",self.nickName)
        print("Health:",self.health)

class Dog(Pet):
    color = ""
    def __init__(self, name, health, color) -> None:
        super().__init__(name, health)
        self.color = color

    def show(self):
        super().show()
        print("Color:",self.color)

    def feed(self):
        self.health += 5

d = Dog("毛毛",5,"黑色")
d.feed()
d.show()
```

# CH6以后

## 掌握第三方库的安装方法

```
pip install xxx
```

## 窗体的定义方法

```python
import tkinter  #导入模块
win = tkinter.TK()  #创建窗体实例对象
win.mainloop  #显示窗体进入监听循环
```

## 窗体属性的设置方法
```python
win.geometry("1024x768")
win.minsize(800,600)
win.maxsize(1440,900)
```
（具体组件不做要求）