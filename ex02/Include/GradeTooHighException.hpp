/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:08:22 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/16 22:09:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_HIGH_HPP
#define GRADE_HIGH_HPP

#include <exception>

class GradeTooHighException : public std::exception {
public:
  virtual const char *what() throw();
};

#endif
