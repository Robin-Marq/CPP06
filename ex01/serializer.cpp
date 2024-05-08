/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:11:31 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/30 11:07:07 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Default constructor called" << DEFAULT << std::endl;
}

Serializer::~Serializer()
{
	std::cout << RED << "Default Destructor called" << DEFAULT << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << GREEN << "Copy constructor called" << DEFAULT << std::endl;
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << GREEN << "Assignation operator called" << DEFAULT << std::endl;
	(void)src;
	return *this;
}

// This function serializes a Data object to a raw pointer.
// The function returns the raw pointer as an uintptr_t.
// from Robin Marquardt
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// This function deserializes a raw pointer to a Data object.
// The function returns a pointer to the deserialized Data object.
// from Robin Marquardt
Data* Serializer::deserialize(uintptr_t raw)
{
	Data* deserializedData = new Data;
	*deserializedData = *reinterpret_cast<Data*>(raw);

	return deserializedData;
}
