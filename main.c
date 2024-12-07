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
#include <stdlib.h>

#define LEN 4

void	split_argv(char *str, int *arr);
int	**create_mat(void);
void    init_up_down(int *arr, int *arr_up, int *arr_down);
void    init_left_right(int *arr, int *arr_left, int *arr_right);
void    dest_mat(int **mat);
void	service(int *arr);
void	print_mat(int **mat);

int	main(int argc, char *argv[])
{
    int	arr[16];

    if (argc != 2)
    {
        write(2, "Invalid input\n", 14);
        exit (0);
    }
    split_argv(argv[1], arr);
	service(arr);
	return (0);
}

void	service(int *arr)
{
	int	arr_up[4];
	int	arr_down[4];
	int	arr_left[4];
	int	arr_right[4];
	int	**mat;

	init_up_down(arr, arr_up, arr_down);
	init_left_right(arr, arr_left, arr_right);
	mat = create_mat();

	print_mat(mat);

	dest_mat(mat);
}

//this function takes the string passed to argv[1] and splits it to craete a matrix
void    split_argv(char *str, int *arr)
{
	int	i;

	if (*str == '\0')
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
			exit (0);
		}
		str++;
	}
}

void    init_up_down(int *arr, int *arr_up, int *arr_down)
{
    int i;

    i = 0;
    while (i < 4)
    {
        arr_up[i] = arr[i];
        arr_down[i] = arr[i + 4];
    	++i;
    }
}

void    init_left_right(int *arr, int *arr_left, int *arr_right)
{
    int i;

    i = 0;
    while (i < 4)
    {
        arr_left[i] = arr[i + 8];
        arr_right[i] = arr[i + 12];
    	++i;
    }
}

int	**create_mat(void)
{
    int i;
    int**   arr;

    i = 0;
    arr = (int**)malloc(4 * sizeof(int*));
    while (i < 4)
    {
        arr[i] = (int*)malloc(4 * sizeof(int));
        ++i;
    }
	return (arr);
}

void    dest_mat(int **mat)
{
    int i;

    i = 0;
    while (i < 4)
    {
        free(mat[i]);
    	mat[i] = NULL;
    	++i;
    }

    free(mat);
	mat = NULL;
}

void	print_mat(int **mat)
{
	int	i;
	int j;
	char num;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			num = mat[i][j] + '0';
			write(1, &num, 1);
			++j;
		}
		write(1, "\n", 1);
		j = 0;
		++i;
	}
}