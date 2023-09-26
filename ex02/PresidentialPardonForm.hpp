/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:52:18 by aherbet           #+#    #+#             */
/*   Updated: 2023/07/05 21:08:57 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                     PRESIDENTIAL PARDON FORM CLASS                         */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        // private member attributes
        std::string     _target;
        // private member functions
        // default constructor
        PresidentialPardonForm( void );
    public:
        // other constructors
        PresidentialPardonForm( std::string const &target);
        PresidentialPardonForm( PresidentialPardonForm &src);
        // destructor
        ~PresidentialPardonForm( void );
        // operators overload
        PresidentialPardonForm& operator=( PresidentialPardonForm const &src);
        // getter, setter
        // public member functions
        void                    execute( Bureaucrat const &executor ) const;
        // exception classes
};

#endif