#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int countOperations(const std::vector<int>& arr) {
    int n = arr.size();
    int cnt = 0;
    std::deque<int> stack;

    for (int num : arr) {
        while (!stack.empty() && stack.back() <= num) {
            stack.pop_back();
        }

        stack.push_back(num);
    }

    return stack.size() - 1;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int result = countOperations(arr);
    std::cout << result << std::endl;

    return 0;
}

