/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:37:32 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/12 19:19:53 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_putchar_len(char c);
size_t	ft_strlen(char	*str);
size_t	ft_putstr_len(char	*str);
size_t	ft_putnbr_len(int n);

#endif
