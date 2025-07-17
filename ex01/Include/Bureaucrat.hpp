/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:54:22 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/16 22:38:59 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>

class Form;

class Bureaucrat {
public:
  Bureaucrat(void);
  Bureaucrat(const std::string name, short grade);
  Bureaucrat(const Bureaucrat &bur);
  Bureaucrat &operator=(const Bureaucrat &bur);
  ~Bureaucrat(void);
  std::string getName(void) const;
  short getGrade(void) const;
  void incGrade(short inc);
  void decGrade(short dec);
  void signForm(Form &form);

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
  short _grade;
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bur);

#endif
