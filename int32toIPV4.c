#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void uint32_to_ip (uint32_t number, char *IPv4)
{
  char ipString[16];
  sprintf(ipString, "%d.%d.%d.%d",
    (number >> 24) & 0xFF, (number >> 16) & 0xFF,
    (number >> 8) & 0xFF,  number & 0xFF
  );
  memcpy(IPv4, ipString, 16);
}



