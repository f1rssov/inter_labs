#include "MyArrs.hpp"

int GetRandomNumber(int min, int max)
{
  srand(time(0));

  int num = rand() % (max - min + 1) + min;
  srand(1);
  return num;
}