# Get Next Line Project

This project includes a function `get_next_line` that reads a line from a file descriptor.

## Files

- `get_next_line.c`: Contains the implementation of the `get_next_line` function.
- `get_next_line.h`: Contains the declaration of the `get_next_line` function and some utility functions.
- `get_next_line_bonus.c`: Contains the bonus implementation of the `get_next_line` function.
- `get_next_line_bonus.h`: Contains the bonus declaration of the `get_next_line` function and some utility functions.
- `get_next_line_utils.c`: Contains the implementation of some utility functions used by `get_next_line`.
- `get_next_line_utils_bonus.c`: Contains the bonus implementation of some utility functions used by `get_next_line`.

## Usage

To use the `get_next_line` function, include the `get_next_line.h` header file in your C file:

```c
#include "get_next_line.h"

Then, you can call the function like this:

char *line = get_next_line(fd);

Where fd is the file descriptor from which to read. The function will return a string containing the next line from the file, or NULL if there are no more lines.

```