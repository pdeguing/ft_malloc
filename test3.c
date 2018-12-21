#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define M (1024 * 1024)

void print(char *s)
{
write(1, s, strlen(s));
}

int main()
{
char *addr1;
char *addr3;

print("\n\n\n\n\n\n\n\n\n\ntest3: in\n");
print("test3: in\n");
addr1 = (char*)malloc(16*M);
print("test3: in\n");
print("test3: malloc passed\n");
if (addr1)
	strcpy(addr1, "Bonjours\n");
else
	print("addr1 = NULL\n");
print(addr1);
addr3 = (char*)realloc(addr1, 128*M);
print("test3: realloc passed\n");
addr3[127*M] = 42;
print(addr3);
return (0);
} 
