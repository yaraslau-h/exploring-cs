#include <stdio.h>
#include <stdalign.h>
#include <stddef.h>

struct TestStruct
{
    char c; // size = 1 byte
    int i;  // size = 4 bytes
};

int main()
{
    // Print size of struct
    printf("Size of TestStruct: %zu bytes\n", sizeof(struct TestStruct));
    // Print alignment requirement
    printf("Alignment of int: %zu\n", alignof(int));
    // Print offset of elements
    printf("Offset of c: %zu\n", offsetof(struct TestStruct, c));
    printf("Offset of i: %zu\n", offsetof(struct TestStruct, i));

    struct TestStruct a;

    // A padding of 3 bytes added after char to align int
    printf("a.c (char) = %lu\n", sizeof(a.c));
    printf("a.i (int) = %lu\n", sizeof(a.i));
    printf("whole struct takes %lu bytes\n", sizeof(a)); // = 1 + 3 pad bytes + 4 = 8 bytes

    return 0;
}
