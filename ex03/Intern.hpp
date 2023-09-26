/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 03:57:32 by antoineherb       #+#    #+#             */
/*   Updated: 2023/07/06 18:32:16 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                              INTERN CLASS                                  */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        // private member attributes
        // private member functions
    public:
        // constructors
        Intern( void );
        Intern( Intern const &src );
        // destructor
        ~Intern( void );
        // operators overload
        Intern&     operator=( Intern const &src);
        // getter, setter
        // public member functions
        int         checkFname( std::string const &name );
        Form*       makeForm( std::string const &name, std::string const &target);
        // exception classes
};

#endif