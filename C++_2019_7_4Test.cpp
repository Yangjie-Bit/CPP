1.计算糖果
> 真正的救赎并不是厮杀后的胜利, 而是能在苦难中找到生的力量和心的安宁.

**题目描述**
计算糖果 | 时间限制：1秒 | 内存限制：32768K
A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上
具体有多少个糖果, 但是我们知道 以下的信息： A - B, B - C, A + B, B + C.
这四个数值.每个字母代表每个人所拥有的糖果数.现在需要通过这四个数值计算出
每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足
所有题设条件。

**输入描述**
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 
范围均在 - 30到30之间(闭区间)。

**输出描述**
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末
无空格。 如果不存在 这样的整数A，B，C，则输出No 示例1 : 输入 1 - 2 3 4 
输出 2 1 3

**题目解析**
A, B, C是三个人手里的糖果数量，我们不知道A, B, C是多少？但是我们知道A - B,
B - C, A + B, B + C的结果，这个结果题目是通过输入测试用例给我们的。所以
本题本质是一个表达式求解问题。

**解题思路**
1、A - B = a 2、B - C = b 3、A + B = c 4、B + C = d 这道题目的实质是：
判断三元一次方程组是否有解及求 解，1 + 3可以得到A = (a + c) / 2；
4 - 2可以得到C = (d - b) / 2;2 + 4可以得到B2 = (b + d) / 2，3 - 1可以
得到B1 = (c - a) / 2；
如果B1不等B2则表达式无解.

#include<iostream> 
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;
	if (B1 != B2){
		cout << "No";
	}
	else{
		cout << A << " " << B1 << " " << C;
	}
	return 0;
}


2.进制转换
**题目描述**
进制转换 | 时间限制：1秒 | 内存限制：32768K
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

**输入描述**
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。

**输出描述**
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字
规则参考16进制（比如，10 用A表示，等等）

**示例1: 输入 7 2 输出 111 * *

**题目解析**
本题题目很简单，题目的本意就是将10进制的数转换成N进制。N(2 ≤ N ≤ 16)
可以看出进制最多可以到16进制。

**解题思路**
本题思路很简单，首先想清楚原理：N进制数，每个进制位的值分别是X0* N ^ 0，
X1* N ^ 1, X2* N^2.....，X0， X1，X2就是这些进制位的值，就是就是进行取模
余数就是当前低进制的位的值是多少，通过除掉进制数，进入下一个进制位的计算。

#include <iostream>
using namespace std;
int main(){
	string s = "", table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	while (m){
		if (m<0){
			m = -m;
			cout << "-";
		}
		s = table[m%n] + s;
		m /= n;
	}
	cout << s << endl;
	return 0;
}
