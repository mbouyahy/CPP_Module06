/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:52:32 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/18 19:34:25 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

typedef struct s_Data
{
    int         id;
    std::string name;
} Data;

class Serialize
{
    public:
        Serialize(void);
        Serialize(const Serialize &other);
        ~Serialize(void);
        Serialize &operator=(const Serialize &other);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif