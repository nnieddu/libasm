/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:38:20 by ninieddu   W       #+#    #+#             */
/*   Updated: 2020/10/28 19:38:33 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		main(void)
{
	char dest[100];
	printf("\n------------------------------------------------\n");
	printf("| ft_strlen |\n");
	printf("| ASM || C  |\n");
	printf("|  %ld  || %ld  |\n", ft_strlen(""), strlen(""));
	printf("|  %ld  || %ld  |\n", ft_strlen("1"), strlen("1"));
	printf("|  %ld  || %ld  |\n", ft_strlen("12345"), strlen("12345"));
	printf("|  %ld  || %ld  |\n", ft_strlen("123456789"), strlen("123456789"));

	printf("\n------------------------------------------------\n");

	printf("\n[ft_strcpy ASM]\n");
	printf("%s\n", ft_strcpy(dest, "test"));
	printf("%s\n", ft_strcpy(dest, "deuxiemetest"));
	printf("%s\n", ft_strcpy(dest, "et un petit troisieme"));
	printf("\n[strcpy  C]\n");
	printf("%s\n", strcpy(dest, "test"));
	printf("%s\n", strcpy(dest, "deuxiemetest"));
	printf("%s\n", strcpy(dest, "et un petit troisieme"));

	printf("\n------------------------------------------------\n");

	printf("\n[ft_strcmp ASM]\n");
	printf("%d\n", ft_strcmp("a", "aaaaaaaaaa"));
	printf("%d\n", ft_strcmp("a", "b"));
	printf("%d\n", ft_strcmp("aaaaaaaaaa", "a"));
	printf("\n\n[strcmp C]\n");
	printf("%d\n", strcmp("a", "aaaaaaaaaa"));
	printf("%d\n", strcmp("a", "b"));
	printf("%d\n", strcmp("aaaaaaaaaa", "a"));

	printf("\n------------------------------------------------\n");
	printf("%d\n", ft_strcmp("\x02", "\x01"));
	printf("%d\n", strcmp("\x02", "\x01"));
	printf("%d\n", ft_strcmp("bonjour", "onjour"));
	printf("%d\n", strcmp("bonjour", "onjour"));

	printf("\n------------------------------------------------\n");
	
	int ret;
	printf("\n[ft_write]\n\n");
	printf("\nft_write(1, \"negative count\", -15)");
	ret = ft_write(1, "negative count", -15);
	printf( "\nret = %d\n", ret);
	printf("errno = %d\n", errno);
	printf("%s\n", strerror(errno));
	errno = 0;
	
	printf("\nft_write(-1, \"file descriptore negatif\", 25)");
	ret = ft_write(-1, "file descriptore negatif", 25);
	printf( "\nret = %d\n", ret);
	printf("errno = %d\n", errno);
	printf("%s\n", strerror(errno));
	errno = 0;

	printf( "\nft_write(1, \"aaaaaaaaaaaaa\", 14)\n");
	ret = ft_write(1, "aaaaaaaaaaaaa", 14);
	printf("\nret = %d\n", ret);
	printf("errno = %d\n", errno);
	printf("%s\n", strerror(errno));
	errno = 0;


	printf("\n\n[Reel write]\n");
	printf("\nwrite(1, \"negative count\", -15)");
	ret = write(1, "negative count", -15);
	printf( "\nret = %d\n", ret);
	printf("errno = %d\n", errno);
	printf("%s\n", strerror(errno));
	errno = 0;

	printf("\nwrite(-1, \"file descriptore negatif\", 25)");
	ret = write(-1, "file descriptore negatif", 25);
	printf( "\nret = %d\n", ret);
	printf("errno = %d\n", errno);
	printf("%s\n", strerror(errno));
	errno = 0;

	printf( "\nwrite(1, \"aaaaaaaaaaaaa\", 14)\n");
	ret = write(1, "aaaaaaaaaaaaa", 14);
	printf("\nret = %d\n", ret);
	printf("errno = %d\n", errno);
	printf("%s\n", strerror(errno));
	errno = 0;

	printf("\n------------------------------------------------\n");

	printf("\n[ft_read]\n\n");
	int fd = open("test.txt", O_RDONLY);
	char buf[32 + 1];
	ret = ft_read(fd, buf, 320);
	printf("%s\n", buf);
	close(fd);
	printf("ret = %d\n", ret);
	printf("errno = %d\n", errno);
	printf("%s\n\n", strerror(errno));
	errno = 0;
	memset(buf, 0, 32);
	
	printf("%s\n", "Please type something to test (ft_read on fd 0) :");
	ret = ft_read(0, buf, 32);
	printf("%s", buf);
	printf("ret = %d\n", ret);
	printf("errno = %d\n", errno);
	printf("%s\n", strerror(errno));
	errno = 0;
	memset(buf, 0, 32);
	
	ret = ft_read(-2, buf, 32);
	printf("%s\n", buf);
	printf("ret = %d\n", ret);
	printf("errno = %d\n", errno);
	printf("%s\n", strerror(errno));

	printf("\n------------------------------------------------\n");

	printf("[ft_strdup ASM]\n");
	printf("%s\n", ft_strdup("Test"));
	printf("%s\n", ft_strdup("un autre"));
	printf("%s\n", ft_strdup(""));
	printf("%s\n", ft_strdup("un dernier apres le vide"));
	
	printf("\n[strdup C]\n");
	printf("%s\n", strdup("Test"));
	printf("%s\n", strdup("un autre"));
	printf("%s\n", strdup(""));
	printf("%s\n", strdup("un dernier apres le vide"));
}