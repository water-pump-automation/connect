#include "connect.h"

#include <stdio.h>
#include <string.h>

#define DEBUG

#define MAX_RETRIES 10
#define SUCCESS 0
#define FAIL 1

int main() {
    Input input;
    memset((Input*)&input, 0x0, sizeof(Input));

    input.ssid = "WIFI\0";
    input.password = "PASSWORD\0";

    if (Connect(MAX_RETRIES, &input) != connected) {
        printf("not connected!\n");
        return FAIL;
    }

    printf("connected!\n");
    return SUCCESS;
}