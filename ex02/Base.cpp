/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:56:05 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 18:36:17 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    
}

Base    *generate(void)
{
    size_t random;

    srand(time(0));
    random = rand() % 9;
    if (random > 0 && random <= 3)
        return (dynamic_cast<Base *>(new A()));
    else if (random > 3 && random <= 6)
        return (dynamic_cast<Base *>(new B()));
    else
        return (dynamic_cast<Base *>(new C()));
    return (NULL);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Obj of Drived Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Obj of Drived Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Obj of Drived Class C" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A A_obj = dynamic_cast<A&>(p);
        std::cout << "Obj of Drived Class A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B B_obj = dynamic_cast<B&>(p);
            std::cout << "Obj of Drived Class B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                C C_obj = dynamic_cast<C&>(p);
                std::cout << "Obj of Drived Class C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
}
