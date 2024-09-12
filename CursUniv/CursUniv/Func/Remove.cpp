#include "../MyArrs.hpp"

void MyArrs::Remove()
{
	this->flag = 1;
	char a;
	int b;
	int count;
	///// проверка валидности аргументов
	if(this->args > 4 || this->args < 4)
	{
		std::cerr << "\nWrong number of arguments -> (Remove a,2,7)\n"<< std::endl;
		return;
	}
	if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Remove a,2,7)\n"<< std::endl;
		return;
	}
	if(std::stoi(arg2) == 0 || std::stoi(arg3) == 0)
	{
		std::cerr << "\nWrong arguments -> (Remove a, 2, 7)\n"<< std::endl;
		return;
	}
	try
	{
		b = std::stoi(arg2) - 1;
		count = std::stoi(arg3);
	}
	catch(std::exception &e)
	{
		std::cerr << "\nWrong arguments -> (Remove a,2,7)\n"<< std::endl;
		return;
	}
	a = ft_toupper(arg1[0]);
	if(arr[a].empty())
	{
		std::cerr << "ARR "<< a << " is empty"<< std::endl;
		return;
	}
	///// проверка, чтобы аргументы были в пределах размера массива
	///// и алгоритм удаления элемента
	if (b >= 0 && b < (int)arr[a].size() && (count < (int)arr[a].size()-b+1)) {
        arr[a].erase(arr[a].begin() + b, arr[a].begin() + b + count);
    }
	else{
		std::cerr << "\nOut of array\n"<< std::endl;
		return;
	}
}