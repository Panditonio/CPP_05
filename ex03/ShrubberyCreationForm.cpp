/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:52:38 by aherbet           #+#    #+#             */
/*   Updated: 2023/07/06 06:34:38 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): Form("shrubbery creation", 145, 137) {
    std::cout << "[SCF] default constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target):
                Form("shrubbery creation", 145, 137), _target(target) {
    std::cout << "[SCF] parametric constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm &src):
                Form(src), _target(src._target) {
    std::cout << "[SCF] copy constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
    std::cout << "[SCF] destructor called" << std::endl;
    return;
}

ShrubberyCreationForm&     ShrubberyCreationForm::operator=( ShrubberyCreationForm const &src) {
    std::cout << "[SCF] copy assignment operator called" << std::endl;
    if (this != &src) {
        Form::operator=(src);
        this->_target = src._target;
    }
    return (*this);
}

void        ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
    try {
        if (this->getSignedStatus().compare("signed") != 0)
            throw UnsignedFormException();
        else if (executor.getGrade() > this->getExecLevel())
            throw GradeTooLowException();
        else {
            std::ofstream   output;

            output.open((this->_target + "_shrubbery").c_str());
            if (output.bad()) {
                std::cout << "[ERROR] could not open output file" << std::endl;
                return;
            }
            else {
                output << ASCII_TREE;
                output.close();
                std::cout << "Ganja shrub successfully created by " << executor.getName();
                std::cout << " in " << this->_target << std::endl;
            }
        }
    }
    catch (Form::UnsignedFormException &e) {
        std::cout << executor.getName() << " could not shrub because : " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e) {
        std::cout << executor.getName() << " could not shrub because : " << e.what() << std::endl;
    }
    return;
}