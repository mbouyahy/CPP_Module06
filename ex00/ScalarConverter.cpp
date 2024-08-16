/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:17:20 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 18:33:35 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter::~ScalarConverter(void)
{
    
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
        
    }
    return (*this);
}

void    init_data(t_data *data, std::string str)
{
    data->Non_Displayable = false;
    data->Impossible = false;
    data->IsLimit = false;
    data->isFloatNumber = false;
    data->SpecialCases = false;
    data->IsPrintable = false;
    data->ImpossibleCases = false;

    data->argument = str.c_str();
    data->str = str;
    data->status = 0;
    data->count =  0;
    data->type = -1;
    
    data->char_ = -1;
    data->double_ = -1;
    data->int_ = -1;
    data->float_ = -1;
}

void ScalarConverter::convert(std::string str)
{
    t_data  data;
    int     status;

    init_data(&data, str);
    status = CheckSyntaxError(&data);
    if (status == -1 && SpecialCompare(str))
        data.SpecialCases = true;
    else if (status == -1)
        data.Impossible = true;
    else if (status == -2)
        data.ImpossibleCases = true;
    Fill_Types(&data);
}