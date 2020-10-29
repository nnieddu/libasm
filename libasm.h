/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:33:02 by ninieddu          #+#    #+#             */
/*   Updated: 2020/10/29 10:14:07 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int		ft_read(int fd, void *buf, int count);
int		ft_write(int fd, const void *_buf, int nbytes);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *str);

#endif