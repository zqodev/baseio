#include <stdio.h>

#include "string.h"
#include "utils.h"

int main() {
    char buffer[] = "hello world";

    capitalize(buffer);

    printf("%s", buffer);

    return 0;
}