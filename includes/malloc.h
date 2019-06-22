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
# define PAGE_SIZE getpagesize()
# define TINY_ZONE_MULT  40
# define SMALL_ZONE_MULT  4
# define TINY_ZONE PAGE_SIZE * TINY_ZONE_MULT
# define SMALL_ZONE PAGE_SIZE * SMALL_ZONE_MULT
# define TINY_NUM 480
# define SMALL_NUM 20//8
# define MAX_TINY_BLOCK_SIZE (TINY_ZONE - TINY_NUM * BLOCK_SIZE) / TINY_NUM
# define MAX_SMALL_BLOCK_SIZE (SMALL_ZONE - SMALL_NUM * BLOCK_SIZE) / (SMALL_NUM )//* 10)


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
//size_t 				count_1 = 1;
typedef struct			s_memory_list
{
	t_block 			*memory_begin;
	t_block 			*tiny_segment;
	t_block 			*small_segment;
	t_block 			*large_segment;
	t_block 			*memory_list_end;
	int 				count;
}						t_memory;


//void					free_1(void *ptr);
//void 	*malloc_1(size_t size);
void					free(void *ptr);
void 					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
//void					*malloc_1(size_t size);
//void					*realloc_1(void *ptr, size_t size);
void					*calloc(size_t nitems, size_t size);
void 					show_alloc_mem();
void 					print_block_info(t_block *cursor);
void 					print_segment_header(t_block *cursor);
//void					hello();

//t_block 				**memory_list();
t_memory			*memory_list();
t_block 				**memory_begin();
t_block 				**tiny_segment();
t_block 				**small_segment();
t_block 				**large_segment();
//t_block 				**memory_list_end();
t_block 				**memory_end();
t_block  				*memory_allocate(size_t size, t_block *last_block);//, int preallocate);
t_block					*find_free_block(size_t size, t_block **last_block);//, int preallocate);
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
char			*ft_itoa(int n);
char	*ft_strnew(size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);

#endif
