#!/usr/bin/python3

from heapq import heappop, heappush

def heap_sort(array):
    heap = []
    for element in array:
        heappush(heap, element)

    ordered = []

    while heap:
        ordered.append(heappop(heap))

    return ordered

array = [1,3,2,5,7,6,8,10,9]
print(heap_sort(array))
