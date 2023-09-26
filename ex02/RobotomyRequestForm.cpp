/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbet <aherbet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:52:27 by aherbet           #+#    #+#             */
/*   Updated: 2023/08/09 16:20:30 by aherbet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): Form("RRF", 72, 45) {
    std::cout << "[RRF] default constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const &target):
                Form("RRF", 72, 45), _target(target) {
    std::cout << "[RRF] parametric constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm &src):
                Form(src), _target(src._target) {
    std::cout << "[RRF] copy constructor called" << std::endl;
    return;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
    std::cout << "[RRF] destructor called" << std::endl;
    return;
}

RobotomyRequestForm&     RobotomyRequestForm::operator=( RobotomyRequestForm const &src) {
    std::cout << "[PPF] copy assignment operator called" << std::endl;
    if (this != &src) {
        Form::operator=(src);
        this->_target = src._target;
    }
    return (*this);
}

void        RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
    try {
        if (this->getSignedStatus().compare("signed") != 0)
            throw UnsignedFormException();
        else if (executor.getGrade() > this->getExecLevel())
            throw GradeTooLowException();
        else {
        	std::cout << "* UNBEARABLE DRILLING NOISES *" << std::endl;
            std::srand(std::time(NULL));
            int random = std::rand();
            if (random % 2 == 0)
                std::cout << this->_target << " successfully robotomized" << std::endl;
            else
                std::cout << this->_target << "'s robotomization failed" << std::endl;
        }
    }
    catch (Form::UnsignedFormException &e) {
        std::cout << this->_target << " could not be robotomized because : " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e) {
        std::cout << this->_target << " could not be robotomized because : " << e.what() << std::endl;
    }
    return;
}
