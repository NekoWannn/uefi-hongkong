/* minimal libc bits the shim needs (freestanding build) */
typedef unsigned long size_t;

int
strcmp(const char *a, const char *b)
{
	while (*a && *a == *b) {
		a++;
		b++;
	}
	return (unsigned char)*a - (unsigned char)*b;
}

void *
memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d = dst;
	const unsigned char *s = src;

	while (n--) {
		*d++ = *s++;
	}
	return dst;
}

void *
memset(void *dst, int c, size_t n)
{
	unsigned char *d = dst;

	while (n--) {
		*d++ = (unsigned char)c;
	}
	return dst;
}
