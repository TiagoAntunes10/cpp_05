/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:07:49 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 14:24:05 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
public:
  Form(void);
  Form(const std::string name, short sign_grade, short exec_grade);
  Form(const Form &form);
  Form &operator=(const Form &form);
  ~Form(void);
  std::string getName(void) const;
  bool getSignStatus(void) const;
  short getSignGrade(void) const;
  short getExecGrade(void) const;
  void beSigned(Bureaucrat const &bur);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() throw();
  } high_except;

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() throw();
  } low_except;

private:
  std::string _name;
  bool _signed;
  short _sign_grade;
  short _exec_grade;
};

std::ostream &operator<<(std::ostream &output, Form const &form);

#endif
