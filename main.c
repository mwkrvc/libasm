
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define KGRN "\x1B[32m"
#define KNRM  "\x1B[0m"
#define BUF_S (1 << 12)
#define BUF_R (1 << 12)

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, char *src);
ssize_t ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s1);

int main()
{
	char buf[BUF_S] = {0};
	char buf1[BUF_R] = {0};
	char buf2[BUF_R] = {0};
	int fd = open("test.txt", O_RDONLY);

	printf("%sft_strdup", KGRN);
	printf("%s\n", KNRM);
	printf("ft: %s\n", ft_strdup(""));
	printf("or: %s\n", strdup(""));
	printf("ft: %s\n", ft_strdup("abc"));
	printf("or: %s\n", strdup("abc"));
	printf("ft: %s\n", ft_strdup("haha"));
	printf("or: %s\n", strdup("haha"));
	printf("ft: %s\n", ft_strdup(NULL));
//	printf("or: %s\n", strdup(NULL));
	
	
	printf("%sft_write", KGRN);
	printf("%s\n", KNRM);

	ft_write(1, "haha\n", 5);
	printf("%s\n", strerror(errno));
	write(1, "haha\n", 5);
	printf("%s\n", strerror(errno));
	ft_write(8, "haha\n", 5);
	printf("%s\n", strerror(errno));
	write(8, "haha\n", 5);
	printf("%s\n", strerror(errno));

	printf("%sft_strcpy\n", KGRN);
	
	printf("%sft:%s\n", KNRM, ft_strcpy(buf, ""));
	printf("or: %s\n", strcpy(buf, ""));
	printf("ft: %s\n", ft_strcpy(NULL, "abc"));
//	printf("or: %s\n", strcpy(NULL, "abc"));
	printf("ft: %s\n", ft_strcpy(buf, NULL));
//	printf("or: %s\n", strcpy(buf, NULL));
	printf("ft: %s\n", ft_strcpy(buf, "abc"));
	printf("or: %s\n", strcpy(buf, "abc"));
	printf("ft: %s\n", ft_strcpy(buf, "asl;fjl;asdjfjkasdl;fjadjsf"));
	printf("or: %s\n", strcpy(buf , "asl;fjl;asdjfjkasdl;fjadjsf"));
	printf("ft: %s\n", ft_strcpy(buf, "yope\0la"));
	printf("or: %s\n", strcpy(buf, "yope\0la"));
	
	printf("%sft_strcmp\n", KGRN);
	
	printf("%sft: %d\n", KNRM,  ft_strcmp("", ""));
	printf("or: %d\n", strcmp("", ""));
	printf("ft: %d\n", ft_strcmp("Lorem ipsum dolor st amet, consectetur adipiscing", "Lodsfsdfasdf"));
	printf("or: %d\n", strcmp("Lorem ipsum dolor st amet, consectetur adipiscing", "Lodsfsdfasdf"));
	printf("ft: %d\n", ft_strcmp("haha", "kek"));
	printf("or: %d\n", strcmp("haha", "kek"));
	printf("ft: %d\n", ft_strcmp("haha", "haha"));
	printf("or: %d\n", strcmp("haha", "haha"));
	printf("ft: %d\n", ft_strcmp("lol", "kek"));
	printf("or: %d\n", strcmp("lol", "kek"));
	printf("ft: %d\n", ft_strcmp("", "haha"));
	printf("or: %d\n", strcmp("", "haha"));
	printf("ft: %d\n", ft_strcmp("haha", ""));
	printf("or: %d\n", strcmp("haha", ""));
	printf("ft: %d\n", ft_strcmp("aaaa", "aaaz"));
	printf("or: %d\n", strcmp("aaaa", "aaaz"));

	printf("%sft_strlen\n", KGRN);
	
	printf("%sft: %zu\n",KNRM, ft_strlen(""));
	printf("or: %zu\n", strlen(""));
	printf("ft: %zu\n", ft_strlen("HAHA"));
	printf("or: %zu\n", strlen(""));
	printf("ft: %zu\n", ft_strlen("12345678901234567890123456789012345678901234567890"));
	printf("or: %zu\n", strlen("12345678901234567890123456789012345678901234567890"));

	printf("%sft_read\n", KGRN);
	printf("%sft: %zd\n", KNRM, ft_read(fd, buf1, 10));
	printf("%s\n", buf1);
}
