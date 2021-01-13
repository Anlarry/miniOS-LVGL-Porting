#define NULL 0

char* strcat(char *dst, const char *src)
{
    // assert(dst != NULL && src != NULL);
    char *temp = dst;
    while (*temp != '\0')
        temp++;
    while ((*temp++ = *src++) != '\0');

    return dst;
}


char *strncpy(char *dest,const char *str,int n)
{
	// assert((dest!=NULL)&&(str!=NULL));
	char *cp=dest;
	while(n&&(*cp++=*str++)!='\0')
	{
		n--;
	}
	if(n)
	{
		while(--n)
		*cp++='\0';
	}
	return dest;
}