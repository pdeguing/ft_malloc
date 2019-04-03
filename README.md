# ft_malloc
Implementation of dynamic memory allocation API to learn how it works.

# API
``` C
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	*calloc(size_t count, size_t size);
void	free(void *ptr);

void	show_alloc_mem(void); /* print a summary of allocated blocks */
```

# Usage & testing
Clone the dependencies and build the library:
```
make
```
Then run a program with the scrip to inject the library:
```
./run.sh program
```
You can also link with `libft_malloc.so`.
