# 内存管理
- [内存管理](#内存管理)
- [变量](#变量)
- [内存四区](#内存四区)
  - [代码区](#代码区)
  - [静态区](#静态区)
  - [栈](#栈)
  - [堆](#堆)
- [内存分配](#内存分配)
  - [静态内存分配](#静态内存分配)
  - [动态内存分配](#动态内存分配)
- [例子](#例子)
  - [不同类型变量的存储](#不同类型变量的存储)
  - [栈变量与作用域](#栈变量与作用域)
  - [栈溢出](#栈溢出)
- [参考](#参考)



# 变量

- 全局变量（外部变量）: 
- 局部变量（自动变量）: 
- 静态变量: 关键字static修饰

# 内存四区
- 代码区
- 全局区/静态区 (static): 全局变量和静态局部变量区。已经初始化的全局变量和静态局部变量存储在同一区域，未初始化的全局变量和静态局部变量存储在另一个区域
- 栈 (stack), 局部变量区: 编译器自动分配和释放内存，存放局部变量、函数参数等数据
- 堆 (stack), 动态存储区: 程序员手动分配和释放内存
![内存四区](https://images2015.cnblogs.com/blog/686215/201512/686215-20151217212238302-1812512007.png)

## 代码区
程序被操作系统加载到内存的时候，所有的可执行代码（程序代码指令、常量字符串等）都加载到代码区，这块内存在程序运行期间是不变的。代码区是平行的，里面装的就是一堆指令，在程序运行期间是不能改变的。函数也是代码的一部分，故函数都被放在代码区，包括main函数。

　　注意："int a = 0;"语句可拆分成"int a;"和"a = 0"，定义变量a的"int a;"语句并不是代码，它在程序编译时就执行了，并没有放到代码区，放到代码区的只有"a = 0"这句。

## 静态区
静态区存放程序中所有的全局变量和静态变量。

## 栈
**栈** (**stack**) 是一种先进后出的内存结构，所有的自动变量、函数形参都存储在栈中，这个动作由编译器自动完成，我们写程序时不需要考虑。栈区在程序运行期间是可以随时修改的。当一个自动变量超出其作用域时，自动从栈中弹出。

每个线程都有自己专属的栈；
栈的最大尺寸固定，超出则引起栈溢出；
变量离开作用域后栈上的内存会自动释放。

## 堆

　　堆（heap）和栈一样，也是一种在程序运行过程中可以随时修改的内存区域，但没有栈那样先进后出的顺序。更重要的是堆是一个大容器，它的容量要远远大于栈，这可以解决上面实验三造成的内存溢出困难。一般比较复杂的数据类型都是放在堆中。但是在C语言中，堆内存空间的申请和释放需要手动通过代码来完成。对于一个32位操作系统，最大管理管理4G内存，其中1G是给操作系统自己用的，剩下的3G都是给用户程序，一个用户程序理论上可以使用3G的内存空间。堆上的内存必须手动释放（C/C++），除非语言执行环境支持GC（如C#在.NET上运行就有垃圾回收机制）。那堆内存如何使用？

　　接下来看堆内存的分配和释放：

malloc与free
　　malloc函数用来在堆中分配指定大小的内存，单位为字节（Byte），函数返回void *指针；free负责在堆中释放malloc分配的内存。malloc与free一定成对使用。看下面的例子：




# 内存分配
## 静态内存分配
## 动态内存分配
`malloc()` 函数原型：
```c
#include <stdlib.h>
void *malloc(unsigned size);
```
size是需要动态申请的内存的字节数。若申请成功，函数返回申请到的内存的起始地址，若申请失败，返回NULL。我们看下面这个例子：
```c
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint16_t *get_memory(uint16_t n)
{
    uint16_t *p = NULL;

    p = (uin16_t *)malloc(sizeof(uint16_t));
    if (NULL != p)
    {
         memset(p, 0, n * sizeof(uint16_t));
    }
    else
    {
         printf("malloc error\r\n");
    }

    return p;
}
```
使用该函数时，有下面几点要注意：
1）只关心申请内存的大小；
2）申请的是一块连续的内存。记得一定要写出错判断；
3）显示初始化。即我们不知这块内存中有什么东西，要对其清零；




在堆上分配的内存，需要用 `free()` 函数来释放，函数原型如下：
```c
#include <stdlib.h>
void free(void *ptr);
```
使用 `free()` ,也有下面几点要注意：

- 必须提供内存的起始地址。调用该函数时，必须提供内存的起始地址，不能够提供部分地址，释放内存中的一部分是不允许的。

- malloc和free成对使用。编译器不负责动态内存的释放，需要程序员自己释放。因此，malloc与free是成对使用的，避免内存泄漏。
  ```c
  free(p);
  p = NULL;
  ```
  p = NULL是必须的，因为虽然这块内存被释放了，但是p仍指向这块内存，避免下次对p的误操作；

- 不允许重复释放。因为这块内存被释放后，可能已另分配，这块区域被别人占用，如果再次释放，会造成数据丢失；




# 例子

## 不同类型变量的存储
```c
#include "stdio.h"

int  global_variable = 0;
void print_formal_parameter(int formal_parameter) { printf("  formal parameter: %p\n", &formal_parameter); }
int  main(int argc, char const* argv[])
{
    static int static_variable  = 1;
    int        local_varibale_a = 2;
    int        local_varibale_b = 3;
    printf("address:\n");
    printf("  global variable : %p\n", &global_variable);
    printf("  static variable : %p\n", &static_variable);
    printf("  local varibale a: %p\n", &local_varibale_a);
    printf("  local varibale b: %p\n", &local_varibale_b);

    print_formal_parameter(local_varibale_a);

    printf("  main func main(): %p", &main);
    return 0;
}
```
输出为
```bash
address:
  global variable : 0000000000407030
  static variable : 0000000000403010
  local varibale a: 000000000061FE1C
  local varibale b: 000000000061FE18
  formal parameter: 000000000061FDF0
  main func main(): 0000000000401572
```


## 栈变量与作用域
```c
//实验二：栈变量与作用域
#include "stdafx.h"
//函数的返回值是一个指针，尽管这样可以运行程序，但这样做是不合法的，因为
//非要这样做需在x变量前加static关键字修饰，即static int a = 0;
int *getx()
{
    int x = 10;
    return &x;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int *p = getx();
    *p = 20;
    printf("%d", *p);
    getchar();
}
```
这段代码没有任何语法错误，也能得到预期的结果：20。但是这么写是有问题的：因为int *p = getx()中变量x的作用域为getx()函数体内部，这里得到一个临时栈变量x的地址，getx()函数调用结束后这个地址就无效了，但是后面的*p = 20仍然在对其进行访问并修改，结果可能对也可能错，实际工作中应避免这种做法，不然怎么死的都不知道。不能将一个栈变量的地址通过函数的返回值返回，切记！

　　另外，栈不会很大，一般都是以K为单位。如果在程序中直接将较大的数组保存在函数内的栈变量中，很可能会内存溢出，导致程序崩溃（如下实验三），严格来说应该叫栈溢出（当栈空间以满，但还往栈内存压变量，这个就叫栈溢出）。


## 栈溢出
```c
//实验三：看看什么是栈溢出
int _tmain(int argc, _TCHAR* argv[])
{
    char array_char[1024*1024*1024] = {0};
    array_char[0] = 'a';
    printf("%s", array_char);
    getchar();
}
```

```c
//实验四：解决栈溢出的问题
#include "stdafx.h"
#include "stdlib.h"
#include "string.h"

void print_array(char *p, char n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("p[%d] = %d\n", i, p[i]);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    char *p = (char *)malloc(1024*1024*1024);//在堆中申请了内存
    memset(p, 'a', sizeof(int) * 10);//初始化内存
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        p[i] = i + 65;
    }
    print_array(p, 10);
    free(p);//释放申请的堆内存
    getchar();
}
```

程序可以正常运行，这样就解决了刚才实验三的栈溢出问题。堆的容量有多大?理论上讲，它可以使用除了系统占用内存空间之外的所有空间。实际上比这要小些，比如我们平时会打开诸如QQ、浏览器之类的软件，但这在一般情况下足够用了。实验二中说到，不能将一个栈变量的地址通过函数的返回值返回，如果我们需要返回一个函数内定义的变量的地址该怎么办？可以这样做：
```c
//实验五：
#include "stdafx.h"
#include "stdlib.h"

int *getx()
{
    int *p = (int *)malloc(sizeof(int));//申请了一个堆空间
    return p;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int *pp = getx();
    *pp = 10;
    free(pp);
}
```
　这样写是没有问题的，可以通过函数返回一个堆地址，但记得一定用通过free函数释放申请的堆内存空间。"int *p = (int *)malloc(sizeof(int));"换成"static int a = 0"也是合法的。因为静态区的内存在程序运行的整个期间都有效，但是后面的free函数就不能用了！

　　用来在堆中申请内存空间的函数还有calloc和realloc，用法与malloc类似。
# 参考

- [C语言知识整理（3）：内存管理（详细版）](https://www.cnblogs.com/yif1991/p/5049638.html)
- [C 语言内存管理 - 知乎](https://zhuanlan.zhihu.com/p/365791618)

