/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:29:38 by antoineherb       #+#    #+#             */
/*   Updated: 2023/07/05 22:05:57 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               FORM CLASS                                   */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define GRADE_MIN 150
#define GRADE_MAX 1

class Bureaucrat;

class Form
{
    private:
        // private member attributes
        std::string const   _name;
        bool                _signed;
        int const           _gradeSign;
        int const           _gradeExec;
        // private member functions
    public:
        // constructors
        Form( void );
        Form( std::string const n, int const gS, int const gE );
        Form( Form const &src );
        // destructor
        virtual ~Form( void );
        // operators overload
        Form&     operator=( Form const &src );
        // getter, setter
        std::string const   getName( void ) const;
        std::string const   getSignedStatus( void ) const;
        int                 getSignLevel( void ) const;
        int                 getExecLevel( void ) const;
        // public member functions
        void                beSigned( Bureaucrat const &boss);
        virtual void        execute( Bureaucrat const &executor ) const = 0;
        // exception classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() { 
                    return "[F-ERROR] grade too high";
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() { 
                    return "[F-ERROR] grade too low";
                }
        };
        class UnsignedFormException : public std::exception {
            public:
                virtual const char* what() const throw() { 
                    return "[F-ERROR] unsigned forms cannot be executed";
                }
        };
};

std::ostream&   operator<<(std::ostream &os, Form const &op);

#endif