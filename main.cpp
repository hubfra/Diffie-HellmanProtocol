
#include <iostream>


int64_t ModPow(int64_t base, int64_t exponent, int64_t mod);
bool isPrime(int64_t number);


int main()
{
	int64_t prime_exponent, base, secrete_number, your_result, other_person_result, common_key;

	std::cout << "Enter prime exponent: ";
	std::cin >> prime_exponent;

	while (!isPrime(prime_exponent)) {
		std::cout << "Entered number is not prime\nEnter prime exponent: ";
		std::cin >> prime_exponent;
	}

	std::cout << "Enter base: ";
	std::cin >> base;
	std::cout << "Enter your secrete number: ";
	std::cin >> secrete_number;

	your_result = ModPow(base, secrete_number, prime_exponent);

	std::cout << "\Result: = " << your_result;
	std::cout << "\n\nEnter the other person result: ";
	std::cin >> other_person_result;

	common_key = ModPow(other_person_result, secrete_number, prime_exponent);

	std::cout << "\nKey = " << common_key << '\n';

	return 0;
}


int64_t ModPow(int64_t base, int64_t exponent, int64_t modulus)
{
	int64_t result = 1;
	int64_t pow = base % modulus;

	for (int64_t a = 1; a <= exponent; a <<= 1) {
		if (a & exponent) result = (result * pow) % modulus;
		pow = (pow * pow) % modulus;
	}

	return result;
}

bool isPrime(int64_t number)
{
	if (number < 2) return false;
	if (number == 2) return true;
	if (number % 2 == 0) return false;

	int64_t sqrt_n = static_cast<int64_t>(sqrt(number) + 1.0);
	for (int64_t a = 3; a < sqrt_n; a += 2) {
		if (number % a == 0) return false;
	}

	return true;
}