#pragma once
#include <vector>
class Sort
{
private:
    Sort()=default;
public:
    template<typename T>
    // requires std::totally_ordered<T> // C++ 20
    static std::vector<T> SelectSort(std::vector<T> unordered_array,bool descending = false) {
        int len = unordered_array.size();
        if (len < 2) return unordered_array;

        std::vector<T> ordered_array(unordered_array);
        for(int i = 0 ;i<len;i++){
            // auto tmp_index=unordered_array.begin();
            typename::std::vector<T>::iterator tmp_index=unordered_array.begin();
            for(typename::std::vector<T>::iterator j = unordered_array.begin() ;j!=unordered_array.end() ;j++ ){
                if(descending){
                    if( (*j)>(*tmp_index) ) tmp_index = j;
                }
                else{
                    if( (*j)<(*tmp_index) ) tmp_index = j;
                } 
            }
            ordered_array[i] = *tmp_index;
            unordered_array.erase(tmp_index);
        }
        return ordered_array;
    }

    template<typename T>
    // requires std::totally_ordered<T> // C++ 20
    static void InplaceSelectSort(std::vector<T>& unordered_array, bool descending = false) {
        int len = unordered_array.size();
        if (len < 2) return;
        for (int i = 0,t_index=0; i < len; t_index = ++i) {
            for (int j = i; j < len; j++) {
                if (descending) {
                    if (unordered_array[j] > unordered_array[t_index]) {
                        t_index=j;
                    }
                }
                else {
                    if (unordered_array[j] < unordered_array[t_index]) {
                        t_index=j;
                    }
                }
            }
            std::swap(unordered_array[i],unordered_array[t_index]);
        }
    }

    template<typename T>
    // requires std::totally_ordered<T> // C++ 20
    static void InplaceSelectSort2(std::vector<T>& unordered_array, bool descending = false){
        int len = unordered_array.size();
        if(len < 2) return ;
        
        for(int i{len - 1},tmp_index{len - 1}; i >= 0; tmp_index=--i){
            //循环不变量：保持数组[i,len-1)有序且在整个数组中排到了应有的位置
            for(int j = i ; j >= 0; j --){
                if(descending){
                    if(unordered_array[j]<unordered_array[tmp_index]){
                        tmp_index = j;
                    }
                }
                else{
                    if(unordered_array[j]>unordered_array[tmp_index]){
                        tmp_index = j;
                    }
                }
            }
            std::swap(unordered_array[i],unordered_array[tmp_index]);
        }
    }


    template<typename T>
    // requires std::totally_ordered<T> // C++ 20
    static void InsertSelectSort(std::vector<T>& unordered_array, bool descending = false){
        int len = unordered_array.size();
        T tmp;
        if(len < 2) return;
        for(int i = 0; i < len;i++){
            tmp = unordered_array[i];
            int j = i;
            if(descending){
                for(; j > 0 && unordered_array[j - 1] < tmp ; j --){
                   unordered_array[j-1] = unordered_array[j];
                }
            }
            else{
                for(; j > 0 && unordered_array[j - 1] > tmp ; j --){
                   unordered_array[j-1] = unordered_array[j];
                }
            }
            unordered_array[j] = tmp;
        }
    }
};

