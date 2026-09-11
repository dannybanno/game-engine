#include <optional>

class Input {

public:
	enum actions {
		MOVE,
		QUIT,

	};

	enum directions {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

	struct InputResult {
		actions action;
		std::optional<directions> direction;
	};


	InputResult getInput() {

		std::string str;
		std::cin >> str;

		if (str == "quit") {
			return { actions::QUIT, std::nullopt };
		
		}


		if (str == "move") {
			std::string dir;
			std::cin >> dir;

			if (dir == "north")
				return { MOVE, NORTH };

			if (dir == "south")
				return { MOVE, SOUTH };

			if (dir == "east")
				return { MOVE, EAST };

			if (dir == "west")
				return { MOVE, WEST };

		}


	}


};