#include "Tools.h"
#include <cstdlib>
#include <ctime>

const std::vector<std::string> Tools::name_list = {
	"Azai","Basil","Che","Nile","Bogda","Taru","Ryatt","Lotem","Maple","Gera"
};

void Tools::getOrderedArray(std::vector<int>& array, int num,bool descending) {
	array.clear();
	for (int i = 0; i < num; i++) {
		if(descending) array.push_back(num - i); 
		else array.push_back(i);
	}
}
void Tools::getRandArray(std::vector<int>& array, int num ,int upperbound) {
	array.clear();
	srand(time(0));  // set random seed
	for (int i = 0; i < num; i++) {
		array.push_back(rand() % upperbound);
	}
}
void Tools::getRandStudents(std::vector<Student>& array,int num,int upperbound){
	array.clear();
	srand(time(0));  // set random seed
	for(int i = 0 ; i< num;i++){
		array.push_back(
			Student( rand() % upperbound ,name_list[ rand()%10 ])
		);
	}
}
