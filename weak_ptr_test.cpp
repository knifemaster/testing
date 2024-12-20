#include <iostream>
#include <memory>


class Object {
	public:
		Object(int value) : data(value) {
			std::cout << "Object created with value: " << data << std::endl;

		
		}

		~Object() {
			std::cout << "Object destroyed with value " << data << std::endl;
		}

		int data;

};


int main() {

	std::shared_ptr<Object> sharedObjectA = std::make_shared<Object>(42);
	std::weak_ptr<Object> weakObjectA = sharedObjectA;

	
	if (!weakObjectA.expired()) {
		std::cout << "not expired The value stored in sharedObjectA " << (*weakObjectA.lock()).data << std::endl;
	}	
	
	sharedObjectA.reset();

	std::cout << "End of the program" << std::endl;

	return 0;
}
