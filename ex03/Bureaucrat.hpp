/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:21 by aherbet           #+#    #+#             */
/*   Updated: 2023/07/06 01:42:09 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                            BUREAUCRAT CLASS                                */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

#define GRADE_MIN 150
#define GRADE_MAX 1

class Form;

class Bureaucrat
{
    private:
        // private member attributes
        std::string const   _name;
        int                 _grade;
        // private member functions
    public:
        // constructors
        Bureaucrat( void );
        Bureaucrat( std::string const &name, int grade );
        Bureaucrat( Bureaucrat const &src );
        // destructor
        ~Bureaucrat( void );
        // operators overload
        Bureaucrat&         operator=( Bureaucrat const &rhs );
        // getter, setter
        std::string const   getName( void ) const;
        int                 getGrade( void ) const;
        void                setGrade( int const grade );
        // public member functions
        void                incrementGrade( void );
        void                decrementGrade( void );
        void                signForm( Form &form );
        void                executeForm( Form const &form );
        // exception classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() { 
                    return "[ERROR] Grade too high";
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() { 
                    return "[ERROR] Grade too low";
                }
        };
};

std::ostream&   operator<<(std::ostream &os, Bureaucrat const &op);

#endif