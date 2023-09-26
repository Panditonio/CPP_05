/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbet <aherbet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 03:57:27 by antoineherb       #+#    #+#             */
/*   Updated: 2023/08/09 16:23:11 by aherbet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
    std::cout << "[INTERN] default constructor called" << std::endl;
    return;
}

Intern::Intern( Intern const &src ) {
    std::cout << "[INTERN] copy constructor called" << std::endl;
    *this = src;
    return;
}

Intern::~Intern( void ) {
    std::cout << "[INTERN] destructor called" << std::endl;
    return;
}

Intern&     Intern::operator=( Intern const &src ) {
    std::cout << "[INTERN] copy assignment operator called" << std::endl;
    if (this != &src)
        *this = src;
    return (*this);
}

int        Intern::checkFname( std::string const &name ) {
    std::string     fName[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    
    try {
        for (int i = 0; i < 3; i++)
            if (fName[i] == name)
                return (i);
        throw Form::WrongFormNameException();
    }
    catch (Form::WrongFormNameException &e) {
        std::cout << "[INTERN] failed to create form because : " << e.what() << std::endl;
    }
    return (-1);
}

Form*       Intern::makeForm( std::string const &name, std::string const &target) {
    std::string     fName[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    Form*           form = NULL;

    int i = checkFname(name);
    if (i != -1) {
        switch (i) {
            case 0:
                form = new PresidentialPardonForm(target);
                break;
            case 1:
                form = new RobotomyRequestForm(target);
                break;
            case 2:
                form = new ShrubberyCreationForm(target);
                break;
        }
        std::cout << "[INTERN] created form " << form->getName();
        std::cout << " for " << target << std::endl;
        return (form);
    }
    else {
        std::cout << "Form creation failed... the intern is worthless !" << std::endl;
        return (NULL);
    }
}