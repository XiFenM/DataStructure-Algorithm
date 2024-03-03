#pragma once
#include <vector>
class Sort
{
private:
    Sort();
public:
    template<typename T>
    static std::vector<T> SelectSort(const std::vector<T>& unordered_array,bool descending = false) {
        std::vector<T> ordered_array(unordered_array);
        InplaceSelectSort(ordered_array, descending);
        return ordered_array;
    }

    template<typename T>
    static void InplaceSelectSort(std::vector<T>& unordered_array, bool descending = false) {
        int len = unordered_array.size(), tmp{ 0 };
        if (len < 2)
            return;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (descending) {
                    if (unordered_array[j] > unordered_array[i]) {
                        tmp = unordered_array[i];
                        unordered_array[i] = unordered_array[j];
                        unordered_array[j] = tmp;
                    }
                }
                else {
                    if (unordered_array[j] < unordered_array[i]) {
                        tmp = unordered_array[i];
                        unordered_array[i] = unordered_array[j];
                        unordered_array[j] = tmp;
                    }
                }
            }
        }
    }
};

