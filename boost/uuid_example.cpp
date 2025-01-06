#include <iostream>
#include <string>
#include <vector>
#include <boost/uuid.hpp>

#include <chrono>


using namespace boost::uuids;

std::string create_uuid_string() {
	static thread_local random_generator gen;
	return boost::uuids::to_string(gen());
}


namespace utils {
	using namespace boost::uuids;
	
	class IdGenerator {
		public:
			std::string create_uuid_string() {
				return to_string(gen());
			}

		private:
			random_generator gen;
	
	};


	class Clock {
		public:

			void init_clock() {
			
			}

			void set_clock_time() {
			
			}

			void start_clock() {
			
			}

			void stop_clock() {
			
			}

			void get_seconds_remaining() {
				
			}

			void get_minutes_remaining() {
			
			}

			std::string get_remaining_time_string() {
			
			}


		private:
			bool player_color;
	
	}


}



int main() {

	utils::IdGenerator game_generator_id;

	for(int i = 0; i < 1000; i++) {
		std::cout << game_generator_id.create_uuid_string() << std::endl;
	}

	std::string tournament_game = game_generator_id.create_uuid_string();

	std::cout << sizeof(tournament_game) << "  " << tournament_game.size() << std::endl;
	//std::cout << create_uuid_string() << std::endl;
	//std::cout << create_uuid_string() << std::endl;


	///string_generator gen;

	//uuid game_id = gen( "{01234567-89ab-cdef-0123-456789abcdef}" );

	//std::cout << game_id << std::endl;	


}
