#include <iostream>
#include <type_traits>

constexpr static auto exec() noexcept {
	return 10;
}


template <typename... Args> constexpr auto try_extract(Args && ... args) {
	exec(std::forward<Args>(args)...);	
}



int main() {



}
