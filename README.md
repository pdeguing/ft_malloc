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

# Implementation
- Memory management is done via the system calls `mmap(2)` and `mmunmap(2)`.
- In order to optimize the number of systam calls and to save time, requests for
  memory are divided in three categories: tiny, small and large.
- The memory is mapped in three types of zones, one for each categories. Upon
  request, for a tiny or small allocation, we first check the corresponding
  linked list of zones and try to find an empty chunk. If no chunk is found, we
  map a new zone for this category, add it to the corresponding list, and return
  a chunk of it.
- A large request will be considered as its own zone and will be store in a list
  of large zones. The current implementation will not try to reuse those zones
  when it would be possible, we will map a new zone every time and unmap it on
  freeing. This could be improved by keeping a freelist of large zones and
  dividing them when possible.
- Defragmentation is implemented in order to avoid mapping new zones when it is
  not necessary. It runs at allocation time. If a zone has enough free memory to
  fit the current request and yet the request fails, we will assume memory is
  fragmented and run through the zone to merge all blocks when possible. 
