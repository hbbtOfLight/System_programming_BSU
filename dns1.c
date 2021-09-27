/*************************************************************************
   LAB 1

    Edit this file ONLY!

 Implementation using chaining
*************************************************************************/

#include "dns.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ENTRY {
  char* domainName;
  IPADDRESS ip;
  struct ENTRY* next;
} ENTRY, * P_ENTRY;

const int SIZE = 13729;

DNSHandle InitDNS() {
  DNSHandle entry = (unsigned int) (P_ENTRY*) calloc(SIZE, sizeof(P_ENTRY));
  if ((P_ENTRY*) entry != NULL) {
    return entry;
  }
  return INVALID_DNS_HANDLE;
}

unsigned int modifiedROT13Hash(const char* str) {
  unsigned int hash = 0;
  for (; *str; ++str) {
    hash = hash + *str - (hash << 13) | (hash >> 19);
  }
  return hash % SIZE;
}

void AddAddress(DNSHandle hDNS, IPADDRESS ip, const char* name) {
  unsigned int idx = modifiedROT13Hash(name);
  P_ENTRY next = ((P_ENTRY*) hDNS)[idx];
  ((P_ENTRY*) hDNS)[idx] = malloc(sizeof(ENTRY));
  ((P_ENTRY*) hDNS)[idx]->domainName = (char*) malloc(strlen(name) + 1);
  strcpy(((P_ENTRY*) hDNS)[idx]->domainName, name);
  ((P_ENTRY*) hDNS)[idx]->ip = ip;
  ((P_ENTRY*) hDNS)[idx]->next = next;

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
  unsigned int idx = modifiedROT13Hash(hostName);
  P_ENTRY res = ((P_ENTRY*) hDNS)[idx];
  while (res != NULL && strcmp(res->domainName, hostName) != 0) {
    res = res->next;
  }
  if (res != NULL) {
    return res->ip;
  }

  return INVALID_IP_ADDRESS;
}

void FreeEntry(P_ENTRY e) {
  if (e != NULL) {
    FreeEntry(e->next);
    free(e->domainName);
    free(e);
  }
}

void ShutdownDNS(DNSHandle hDNS) {
  for (int i = 0; i < SIZE; ++i) {
    FreeEntry(((P_ENTRY*) hDNS)[i]);
  }
  free((P_ENTRY*) hDNS);
}