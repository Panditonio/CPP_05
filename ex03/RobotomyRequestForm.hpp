/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbet <aherbet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:52:33 by aherbet           #+#    #+#             */
/*   Updated: 2023/08/09 16:21:15 by aherbet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                        ROBOTOMY REQUEST FORM CLASS                         */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Form.hpp" 

class RobotomyRequestForm : public Form
{
    private:
        // private member attributes
        std::string     _target;
        // private member functions
        // default constructor
        RobotomyRequestForm( void );
    public:
        // other constructors
        RobotomyRequestForm( std::string const &target);
        RobotomyRequestForm( RobotomyRequestForm &src);
        // destructor
        ~RobotomyRequestForm( void );
        // operators overload
        RobotomyRequestForm& operator=( RobotomyRequestForm const &src);
        // getter, setter
        // public member functions
        void                    execute( Bureaucrat const &executor ) const;
        // exception classes
};

#endif