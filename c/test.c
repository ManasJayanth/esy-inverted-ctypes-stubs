#include <stdio.h>
#include <caml/callback.h>

#include "mylib.h"

int main(int argc, char **argv) {
    printf("mylib_fn_exported: %d\n", mylib_fn_exported());
    return 0;
}
