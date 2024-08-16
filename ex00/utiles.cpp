/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:53:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 15:51:22 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool    operator_check(std::string operators, char c)
{
    for (int i = 0; operators[i]; i++)
    {
        if (operators[i] == c)
            return (true);
    }
    return (false);
}

int SpecialCompare(std::string str)
{
    std::string M_SpecialCases[8] = {"-inff", "+inff" , "nanf", "-inf", "+inf" , "nan", "inf", "inff"};
    std::string m_SpecialCases[8] = {"-INFF", "+INFF" , "NANF", "-INF", "+INF" , "NAN", "INF", "INFF"};
    for (int i = 0; i < 8; i++)
    {
        if (str == M_SpecialCases[i] || str == m_SpecialCases[i])
            return (1);
    }
    return (0);
}

bool    HavePoint(std::string str)
{
    for(int i = 0; str[i]; i++)
    {
        if (str[i] == '.')
            return (true);
    }
    return (false);
}

int CheckMaxMin(t_data *data, int type)
{
    if (type == FLOAT_ && (data->float_ > FLT_MAX || data->float_ < -FLT_MAX))
        return (1);
    if (type == DOUBLE_ && (data->double_ > DBL_MAX || data->double_ < -DBL_MAX))
        return (1);
    else if (data->type == -1)
        return (1);
    return (0);  
}
