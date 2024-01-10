#include "LinearSearch.h"

Student::Student(int id, std::string name)
	:stu_id(id), stu_name(name)
{}

bool operator== (const Student& stu_a, const Student& stu_b) {
	if ((stu_a.stu_id == stu_b.stu_id) &&
		(stu_a.stu_name == stu_b.stu_name)) {
		return true;
	}
	return false;
}
