#include "../MyArrs.hpp"

void MyArrs::Stat()
{
	this->flag = 1;
	char a;

    if(this->args > 2 || this->args < 2)
	{
		std::cerr << "\nWrong number of arguments -> (Stat a)\n"<< std::endl;
		return;
	}
	if(this->arg1.length() != 1 || !std::isalpha(this->arg1[0]))
	{
		std::cerr << "\nWrong arguments -> (Stat a)\n"<< std::endl;
		return;
	}
	a = ft_toupper(arg1[0]);
	int size = arr[a].size();
    if (size == 0) {
        std::cout << "Array is empty." << std::endl;
        return;
    }

    int minElement = arr[a].at(0);
    int maxElement = arr[a].at(0);
    int minIndex = 0;
    int maxIndex = 0;
    double sum = 0.0;
    std::unordered_map<int, int> frequencyMap;

    // Find min, max, sum, and count frequency of each element
    for (int i = 0; i < size; ++i) {
        int element = arr[a].at(i);
        if (element < minElement) {
            minElement = element;
            minIndex = i;
        }
        if (element > maxElement) {
            maxElement = element;
            maxIndex = i;
        }
        sum += element;
        ++frequencyMap[element];
    }

    double average = sum / size;
    int mostFrequentElement = arr[a].at(0);
    int maxFrequency = frequencyMap[arr[a].at(0)];

    // Find the most frequent element
    for (const auto& entry : frequencyMap) {
        if (entry.second > maxFrequency) {
            mostFrequentElement = entry.first;
            maxFrequency = entry.second;
        }
    }

    double maxDeviation = 0.0;

    // Calculate the maximum deviation from the average
    for (int i = 0; i < size; ++i) {
        double deviation = std::abs(arr[a].at(i) - average);
        if (deviation > maxDeviation) {
            maxDeviation = deviation;
        }
    }

    std::cout << "Размер массива: " << size << std::endl;
    std::cout << "Мин. элемент " << minElement << " (index: " << minIndex << ")" << std::endl;
    std::cout << "Макс. элемент: " << maxElement << " (index: " << maxIndex << ")" << std::endl;
    std::cout << "Самый частый элемент: " << mostFrequentElement << " (frequency: " << maxFrequency << ")" << std::endl;
    std::cout << "Среднее значение: " << average << std::endl;
    std::cout << "Максимальное отклонение от среднего: " << maxDeviation << std::endl;
}