#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int main() {
    const int N = 1'000'000;
    const int M = 100'000;

    vector<int> keys;
    for (int i = 0; i < N; ++i) {
        keys.push_back(i);
    }

    // Shuffle for random lookup keys
    random_device rd;
    mt19937 g(rd());
    shuffle(keys.begin(), keys.end(), g);

    // ---- MAP ----
    map<int, int> m;
    auto start_map_insert = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        m[i] = i;
    }
    auto end_map_insert = high_resolution_clock::now();

    auto start_map_find = high_resolution_clock::now();
    for (int i = 0; i < M; ++i) {
        volatile int x = m[keys[i]]; // volatile để tránh tối ưu hóa compiler
    }
    auto end_map_find = high_resolution_clock::now();

    // ---- UNORDERED_MAP ----
    unordered_map<int, int> um;
    auto start_um_insert = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        um[i] = i;
    }
    auto end_um_insert = high_resolution_clock::now();

    auto start_um_find = high_resolution_clock::now();
    for (int i = 0; i < M; ++i) {
        volatile int x = um[keys[i]];
    }
    auto end_um_find = high_resolution_clock::now();

    // ---- Output results ----
    cout << "\n--- Performance Benchmark ---\n";

    auto t_map_insert = duration_cast<milliseconds>(end_map_insert - start_map_insert).count();
    auto t_map_find = duration_cast<milliseconds>(end_map_find - start_map_find).count();
    auto t_um_insert = duration_cast<milliseconds>(end_um_insert - start_um_insert).count();
    auto t_um_find = duration_cast<milliseconds>(end_um_find - start_um_find).count();

    cout << "std::map insert time      : " << t_map_insert << " ms\n";
    cout << "std::map find time        : " << t_map_find << " ms\n";
    cout << "std::unordered_map insert : " << t_um_insert << " ms\n";
    cout << "std::unordered_map find   : " << t_um_find << " ms\n";

    cout << "\n--- Summary ---\n";
    cout << "std::map is generally slower than std::unordered_map for both insert and find operations.\n";
    cout << "std::unordered_map is optimized for fast access and insertion, making it more suitable for large datasets.\n";
    cout << "Note: Performance may vary based on system architecture and compiler optimizations.\n";
    cout << "For large datasets, std::unordered_map is preferred for performance.\n";
    cout << "For ordered data or when you need to maintain order, std::map is the better choice.\n";
    cout << "For applications requiring frequent insertions and deletions, std::unordered_map is more efficient.\n";        

    return 0;
}
