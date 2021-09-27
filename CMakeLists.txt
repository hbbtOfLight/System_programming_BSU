cmake_minimum_required(VERSION 3.20)
project(dns_server C)

set(CMAKE_C_STANDARD 11)

add_executable(dns_server main.c dns1.c)
