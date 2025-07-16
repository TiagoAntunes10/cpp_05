/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:54:22 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/16 17:37:33 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>

class Bureaucrat {
public:
  Bureaucrat(void);
  Bureaucrat(const std::string name, short grade);
  Bureaucrat(const Bureaucrat &bur);
  Bureaucrat &operator=(const Bureaucrat &bur);
  ~Bureaucrat(void);
  std::string get_name(void) const;
  short get_grade(void) const;
  void inc_grade(short inc);
  void dec_grade(short dec);

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
