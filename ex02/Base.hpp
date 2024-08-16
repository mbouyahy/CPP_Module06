/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:56:16 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/22 16:32:56 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
  //Implement a Base class that has a public virtual destructor only.
  public:
    virtual ~Base(void);
};

Base    *generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif