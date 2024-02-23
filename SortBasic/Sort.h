#pragma once
#include <vector>
class Sort
{
private:
	Sort();
public:
	template<typename T>
	static std::vector<T> SelectSort(const std::vector<T>& unordered_array,bool descending = false) {
		std::vector<T> res;
		int tmp_index{ 0 }, last_index{ 0 };
		int length = unordered_array.size();
		if (descending) {
			for (int i = 0; i < unordered_array.size(); i++) {
				for (int j = 0; j < unordered_array.size(); j++) {
					if (i > 0) {
						if (unordered_array[j] >= unordered_array[tmp_index] &&
							unordered_array[j] <= unordered_array[last_index] &&
							j != last_index) {
							tmp_index = j;
						}
					}
					else {
						if (unordered_array[j] >= unordered_array[tmp_index]) {
							tmp_index = j;
						}
					}
				}
				res.push_back(unordered_array[tmp_index]);
				last_index = tmp_index;
			}
		}
		else {
			for (int i = 0; i < unordered_array.size(); i++) {
				tmp_index = 0;
				for (int j = 0; j < unordered_array.size(); j++) {
					if (i > 0) {
						if (unordered_array[j] <= unordered_array[tmp_index] &&
							unordered_array[j] >= unordered_array[last_index] &&
							j != last_index) {
							tmp_index = j;
						}
					}
					else {
						if (unordered_array[j] <= unordered_array[tmp_index]) {
							tmp_index = j;
						}
					}
				}
				res.push_back(unordered_array[tmp_index]);
				last_index = tmp_index;
			}
		}
		return res;
	}

	template<typename T>
	static void SelectSortInPlace(std::vector<T>&);
};

