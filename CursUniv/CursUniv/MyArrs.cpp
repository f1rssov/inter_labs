#include "MyArrs.hpp"

MyArrs::MyArrs()
{
}

MyArrs::~MyArrs()
{	
}


void MyArrs::algorithm(std::string fun, std::string ar1, std::string ar2, std::string ar3, std::string ar4, int ars)
{
    std::string names[14] = {"Load", "Save", "Rand", "Concat", "Free", "Remove", "Copy", "Sort", "Permute", "Intersect", "Xor", "Stat", "Print", "EXIT"};
	ArrsPtr ptr[14] = {&MyArrs::Load, &MyArrs::Save, &MyArrs::Rand, &MyArrs::Concat, &MyArrs::Free, &MyArrs::Remove, &MyArrs::Copy, &MyArrs::Sort, &MyArrs::Permute, &MyArrs::Intersect, &MyArrs::Xor, &MyArrs::Stat, &MyArrs::Print, &MyArrs::Exit};

	this->func = fun;
	this->arg1 = ar1;
	this->arg2 = ar2;
	this->arg3 = ar3;
	this->arg4 = ar4;
	this->args = ars;


	this->flag = 0;
	for(int i = 0; i<14; i++)
	{
		if(!names[i].compare(func))
			(this->*ptr[i])();
	}
	if(this->flag == 0)
		std::cerr<<"\nNo such function\n" <<std::endl;
}
