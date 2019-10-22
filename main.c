#include <stdio.h>
#include <string.h>

/* cow without escaped characters
     \  ^__^
      \ (oo)\______
        (__)\      )\/\
            ||---w |
            ||    ||
*/

// believe it or not, this is a cow
char cow[] ="\n\
     \\  ^__^              \n\
      \\ (oo)\\______      \n\
        (__)\\      )\\/\\ \n\
            ||---w |       \n\
            ||    ||       \n";

char tux[] = "\n\
        \\           \n\
         \\          \n\
           .--.      \n\
          |o_o |     \n\
          |:_/ |     \n\
         //   \\ \\  \n\
        (|     | )   \n\
       /'\\_   _/'\\ \n\
       \\___)=(___/  \n";

char dino[] = "\n\
        \\                      .       .                            \n\
         \\                    / `.   .' \"                          \n\
          \\           .---.  <    > <    >  .---.                   \n\
           \\          |    \\  \\ - ~ ~ - /  /    |                 \n\
         _____           ..-~             ~-..-~                     \n\
        |     |   \\\\~~~\\.'                    `./~~~/             \n\
       ---------   \\__/                         \\__/               \n\
      .'  O    \\     /               /       \\  \"                 \n\
     (_____,    `._.'               |         }  \\/~~~/             \n\
      `----.          /       }     |        /    \\__/              \n\
            `-.      |       /      |       /      `. ,~~|           \n\
                ~-.__|      /_ - ~ ^|      /- _      `..-'           \n\
                     |     /        |     /     ~-.     `-. _  _  _  \n\
                     |_____|        |_____|         ~ - . _ _ _ _ _> \n";

char head_in_but[] = "\n\
        \\                                    \n\
         \\                                   \n\
           ^__^         /                     \n\
           (oo)\\_______/  _________          \n\
           (__)\\       )=(  ____|_ \\_____   \n\
               ||----w |  \\ \\     \\_____ | \n\
               ||     ||   ||           ||    \n";

void print_usage()
{
    printf("Usage: cowsay \"<your text goes here>\"\n");
}

void dashed_line(int l)
{
    printf(" ");
    for (int i = 0; i < l+2; i++)
        printf("_");
    printf(" \n");
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        print_usage();
        return 0;
    }

    int lsize = strlen(argv[1]);
    dashed_line(lsize);
    printf("\n");
    printf("< %s >\n", argv[1]);
    dashed_line(lsize);
    printf("%s\n", head_in_but);

    return 0;
}
