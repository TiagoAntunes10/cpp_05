/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:08:22 by tialbert          #+#    #+#             */
/*   Updated: 2025/07/16 22:10:24 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_LOW_HPP
#define GRADE_LOW_HPP

#include <exception>

class GradeTooLowException : public std::exception {
public:
  virtual const char *what() throw();
};

#endif
