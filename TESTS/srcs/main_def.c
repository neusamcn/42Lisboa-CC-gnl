/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_def.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:24:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/12/06 14:54:08 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*file;
	char	*line;
	int		fd;
	int		line_count;

	file = "TESTS/test.txt";
	fd = open(file, O_RDONLY);
	// file offset (mark of current position @ file) set to beginning of file.
	if (fd == -1)
		printf("fd = %d => cannot open '%s'\n", fd, file);
	else
		printf("fd = %d => '%s' opened successfully.\n----------\n", fd, file);
	line_count = 1;
	printf("\n***** 1st line: *****\n");
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 2
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 3
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 4
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 5
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 6
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 7
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 8
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 9
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 10
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 11
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 12
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 13
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 14
	printf("%s", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line %d: *****\n", ++line_count); // 15
	printf("%s\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	close(fd);
	return (0);
}
