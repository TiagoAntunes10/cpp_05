/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:57:35 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 18:36:31 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
public:
  AForm(void);
  AForm(const std::string name, short sign_grade, short exec_grade);
  AForm(const AForm &form);
  AForm &operator=(const AForm &form);
  ~AForm(void);
  std::string getName(void) const;
  bool getSignStatus(void) const;
  short getSignGrade(void) const;
  short getExecGrade(void) const;
  void beSigned(Bureaucrat const &bur);
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() throw();
  } high_except;

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() throw();
  } low_except;

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() throw();
  } not_signed_except;

private:
  std::string _name;
  bool _signed;
  short _sign_grade;
  short _exec_grade;
};

std::ostream &operator<<(std::ostream &output, AForm const &form);

#endif
