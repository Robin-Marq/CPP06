/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:56:52 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/30 11:39:07 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
			std::cout << "wrong nr. of arguments!" << std::endl;
			return 1;
	}

	ScalarConverter::convert(av[1]);

	return 0;
}
