#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000000

typedef struct History {
    char *snapshot;
    struct History *below;
} History;

History *saveState(History *top, const char *current) {
    History *node = (History *)malloc(sizeof(History));
    node->snapshot = strdup(current);
    node->below = top;
    return node;
}

History *revertState(History *top, char **prevText) {
    if (!top) return NULL;
    *prevText = top->snapshot;
    History *next = top->below;
    free(top);
    return next;
}

int main() {
    int queries;
    scanf("%d", &queries);

    char *text = (char *)calloc(LIMIT, sizeof(char));
    int length = 0;
    History *history = NULL;

    for (int q = 0; q < queries; q++) {
        int action;
        scanf("%d", &action);

        if (action == 1) {
            char word[LIMIT];
            scanf("%s", word);
            history = saveState(history, text);
            strcat(text, word);
            length = strlen(text);

        } else if (action == 2) {
            int cnt;
            scanf("%d", &cnt);
            history = saveState(history, text);
            length = strlen(text);
            if (cnt <= length) {
                text[length - cnt] = '\0';
                length -= cnt;
            }

        } else if (action == 3) {
            int pos;
            scanf("%d", &pos);
            if (pos >= 1 && pos <= length) {
                putchar(text[pos - 1]);
                putchar('\n');
            }

        } else if (action == 4) {
            char *old;
            history = revertState(history, &old);
            if (old) {
                strcpy(text, old);
                length = strlen(text);
                free(old);
            }
        }
    }

    free(text);
    return 0;
}
