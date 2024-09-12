#include "../MyArrs.hpp"

void MyArrs::Save()
{
	this->flag = 1;
	char a;
	if(this->args > 3 || this->args < 3)
	{
		std::cerr << "\nWrong number of arguments -> (Save A, in2.txt)\n"<< std::endl;
		return;
	}
	if(this->arg1.length()-1 != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Save A, in2.txt)\n"<< std::endl;
		return;
	}
	a = ft_toupper(arg1[0]);
	if(arr[a].empty())
	{
		std::cerr << "ARR "<< a << " is empty"<< std::endl;
		return;
	}

	std::ofstream file(arg2);
	if (file.is_open())
	{
        for (int i = 0; i < (int)arr[a].size(); ++i) {
            file << arr[a].at(i) << " ";
		}
    }
    file.close();

}