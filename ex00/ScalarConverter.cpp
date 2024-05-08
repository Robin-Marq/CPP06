/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:56:59 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/24 16:17:57 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "Default constructor called" << DEFAULT << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "Default Destructor called" << DEFAULT << std::endl;
}

ScalarConverter::ScalarConverter(const std::string &input) : _string(input)
{
	std::cout << GREEN << "Parameter Constructor called" << DEFAULT << std::endl;
	convert(_string);
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << GREEN << "Copy constructor called" << DEFAULT << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << GREEN "Assignation operator called" << DEFAULT << std::endl;
	(void)other;
	return *this;
}

// This function converts a string to a double value.
// If the string is empty or contains only whitespace characters, the function throws an exception.
// If the string contains a 'f' character at the end, it is removed.
// The function uses a std::istringstream object to convert the string to a double value.
// from Robin Marquardt
double stringToDouble(const std::string &input)
{
	std::string modifiedInput = input;
	if (!modifiedInput.empty() && modifiedInput[modifiedInput.length() - 1] == 'f')
		modifiedInput = modifiedInput.substr(0, modifiedInput.length() - 1);

	std::istringstream stream(modifiedInput);
	double doubleValue;
	stream >> doubleValue;
	if (stream.fail() || !stream.eof())
		throw std::exception();

	return doubleValue;
}

// This function converts a string to a float value.
// If the string is empty or contains only whitespace characters, the function throws an exception.
// If the string contains a 'f' character at the end, it is removed.
// The function uses a std::istringstream object to convert the string to a float value.
// from Robin Marquardt
float stringToFloat(const std::string &input)
{
	std::string modifiedInput = input;
	if (!modifiedInput.empty() && modifiedInput[modifiedInput.length() - 1] == 'f')
		modifiedInput = modifiedInput.substr(0, modifiedInput.length() - 1);

	std::istringstream stream(modifiedInput);
	float floatValue;
	stream >> floatValue;
	if (stream.fail() || !stream.eof())
		throw std::exception();

	return floatValue;
}

// This function checks first if the input string is equal to "nan", "-inf" or "+inf".
// If it is, the function prints the corresponding values for each type.
// after that, the function try to print the char, int, float and double values of the input string.
// from Robin Marquardt

void ScalarConverter::convert(const std::string &input)
{
	if (input == "nan" || input == "-inf" || input == "+inf")
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;

	else if (input == "-inff" || input == "+inff" || input == "nanf")
		std::cout << "char: impossible\nint: impossible\nfloat: " << input << "\ndouble: " << input.substr(0, input.size() - 1) << std::endl;

	else
	{
		try
		{
		if (input.size() == 1 && isalpha(input[0]))
			std::cout << "char: '" << input[0] << "'" << std::endl;
		else if (input[input.size() - 1] == 'f')
			std::cout << "char: '*'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		}
		catch(const std::exception& e)
		{
		std::cerr << e.what() << '\n';
		}

	try
	{
		float floatValue = stringToFloat(input);
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;

		size_t decimalPos = input.find('.');

		if (decimalPos != std::string::npos)
		{
			int decimalPlaces = input.length() - decimalPos - 1;
			if (input[input.size() - 1] == 'f')
				decimalPlaces--;

			if (decimalPlaces > 6)
				decimalPlaces = 6;
			if (decimalPlaces < 1)
				decimalPlaces = 1;

			std::cout << "float: " << std::fixed << std::setprecision(decimalPlaces) << floatValue << "f" << std::endl;
		}
		else
		{
			if (input[input.size() - 1] == 'f')
			{
				std::cout << "float: " << input << std::endl;
			}
			else
			{
				std::cout << "float: " << floatValue << ".0f" << std::endl;
			}
		}
	}

	catch(const std::exception& e)
	{
		std::cerr << RED << "impossible" << DEFAULT << '\n';
	}

try
{
	std::string inputCopy = input;

	if (inputCopy[inputCopy.length() - 1] == 'f')
	{
		inputCopy = inputCopy.substr(0, inputCopy.length() - 1);
	}

	double doubleValue = static_cast<double>(stringToDouble(inputCopy));

	size_t decimalPos = inputCopy.find('.');

	if (decimalPos != std::string::npos)
	{
		int decimalPlaces = inputCopy.length() - decimalPos - 1;

		if (decimalPlaces > 15)
			decimalPlaces = 15;

		std::cout << "double: " << std::fixed << std::setprecision(decimalPlaces) << doubleValue << std::endl;
	}
	else
	{
		std::cout << "double: " << doubleValue << ".0" << std::endl;
	}

}
catch(const std::exception& e)
{
	std::cerr << RED << "impossible" << DEFAULT << '\n';
}
}
}
