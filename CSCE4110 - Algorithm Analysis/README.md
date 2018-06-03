Justin Wei  
JustinWei@my.unt.edu  

COMPILE:
make

RUN:
./main.out <filename>

EXAMPLE
./main.out graphs/graph_10

OUTPUT:

In file "OUTPUT":

file: graphs/graph_10
Cost Matrix:
0 86 49 89 34 34 22 61 69 76
33 0 88 44 48 53 53 81 69 31
83 1 0 74 34 5 4 33 75 58
38 19 65 0 10 56 66 50 89 99
71 2 20 98 0 34 7 93 33 11
45 65 80 28 48 0 80 1 33 36
4 65 63 14 55 81 0 78 64 88
43 13 28 94 35 29 13 0 85 14
71 77 99 33 74 63 12 1 0 62
43 1 95 79 56 11 41 69 65 0

Dijkstra -- 0.000027 seconds
0 36 49 36 34 34 22 35 67 45
33 0 68 44 48 42 53 43 69 31
8 1 0 18 28 5 4 6 38 20
21 12 30 0 10 32 17 33 43 21
11 2 20 21 0 22 7 23 33 11
18 14 29 28 36 0 14 1 33 15
4 26 44 14 24 38 0 39 57 35
17 13 28 27 35 25 13 0 58 14
16 14 29 26 36 26 12 1 0 15
29 1 40 39 47 11 25 12 44 0

Floyd Warshall -- 0.000021 seconds
0 36 49 36 34 34 22 35 67 45
33 0 68 44 48 42 53 43 69 31
8 1 0 18 28 5 4 6 38 20
21 12 30 0 10 32 17 33 43 21
11 2 20 21 0 22 7 23 33 11
18 14 29 28 36 0 14 1 33 15
4 26 44 14 24 38 0 39 57 35
17 13 28 27 35 25 13 0 58 14
16 14 29 26 36 26 12 1 0 15
29 1 40 39 47 11 25 12 44 0