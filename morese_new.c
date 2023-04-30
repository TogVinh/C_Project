#include <stdio.h>
#include <string.h>

typedef struct
{
    char* morse;
    char* ascii;
} morse_table_t;

int main(void) {
    char input[] = ".- -... -.-.";

    morse_table_t table[] = { {".-", "A"},
                              {"-...", "B"},
                              {"-.-.", "C"}
/* TODO: Fill in the rest of the Morse Table Here */
    };

    char* segment;
    int i;
    segment = strtok(input, " ");

    while(segment)
    {
        for(i=0; i < sizeof(table); ++i)
        {
            if (!strcmp(segment, table[i].morse)) puts(table[i].ascii);
        }
        segment = strtok(NULL, " ");
    }

    return 0;
}