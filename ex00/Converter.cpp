/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:53:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 18:28:34 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int Get_Type(t_data *data, int f, int point, int character, int number)
{
    if (SpecialCompare(data->argument))
        return (-1);
    if (character > 1 || point > 1 || f > 1)
        return (-2);
    if (data->status == -2)
        return (-2);
    if (data->status == ERROR)
        return (-1);
    if (!point && f && (number || character))
        return (-2);
    if (number == 1 && point && f)
        data->type = FLOAT_;
    if (f && !character && point)
        data->type = FLOAT_;
    else if (point == 1 && !character)
        data->type = DOUBLE_;
    else if (!character && !point && !f)
        data->type = INT_;
    else if (data->count > 1 && character && !f)
        return (-2);
    else if (data->count == 1 && (character || f || point))
        data->type = CHAR_;
    else
        return (-1);
    return (data->count);
}

void    CountAndCheck(t_data *data, int i, int *character)
{
    if (data->argument[i] && !std::isdigit(data->argument[i]) && data->status != FLOAT_)
    {
        if (data->status != POINT)
            (*character)++;
        data->status = CHAR_;
    }
    data->count++;
    if (!operator_check(OPERATORS, data->argument[i]) && data->status != CHAR_ && data->status != POINT && data->status != FLOAT_)
        data->status = ERROR;
    data->status = 0;
}

int CheckSyntaxError(t_data *data)
{
    int f;
    int point;
    int character;
    int number;

    point = 0;
    f = 0;
    character = 0;
    number = 0;
    for (size_t i = 0; data->argument[i]; i++)
    {
        if (data->argument[i] && std::isdigit(data->argument[i]))
            number++;
        if (data->argument[i] == 'f' || data->argument[i] == 'F')
        {
            f++;
            if (data->argument[i + 1] && std::isdigit(data->argument[i + 1]) && (!data->argument[i + 2]))
            {
                data->status = -2;
                break ;
            }
            data->status = FLOAT_;
        }
        if (data->argument[i] == '.')
        {
            point++;
            data->status = POINT;
        }
        CountAndCheck(data, i, &character);
        if (data->status == ERROR)
            break ;
    }
    return (Get_Type(data, f, point, character, number));
}

void    ConvertMethod(t_data *data, int activate)
{
    std::stringstream   save_int;
    long long int       integer_check;
    bool                status;

    //initialize IsLimit variable
    data->IsLimit = false;
    
    //convert from float to integer
    std::stringstream   save_float;
    save_float << data->float_;
    save_float >> data->save;
    if(activate)
        return ;

    save_int << data->argument;
    save_int >> integer_check;

    //Check if the number is outside the INT range
    status = integer_check <= INT_MAX && integer_check >= INT_MIN;
    
    //check if the integer_check is pritable or not
    data->IsPrintable = isprint(integer_check);
    //check the result of status before filling the data->int_ variale
    status ? data->int_ = integer_check : data->IsLimit = true;
}

void    ConvertAndPrint(t_data *data)
{
    if (data->type == CHAR_)
    {
        char c;

        c = *data->argument;
        data->float_ = static_cast<int>(c);
        data->double_ = static_cast<int>(c);
        data->int_ = static_cast<int>(c);
    }
    else
    {
        char *f_res;
        char *d_res;

        data->float_ = strtof(data->argument, &f_res);
        data->double_ = strtod(data->argument, &d_res);
        if ((d_res && strlen(d_res) > 1) || (d_res && strlen(d_res) > 1))
            data->ImpossibleCases = true;
        if (!data->ImpossibleCases)
            data->int_ = static_cast<int>(data->float_);
    }
    
    if (!data->SpecialCases && !data->Impossible)
    {
        if (data->type == CHAR_)
        {
            data->IsPrintable = isprint(data->int_);
            ConvertMethod(data, true);
        }
        else
            ConvertMethod(data, false);
        data->char_ = static_cast<char>(data->int_);
    }
    PrintData(data, data->save);
}

void    Fill_Types(t_data *data)
{
    if (data->type == FLOAT_ || data->type == DOUBLE_ || data->type == INT_ \
        || data->type == CHAR_ || data->SpecialCases || data->Impossible || data->ImpossibleCases)
        ConvertAndPrint(data);
}
