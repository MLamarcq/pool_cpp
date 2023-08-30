#include <iostream>

int is_digit(int c)
{
    if ((c >= 48 && c <= 57))
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEBACK NOISE *" << std::endl;
    if (argc > 1)
    {
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                if (is_digit(argv[i][j]) == 1)
                {
                    std::cout << "Only letters accpeted" << std::endl;
                    return (0);
                }
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    argv[i][j] = argv[i][j] - 32;
                j++;
            }
            std::cout << argv[i] << std::endl;
            i++;
        }
    }
    return (0);
}