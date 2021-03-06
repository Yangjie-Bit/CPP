> 上天很有意思, 猫喜欢吃鱼, 猫却不能下水;
> 鱼喜欢吃蚯蚓, 鱼却不能上岸.
> 人生, 就是一边拥有, 一边失去, 一边选择, 一边放弃.
> 人生, 哪有事事如意, 生活, 哪有样样顺心.
> 所以, 不和别人较真, 因为不值得;
> 不和自己较真, 因为伤不起, 不和往事较真, 因为回不去!--<卡农>
>
###### 题目要求 
| 时间限制：1秒 | 内存限制：32768K

###### 题目描述 
牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增
或者非递减排序的。牛牛有一 个长度为n的整数数组A, 他现在有一个任务是把
数组A分为若干段排序子序列, 牛牛想知道他最少可以把这个数 组分为几段排序
子序列.

如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 
至少需要划分为2个排序子序列, 所以输出 2 输入描述： 输入的第一行为一个
正整数n(1 ≤ n ≤ 10 ^ 5)第二行包括n个整数A_i(1 ≤ A_i ≤ 10 ^ 9), 
表示数组A的每个数字。

输出描述： 输出一个整数表示牛牛可以将A最少划分为多少段排序子序列 示例1 :
输入 6 1 2 3 2 2 1 输出 2

###### 题目解析
本题要求解的是排序子序列，排序子序列为非递增或者非递减，很多同学在这个
非递增、非递减问题上很纠 结，注意：非递减就是a[i] <= a[i + 1]，递减就是
a[i]>a[i + 1]，非递增就是a[i] >= a[i + 1]，递增就是a[i]<a[i + 1]。

###### 解题思路
1.本题依次比较整个数组
2. a[i + 1]>a[i] ，则进入非递增序列判断，直到遍历到下一个值不大于等于为止count++，然后进行下一位 置的判断
3. a[i + 1]<a[i]，则进入非递增序列判断，直到遍历到下一个值不小于等于为止count++，然后进行下一位 置的判断
4. a[i + 1] == a[i]不进行操作，++i进行下一位置遍历，因为相等既可以属于非递增序列，也可以属于非递减 序列。

###### 【本题注意点】
本题开始比较a[i + 1]与a[i]进行比较，为了避免越界，数组定义为n + 1个，同时给a[n] = 0; a[n] = 0带来的影响
###### 【分三种情况讨论】

1.若到a[n - 1] 的最后一组是非递减序列，当i == n - 1，a[i] >a[i + 1]，因为
前面的数都是大于0的，这个输入 条件已经说明了(去看看题目输入条件描述)，里面
的循环结束，i++，count++，i == n，外面的循环结 束。

2.若到a[n - 1] 的最后一组是非递增序列，当i == n - 1，a[i] >a[i + 1]，因为
前面的数都是大于0的，这个输入 条件已经说明了(去看看题目输入条件描述)，循环
再走一次，i++， i == n，里面的循环结束，i++， count++，i == n + 1，外面的
循环结束。

3.第三种情况  1 2 1 2 1最后一个数是单独的情况，后面补个0，序列变成
1 2 1 2 1 0，当走完全面的序列 i == n - 1时，a[i] > a[i + 1], 进入判断
出一个非递增序列，count++，i++, 循环结束。 4. 也就是说数组最后一个位置
多增加一个0，不会影响第1、2情况的判断，主要是帮助第3情况的正确判断。

###### 【程序代码】

#include<iostream>
#include<vector> 
using namespace std;

// 本题牛客测试用例不全，至少应该增加以下两组测试用例
// 输入： 
// 4
// 1 3 2 3 
// 输出：2

// 输入： 
// 6 
// 3 2 1 1 2 3 
// 输出：2

