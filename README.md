# Retreives the next line of a text file pointed to by a given file descriptor
A project done at [Codam](https://www.codam.nl/) Amsterdam.

# Specifications

1. Repeated calls (e.g., using a loop) to get_next_line should let
you read the text file pointed to by the file descriptor, one line at a time.

2. The function returns the line that was read.
If there is nothing else to read or if an error occurred, it returns NULL.

3. The returned line includes the terminating \n character,
except if the end of file was reached and does not end with a \n character.
