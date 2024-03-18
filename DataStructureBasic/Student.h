#pragma once
#include<string>
#include<iostream>
class Student{
    private:
        int number;
        std::string name;
    public:
        Student(int id=-1, std::string name_input="Test")
            :number(id),name(name_input){}
        friend bool operator== (const Student& s1,const Student& s2);
        friend bool operator!= (const Student& s1,const Student& s2);
        friend bool operator< (const Student& s1,const Student& s2);
        friend bool operator<= (const Student& s1,const Student& s2);
        friend bool operator> (const Student& s1,const Student& s2);
        friend bool operator>= (const Student& s1,const Student& s2);
        friend std::ostream& operator << (std::ostream& os,const Student& s);
};