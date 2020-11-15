/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arannara <base1905@yandex.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:16:32 by lpressed          #+#    #+#             */
/*   Updated: 2020/10/11 19:16:34 by lpressed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libasm.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int			main(void)
{
	char	long_line[1000 + 1];
	int		i;
	char	long_line2[1000 + 1];
	char	long_s1[20];
	int		ft, s, fd;
	char	*str;
	char	buf1[100];
	char	buf2[100];
	char	*str1;
	char	*str2;

	printf("_________________________ft_strlen_________________________\n");
	printf("empty_line: %d\n", ft_strlen("") == strlen(""));
	printf("Hello_world: %d\n", ft_strlen("Hello_world") == strlen("Hello_world"));
	i = -1;
	while (++i < 1000)
		long_line[i] = '*';
	long_line[1000] = '\0';
	printf("Long line: %d\n", ft_strlen(long_line) == strlen(long_line));
	/*i = -1;
	while (++i < 2000)
		printf("%c", long_line[i]);*/
	printf("_________________________ft_strcpy_________________________\n");
	printf("empty_line: %d \n", ft_strcpy(long_s1, "") == strcpy(long_s1, ""));
	printf("Hello_world: %d \n", ft_strcpy(long_s1, "Hello_world") == strcpy(long_s1, "Hello_world"));
	bzero(long_line2, 1001);
	printf("Long line: %d\n", ft_strcpy(long_line, long_line2) == strcpy(long_line, long_line2));
	str = strdup("help");
	printf("_________________________ft_strcmp_________________________\n");
	printf("empty_lines: %d\n", ft_strcmp("", "") == strcmp("", ""));
	printf("2_line: %d\n", ft_strcmp(str, "") == strcmp(str, ""));
	printf("1_line: %d\n", ft_strcmp("", str) == strcmp("", str));
	printf("Hello_world: %d\n", ft_strcmp("Hello_world1", "Hello_world2") == strcmp("Hello_world1", "Hello_world2"));
	free(str);
	printf("_________________________ft_write__________________________\n");
	printf(" simple write: %d\n", ft_write(1, "TEST>", 5) == write(1, "TEST>", 5));
	fd = open("write.txt", O_WRONLY | O_TRUNC);
	ft = write(fd, "TEST1\n", 6);
	printf("write: %d\n", ft);
	close(fd);
	fd = open("ft_write.txt", O_WRONLY | O_TRUNC);
	s = ft_write(fd, "TEST1\n", 6);
	printf("ft_write: %d\n", s);
	close(fd);
	ft = write(222, "test", 4);
	printf("fd = 222: %s\n", strerror(errno));
	printf("ret_val: %d\n", ft);
	printf("_________________________ft_read___________________________\n");
	bzero(buf1, 100);
	bzero(buf2, 100);
	ft = ft_read(0, buf1, 100);
	printf("ft_read: %d ", ft);
	printf("%s|\n", buf1);
	s = read(0, buf2, 100);
	printf("my read: %d ", s);
	printf("%s|\n", buf2);
	bzero(buf1, 100);
	bzero(buf2, 100);
	fd = open("write.txt", O_RDONLY);
	ft = ft_read(fd, buf1, 100);
	printf("ft_read: %d ", ft);
	printf("%s|\n", buf1);
	close(fd);
	fd = open("ft_write.txt", O_RDONLY);
	s = read(fd, buf2, 100);
	printf("my read: %d ", s);
	printf("%s|\n", buf2);
	close(fd);
	bzero(buf1, 100);
	bzero(buf2, 100);
	ft = ft_read(222, buf1, 100);
	printf("fd = 222: %s\n", strerror(errno));
	printf("ret_val: %d\n", ft);
	printf("_________________________ft_strdup_________________________\n");
	str1 = strdup(" ");
	printf("str1: %s\n", str1);
	str1[0] = 'F';
	printf("str1: %s\n", str1);
	free(str1);
	str2 = ft_strdup(" ");
	printf("str2: %s\n", str2);
	str2[0] = 'F';
	printf("str2: %s\n", str2);
	free(str2);
	str1 = strdup("Hello World!");
	printf("\nstr1: %s\n", str1);
	str1[0] = 'B';
	printf("str1: %s\n", str1);
	free(str1);
	str2 = ft_strdup("Hello World!");
	printf("str2: %s\n", str2);
	str2[0] = 'B';
	printf("str2: %s\n", str2);
	free(str2);
	i = -1;
	while (++i < 200)
		long_line[i] = '*';
	long_line[200] = '\0';
	str1 = strdup(long_line);
	printf("str1: %s\n", str1);
	str1[0] = 'D';
	printf("str1: %s\n", str1);
	free(str1);
	str2 = ft_strdup(long_line);
	printf("str2: %s\n", str2);
	str2[0] = 'D';
	printf("str2: %s\n", str2);
	free(str2);
}