int main() {
	int n;
	cin >> n;
	// 注意这里多给了一个值，是处理越界的情况的比较，具体参考上面的解题思路   
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;

	//读入数组    
	int i = 0;
	for (i = 0; i < n; ++i){
		cin >> a[i];
	}
	i = 0;
	int count = 0;
	while (i < n){
		// 非递减子序列        
		if (a[i] < a[i + 1]){
			while (i < n && a[i] <= a[i + 1]){
				i++;
			}
			count++;
			i++;
		}
		else if (a[i] == a[i + 1]){
			i++;
		}
		else {
			// 非递增子序列       
			while (i < n && a[i] >= a[i + 1]){
				i++;
			}
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}


###### 题目要求
时间限制1秒 | 内存限制：32768K

###### 题目描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：
beijing.like I

###### 输入描述
每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100 输出
描述： 依次输出倒置之后的字符串, 以空格分割 示例1 : 输入 I like beijing.
输出 beijing.like I

###### 题目解析
本题题意很简单，就是将一段字符串中的前后单词交换，以单词为单位逆置。

###### 解题思路 
先将整个字符串逆置过来，再遍历字符串，找出每个单词，对单词逆置。这里我们
使用了stl算法中的 reverse，所以这里使用迭代器遍历string

###### 程序代码
###### 解法一

#include <iostream>
#include <string> 
#include <algorithm> using namespace std;

int main(){
	string s;
	// 注意这里要使用getline，cin>>s遇到空格就接收结束了    
	getline(cin, s);
	// 翻转整个句子    
	reverse(s.begin(), s.end());
	// 翻转单词    
	auto start = s.begin();
	while (start != s.end()){
		auto end = start;
		while (end != s.end() && *end != ' '){
			end++;
		}
		reverse(start, end);
		if (end != s.end()){
			start = end + 1;
		}
		else{
			start = end;
		}
	}
	cout << s << endl;
	return 0;
}


###### 解法二
###### 解题思路 
直接利用cin >> s接收输入，遇到空格就结束了，自然就分割开了每个单 词，其次
将每次接收到的单词拼接到之前串的前面就逆置过来了

#include <iostream> 
#include <string> 
using namespace std;
// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出 
int main() {
	string s1, s2;
	cin >> s2;
	while (cin >> s1){
		s2 = s1 + " " + s2;
	}
	cout << s2 << endl;
	return 0;
}

1.字符串中找出连续最长的数字串
**题目描述**
字符串中找出连续最长的数字串 | 时间限制：1秒 | 内存限制：32768K
读入一个字符串str，输出字符串str中的连续最长的数字串 .

**输入描述**
测试输入包含1个测试用例，一个字符串str，长度不超过255。 

**输出描述**
在一行内输出str中里连续最长的数字串。

示例1 : 输入 abcd12345ed125ss123456789
		输出 123456789

**解题思路**
遍历字符串，使用cur去记录连续的数字串，如果遇到不是数字字符，则表示一个
连续的数字串结束了，则将 数字串跟之前的数字串比较，如果更长，则更新更长
的数字串更新到res.

**程序代码**

#include<iostream>
#include<string> 
	  using namespace std;
int main(){
	string str, res, cur;
	cin >> str;
	for (int i = 0; i <= str.length(); i++){
		// 数字+=到cur        
		if (str[i] >= '0' && str[i] <= '9'){
			cur += str[i];
		}
		else{
			// 找出更长的字符串，则更新字符串            
			if (res.size() < cur.size()){
				res = cur;
			}
			else{
				cur.clear();
			}
		}
	}
	cout << res;
	return 0;
}

2.数组中出现次数超过一半的数字
**题目描述**
数组中出现次数超过一半的数字 | 时间限制：1秒 | 内存限制：32768K | 
语言限制：[Javascript_V8, Python, C++, Javascript, Php, C#, Java]
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入
一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。由于数字2在数组中出现
了5次，超过数组长度的一半，因此输出2。如果不存在则输出 0。

**题目解析**
本题题意很简单，需要找出超过一半的那个数字。

**解题思路**

**思路一**
数组排序后，如果符合条件的数存在，则一定是数组中间那个数。这种方法虽然
容易理解，但由于 涉及到快排sort，其时间复杂度为O(NlogN)并非最优；

**解法一**

class Solution{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers){
		// 因为用到了sort，时间复杂度O(NlogN)，并非最优        
		if (numbers.empty()){
			return 0;
		}
		sort(numbers.begin(), numbers.end());
		// 排序，取数组中间那个数        
		int middle = numbers[numbers.size() / 2];
		int count = 0;
		// 出现次数        
		for (int i = 0; i<numbers.size(); ++i){
			if (numbers[i] == middle){
				++count;
			}
		}
		return (count>numbers.size() / 2) ? middle : 0;
	}
};

**解题思路2**
如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
在遍历数组时保存两个值： 一是数组中一个数字，一是次数。遍历下一个数
字时，若它与之前保存的数字相同，则次数加1，否则次数减 1；若次数为0，
则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。
然后再判断它 是否符合条件即可.

**解法二**

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers){
		if (numbers.empty()){
			return 0;
		}
		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1         
		int result = numbers[0];
		int times = 1; // 次数                 
		for (int i = 1; i<numbers.size(); ++i){
			if (times == 0){
				// 更新result的值为当前元素，并置次数为1                
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result){
				// 相同则加1
				++times;
			}
			else
			{
				// 不同则减1
				--times;
			}
		}
		// 判断result是否符合条件，即出现次数大于数组长度的一半        
		times = 0;
		for (int i = 0; i<numbers.size(); ++i){
			if (numbers[i] == result){
				++times;
			}
		}
		return (times > numbers.size() / 2) ? result : 0;
	}
};
