/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:53:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 18:26:02 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    FloatPrint(t_data *data, std::string float_s)
{
    if (!data->IsLimit && ((HavePoint(data->argument) && !HavePoint(float_s) && !CheckMaxMin(data, FLOAT_)) \
        || (data->type == INT_ && data->str.length() <= 6) || data->type == CHAR_))
        std::cout << "float: " << data->float_ << ".0f" << std::endl;
    else if ((data->Impossible && !CheckMaxMin(data, FLOAT_)) || data->ImpossibleCases)
        std::cout << "float: " << "Impossible" << std::endl;
    else
        std::cout << "float: " << data->float_ << "f" << std::endl;
}

void    DoublePrint(t_data *data, std::string float_s)
{
    if (!data->IsLimit && ((HavePoint(data->argument) && !HavePoint(float_s) && !CheckMaxMin(data, DOUBLE_)) \
        || (data->type == INT_ && data->str.length() <= 6) || data->type == CHAR_)) 
        std::cout << "double: " << data->double_ << ".0" << std::endl;
    else if ((data->Impossible && !CheckMaxMin(data, DOUBLE_)) || data->ImpossibleCases)
        std::cout << "double: " << "Impossible" << std::endl;
    else
        std::cout << "double: " << data->double_ << std::endl;
}

void    IntPrint(t_data *data)
{
    if (data->SpecialCases || data->Impossible || data->IsLimit || data->ImpossibleCases)
        std::cout << "int: " << "Impossible" << std::endl;
    else
        std::cout << "int: " << data->int_ << std::endl;
}

void    CharPrint(t_data *data)
{
    if (!data->IsPrintable && !data->SpecialCases && !data->Impossible && !data->IsLimit && !data->ImpossibleCases)
        std::cout << "char: " << "Non displayable" << std::endl;
    else if (data->SpecialCases || data->Impossible || data->IsLimit || data->ImpossibleCases)
        std::cout << "char: " << "Impossible" << std::endl;
    else
        std::cout << "char: '" << data->char_ << "'" << std::endl;
}

void    PrintData(t_data *data, std::string float_s)
{
    CharPrint(data);
    IntPrint(data);
    FloatPrint(data, float_s);
    DoublePrint(data, float_s);
}
