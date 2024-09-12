#include "../MyArrs.hpp"

void MyArrs::Xor()
{
	this->flag = 1;
	char a;
	char b;

	if(this->args > 3 || this->args < 3)
	{
		std::cerr << "\nWrong number of arguments -> (Xor A, B)\n"<< std::endl;
		return;
	}
	if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Xor A, B)\n"<< std::endl;
		return;
	}
	if(this->arg2.length() != 1 || !std::isalpha(this->arg2[0]))
	{
		std::cerr << "\nWrong arguments -> (Xor A, B)\n"<< std::endl;
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

	a = ft_toupper(arg1[0]);
	b = ft_toupper(arg2[0]);
	int i=0;
	int j=0;
	int count = 0;
	std::vector<int> A(arr[a]);
	std::vector<int> B(arr[b]);

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());

	std::vector<int> result;
	std::vector<int>::iterator it;

	std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(result));
    // std::cout << *it;
	arr[a] = result;
}