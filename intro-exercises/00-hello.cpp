#include <iostream>
#include <unordered_map>
#include <deque>
#include <list>
#include <vector>

int main() {
    std::deque<int> d;
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[]= {1, 2, 3, 4, 5};
    d.push_back(10);
    d.push_front(20);
    std::cout << "first" << d.front() << std::endl;
    std::cout << "last" << d.back() << std::endl;

    for (int elem : d) {
        std::cout << elem << std::endl;
    }
}

int max_min_charm(std::vector<int> nums1, std::vector<int> nums2) {
    return 0;
}