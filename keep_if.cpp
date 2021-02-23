#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fplus/fplus.hpp>

std::vector<int> xs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::vector<char> ab = {'a', 'd', 'f', 'g', 'e', 'b', 'i', 'c'};

bool is_even(int x){
    return x % 2 == 0;
}

bool is_some_of_az(char x){
    return (x == 'a' || x == 'b' || x == 'c') ? true : false;
}

template <typename F, typename T>
std::vector<T> keep_if(F f, const std::vector<T>& xs) {
    std::vector<T> runner;
    for (int i = 0; i < xs.size(); i++){
        if (f(xs[i])){
            runner.push_back(xs[i]);
        }
    }
    return runner;
}

int main() {
    const auto ys = keep_if(is_even, xs);
    for (auto i = ys.begin(); i != ys.end(); ++i)
    std::cout << *i << ' ';
    std::cout << std::endl;
    const auto bc = keep_if(is_some_of_az, ab);
    for (auto i = bc.begin(); i != bc.end(); ++i)
    std::cout << *i << ' ';
    std::cout << std::endl;
}

// https://www.udemy.com/course/functional-programming-using-cpp/
