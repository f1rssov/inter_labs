#include "../MyArrs.hpp"


void MyArrs::Load()
{

	int a;

	this->flag = 1;

	//////// CHECKER VALID
	if(this->args > 3 || this->args < 3)
	{
		std::cerr << "\nWrong number of arguments -> (Load A, in.txt)\n"<< std::endl;
		return;
	}
	if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Load A, in.txt)\n"<< std::endl;
		return;
	}
	std::ifstream file(arg2);
	if(!file.is_open())
	{
		std::cerr << "\nWrong file\n" << std::endl;
		return ;
	}
	///////
	a = ft_toupper(arg1[0]);
	if(!arr[a].empty())
		arr[a].clear();
	if (file.is_open())
	{
        int number;
        while (file >> number) {
            arr[a].push_back(number);
		}
    }
    file.close();
}