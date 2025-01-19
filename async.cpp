#include <future>

#include <iostream>

#include <thread>
#include <chrono>

int some_func() {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 2;
}


int function1() {

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "in function1" << std::endl;
	return 200;

}

int main() {

	std::packaged_task<int()> task([]{return function1();});
	std::future<int> f1 = task.get_future();
	std::thread t(std::move(task));

	std::future<int> f2 = std::async(std::launch::async, [] {return 8;});

	std::promise<int> p;
	std::future<int> f3 = p.get_future();
	std::thread([&p] { p.set_value_at_thread_exit(9);}).detach();

	std::cout << "waiting..." << std::flush;
	f1.wait();
	f2.wait();
	f3.wait();

	std::cout << "done\nResults are: " << f1.get() << " " << f2.get() << " "<< f3.get() << std::endl; 

	t.join();

	//std::future futur = std::async(std::launch::async, []() { return some_func();});
	
	//std::cout << futur.get() << std::endl;

	return 0;

}
