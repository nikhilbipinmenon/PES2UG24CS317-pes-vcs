#include "pes.h"
#include <stdio.h>
#include <string.h>
// Forward declaration
int object_write(ObjectType type, const void *data, size_t len, ObjectID *id_out);
int main() {
    const char *data = "hello world";
    ObjectID id;

    if (object_write(OBJ_BLOB, data, strlen(data), &id) != 0) {
        printf("Write failed\n");
        return 1;
    }

    char hex[HASH_HEX_SIZE + 1];
    hash_to_hex(&id, hex);

    printf("Object written with hash: %s\n", hex);
    return 0;
}
