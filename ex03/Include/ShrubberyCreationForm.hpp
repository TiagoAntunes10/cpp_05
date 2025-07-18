/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:24:05 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/17 17:41:00 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUB_HPP
#define SHRUB_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(std::string const target);
  ShrubberyCreationForm(ShrubberyCreationForm const &form);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);
  ~ShrubberyCreationForm(void);
  void execute(Bureaucrat const &executor) const;

private:
  std::string _target;
};

#endif
