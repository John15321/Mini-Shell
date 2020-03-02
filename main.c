#include "stdio.h"

#define LSH_RL_BUFSIZE 1024

// Initialize/Configure at startup
// Interpret
// Terminate

char *lsh_read_line()
{
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(bufsize * sizeof(char));
    int c;

    if (buffer == NULL)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (1)
        {
            // Reading characters
            c = getchar();

            // If we hit EOF, replace it with a null character and return
            if (c == EOF || c == '\0')
            {
                buffer[position] = '\0';
                return buffer;
            }
            else
            {
                buffer[position] = c;
            }
            position++;

            // If we have exceeded the buffer, reallocate to gain more memory
            if (position >= bufsize)
            {
                bufsize += LSH_RL_BUFSIZE;
                buffer = realloc(buffer, bufsize);
                if (buffer == NULL)
                {
                    fprintf(stderr, "lsh: allocation error\n");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
}






void lsh_loop()
{
    char *line;  // our input line
    char **args; // args passed as input from input line
    int status;  // status of execution

    do
    {
        printf("> ");
        // Read
        line = lsh_read_line();
        // Parse
        args = lsh_split_line();
        // Execute
        status = lsh_execute(args);

        // Cleanup
        free(line);
        free(args);
    } while (status);
}

int main(int argc, char **argv)
{
    // Load config files if any

    // Command Loop
    // Read
    // Parse
    // Execute
    lsh_loop();

    // Terminate/Shutdown/Cleanup

    return EXIT_SUCCESS;
}