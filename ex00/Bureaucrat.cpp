/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbet <aherbet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:25 by aherbet           #+#    #+#             */
/*   Updated: 2023/07/03 22:10:30 by aherbet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name("noname"), _grade(150) {
    std::cout << "[BUREAUCRAT] default constructor called" << std::endl;
    return;
}

Bureaucrat::Bureaucrat( std::string const &name, int grade ): _name(name) {
    std::cout << "[BUREAUCRAT] parametric constructor called" << std::endl;
    try {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        else
            this->_grade = grade;
    }
    catch(const Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << '\n';
    }
    return;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) {
    std::cout << "[BUREAUCRAT] copy constructor called" << std::endl;
    *this = src;
    return;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "[BUREAUCRAT] destructor called" << std::endl;
    return;
}

Bureaucrat&     Bureaucrat::operator=( Bureaucrat const &src ) {
    std::cout << "[BUREAUCRAT] copy assignment operator called" << std::endl;
    std::cout << "[WARNING] name is const and cannot be copied" << std::endl;
    if (this != &src)
        this->_grade = src._grade;
    return (*this);
}

std::string const   Bureaucrat::getName( void ) const {
    return (this->_name);
}

int     Bureaucrat::getGrade( void ) const {
    return (this->_grade);
}

void    Bureaucrat::setGrade( int const grade ) {
    this->_grade = grade;
    return;
}

void    Bureaucrat::incrementGrade() {
    try {
        this->_grade -= 1;
        if (this->_grade < 1)
            throw GradeTooHighException();
    }
    catch(const Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << '\n';
    }
    return;
}

void    Bureaucrat::decrementGrade() {
    try {
        this->_grade += 1;
        if (this->_grade > 150)
            throw GradeTooLowException();
    }
    catch(const Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << '\n';
    }
    return;    
}

std::ostream   &operator<<(std::ostream &os, Bureaucrat const &op) {
    os << op.getName() << ", bureaucrat grade " << op.getGrade();
    return (os);
}