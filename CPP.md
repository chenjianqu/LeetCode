







## 输入输出

### 输入数组

如果给出以下数组：`23，12，34，56，33`，则：

```C++
vector<int> data;
int tmp;
while (cin >> tmp) {
	data.push_back(tmp);
	if (cin.get() == '\n') //读入一个字符，若为回车，则结束输入
		break;
}
```



如果给出矩阵：

```
12，23，34
23，45，56
34，45，76
```

则：

```C++
vector<vector<int>> arr;	
vector<int> a;
while (cin>>num) {
    a.push_back(num);
    if (cin.get() == '\n'){
       arr.push_back(a);
       a.clear();
  }
}
```



如果给出以下字符串数组：`dsfsd,sdsf,sdf,ftry,hyrdr`，则：

```C++
vector<string> data;
string tmp;
while (cin>>tmp) {
	data.push_back(tmp);
	if (cin.get() == '\n') 
		break;
}
```






## 数据的表示范围

```C++
#include <limits>

cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
cout << "\t最大值：" << (numeric_limits<bool>::max)();
cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;

cout << "char: \t\t" << "所占字节数：" << sizeof(char);
cout << "\t最大值：" << (numeric_limits<char>::max)();
cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;

cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
cout << "\t最大值：" << (numeric_limits<signed char>::max)();
cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;

cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;

cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;

cout << "short: \t\t" << "所占字节数：" << sizeof(short);
cout << "\t最大值：" << (numeric_limits<short>::max)();
cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;

cout << "int: \t\t" << "所占字节数：" << sizeof(int);
cout << "\t最大值：" << (numeric_limits<int>::max)();
cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;

cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;

cout << "long: \t\t" << "所占字节数：" << sizeof(long);
cout << "\t最大值：" << (numeric_limits<long>::max)();
cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;

cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;

cout << "double: \t" << "所占字节数：" << sizeof(double);
cout << "\t最大值：" << (numeric_limits<double>::max)();
cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;

cout << "long double: \t" << "所占字节数：" << sizeof(long double);
cout << "\t最大值：" << (numeric_limits<long double>::max)();
cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;

cout << "float: \t\t" << "所占字节数：" << sizeof(float);
cout << "\t最大值：" << (numeric_limits<float>::max)();
cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;

cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
cout << "\t最大值：" << (numeric_limits<size_t>::max)();
cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
```









## 随机数

随机数引擎类：生成随机unsigned整数序列；

随机数分布类：使用引擎返回服从特定概率分布的随机数。

**例子1：生成一个指定范围内的随机整数**

```C++
uniform_int_distribution<unsigned> u(0,9);//0到9范围内的均匀随机数
default_random_engine e;//生成无符号随机数
//default_random_engine e(23234);//使用给定种子
//default_random_engine e(time(0));//设置随机种子为时间
for(int i=0;i<10;++i){
    cout<<u(e)<<endl;
}
```



**例子2：生成一个指定范围内的随机浮点数**

```C++
uniform_real_distribution<double> u(0,1);//0-1的随机数
default_random_engine e;
for(int i=0;i<10;++i){
    cout<<u(e)<<endl;
}
```





## 数据结构

### 最大堆和最小堆

**红黑树**：

```C++
//定义最大堆
std::multiset<int, std::greater<int>> windows;//最大堆
//添加元素
windows.insert(nums[i]);
//删除一个元素
windows.erase(windows.find(nums[left]));
//删除多个元素
windows.erase(nums[left]);
//获取最大值
*windows.begin();
```



**优先队列**：

```C++
//定义大顶堆
std::priority_queue<int,vector<int>,std::less<int>> less_media;
//定义小顶堆
std::priority_queue<int,vector<int>,std::greater<int>> greater_median;

//插入数据
less_media.push(num);

//删除数据
less_media.pop();

//获得堆顶的值
less_media.top();
```







