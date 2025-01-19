#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <vector>
#include <chrono>


void worker(int n) {
	std::cout << "worker thread:" << std::this_thread::get_id() << std::endl;

	for (int i = 0; i < n; i ++) {
		std::pow(434,54);
	}

}

int main() {

	std::cout << "main thread:" << std::this_thread::get_id() << std::endl;

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

	std::vector<std::future<void>> futures;

	int nLoops = 10;int nThreads = 3;

	for (int i = 0; i < nThreads; i++) {
		futures.emplace_back(std::async(worker, nLoops));
	
	}

	for (const std::future<void>& ftr : futures ) {
		ftr.wait();
	
	}

	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds> ( t2 - t1 ).count();

	std::cout << "execution finished after " << duration << " microseconds";






}
