#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

long long extractIntegerPart(const std::string &str) {
    std::istringstream iss(str);
    long long integerPart;
    iss >> integerPart;
    return integerPart;
}

long double extractRealPart(const std::string &str) {
    std::istringstream iss(str);
    long double realPart;
    iss >> realPart;
    return realPart;
}

std::string calculateMantissa(long long integerPart, long double realPart) {
    long double result = integerPart * realPart;
    std::string resultStr = std::to_string(static_cast<long long>(result));
    std::string fractionStr = std::to_string(static_cast<long long>((result - static_cast<long long>(result)) * pow(10, 15)));

    while (fractionStr.length() < 15) {
        fractionStr += "0";
    }

    return resultStr + "." + fractionStr.substr(0, 4);
}

std::string formatResult(const std::string &mantissaStr, int exponent) {
    std::string formattedResult = mantissaStr + " * 10^" + std::to_string(exponent);
    return formattedResult;
}

int main() {
    std::string strInteger, strReal;

    std::cout << "Введите целое число (до 30 цифр): ";
    std::cin >> strInteger;
    std::cout << "Введите вещественное число (до 30 значащих цифр): ";
    std::cin >> strReal;

    long long integerPart = extractIntegerPart(strInteger);
    long double realPart = extractRealPart(strReal);
    std::string mantissaStr = calculateMantissa(integerPart, realPart);
    int exponent = std::to_string(integerPart).length();

    if (mantissaStr[0] == '-' && mantissaStr[1] == '-') {
        mantissaStr.erase(0, 1);
    }

    std::string formattedResult = formatResult(mantissaStr, exponent);
    std::cout << "Результат умножения: " << formattedResult << std::endl;

    return 0;
}
