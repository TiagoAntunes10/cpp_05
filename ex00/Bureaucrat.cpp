/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:30:40 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/21 10:56:26 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/includes.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "grade exceeds upper bound.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade exceeds lower bound.";
}

Bureaucrat::Bureaucrat(void) {
  _name = "Bob";
  _grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, short grade) {
  _name = name;
  if (grade > 150)
    throw low_except;
  else if (grade < 1)
    throw high_except;
  _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bur) {
  _name = bur._name;
  _grade = bur._grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bur) {
  if (_name.empty())
    _name = bur._name;
  _grade = bur._grade;

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

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bur) {
  output << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "."
         << std::endl;

  return output;
}
