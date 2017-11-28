#include <stdio.h>
#include <string.h>

/* cow without escaped characters
     \    ^__^
      \   (oo)\______
          (__)\      )\/\
              ||---w |
              ||    ||
 */

// believe it or not, this is a cow
char cow[] ="\n\
     \\    ^__^              \n\
      \\   (oo)\\______      \n\
          (__)\\      )\\/\\ \n\
              ||---w |       \n\
              ||    ||       \n";

void print_usage()
{
    printf("Usage: cowsay \"<something>\"\n");
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        print_usage();
        return 0;
    }

    // top line
    int ll = strlen(argv[1]);
    printf(" ");
    for (int i = 0; i < ll + 2; i++)
        printf("_");
    printf(" \n\n");

    // text
    printf("< %s >\n", argv[1]);

    // bottom line
    printf(" ");
    for (int i = 0; i < ll + 2; i++)
        printf("_");
    printf(" \n");

    // cow
    printf("%s\n", cow);

    return 0;
}
