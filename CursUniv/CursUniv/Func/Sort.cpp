#include "../MyArrs.hpp"

void MyArrs::Sort()
{
	this->flag = 1;
	
	if(this->args > 2 || this->args < 2)
	{
		std::cerr << "\nWrong number of arguments -> (Sort A+(-))\n"<< std::endl;
		return;
	}
	if((this->arg1.length() != 2 || !std::isalpha(this->arg1[0])) && arg1[1] != 43 && arg1[1] != 45)
	{
		std::cerr << "\nWrong arguments -> (Sort A+(-))\n"<< std::endl;
		return;
	}
	///// ++++
	if(arr[ft_toupper(arg1[0])].empty())
	{
		std::cerr << "ARR "<< (char)ft_toupper(arg1[0]) << " is empty"<< std::endl;
		return;
	}
	if(arg1[1] == 43)
		std::sort(arr[ft_toupper(arg1[0])].begin(), arr[ft_toupper(arg1[0])].end());
	////  ----
	if(arg1[1] == 45)
		std::sort(arr[ft_toupper(arg1[0])].begin(), arr[ft_toupper(arg1[0])].end(), std::greater<int>());
}