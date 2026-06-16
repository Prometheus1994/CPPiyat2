#include "PmergeMe.hpp"

int Jacobsthal(int index, size_t size)
{
	std::deque<int> jacobsthal_seq;
	size_t i = 2;
	size_t jacobsthal_nbr = 0;
	while (size > jacobsthal_nbr)
	{
		if (i % 2)
			jacobsthal_nbr = ((1 << i) + 1) / 3;
		else
			jacobsthal_nbr = ((1 << i) - 1) / 3;
		jacobsthal_seq.push_back(jacobsthal_nbr);
		i++;
	}
	std::deque<int> inserting_indices(size - 1, 0);
	inserting_indices.push_front(1);
	i = 0;
	while (i < jacobsthal_seq.size() - 2)
	{
		inserting_indices[jacobsthal_seq[i]] = jacobsthal_seq[i + 1];
		i++;
	}
	inserting_indices[jacobsthal_seq[i]] = size;
	i = 2;
	jacobsthal_nbr = 3;
	while (i < size)
	{
		if (inserting_indices[i] == 0)
		{
			jacobsthal_nbr--;
			inserting_indices[i] = jacobsthal_nbr;
		}
		else
			jacobsthal_nbr = inserting_indices[i];
		i++;
	}
	i = 0;
	while (i < inserting_indices.size())
	{
		inserting_indices[i]--;
		i++;
	}
	return inserting_indices[index];
}

std::vector<int> PmergeMeVect(std::vector<int> vect)
{
	if (vect.size() == 1)
		return vect;
	std::vector<int> biggers;
	std::vector<int> smallers;
	std::unordered_map<int, int> pairs;
	size_t i = 0;
	while (i < vect.size() / 2)
	{
		if (vect[i * 2] > vect[i * 2 + 1])
		{
			biggers.push_back(vect[i * 2]);
			smallers.push_back(vect[i * 2 + 1]);
			pairs[vect[i * 2]] = vect[i * 2 + 1];
		}
		else
		{
			biggers.push_back(vect[i * 2 + 1]);
			smallers.push_back(vect[i * 2]);
			pairs[vect[i * 2 + 1]] = vect[i * 2];
		}
		i++;
	}
	if (vect.size() % 2)
		smallers.push_back(vect[vect.size() - 1]);

	std::vector<int> sorted = PmergeMeVect(biggers);

	// pend contains all smallers according to the order of sorted biggers linked to them
	std::vector<int> pend;
	i = 0;
	while (i < sorted.size())
	{
		pend.push_back(pairs[sorted[i]]);
		i++;
	}
	if (vect.size() % 2)
		pend.push_back(smallers.back());

	// the smaller linked to the smallest bigger is guaranteed to be smaller than all biggers
	sorted.insert(sorted.begin(), pend[0]);

	// we start from index 1 because we already inserted the first smaller in the pend
	i = 1;
	while (i < pend.size())
	{
		int idx = Jacobsthal(i, pend.size());
		int nbr2insert = pend[idx];
		sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), nbr2insert), nbr2insert);
		i++;
	}
	return sorted;
}

std::deque<int> PmergeMeDQ(std::deque<int> dq)
{
	if (dq.size() == 1)
		return dq;
	std::deque<int> biggers;
	std::deque<int> smallers;
	std::unordered_map<int, int> pairs;
	size_t i = 0;
	while (i < dq.size() / 2)
	{
		if (dq[i * 2] > dq[i * 2 + 1])
		{
			biggers.push_back(dq[i * 2]);
			smallers.push_back(dq[i * 2 + 1]);
			pairs[dq[i * 2]] = dq[i * 2 + 1];
		}
		else
		{
			biggers.push_back(dq[i * 2 + 1]);
			smallers.push_back(dq[i * 2]);
			pairs[dq[i * 2 + 1]] = dq[i * 2];
		}
		i++;
	}
	if (dq.size() % 2)
		smallers.push_back(dq[dq.size() - 1]);

	std::deque<int> sorted = PmergeMeDQ(biggers);

	// pend contains all smallers according to the order of sorted biggers linked to them
	std::deque<int> pend;
	i = 0;
	while (i < sorted.size())
	{
		pend.push_back(pairs[sorted[i]]);
		i++;
	}
	if (dq.size() % 2)
		pend.push_back(smallers.back());

	// the smaller linked to the smallest bigger is guaranteed to be smaller than all biggers
	sorted.insert(sorted.begin(), pend[0]);

	// we start from index 1 because we already inserted the first smaller in the pend
	i = 1;
	while (i < pend.size())
	{
		int idx = Jacobsthal(i, pend.size());
		int nbr2insert = pend[idx];
		sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), nbr2insert), nbr2insert);
		i++;
	}
	return sorted;
}