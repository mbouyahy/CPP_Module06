/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:44:00 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 18:30:38 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
    Data        data;
    Data        *deserialize_data;
    uintptr_t   serialize_address;

    //init data
    data.id = 1;
    data.name = "mbouyahy";

    //data address
    std::cout << "original address               : " << &data << std::endl;

    //Fill variables
    serialize_address = Serialize::serialize(&data);
    deserialize_data = Serialize::deserialize(serialize_address);
    
    //Print variables
    std::cout << "address converted to uintptr_t : " << serialize_address << std::endl;
    std::cout << "return to the original address : " << deserialize_data << std::endl;
    
    std::cout << "\nId value of data               : " << deserialize_data->id << std::endl;
    std::cout << "Name value of data             : " << deserialize_data->name << std::endl;
    
}
