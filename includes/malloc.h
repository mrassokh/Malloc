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
# define align8(x) (((((x)-1)>>3)<<3)+8)
# define MEMORY_DATA(m) (m ? (void *)((char*)m + BLOCK_SIZE) : NULL)
# define GET_BLOCK_POINTER(p) (p ? (void *)((char*)p - BLOCK_SIZE) : NULL)
# define TINY_ZONE getpagesize() * 12
# define SMALL_ZONE getpagesize() * 24
# define TINY_NUM 128
# define SMALL_NUM 128
# define MAX_TINY_BLOCK_SIZE (TINY_ZONE - TINY_NUM * BLOCK_SIZE) / TINY_NUM
# define MAX_SMALL_BLOCK_SIZE (SMALL_ZONE - SMALL_NUM * BLOCK_SIZE) / (SMALL_NUM * 10)


//# include <stdio.h>
#include <unistd.h>
# include <sys/mman.h>
#include <sys/resource.h>
//# include <unistd.h>
//# include <stdlib.h>
//# include "../libft/includes/libft.h"

typedef struct			s_block
{
	size_t				size;
	int					is_free;
	struct s_block		*next;
	struct s_block		*prev;
	int 				magic;
	//struct s_block		*this;
	//char 				data [1];
}						t_block;



//void					free_1(void *ptr);
//void 	*malloc_1(size_t size);
void					free(void *ptr);
void 					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
//void					*malloc_1(size_t size);
//void					*realloc_1(void *ptr, size_t size);
void					*calloc(size_t nitems, size_t size);
void 					show_alloc_mem();
void					hello();

t_block 				**memory_list();
t_block 				**tiny_segment();
t_block 				**small_segment();
t_block 				**memory_list_end();
t_block					*find_free_block(size_t size, t_block **last_block);
t_block 				*add_new_memory_block(size_t size,t_block *last_block);
void					split_free_block(t_block *memory, size_t size);
t_block 				*memory_fusion(t_block *memory);
t_block 				*get_block(void *ptr);
int 					valid_addr(void *ptr);
void 					initiate_new_block(t_block *new_block, size_t size);

void 					first_call_processing();
void					split_free_page(t_block *memory, size_t size);

char					*ft_itoa_base(uint64_t n, int base, int uppercase);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putchar(char c);
char	*ft_strrev(char *str);
size_t	ft_strlen(const char *s);

#endif
