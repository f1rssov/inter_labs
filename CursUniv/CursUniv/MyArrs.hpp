#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <random>
#include <string>
#include <map>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <set>

class MyArrs
{
public:
    MyArrs();
    ~MyArrs();
    void Load();
    void Save();    
    void Rand();    
    void Concat();    
    void Free();    
    void Remove();    
    void Copy();    
    void Sort();    
    void Permute();   
    void Intersect();   
    void Xor();   
    void Stat();
    void Print();
    void Exit();
    void algorithm(std::string func, std::string ar1, std::string ar2, std::string ar3, std::string ar4, int ars);
 
private:
    std::map<char, std::vector<int> > arr;
    std::string func;
    std::string arg1;
    std::string arg2; 
    std::string arg3; 
    std::string arg4;
    int flag;
    int args;
};

typedef void(MyArrs::*ArrsPtr)();
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char	*s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen_arr(char	**s);
int	ft_toupper(int c);
int GetRandomNumber(int min, int max);