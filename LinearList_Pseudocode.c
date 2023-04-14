~~~
// 以下为伪代码
// 各类数据结构基础操作为创建销毁、增删改查。
// 按照C语言的定义需要在参数表中定义参数类型，但数据结构伪代码只需要抽象类，只有在具体实现的时候才需要定义。
// 什么时候需要传入引用“&”————对参数的修改结果需要“带回来”的时候。
~~~

# 0. 线性表基本操作
InitList(&L); //初始化表。构造一个空的线性表；分配内存空间。  
DestroyList(&L); //销毁表。销毁线性表，并师范线性表L所占用的内存空间。  
  
ListInsert(&L, i, e); //插入。在表L的第i个位置上插入元素e。  
ListDelete(&L, i, &e); //删除。删除表L的第i个位置的元素，并用e返回删除元素的值。  
  
LocElem(L, e); //按值查找。在表L中查找值为e的元素。  
GetElem(L, i); //按位置查找。在表L中获取第i个位置的元素的值。  
  
Length(L); //求表长度。返回线性表L的长度，即线性表L中的元素个数。  
PrintList(L); //输出线性表。按前后顺序输出线性表L的所有元素值。  
Empty(L); //判断表是否为空。是则返回True，否则返回False。  

# 1. 线性表初始化
~~~
1.1 静态分配表空间
# define Maxsize 10// 定义最大长度。#define是宏定义，在编译的时候遇到这个变量都直接替换，使其在定义域内全局有效。
typedef struct{
  ElemType data[Maxsize]; // 用静态的“数组”存放数据元素，一旦确定不可改变
  int length;//顺序表当前长度
}SqList;

1.1.1 数据表初始化
void InitList(SqList &L){
  for(int i=0; i<Maxsize; i++){
    L.data[i]=0; // 将所有数据元素设置为默认初始值0
  }
  L.length=0;
}
1.1.2 主函数
int main(){
  SqList L; // 声明一个顺序表
  InitList(L); //初始化顺序表
  // ...
  return 0;
  }
  
1.2 动态分配表空间
# include <stdlib.h> // malloc和free函数所依赖的库
# define Initsize 10 //顺序表的初始长度
typedef struct{
  Elemtype *data; // 指示动态分配数组的指针
  int Maxsize; //顺序表的最大容量
  int length; //顺序表当前长度
}SeqList; //顺序表的类型定义（动态分配方式）

1.2.1 初始化顺序表
void InitList(SeqList &L){
  // 用malloc函数申请一片连续的存储空间
  L.data=(Elemtype *)malloc(Initsize * sizeof(Elemtype)); //（Elemtype *）将malloc返回的指针（申请的一整片空间的起始地址）转换为与SeqList统一的数据类型Elemtype
  L.length=0;
  L.Maxsize=Initsize;
}

1.2.2 增加动态顺序表的长度
void IncreaseSize(SeqList &L, int len){
  int *p=L.data; // 把data的指针赋给p，让p指向data同一个指针
  L.data=(Elemtype *)malloc(L.Maxsize+len)*sizeof(Elemtype)); // 让data的指针指向新的内存空间的起始地址
  for(int i=0; i<L.length; i++){
    L.data[i]=p[i]; // 将数组复制到新区域
    }
    L.Maxsize=L.Maxsize+len; // 顺序表最大长度增加len
    free(p); //释放原来的（p所指向的data所指的那一片）内存空间；且由于p是局部变量，p本身也会在函数运行结束后被系统自动回收
}

1.2.3 主函数
int main(){
  SeqList L; // 声明一个顺序表
  InitList(L); // 初始化顺序表
  // ...往顺序表中任意插入几个元素，使得最终length和maxsize都为10
  IncreaseSize(L, 5);
  return 0;
}
~~~
# 2. 线性表插入
~~~
2.1 线性表插入_原始版
#define Maxsize 10
typedef struct{
  Elemtype data[Maxsize];
  int length;
}SqList;

2.1.1 初始化

2.1.2 插入
void ListInsert(SqList &L, int i, int e){
  for(j=L.length; j>=i; j--){
    L.data[j]=L.data[j-1];
  }
  L.data[i-1]=e; // 第i个位置，在数组里是第i-1个位置
  L.length++;
}

2.1.3 主函数
int main(){
  SqList L;
  InitList(L);
  L.data={12,34,45,324,23}; // 插入一些元素
  ListInsert(L, 3, "a");
  return 0;
}

2.2 线性表插入_健壮版
2.2.1 初始化
2.2.2 插入
bool ListInsert(SqList &L, int i, int e){
  if(i<1 || i>L.Length+1){ // 判断i的范围是否有效
    return false;
    }
  if(L.length>=Maxsize){ // 当存储空间已满的时候不能插入
    return false;
    }
  for(int j=L.length; j>=i; j--){ // 插入从表尾开始移动 
    L.data[j]=L.data[j-1];
    }
  L.data[i-1] = e;
  L.length++;
  return true;
}
2.2.3 主函数    
~~~
# 3. 线性表删除
~~~
#define Maxsize 10
typedef struct{
  Elemtype data[Maxsize];
  int length;
  }SqList;
3.1.1 初始化
3.1.2 删除_健壮版
bool ListDelete(&L, int i, int &e){
  if(i<1 || i>L.length){
    return false;
    }
  e=L.data[i-1];
  for(j=i; j<L.length; j++){ // 删除从i开始移动
    L.data[j-1]=L.data[j];
    }
  L.length--;
  return true
3.1.3 主函数
int main(){
  SqList L;
  InitList(L);
  // ...插入一些数据
  int e = -1; // 用变量额把删除的元素“带回来”
  if(ListDelete(L, 4, e)){
    printff("已删除第4个元素，删除元素值为%d\n", e);
    }
  else{
    printf("位序i不合法，请重试");
    }
  return 0;
  }
~~~

# 4. 线性表查找
~~~
4.1 按位查找_静态分配
Elemtype GetElem(SeqList L, int i){
  return L.data[i-1];
  }
4.2 按位查找_动态分配
#define Initsize 10 // 默认的最大长度
typedef struct{
  Elemtype *data; // 指示动态分配数组的指针
  int Maxsize; // 顺序表的最大容量
  int length; // 顺序表的当前长度
  }SeqList;
  
Elemtype GetElem(SeqList L, int i){
  return L.data[i-1]; // data虽然为指针类型，但是用数组下标访问依然合法，指向连续地址空间中对应元素开头的地址（如2000），并取到之后Elemtype大小的字节数（如init类型为4B）
  }
 
4.3 按值查找
#define Initsize 10
typedef struct{
  Elemtype *data;
  int Maxsize;
  int length;
  }SeqList;
  
// 在顺序表中查找第一个元素值为e的元素，并返回其位序
int LocateElem(SeqList L, Elemtype e){
  for(int i=0; i<L.length; i++){
    if(L.data[i]==e){
      return L.data[i+1];
      }
    }
    return 0;
}
~~~

# 5. 单链表初始化
~~~
5.1 定义单链表
struct LNode{ // 定义单链表节点类型
  Elemtype data; // 数据域。每个节点存放一个数据元素
  struct LNode *next; // 指针域。指针指向下一个节点
};
struct LNode *p = (struct LNode *)malloc(sizeof(struct LNode)); // 增加一个新的节点：在内存中声擎一个节点所需空间，并用指针p指向这个节点
typedef struct LNode LNode; // 将struct LNode重命名为LNode，简化书写
typedef struct LNode *Linklist; // 将struct LNode *重命名为LinkList
~~~
