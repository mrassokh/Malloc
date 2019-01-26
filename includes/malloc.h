/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:44:53 by mrassokh          #+#    #+#             */
/*   Updated: 2019/01/06 13:44:54 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define BLOCK_SIZE sizeof(t_block)
# define align4(x) (((((x)-1)>>2)<<2)+4)
# define MEMORY_DATA(m) (m ? (void *)((char*)m + BLOCK_SIZE + 1) : NULL)

//# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

typedef struct			s_block
{
	size_t				size;
	int					is_free;
	struct s_block		*next;
	struct s_block		*prev;
}						t_block;


void					free(void *ptr);
void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					*calloc(size_t nitems, size_t size);
void					hello();

t_block 				**memory_list();
t_block					*find_free_block(size_t size, t_block *last_block);
t_block 				*add_new_memory_block(size_t size,t_block *last_block);
void					split_free_block(t_block *memory, size_t size);
void 					initiate_new_block(t_block *new_block, size_t size);
#endif
