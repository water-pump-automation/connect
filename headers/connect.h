#ifndef __CONNECT_H__
#define __CONNECT_H__

typedef char *String;

typedef enum _bool
{
    not_connected = 0,
    connected
} Conn;

typedef struct _input
{
    String ssid;
    String password;
} Input;


Conn Connect(int retries, Input *input);

#endif