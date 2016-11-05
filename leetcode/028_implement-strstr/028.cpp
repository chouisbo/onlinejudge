#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    	if (haystack.length() < needle.length()) { return -1; }
        if (needle.length() < 0) { return -1; }
        if (needle.length() == 0) { return 0; }

    	int i, j;
    	for (i=0, j=0; i<haystack.length() && j<needle.length();) {
    		if (haystack[i] == needle[j]) {
    			i++; j++;
    		} else {
    			i = i-j+1;
    			j = 0;
    		}
    	}

    	if (j == needle.length()) {
    		return i-j;
    	} else {
    		return -1;
    	}
        
    }

    // KMP String Searching Implementation
    
    // next [j] = k，代表 j 之前的字符串中有最大长度为 k 的相同前缀后缀。
    // 如果对于值 k，已有 p0 p1, ..., pk-1 = pj-k pj-k+1, ..., pj-1，相当于 next[j] = k。 
    // 此意味着什么呢？究其本质，next[j] = k 代表 p[j] 之前的模式串子串中，有长度为 k 的相同前缀和后缀。
    // 
    // 2.下面的问题是：已知 next [0, ..., j]，如何求出 next [j + 1] 呢？
    // 
    // 若p[k] == p[j]，则 next[j + 1 ] = next [j] + 1 = k + 1；
    // 若p[k ] ≠ p[j]，如果此时 p[ next[k] ] == p[j ]，则 next[ j + 1 ] = next[k] + 1，
    // 否则继续递归前缀索引 k = next[k]，而后重复此过程。 
    // 相当于在字符 p[j+1] 之前不存在长度为 k+1 的前缀"p0 p1, …, pk-1 pk"跟后缀“pj-k pj-k+1, …, pj-1 pj"相等，
    // 那么是否可能存在另一个值 t+1 < k+1，使得长度更小的前缀 “p0 p1, …, pt-1 pt” 等于长度更小的后缀 
    // “pj-t pj-t+1, …, pj-1 pj” 呢？如果存在，那么这个 t+1 便是 next[ j+1] 的值，
    // 此相当于利用已经求得的 next 数组（next [0, ..., k, ..., j]）进行 P 串前缀跟 P 串后缀的匹配。
    
    // Assumption needle.length() >= 1
    static vector<int> genNext(const string &needle) {
        vector<int> next(needle.length(), 0);
        int k = -1;
        int j = 0;
        next[0] = -1;
        while (j < needle.length()-1) {
            if (-1 == k || needle[j] == needle[k]) {
                k++;
                j++;
                if (needle[j] != needle[k]) {
                    next[j] = k;
                } else {
                    // 因为不能出现p[j] = p[next[j]]，所以当出现时需要继续递归，k = next[k] = next[next[k]] ...
                    next[j] = next[k];
                }
            } else {
                k = next[k];
            }
        }
        return next;
    }
    
    int kmpStrStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) { return -1; }
        if (needle.length() < 0) { return -1; }
        if (needle.length() == 0) { return 0; }

        vector<int> next = genNext(needle);

        int i, j;
        for (i=0, j=0; i<haystack.length() && j<(int)needle.length();) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++; j++;
            } else {
                j = next[j];
            }
        }

        if (j == needle.length()) {
            return i-j;
        } else {
            return -1;
        }
    }

};


int main(int argc, char const *argv[])
{
    for (auto &i : Solution::genNext("ABCDABCE")) { cout << i << ", "; }; cout << endl;
    for (auto &i : Solution::genNext("ABCDABDE")) { cout << i << ", "; }; cout << endl;

    string haystack("Hello, World!");
    string needle("World");

    Solution s;

    cout << "find " << needle << " in " << haystack << " @ " << s.strStr(haystack, needle) << endl;
    cout << "find " << needle << " in " << haystack << " @ " << s.kmpStrStr(haystack, needle) << endl;
    cout << "find " << needle << " in " << haystack << " @ " << s.kmpStrStr("", "") << endl;

	return 0;
}