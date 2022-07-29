/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:37:29 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/12 19:20:03 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_putchar_len(char c);
size_t	ft_strlen(char	*str);
size_t	ft_putstr_len(char	*str);
size_t	ft_putnbr_len(int n);
int		ft_atoi(const char *str);

#endif
