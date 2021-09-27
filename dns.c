/*************************************************************************
   LAB 1

    Edit this file ONLY!

 Implementation using double hashing
*************************************************************************/



#include "dns.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* domainName;
  IPADDRESS ip;
} ENTRY, * P_ENTRY;
const int SIZE = 13729;
DNSHandle InitDNS() {
  // IMPLEMENT ME =)
  DNSHandle entry = (unsigned int) (P_ENTRY) calloc(SIZE, sizeof(ENTRY));
  if ((P_ENTRY) entry != NULL) {
    return entry;
  }
  return INVALID_DNS_HANDLE;
}

unsigned int ROT13Hash(const char* str) {
  unsigned int hash = 0;

  for (; *str; ++str) {
    hash += (unsigned char) (*str);
    hash -= (hash << 13) | (hash >> 19);
  }
  return hash % SIZE;
}

unsigned int HashRS(const char* s) {
  unsigned int hash = 0;
  unsigned int A = 63689;
  unsigned int B = 378551;
  for (; *s; ++s) {
    hash = hash * A + *s;
    A *= B;
  }
  return hash % (SIZE - 1) + 1;
}

void AddAddress(DNSHandle hDNS, IPADDRESS ip, const char* name) {
  unsigned int idx = ROT13Hash(name);
  unsigned int step = HashRS(name);

  while (((P_ENTRY) hDNS)[idx].domainName != NULL) {
    idx = (idx + step);
    if (idx >= SIZE) {
      idx -= SIZE;
    }
  }
  ((P_ENTRY) hDNS)[idx].domainName = (char*) malloc(strlen(name) + 1);
  strcpy(((P_ENTRY) hDNS)[idx].domainName, name);
  ((P_ENTRY) hDNS)[idx].ip = ip;
}

void LoadHostsFile(DNSHandle hDNS, const char* hostsFilePath) {
  FILE* input = fopen(hostsFilePath, "r");
  if (input == NULL) {
    return;
  }
  unsigned int ip1 = 0, ip2 = 0, ip3 = 0, ip4 = 0;
  char* buffer = (char*) malloc(201);
  while (!feof(input)) {
    if (5 != fscanf_s(input, "%d.%d.%d.%d %s", &ip1, &ip2, &ip3, &ip4, buffer, 200))
      continue;
    IPADDRESS ip = (ip1 & 0xFF) << 24 |
        (ip2 & 0xFF) << 16 |
        (ip3 & 0xFF) << 8 |
        (ip4 & 0xFF);
    AddAddress(hDNS, ip, buffer);
  }
}

IPADDRESS DnsLookUp(DNSHandle hDNS, const char* hostName) {
  unsigned int idx = ROT13Hash(hostName);
  unsigned int step = HashRS(hostName);
  // P_ENTRY res = &((P_ENTRY) hDNS)[idx];
  int i = 0;
  while (i < SIZE) {
    //  printf_s("%s - %s\n", res->domainName, hostName);
    if (strcmp(((P_ENTRY) hDNS)[idx].domainName, hostName) == 0) {
      return ((P_ENTRY) hDNS)[idx].ip;
    }
    idx = (idx + step);
    if (idx >= SIZE) {
      idx -= SIZE;
    }
    ++i;
  }

  return INVALID_IP_ADDRESS;
}

void ShutdownDNS(DNSHandle hDNS) {
  for (int i = 0; i < SIZE; ++i) {
    free(((P_ENTRY) hDNS)[i].domainName);
  }
  free((P_ENTRY) hDNS);
}