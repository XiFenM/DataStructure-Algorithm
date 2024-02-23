#pragma once
#include <string>
class Student {
private:
	int stu_id;
	std::string stu_name;
public:
	Student(int id, std::string name);
	friend bool operator== (const Student&, const Student&);
};

