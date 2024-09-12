#include "../MyArrs.hpp"

void MyArrs::Intersect()
{
	this->flag = 1;

	if(this->args > 3 || this->args < 3)
	{
		std::cerr << "\nWrong number of arguments -> (Intersect A, B)\n"<< std::endl;
		return;
	}
	if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Intersect A, B)\n"<< std::endl;
		return;
	}
	if(this->arg2.length() != 1 || !std::isalpha(this->arg2[0]))
	{
		std::cerr << "\nWrong arguments -> (Intersect A, B)\n"<< std::endl;
		return;
	}
	if(arr[ft_toupper(arg1[0])].empty())
	{
		std::cerr << "ARR "<< (char)ft_toupper(arg1[0]) << " is empty"<< std::endl;
		return;
	}
	if(arr[ft_toupper(arg2[0])].empty())
	{
		std::cerr << "ARR "<< (char)ft_toupper(arg2[0]) << " is empty"<< std::endl;
		return;
	}
	std::vector<int> A(arr[ft_toupper(arg1[0])]);
	std::vector<int> B(arr[ft_toupper(arg2[0])]);

	std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<int> intersection;
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(intersection));

	if(!arr[ft_toupper(arg1[0])].empty())
		arr[ft_toupper(arg1[0])].clear();
    arr[ft_toupper(arg1[0])] = intersection;
}