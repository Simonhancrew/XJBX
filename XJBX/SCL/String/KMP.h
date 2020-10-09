#pragma once
#include <string>
#include <vector>
using namespace std;
class Kmp {
public:
	int getIndexOf(const string &s,const string &m) {
		if (s.empty() || m.empty() || s.size() < m.size()) {
			return -1;
		}
		int si = 0;
		int mi = 0;
		vector<int> next = getNextArray(m);
		while(si<s.length()&&mi<m.length()){
			//str1的和str2配上了
			if (s[si] == m[mi]) {
				si++;
				mi++;
			}
			//str2来到了0位置，不能再往前跳了。说明0位置都配不上
			else if (next[mi] == -1) {
				//不好意思，str1往前走吧
				si++;
			}
			//str2有得往前跳，继续往前走
			else {
				mi = next[mi];
			}
		}
		//str2被撸完了，那就配出来了
		return mi == m.length() ? si - mi: -1;
	}
	//next数组的实质就是pmt
	//对pattern串求next数组，实质就是匹配过的部分会有公共前（后）缀部分，可以利用这个信息进行加速，
	//下一次匹配就可以从next[i]位置开始了（可以看作把patter子串往前推）
	//next[0]前面没有子串，next[1]前面就一个char，子缀不能包含全部的字符串，所以这两个人为规定为-1和0
	vector<int> getNextArray(const string& m) { 
		vector<int> next;
		if (m.size() == 1) {
			next.push_back(-1);
		}
		next.resize(m.size());
		next[0] = -1;
		next[1] = 0;
		//pos是来到的位置，cn是往前跳到的位置（就是最长前缀的位置）
		int pos = 2, cn = 0;
		//假设i位置之前所有得next数组得值都得到了，那我们看str2中next[i-1]的位置是否等于str2[i-1],等的话next[i] = next[i-1]+1
		//假如不等可以继续从str2中next[i-1]的位置往前跳
		while (pos < next.size()) {
			//当前位置之前一位位置的值和跳到的位置一样
			if (m[pos - 1] == m[cn]) {//next数组的索引比原pattern字符串少一    ------X
				//公共前缀长度就是cn++
				next[pos++] = ++cn;
			}
			//假如前一步不相等的话，如果还能往前跳，跳到next数组的值的位置
			//即使cn位置之前的最长公共前后缀的位置
			else if (cn > 0) {
				cn = next[cn];
			}
			//跳不动了
			else
			{
				next[pos++] = 0;
			}
		}
		return next;
	}
};