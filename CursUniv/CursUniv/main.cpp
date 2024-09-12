/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:09:44 by dcompreh          #+#    #+#             */
/*   Updated: 2023/06/01 00:04:50 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyArrs.hpp"
#include <vector>
int len;

void split_funcs(std::string str, std::string *func, std::string *arg1, std::string *arg2, std::string *arg3, std::string *arg4, int *args)
{
	int i = 0;
	char **funcia;
	char *str1;
	int g;


	if(!str[i])
	{
		std::cerr << "\nWrite command\n"<<std::endl;
		return ;
	}
	str1= new char [str.length() + 1];
	while(str[i])
	{
		str1[i] = str[i];
		i++;
	}
	str1[i]='\0';
	funcia = ft_split(str1, ' ');
	len = ft_strlen_arr(funcia);
	if(len > 5)
	{
		std::cerr << "\nWrong number of arguments\n" <<std::endl;
		return ;
	}
	*func = funcia[0];
	if(len >= 2)
		if(funcia[1][0])
		{
			*arg1 = funcia[1];
			if(len>2)
				arg1->at(arg1->length()-1) = '\0';
		}
	if(len >= 3)
		if(funcia[2])
		{
			*arg2 = funcia[2];
			if(len>3)
				arg2->at(arg2->length()-1) = '\0';
		}
	if(len >= 4)
		if(funcia[3])
		{
	 		*arg3 = funcia[3];
			if(len>4)
				arg3->at(arg3->length()-1) = '\0';
		}
	if(len >= 5)
		if(funcia[4])
		{
			*arg4 = funcia[4];
			if(len>5)
				arg4->at(arg3->length()-1) = '\0';
		}
	g = len;
	delete[] funcia;
	delete[] str1;
	*args = len;
}

char *my_str(std::string str)
{
	int i = 0;
	
	char *str1;
	str1= new char[str.length() + 1];
	while(str[i])
	{
		str1[i] = str[i];
		i++;
	}
	str1[i]='\0';
	return(str1);
}

int main(int argc, char **argv)
{
	// int			i = 0;
	std::string str;
	std::string func, arg1, arg2, arg3, arg4;
	int args=0;
	int i = 0;
	MyArrs obj;
	char *str1;

	if (argc > 2 && argv)
	{
		std::cout<< "Too much arguments" << std::endl;
		return 0;
	}
	if(argc == 1)
	{
		while(1)
		{
			std::cout << "Enter command:\n| Load | Save | Rand | Concat | Free | Remove | Copy | Sort | Permute | Intersect | Xor | Stat | Print | EXIT |" << std::endl;
			std::getline(std::cin, str);
			
			//////
			str1 = my_str(str);
			char **line;
			line = ft_split(str1, ';');
			//////
			
			
			i = 0;
			while(line[i])
			{
				split_funcs(line[i], &func, &arg1, &arg2, &arg3, &arg4, &args);
				obj.algorithm(func, arg1, arg2, arg3, arg4, args);
				i++;
			}
			delete[] str1;
			delete[] line;		
		}
	}
	if(argc == 2)
	{
		std::ifstream file(argv[1]);
		if (!file.is_open())
		{
        	std::cout << "Wrong file" << std::endl;
			return 0;
   		}
		while(1)
		{
			if(file.eof())
				return 0;
			std::getline(file, str);
			
			//////
			str1 = my_str(str);
			char **line;
			line = ft_split(str1, ';');
			//////
			
			
			i = 0;
			while(line[i])
			{
				split_funcs(line[i], &func, &arg1, &arg2, &arg3, &arg4, &args);
				obj.algorithm(func, arg1, arg2, arg3, arg4, args);
				i++;
			}
			delete[] str1;
			delete[] line;		
		}
	}
}
////6функция сделать