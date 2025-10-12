#include "headers.hpp"

int main() {
	try {
		wps::scanner scanner;
		scanner.run();
	}
	catch (const std::exception& e) {
		handle_error("error ", e.what());
		return EXIT_FAILURE;
	}

	return 0;
}