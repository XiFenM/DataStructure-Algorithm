#include<string>
class Student{
    private:
        int number;
        std::string name;
    public:
        Student(int id, std::string name_input)
            :number(id),name(name_input){}
        friend bool operator== (const Student& s1,const Student& s2);
        friend bool operator!= (const Student& s1,const Student& s2);
        friend bool operator< (const Student& s1,const Student& s2);
        friend bool operator<= (const Student& s1,const Student& s2);
        friend bool operator> (const Student& s1,const Student& s2);
        friend bool operator>= (const Student& s1,const Student& s2);
};