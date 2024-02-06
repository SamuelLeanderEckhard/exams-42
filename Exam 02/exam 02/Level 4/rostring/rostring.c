#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int start;
    int end;
    if (argc > 1 && argv[1][0])
    {
        i = 0;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        start = i;
        while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        end = i;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while(argv[1][i]) 
        {
        	if (argv[1][i] != ' ' && argv[1][i] != '\t')
     		{
        		write(1, &argv[1][i], 1);
        		if (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\t' || argv[1][i + 1] == '\0')
        			write(1, " ", 1);
        	}
        	i++;
        }
        while (start < end)
        {
            write(1, &argv[1][start++], 1);
        }
    }
    write(1, "\n", 1);
    return(0);
}
