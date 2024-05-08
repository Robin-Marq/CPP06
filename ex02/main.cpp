/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:47:41 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/30 11:26:14 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//Here we generate a random class and return a pointer to the class A, B or C
//We also print the class generated.
//We use the rand() function to generate a random number between 0 and 2
//We use the modulo operator to get a number
//from Robin Marquardt
Base *generate(void)
{
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << GREEN "A class generated" << DEFAULT << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << GREEN << "B class generated" << DEFAULT << std::endl;
		return new B();
	}
	else
	{
		std::cout << GREEN << "C class generated" << DEFAULT << std::endl;
		return new C();
	}

}

//Here we identify the class using the dynamic_cast operator
//We use the dynamic_cast operator to cast the pointer to the class A, B or C
//If the cast is successful, we print the class
//from Robin Marquardt
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "A pointer was succesfully dynamic casted" << DEFAULT << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "B pointer was succesfully dynamic casted" << DEFAULT << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "C pointer was succesfully dynamic casted" << DEFAULT << std::endl;
}

//Here we identify the class using the dynamic_cast operator
//We use the dynamic_cast operator to cast the reference to the class A, B or C
//If the cast is successful, we print the class
//from Robin Marquardt
void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << GREEN "A was succesfully identified" << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << YELLOW << "Exception error in A: " << e.what() << DEFAULT << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << GREEN << "B was succesfully identified" << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << YELLOW << "Exception error in B: " << e.what() << DEFAULT << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << GREEN << "C was succesfully identified" << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << YELLOW << "Exception error in C: " << e.what() << DEFAULT << std::endl;
	}
}

int main()
{
	while(1)
	{
		std::cout << "Press enter to generate a new class" << std::endl;
		std::cin.get();
		Base *base;
		base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return 0;
}
