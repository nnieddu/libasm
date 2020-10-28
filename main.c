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
	printf("%d\n", ft_strcmp("a", "a"));
	printf("%d\n", ft_strcmp("aaaaaaaaaa", "a"));
	printf("\n\n[strcmp C]\n");
	printf("%d\n", strcmp("a", "aaaaaaaaaa"));
	printf("%d\n", strcmp("a", "a"));
	printf("%d\n", strcmp("aaaaaaaaaa", "a"));

	printf("\n------------------------------------------------\n");
	
	#define BUF 32
	int ret;
	printf("\n[ft_write]\n\n");
	dprintf(1, "\nft_write(1, \"truc\\n\", 5)\n");
	errno = 0;
	ret = ft_write(1, "truc\n", 5);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "errno = %d\n", errno);
	dprintf(1, "\nft_write(1, \"aaaaaaaaaaaaa\\n\", 5)\n");
	errno = 0;
	ret = ft_write(1, "aaaaaaaaaa   aaa\n", 17);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "errno = %d\n", errno);
	dprintf(1, "\nft_write(3, \"pouet\\n\", 5)\n");
	errno = 0;
	ret = ft_write(3, "pouet\n", 6);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "errno = %d\n", errno);
	dprintf(1, "\nwrite(3, \"pouet\\n\", 5)\n");
	ret = write(3, "pouet\n", 6);
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "errno = %d\n", errno);

	printf("\n------------------------------------------------\n");

	printf("\n[ft_read]\n\n");
	int fd = open("test.txt", O_RDONLY);
	char buf[BUF + 1];
	errno = 0;
	while ((ret = ft_read(fd, buf, BUF)) > 0)
	{
		buf[ret] = 0;
		dprintf(1, "%s\n", buf);
	}
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "errno = %d\n", errno);
	errno = 0;
	while ((ret = ft_read(42, buf, BUF)) > 0)
	{
		buf[ret] = 0;
		printf("%s", buf);
	}
	dprintf(1, "ret = %d\n", ret);
	dprintf(1, "errno = %d\n", errno);

	printf("\n------------------------------------------------\n");

	printf("[ft_strdup ASM]\n");
	printf("%s\n", ft_strdup("test"));
	printf("%s\n", ft_strdup("un autre"));
	printf("%s\n", ft_strdup(""));
	printf("%s\n", ft_strdup("un dernier apres le vide"));
	printf("\n[strdup C]\n");
	printf("%s\n", strdup("test"));
	printf("%s\n", strdup("un autre"));
	printf("%s\n", strdup(""));
	printf("%s\n", strdup("un dernier apres le vide"));
}
