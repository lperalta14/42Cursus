void ft_ana(int *a, int *b)
{


}

int main(int argc, char **argv)
{
	printf("arg1 :%d, arg2 :%d\n", atoi(argv[1]), atoi(argv[2]));
	ft_ana(atoi(argv[1]), (atoi(argv[2])));
	printf("arg1 :%d, arg2 :%d\n", atoi(argv[1]), atoi(argv[2]));
	return(0);
}