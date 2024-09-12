#include "../MyArrs.hpp"

void MyArrs::Copy()
{
	this->flag = 1;
	int a, b, c, j;
	//// проверка аргументов на валидность
	if(this->args > 5 || this->args < 5)
	{
		std::cerr << "\nWrong number of arguments -> (Copy A, 4, 10, b)\n"<< std::endl;
		return;
	}
	if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Copy A, 4, 10, b)\n"<< std::endl;
		return;
	}
	if(this->arg4.length() != 1 || !std::isalpha(this->arg4[0]))
	{
		std::cerr << "\nWrong arguments -> (Copy a, 4, 10, B)\n"<< std::endl;
		return;
	}
	if(std::stoi(arg2) == 0 || std::stoi(arg3) == 0)
	{
		std::cerr << "\nWrong arguments -> (Copy A, 4, 10, b)\n"<< std::endl;
		return;
	}
	try
	{
		a = std::stoi(arg2)-1;
		b = std::stoi(arg3);
	}
	catch(std::exception &e)
	{
		std::cerr << "\nWrong arguments -> (Copy A, 4, 10, b)\n"<< std::endl;
		return;
	}
	//////

	c = ft_toupper(arg1[0]);
	j = ft_toupper(arg4[0]);

	if(arr[c].empty())
	{
		std::cerr << "ARR "<< a << " is empty"<< std::endl;
		return;
	}
	if(!arr[j].empty())
		arr[j].clear();
	if (a >= 0 && a < (int)arr[c].size()) {
        for (int i = a; i < b-a && i < (int)arr[c].size(); ++i) {
            arr[j].push_back(arr[c].at(i));
        }
    }
}
///&& arr[c].at(a) && arr[c].at(b)