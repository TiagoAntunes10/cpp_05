/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:30:40 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 14:33:23 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/includes.hpp"

const char *Form::GradeTooHighException::what() throw() {
  return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() throw() {
  return "Grade is too low.";
}

Form::Form(void) {
  _name = "Bill";
  _signed = false;
  _sign_grade = 150;
  _exec_grade = 150;
}

Form::Form(const std::string name, short sign_grade, short exec_grade) {
  _name = name;
  _signed = false;
  if (sign_grade > 150 || exec_grade > 150)
    throw low_except;
  else if (sign_grade < 1 || exec_grade < 1)
    throw high_except;
  _sign_grade = sign_grade;
  _exec_grade = exec_grade;
}

Form::Form(const Form &form) {
  _name = form.getName();
  _signed = false;
  _sign_grade = form.getSignGrade();
  _exec_grade = form.getExecGrade();
}

Form &Form::operator=(const Form &form) {
  if (_name.empty()) {
    _name = form.getName();
    _signed = false;
    _sign_grade = form.getSignGrade();
    _exec_grade = form.getExecGrade();
  }

  return (*this);
}

Form::~Form(void) { return; }

std::string Form::getName(void) const { return _name; }

bool Form::getSignStatus(void) const { return _signed; }

short Form::getSignGrade(void) const { return _sign_grade; }

short Form::getExecGrade(void) const { return _exec_grade; }

void Form::beSigned(Bureaucrat const &bur) {
  if (this->getSignGrade() >= bur.getGrade())
    this->_signed = true;
  else
    throw low_except;
}

std::ostream &operator<<(std::ostream &output, Form const &form) {
  output << form.getName() << ", form signing grade " << form.getSignGrade()
         << " and execution grade " << form.getExecGrade() << ", is ";

  if (form.getSignStatus())
    output << "signed.";
  else
    output << "not signed.";

  output << std::endl;

  return output;
}
