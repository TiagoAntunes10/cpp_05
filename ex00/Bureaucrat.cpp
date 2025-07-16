/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:30:40 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/16 17:37:16 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/includes.hpp"

const char *GradeTooHighException::what() throw() {
  return "Grade exceeds upper bound.";
}

const char *GradeTooLowException::what() throw() {
  return "Grade exceeds lower bound.";
}

Bureaucrat::Bureaucrat(void) {
  _name = "Bob";
  _grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, short grade) {
  _name = name;
  if (grade > 150)
    throw high_excep;
  else if (grade < 1)
    throw low_excep;
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) {
  _name = bur._name;
  _grade = bur._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bur) {
  _name = bur._name;
  _grade = bur._grade;

  return (*this);
}

Bureaucrat::~Bureaucrat(void) { return; }

std::string Bureaucrat::get_name(void) const { return _name; }

short Bureaucrat::get_grade(void) const { return _grade; }

void Bureaucrat::inc_grade(short inc) {
  _grade -= inc;
  if (_grade < 1) {
    throw high_excep;
    _grade += inc;
  }
}

void Bureaucrat::dec_grade(short dec) {
  _grade += dec;
  if (_grade > 150) {
    throw low_excep;
    _grade -= dec;
  }
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bur) {
  output << bur.get_name() << ", bureaucrat grade " << bur.get_grade() << "."
         << std::endl;

  return output;
}
