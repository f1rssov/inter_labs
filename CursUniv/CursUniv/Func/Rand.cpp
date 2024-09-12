#include "../MyArrs.hpp"

void MyArrs::Rand()
{
	this->flag = 1;

	if(this->args > 5 || this->args < 5)
	{
		std::cerr << "\nWrong number of arguments -> (Rand A, count, lb, rb)\n"<< std::endl;
		return;
	}
	int count;
	int a, b;
	if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Rand A, count, lb, rb)\n"<< std::endl;
		return;
	}
	try
	{
		count = std::stoi(arg2);
		a = std::stoi(arg3);
		b = std::stoi(arg4);
			
	}
	catch(std::exception &e)
	{
		std::cerr << "\nWrong arguments -> (Rand A, count, lb, rb)\n"<< std::endl;
		return;
	}

	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(a, b);

	int c = ft_toupper(arg1[0]);
	if(!arr[c].empty())
		arr[c].clear();
	for (int i = 0; i < count; i++) {
        int randomNumber = dis(gen);
        arr[c].push_back(randomNumber);
    }

	// /////доделать
}