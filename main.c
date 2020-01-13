#include <stdio.h>
#include <string.h>

/* cow example
     \  ^__^
      \ (oo)\______
        (__)\      )\/\
            ||---w |
            ||    ||
*/

typedef struct {
    char *name;
    char *body;
} figure_t;

figure_t supported_figures[4] = {
    (figure_t) {
        .name = "cow",
        .body = "\n\
        \\  ^__^              \n\
         \\ (oo)\\______      \n\
           (__)\\      )\\/\\ \n\
               ||---w |       \n\
               ||    ||       \n",
    },
    (figure_t) {
        .name = "tux",
        .body = "\n\
        \\           \n\
         \\          \n\
           .--.      \n\
          |o_o |     \n\
          |:_/ |     \n\
         //   \\ \\  \n\
        (|     | )   \n\
       /'\\_   _/'\\ \n\
       \\___)=(___/  \n",
    },
    (figure_t) {
        .name = "dino",
        .body = "\n\
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
                     |_____|        |_____|         ~ - . _ _ _ _ _> \n",
    },
    (figure_t) {
        .name = "head",
        .body = "\n\
        \\                                    \n\
         \\                                   \n\
           ^__^         /                     \n\
           (oo)\\_______/  _________          \n\
           (__)\\       )=(  ____|_ \\_____   \n\
               ||----w |  \\ \\     \\_____ | \n\
               ||     ||   ||           ||    \n",
    }
};

// flags
figure_t *figure_f = &supported_figures[0];
int help_f = 0;


void print_usage() {
    printf("Usage: cowsay [FLAGS] args...\n\n");
    printf("Flags:\n");
    printf("\t-h help: show usage\n");
    printf("\t-f figure: choose from one of the available figures to say the words\n");
    printf("\t\tcow\n");
    printf("\t\tdino\n");
    printf("\t\ttux\n");
    printf("\t\thead\n");
}

void ruler(int l) {
    printf(" ");
    for (int i = 0; i < l+2; i++)
        printf("_");
    printf(" \n");
}

int starts_with(const char *str, const char *s) {
    if (strlen(s) > strlen(str)) {
        return 0;
    }

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != str[i]) {
            return 0;
        }
    }

    return 1;
}

int parse_flags(int argc, char **argv) {
    int i;
    for (i = 1; i < argc; i++) {
        char *param = argv[i];
        if (starts_with(param, "-")) {
            param++;
        } else {
            break;
        }

        if (starts_with(param, "h")) {
            help_f = 1;
        }

        if (starts_with(param, "f=")) {
            param+=2;
            for (int j = 0; j < sizeof(supported_figures)/sizeof(supported_figures[0]); j++) {
                if (!strcmp(param, (const char *) supported_figures[j].name)) {
                    figure_f = &supported_figures[j];
                    break;
                }
            }
        }
    }

    return i;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage();
        return 0;
    }

    int n_flags = parse_flags(argc, argv);
    argv += n_flags;

    if (help_f) {
        print_usage();
        return 0;
    }

    int l = strlen(argv[0]);
    ruler(l);
    printf("\n< %s >\n", argv[0]);
    ruler(l);
    printf("%s\n", figure_f->body);

    return 0;
}
