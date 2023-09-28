#ifndef __CONNECT_H__
#define __CONNECT_H__

#include <stdint.h>

typedef char *String;

typedef struct _input
{
    String connectionAddress;
    String contextName;
    String groupName;
} Input;

typedef struct _output
{
    uint16_t port;
    String accessToken;
} Output;

void Connect(Input *input, Output *output);

#endif