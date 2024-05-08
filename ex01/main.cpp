/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:12:11 by rmarquar          #+#    #+#             */
/*   Updated: 2024/04/30 11:08:53 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

int main()
{
	Data* data = new Data();
	data->id = 1;
	data->value = 42.0f;

	// Serialize the Data object
	uintptr_t serializedData = Serializer::serialize(data);

	// Deserialize the Data object
	Data* deserializedData = Serializer::deserialize(serializedData);

	// check if the deserialized data is the same as the original data
	if (deserializedData->id == data->id && deserializedData->value == data->value)
	{
		std::cout << "Test passed!" << std::endl;
		std::cout << "Data id: " << deserializedData->id << std::endl;
		std::cout << "Data value: " << deserializedData->value << std::endl;
	}
	else
	{
		std::cout << "Test failed!" << std::endl;
	}

	delete data;
	delete deserializedData;

	return 0;
}