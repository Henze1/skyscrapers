/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:42:52 by hpodratc          #+#    #+#             */
/*   Updated: 2024/12/07 18:04:49 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define LEN 4

void	split_argv(char *str, int *arr_up, int *arr_down, int *arr_left, int *arr_right);
int	**create_matrix(void);
void	delete_matrix(int **mat);

int	main(int argc, char *argv[])
{
	int	arr_up[LEN];
	int	arr_down[LEN];
	int	arr_left[LEN];
	int	arr_right[LEN];

	split_argv(argv[1], arr_up, arr_down, arr_left, arr_right);

	return (0);
}

//this function takes the string passed to argv[1] and splits it to craete a matrix
void	split_argv(char *str, int *arr_up, int *arr_down, int *arr_left, int *arr_right)
{
	int	arr[16];
	int	i;

	if (str == '\0')
		return ;
	i = 0;
	while (*str)
	{
		if (*str > '0' && *str <= '4')
		{
			arr[i] = *str - '0';
			i++;
		}
		else if (*str != ' ')
		{
			write(2, "Invalid input\n", 14);
			return ;
		}
		str++;
	}
	i = 0;
	while (i < LEN)
	{
		*(arr_up + i) = arr[i];
		*(arr_down + i) = arr[i + 4];
		*(arr_left + i) = arr[i + 8];
		*(arr_right + i) = arr[i + 12];
		++i;
	}
}

int	**create_matrix(void)
{
	int	i;
	int **mat;

	i = 0;
	mat = (int**)malloc(LEN * sizeof(int*));
    while (i < r)
	{
        arr[i] = (int*)malloc(LEN * sizeof(int));
		++i;
	}

	return (mat);
}

void	delete_matrix(int **mat)
{
	int	i;

	i = 0;
	while (i < LEN)
	{
		free(*(mat + i));
		*(mat + i) = NULL;
		++i;
	}

	free(mat);
	mat = NULL;
}
