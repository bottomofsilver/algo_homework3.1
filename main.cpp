#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <functional> // 用于greater<int>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int k;
    fin >> k;
    vector<int> lengths(k);
    for (int i = 0; i < k; ++i) {
        fin >> lengths[i];
    }
    
    // 计算最少比较次数（使用最小堆）
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int len : lengths) {
        min_heap.push(len);
    }
    int min_comparisons = 0;
    while (min_heap.size() > 1) {
        int a = min_heap.top(); min_heap.pop();
        int b = min_heap.top(); min_heap.pop();
        int sum = a + b;
        min_comparisons += sum - 1;
        min_heap.push(sum);
    }
    
    // 计算最多比较次数（使用最大堆）
    priority_queue<int> max_heap;
    for (int len : lengths) {
        max_heap.push(len);
    }
    int max_comparisons = 0;
    while (max_heap.size() > 1) {
        int a = max_heap.top(); max_heap.pop();
        int b = max_heap.top(); max_heap.pop();
        int sum = a + b;
        max_comparisons += sum - 1;
        max_heap.push(sum);
    }
    
    fout << max_comparisons << " " << min_comparisons << endl;
    
    return 0;
}