#include "../MyArrs.hpp"

void MyArrs::Permute()
{
	this->flag = 1;

	if(this->args > 2 || this->args < 2)
	{
		std::cerr << "\nWrong number of arguments -> (Permute A)\n"<< std::endl;
		return;
	}
	if(this->arg1.length() != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Permute A)\n"<< std::endl;
		return;
	}
	if(arr[ft_toupper(arg1[0])].empty())
	{
		std::cerr << "ARR "<< (char)ft_toupper(arg1[0]) << " is empty"<< std::endl;
		return;
	}

	std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr[ft_toupper(arg1[0])].begin(), arr[ft_toupper(arg1[0])].end(), g);
}