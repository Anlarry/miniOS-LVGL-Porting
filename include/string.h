
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            string.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void*	memcpy(void* p_dst, void* p_src, int size);
void	memset(void* p_dst, char ch, int size);
char*	strcpy(char* p_dst, char* p_src);

//added by zcr
int	strlen(char* p_str);
#define	phys_copy	memcpy
#define	phys_set	memset
