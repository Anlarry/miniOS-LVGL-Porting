void pthread_test1()
{
$$$$for(int i = 0; i < 10; i++) {
$$$$$$$$printf("%d ", global++);
$$$$}
}
int main(int arg,char *argv[])
{
$$$$int i=0;
$$$$int stdin = open("dev_tty0",O_RDWR);
$$$$int stdout= open("dev_tty0",O_RDWR);
$$$$int stderr= open("dev_tty0",O_RDWR);
$$$$pthread(pthread_test1);
$$$$printf("pthread Test\n");
$$$$for(int i = 0; i < 10; i++) {
$$$$$$$$printf("%d ", global++);
$$$$}
$$$$return 0;
}
