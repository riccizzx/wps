#include "headers.hpp"

int main() {
	try {
		WindowsPortScanner::Scanner scanner;
		scanner.Run();
	}
	catch (const std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}