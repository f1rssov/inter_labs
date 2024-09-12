#include "../MyArrs.hpp"

void MyArrs::Print()
{
	this->flag = 1;
	int a;
	if(this->args > 4 || this->args < 3)
	{
		std::cerr << "\nWrong number of arguments -> (Print a, all) (Print a, 4, 16)\n"<< std::endl;
		return;
	}
	if(this->args==3)
	{
		if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
		{
			std::cerr << "\nWrong arguments -> (Print a, all)\n"<< std::endl;
			return;
		}
		if(arg2.compare("all"))
		{
			std::cerr << "\nWrong arguments -> (Print a, all)\n"<< std::endl;
			return;
		}
		a = ft_toupper(arg1[0]);
		if(arr[a].empty())
		{
			std::cerr << "ARR "<< (char)a << " is empty"<< std::endl;
			return;
		}
		for (int i = 0; i < (int) arr[a].size(); ++i)
		{
        	std::cout << arr[a].at(i) << " ";
    	}
		std::cout << std::endl;
	}
	//////
	//////
	if(this->args==4)
	{
		int b;
		int c;
		if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
		{
			std::cerr << "\nWrong arguments -> (Print a, 4, 16)\n"<< std::endl;
			return;
		}
		try
		{
			b = std::stoi(arg2) - 1;
			c = std::stoi(arg3)- 1;
		}
		catch(std::exception &e)
		{
			std::cerr << "\nWrong arguments -> (Print a, 4, 16)\n"<< std::endl;
			return;
		}
		a = ft_toupper(arg1[0]);
		if(arr[a].empty())
		{
			std::cerr << "ARR "<< (char)a << " is empty"<< std::endl;
			return;
		}
		if (b < 0 || b >= (int) arr[a].size() || c < 0 || c >= (int) arr[a].size()) {
			std::cout << "Invalid range." << std::endl;
			return;
		}
		for (int i = b; i <= c; ++i)
		{
			std::cout << arr[a].at(i) << " ";
		}
		std::cout << std::endl;
    }
}