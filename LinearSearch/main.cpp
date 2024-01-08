#include <iostream>
#include <vector>

class Student {
private:
	int stu_id;
	std::string stu_name;
public:
	Student(int id, std::string name)
		:stu_id(id), stu_name(name)
	{};
	friend bool operator== (const Student &, const Student&);
};
bool operator== (const Student& stu_a, const Student& stu_b) {
	if ((stu_a.stu_id == stu_b.stu_id) &&
		(stu_a.stu_name == stu_b.stu_name)) {
		return true;
	}
	return false;
}

class LinearSearch {
private:
	LinearSearch() {};
public:
	template <typename T = int>
	static int search(const std::vector<T> array,const T target) {
		for (int i = 0; i < array.size(); i++) {
			if (array[i] == target) {
				return i;
			}
		}
		return -1;
	}
};


int main() {
	std::vector<int> num_array{ 0,2,3,45,100,6,7,8,1,10 };
	std::vector<char> char_array{ '0','2','3','a','b','c','d','e','o','t'};
	std::vector<Student> student_array{ {0,"Jane"},
		{1,"May"},{2,"August"},{3,"Alice"},{4,"Peter"} };
	std::cout << "查找到的位置索引为"
		<< LinearSearch::search<int>(num_array,235453)
		<< std::endl;
	std::cout << "查找到的位置索引为"
		<< LinearSearch::search<char>(char_array, 'a')
		<< std::endl;
	Student target = Student(3, "Alice");
	std::cout << "查找到的位置索引为"
		<< LinearSearch::search<Student>(student_array, target)
		<< std::endl;
	return 0;
}