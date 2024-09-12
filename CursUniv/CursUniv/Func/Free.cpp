#include "../MyArrs.hpp"

void MyArrs::Free()
{
	this->flag = 1;
	char a;

	if(this->args > 2 || this->args < 2)
	{
		std::cerr << "\nWrong number of arguments -> (Free(a))\n"<< std::endl;
		return;
	}
	if(this->arg1.length() != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Free(a))\n"<< std::endl;
		return;
	}
	a = ft_toupper(arg1[0]);
	if(arr[a].empty())
	{
		std::cerr << "ARR "<< a << " is already empty"<< std::endl;
		return;
	}
	arr[a].clear();
}