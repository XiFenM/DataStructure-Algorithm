#include"Student.h"

bool operator== (const Student& s1,const Student& s2){
    return (s1.number==s2.number) && (s1.name == s2.name);
}
bool operator!= (const Student& s1,const Student& s2){
    return (s1.number!=s2.number) || (s1.name != s2.name);
}
bool operator< (const Student& s1,const Student& s2){
    return (s1.number < s2.number) || 
            ((s1.number == s2.number)&&(s1.name < s2.name));
}
bool operator<= (const Student& s1,const Student& s2){
    return (s1.number < s2.number) || 
            ((s1.number == s2.number)&&(s1.name <= s2.name));
}
bool operator> (const Student& s1,const Student& s2){
    return (s1.number > s2.number) || 
            ((s1.number == s2.number)&&(s1.name > s2.name));
}
bool operator>= (const Student& s1,const Student& s2){
    return (s1.number > s2.number) || 
            ((s1.number == s2.number)&&(s1.name >= s2.name));
}