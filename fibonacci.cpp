#include <iostream>
#include <vector>
using namespace std;

// 方法1: 递推法 - 时间复杂度O(n)，空间复杂度O(n)
vector<long long> fibonacciIterative(int n) {
    vector<long long> result;
    if (n <= 0) return result;
    
    if (n >= 1) result.push_back(0);
    if (n >= 2) result.push_back(1);
    
    for (int i = 2; i < n; i++) {
        result.push_back(result[i-1] + result[i-2]);
    }
    
    return result;
}

// 方法2: 递归法 - 时间复杂度O(2^n)，不推荐用于大的n
long long fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// 方法3: 动态规划 - 获取第n个斐波那契数
long long fibonacciDP(int n) {
    if (n <= 1) return n;
    
    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    
    return curr;
}

int main() {
    int n = 10;
    
    cout << "===== 斐波那契数列 =====" << endl;
    cout << "生成前 " << n << " 项：" << endl;
    
    // 使用方法1：递推法
    vector<long long> fib = fibonacciIterative(n);
    for (int i = 0; i < fib.size(); i++) {
        cout << fib[i];
        if (i < fib.size() - 1) cout << ", ";
    }
    cout << endl << endl;
    
    // 方法2：递归法 - 获取第n项
    cout << "第 " << n << " 项（递归法）：" << fibonacciRecursive(n) << endl;
    
    // 方法3：动态规划 - 获取第n项
    cout << "第 " << n << " 项（动态规划）：" << fibonacciDP(n) << endl;
    
    return 0;
}
