/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:52:13 by aherbet           #+#    #+#             */
/*   Updated: 2023/07/06 02:28:23 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): Form("PPF", 25, 5) {
    std::cout << "[PPF] default constructor called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const &target):
                Form("PPF", 25, 5), _target(target) {
    std::cout << "[PPF] parametric constructor called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &src):
                Form(src), _target(src._target) {
    std::cout << "[PPF] copy constructor called" << std::endl;
    return;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
    std::cout << "[PPF] destructor called" << std::endl;
    return;
}

PresidentialPardonForm&     PresidentialPardonForm::operator=( PresidentialPardonForm const &src) {
    std::cout << "[PPF] copy assignment operator called" << std::endl;
    if (this != &src) {
        Form::operator=(src);
        this->_target = src._target;
    }
    return (*this);
}

void        PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
    try {
        if (this->getSignedStatus().compare("signed") != 0)
            throw UnsignedFormException();
        else if (executor.getGrade() > this->getExecLevel())
            throw GradeTooLowException();
        else
            std::cout << this->_target << " has been pardoned by President Zaphod Beeblebrox" << std::endl;
    }
    catch (Form::UnsignedFormException &e) {
        std::cout << this->_target << " could not be pardoned because : " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e) {
        std::cout << this->_target << " could not be pardoned because : " << e.what() << std::endl;
    }
    return;
}
