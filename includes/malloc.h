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
# define ALLIGN8(x) (((((x)-1)>>3)<<3)+8)
# define MEMORY_DATA(m) (m ? (void *)((char*)m + BLOCK_SIZE) : NULL)
# define GET_BLOCK_POINTER(p) (p ? (void *)((char*)p - BLOCK_SIZE) : NULL)
# define PAGE_SIZE getpagesize()
# define TINY_ZONE_MULT 40
# define SMALL_ZONE_MULT 40
# define TINY_ZONE PAGE_SIZE * TINY_ZONE_MULT
# define SMALL_ZONE PAGE_SIZE * SMALL_ZONE_MULT
# define TINY_N 480
# define SMALL_N 200
# define MAX_TINY_BLOCK_SIZE (TINY_ZONE - TINY_N * BLOCK_SIZE) / TINY_N
# define MAX_SMALL_BLOCK_SIZE (SMALL_ZONE - SMALL_N * BLOCK_SIZE) / (SMALL_N )

# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>

typedef struct			s_block
{
	size_t				size;
	int					is_free;
	struct s_block		*next;
	struct s_block		*prev;
	int					magic;
}						t_block;

typedef struct			s_memory_list
{
	t_block				*memory_begin;
	t_block				*tiny_segment;
	t_block				*small_segment;
	t_block				*large_segment;
	t_block				*memory_list_end;
	int					count;
}						t_memory;

void					free(void *ptr);
void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					*calloc(size_t nitems, size_t size);
void					show_alloc_mem();

void					print_block_info(t_block *cursor);
void					print_segment_header(t_block *cursor);

t_memory				*memory_list();
t_block					**memory_begin();
t_block					**tiny_segment();
t_block					**small_segment();
t_block					**large_segment();
t_block					**memory_end();

t_block					*memory_allocate(size_t size, t_block *last_block);
t_block					*find_free_block(size_t size, t_block **last_block);
t_block					*add_new_memory_block(size_t size, t_block *last_block);

void					split_free_page(t_block *memory, size_t size);
void					split_free_block(t_block *memory, size_t size);
t_block					*memory_fusion(t_block *memory);
int						valid_addr(void *ptr);
void					initiate_new_block(t_block *new_block, size_t size);
void					initiate_split_block(t_block *memory,
										t_block *new_memory_block, size_t size);

void					first_call_processing();
void					preallocate_free_check();

char					*ft_itoa_base(uint64_t n, int base, int uppercase);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putchar(char c);
char					*ft_strrev(char *str);
size_t					ft_strlen(const char *s);

#endif
