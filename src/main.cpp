#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstdint>
#include <chrono>

template<typename T>
bool is_correct_dist(const std::vector<T>& perm){
	for(size_t i = 0; i < perm.size(); ++i){
		const T expected = perm[i]+1;
		
		if(!(i - expected >= 0 && perm[i-expected] == perm[i])
			&& !(i + expected < perm.size() && perm[i+expected] == perm[i]))
			return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	const int N = atoi(argv[1]);
	std::vector<int> combination(N*2);
	std::iota(combination.begin(), combination.begin() + N, 1);
	std::iota(combination.begin() + N, combination.end(), 1);
	std::sort(combination.begin(), combination.end());
	
	auto start = std::chrono::high_resolution_clock::now();
	int64_t count = 0;
	int64_t num_solutions = 0;
	do {
		if(is_correct_dist(combination)){
			for(int e : combination)
				std::cout << e;
			std::cout << "\n";
			++num_solutions;
		}
		++count;
	//	if(count % (2<<24) == 0)
	//		std::cout << "checked " << count << " permutations\n";
	} while(std::next_permutation(combination.begin(), combination.end()));
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Found " << num_solutions << " in " << std::chrono::duration<float>(end-start).count() << "s\n";
	
	return 0;
}