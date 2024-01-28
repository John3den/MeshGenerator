#pragma once
// uploads data for vertices of icosahedron
// into array arr using counting function countFunc
#define A 0.5f
#define B G/2
#define ICOSAHEDRON(arr, countFunc) { {\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = B;\
        \
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        \
        \
        \
        \
        \
        \
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        arr[countFunc(0)] = -B;\
        \
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        arr[countFunc(0)] = -B;\
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = -A;\
        \
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
        arr[countFunc(0)] = 0;\
        arr[countFunc(0)] = A;\
        arr[countFunc(0)] = -B;\
        \
    }\
}
