#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);

static char** dup_grid(int r, int c, char** grid) {
    char** out = (char**)malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        out[i] = (char*)malloc((c + 1) * sizeof(char));
        memcpy(out[i], grid[i], c);
        out[i][c] = '\0';
    }
    return out;
}

static char** full_grid(int r, int c) {
    char** out = (char**)malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        out[i] = (char*)malloc((c + 1) * sizeof(char));
        for (int j = 0; j < c; j++) out[i][j] = 'O';
        out[i][c] = '\0';
    }
    return out;
}

static char** explode(int r, int c, char** grid) {
    int *clear = (int*)calloc(r * c, sizeof(int));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'O') {
                int idx = i * c + j;
                clear[idx] = 1;
                if (i > 0) clear[(i - 1) * c + j] = 1;
                if (i + 1 < r) clear[(i + 1) * c + j] = 1;
                if (j > 0) clear[i * c + (j - 1)] = 1;
                if (j + 1 < c) clear[i * c + (j + 1)] = 1;
            }
        }
    }
    char** out = full_grid(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (clear[i * c + j]) out[i][j] = '.';
        }
    }
    free(clear);
    return out;
}

char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
    int r = grid_count;
    int c = (int)strlen(grid[0]);
    *result_count = r;

    if (n == 1) return dup_grid(r, c, grid);
    if (n % 2 == 0) return full_grid(r, c);

    char** state3 = explode(r, c, grid);
    if (n % 4 == 3) return state3;

    char** state5 = explode(r, c, state3);
    for (int i = 0; i < r; i++) free(state3[i]);
    free(state3);
    return state5;
}

int main() {
    char** first_multiple_input = split_string(rtrim(readline()));
    int r = parse_int(*(first_multiple_input + 0));
    int c = parse_int(*(first_multiple_input + 1));
    int n = parse_int(*(first_multiple_input + 2));

    char** grid = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        char* grid_item = readline();
        *(grid + i) = grid_item;
    }

    int result_count;
    char** result = bomberMan(n, r, grid, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) return '\0';
    }
    if (data[data_length - 1] == '\n') data[data_length - 1] = '\0';
    return data;
}

char* ltrim(char* str) {
    if (!str) return '\0';
    while (*str != '\0' && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return '\0';
    if (!*str) return str;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    return value;
}
