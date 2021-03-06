#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include <windows.h>
#include "file.h"
#include "users.h"
#include "messaging.h"

#include <ws2tcpip.h>
#define EXIT_COMMAND    'e'

void print_info();

int main()
{
    users.cntr = 0;
    char command;
    print_info();

    _beginthread(message_listener, 0, NULL);

    while(1) {
        command = getch();

        if (command == EXIT_COMMAND)
            break;

        switch (command) {
            case 'h':
                print_info();
                break;
            case 'n':
                printf("Please enter your user name: \t");
                gets(this_user.name);
                this_user.port = 9319;
                printf("Your user name is: %s\n", this_user.name);
                break;
            case 'l':
                list_users();
                break;
            case 'm':
                send_message();
                break;
            default:
                printf("Unrecognized command.\n");
                break;
        }
    }
    return 0;
}

void print_info()
{
    printf("TOTORO CHAT\n");
    printf("====================\n");
    printf("Commands:\n");
    printf("h   Display this help info\n");
    printf("e   Exit\n");
    printf("n   Set user name\n");
    printf("l   List known users\n");
    printf("d   Send discovery request\n");
    printf("m   Send message\n");
    printf("l   Start logging\n");
}

