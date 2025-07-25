/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:56:58 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/21 11:13:42 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/includes.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low.";
}

const char *AForm::FormNotSignedException::what() const  throw() {
  return "The form is not signed.";
}

AForm::AForm(void) {
  _name = "Bill";
  _signed = false;
  _sign_grade = 150;
  _exec_grade = 150;
}

AForm::AForm(const std::string name, short sign_grade, short exec_grade) {
  _name = name;
  _signed = false;
  if (sign_grade > 150 || exec_grade > 150)
    throw low_except;
  else if (sign_grade < 1 || exec_grade < 1)
    throw high_except;
  _sign_grade = sign_grade;
  _exec_grade = exec_grade;
}

AForm::AForm(const AForm &form) {
  _name = form.getName();
  _signed = false;
  _sign_grade = form.getSignGrade();
  _exec_grade = form.getExecGrade();
}

AForm &AForm::operator=(const AForm &form) {
  if (_name.empty()) {
    _name = form.getName();
    _signed = false;
    _sign_grade = form.getSignGrade();
    _exec_grade = form.getExecGrade();
  }

  return (*this);
}

AForm::~AForm(void) { return; }

std::string AForm::getName(void) const { return _name; }

bool AForm::getSignStatus(void) const { return _signed; }

short AForm::getSignGrade(void) const { return _sign_grade; }

short AForm::getExecGrade(void) const { return _exec_grade; }

void AForm::beSigned(Bureaucrat const &bur) {
  if (this->getSignGrade() >= bur.getGrade())
    this->_signed = true;
  else
    throw low_except;
}

std::ostream &operator<<(std::ostream &output, AForm const &form) {
  output << form.getName() << ", form signing grade " << form.getSignGrade()
         << " and execution grade " << form.getExecGrade() << ", is ";

  if (form.getSignStatus())
    output << "signed.";
  else
    output << "not signed.";

  output << std::endl;

  return output;
}
