#include <iostream>
#include <map>
#include <algorithm>

namespace UVA100
{
	class Solver
	{
	public:
		Solver()
		{
			cycleLengths[1] = 1;
		}

		~Solver()
		{
		}

		int CalculateMaxCycleLengthInRange(int minN, int maxN)
		{
			auto maxCycleLength = 0;
			for (int n = minN; n <= maxN; n++)
			{
				maxCycleLength = std::max(CalculateCycleLength(n), maxCycleLength);
			}
			return maxCycleLength;
		}

		int CalculateCycleLength(int n)
		{
			if (n == 1)
			{
				return 1;
			}

			auto iter = cycleLengths.find(n);
			if (iter == cycleLengths.end())
			{
				auto isOdd = n % 2 == 1;
				auto next = (isOdd) ? 3 * n + 1 : n >> 1;
				auto cycleLength = CalculateCycleLength(next) + 1;
				cycleLengths[n] = cycleLength;
				return cycleLength;
			}

			return iter->second;
		}

	private:
		std::map<int, int> cycleLengths;

	};
}

int main()
{
	int minN;
	int maxN;
	UVA100::Solver solver;
	while (std::cin >> minN)
	{
		std::cin >> maxN;

		auto maxCycleLength = solver.CalculateMaxCycleLengthInRange(std::min(minN, maxN), std::max(minN, maxN));
		std::cout << minN << " " << maxN << " " << maxCycleLength << std::endl;
	}

	return(0);
}
