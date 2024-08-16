/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:17:06 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 16:54:19 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <float.h>

#define FLOAT_ 3
#define CHAR_ 4
#define DOUBLE_ 5
#define INT_ 6

#define POINT 2
#define ERROR 1
#define WRONG 7

#define OPERATORS "+-*/"

typedef struct s_data
{
    //Essential Variables
    const char  *argument;
    int         status;
    int         count;
    int         type;
    std::string save;
    std::string str;

    //Types variables 
    double  double_;
    float   float_;
    char    char_;
    int     int_;

    //Define Errors Variables
    bool    ImpossibleCases;
    bool    Non_Displayable;
    bool    isFloatNumber;
    bool    SpecialCases;
    bool    IsPrintable;
    bool    Impossible;
    bool    IsLimit;
} t_data;

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter(void);
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        static void convert(std::string str);
};

/*<-----------Converter Functions---------->*/

void    Fill_Types(t_data *data);
int     CheckSyntaxError(t_data *data);

/*<-----------PrintData Functions---------->*/

void    DoublePrint(t_data *data, std::string float_s);
void    FloatPrint(t_data *data, std::string float_s);
void    PrintData(t_data *data, std::string float_s);
void    CharPrint(t_data *data);
void    IntPrint(t_data *data);

/*<-----------Utiles Functions---------->*/

bool    operator_check(std::string operators, char c);
int     CheckMaxMin(t_data *data, int type);
int     SpecialCompare(std::string str);
bool    HavePoint(std::string str);

#endif