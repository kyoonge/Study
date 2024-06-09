#include "Print.h"
#include <string>
#include <iomanip>

void PrintIntegers(std::istream& in, std::ostream& out) {
	out << " .........oct........dec......hex" << std::endl;
	out << " ------------.----------.--------" << std::endl;

	std::string token;
	while (in >> token) {
		try {
			int num = stoi(token);

			if (num < 0) continue;

			out << std::setw(12) << std::oct << num << "."
				<< std::setw(10) << std::dec << num << "."
				<< std::setw(8) << std::uppercase << std::hex << num << std::dec << std::endl;
		}
		catch (std::invalid_argument&) {
		}
		catch (std::out_of_range&) {
		}
	}
}

void PrintMaxFloat(std::istream& in, std::ostream& out) {
	std::string token;
	float max = FLT_MIN;

	while (in >> token) {
		try {
			float num = stof(token);
			bool isNegative = num < 0;
			
			max = std::max(max, num);

			out <<"....." << ( isNegative? '-':'+' ) << std::fixed << std::setprecision(3) << abs(num) << std::endl;
		}
		catch (std::invalid_argument&) {
		}
		catch (std::out_of_range&) {
		}
	}
	out << "max:." << (max<0 ? '-' : '+') << std::fixed << std::setprecision(3) << abs(max) << std::endl;
}