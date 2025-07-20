/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:30:40 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/16 22:21:21 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/Bureaucrat.hpp"
#include "./Include/includes.hpp"

const char *Bureaucrat::GradeTooHighException::what() throw() {
  return "Grade exceeds upper bound.";
}

const char *Bureaucrat::GradeTooLowException::what() throw() {
  return "Grade exceeds lower bound.";
}

Bureaucrat::Bureaucrat(void) {
  _name = "Bob";
  _grade = 150;
}

Bureaucrat::Bureaucrat(std::string const name, short grade) {
  _name = name;
  if (grade > 150)
    throw low_except;
  else if (grade < 1)
    throw high_except;
  _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bur) {
  _name = bur.getName();
  _grade = bur.getGrade();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bur) {
  if (_name.empty())
    _name = bur._name;
  _grade = bur.getGrade();

  return (*this);
}

Bureaucrat::~Bureaucrat(void) { return; }

std::string Bureaucrat::getName(void) const { return _name; }

short Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::incGrade(short inc) {
  _grade -= inc;
  if (_grade < 1) {
    _grade += inc;
    throw high_except;
  }
}

void Bureaucrat::decGrade(short dec) {
  _grade += dec;
  if (_grade > 150) {
    _grade -= dec;
    throw low_except;
  }
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
  } catch (AForm::GradeTooLowException &l_g) {
    std::cout << l_g.what() << std::endl;
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " because grade " << form.getSignGrade()
              << " is required to sign this form." << std::endl;
    return;
  }
  std::cout << this->getName() << " signed " << form.getName() << "."
            << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
  } catch (AForm::GradeTooLowException &l_g) {
    std::cout << l_g.what() << std::endl;
    std::cout << this->getName() << " couldn't execute " << form.getName()
              << " because grade " << form.getExecGrade()
              << " is required to execute this form." << std::endl;
    return;
  } catch (AForm::FormNotSignedException &n_s) {
    std::cout << n_s.what() << std::endl;
    std::cout << this->getName() << " couldn't execute " << form.getName()
              << " because " << form.getName() << " is not signed."
              << std::endl;
    return;
  }

  std::cout << this->getName() << " executed " << form.getName() << "."
            << std::endl;
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bur) {
  output << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "."
         << std::endl;

  return output;
}
