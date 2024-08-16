/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:52:14 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 18:31:49 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize(void)
{
    
}

Serialize::Serialize(const Serialize &other)
{
    *this = other;
}

Serialize::~Serialize(void)
{

}

Serialize &Serialize::operator=(const Serialize &other)
{
    if (this != &other)
    {
        
    }
    return (*this);
}

uintptr_t Serialize::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialize::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}