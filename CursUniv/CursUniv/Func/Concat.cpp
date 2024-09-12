#include "../MyArrs.hpp"

void MyArrs::Concat()
{
	this->flag = 1;
	char a;
	char b;

	if(this->args > 3 || this->args < 3)
	{
		std::cerr << "\nWrong number of arguments -> (Concat A, b)\n"<< std::endl;
		return;
	}
	if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Concat A, b)\n"<< std::endl;
		return;
	}
	if(this->arg2.length() != 1 || !std::isalpha(this->arg2[0]))
	{
		std::cerr << "\nWrong arguments -> (Concat a, B)\n"<< std::endl;
		return;
	}

	a = ft_toupper(arg1[0]);
	b = ft_toupper(arg2[0]);
	if(arr[a].empty())
	{
		std::cerr << "ARR "<< a << " is empty"<< std::endl;
		if(arr[b].empty())
		{
			std::cerr << "ARR "<< b << " is empty"<< std::endl;
			return;
		}
		return;
	}

	arr[a].insert(arr[a].end(), arr[b].begin(), arr[b].end());
}