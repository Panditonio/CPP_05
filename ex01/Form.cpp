/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 03:29:43 by antoineherb       #+#    #+#             */
/*   Updated: 2023/07/05 19:44:04 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ): _name("[blank]"), _signed(false), 
                    _gradeSign(0), _gradeExec(0) {
    std::cout << "[FORM] default constructor called" << std::endl;
    return;                   
}

Form::Form( std::string const n, int const gS, int const gE ): _name(n),
                    _signed(false), _gradeSign(gS), _gradeExec(gE) {
    std::cout << "[FORM] parametric constructor called" << std::endl;
    try {
        if (this->_gradeSign < GRADE_MAX || this->_gradeExec < GRADE_MAX)
            throw GradeTooHighException();
        else if (this->_gradeSign > GRADE_MIN || this->_gradeExec > GRADE_MIN)
            throw GradeTooLowException();
    }
    catch(const Form::GradeTooHighException &e) {
        std::cerr << e.what() << '\n';
    }
    catch(const Form::GradeTooLowException &e) {
        std::cerr << e.what() << '\n';
    }
    return;
}

Form::Form( Form const &src ): _name(src.getName()), _gradeSign(src.getSignLevel()),
                    _gradeExec(src.getExecLevel()) {
    std::cout << "[FORM] copy constructor called" << std::endl;
    *this = src;
    return;
}

Form::~Form( void ) {
    std::cout << "[FORM] destructor called" << std::endl;
    return;
}

Form&     Form::operator=( Form const &src ) {
    std::cout << "[FORM] copy assignment operator called" << std::endl;
    std::cout << "[WARNING] name, sign and exec levels are const";
    std::cout << " and cannot be copied" << std::endl;
    if (this != &src) {
        this->_signed = src._signed;
    }
    return (*this);
}

std::string const   Form::getName( void ) const {
    return (this->_name);
}

std::string const    Form::getSignedStatus( void ) const {
    return (this->_signed ? "signed" : "not signed");
}

int   Form::getSignLevel( void ) const {
    return (this->_gradeSign);
}

int   Form::getExecLevel( void ) const {
    return (this->_gradeExec);
}

void    Form::beSigned( Bureaucrat const &boss) {
    if (boss.getGrade() > this->_gradeSign)
        throw GradeTooLowException();
    else
        this->_signed = true;
    return;
}

std::ostream&   operator<<(std::ostream &os, Form const &op) {
    os << "Form " << op.getName() << " requires grade " << op.getSignLevel()
        << " to sign and grade " << op.getExecLevel() << " to execute.\n"
        << "Current signature status is : " << op.getSignedStatus();
    return (os);
}