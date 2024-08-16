/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:28:42 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 18:10:38 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    std::cout << "<---------Generate Function Called--------->" << std::endl; 
    Base *B = generate();
    std::cout << "\n<---------identify with Reference Called--------->\n" << std::endl; 
    identify(*B);
    std::cout << "\n<---------identify with Pointer Called--------->\n" << std::endl; 
    identify(B);
    delete B;
}