#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		int nbr = atoi(argv[i]);
		if (nbr <= 0)
		{
			std::cerr << "Error: you entered a non-positive number." << std::endl;
			return 1;
		}
		i++;
	}

	timeval start, end;
	{
		gettimeofday(&start, NULL);

		std::vector<int> vect;
		i = 1;
		while (i < argc)
		{
			vect.push_back(atoi(argv[i]));
			i++;
		}

		std::cout << "Before : ";
		size_t j = 0;
		while (j < vect.size())
		{
			std::cout << vect[j] << " ";
			j++;
		}
		std::cout << std::endl;

		vect = PmergeMeVect(vect);

		std::cout << "After : ";
		j = 0;
		while (j < vect.size())
		{
			std::cout << vect[j] << " ";
			j++;
		}
		std::cout << std::endl;

		gettimeofday(&end, NULL);

		long time_difference = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
		std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : " << time_difference << " us" << std::endl;
	}
	{
		gettimeofday(&start, NULL);

		std::deque<int> dq;
		i = 1;
		while (i < argc)
		{
			dq.push_back(atoi(argv[i]));
			i++;
		}

		dq = PmergeMeDQ(dq);

		gettimeofday(&end, NULL);

		long time_difference = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
		std::cout << "Time to process a range of " << dq.size() << " elements with std::deque : " << time_difference << " us" << std::endl;
	}
}