# Homework 3
# Justin Wei

### File:
```
  program_03.cpp
  binary_search_tree.h
  binary_search_tree.cpp
  lfsr.h
  lfsr.cpp
  data.txt
  data2.txt
  data3.txt
```

### Compile:
```
  g++ program_03.cpp lfsr.cpp binary_search_tree.cpp
```

### Run:
```
  ./a.out < data.txt
```


### Class Declarations:
```
  lfsr:
    lfsr class_name(seed)

  binary search tree:
    binary_search_tree class_name;
    binary_search_tree class_name(root_value);
```

### Sample Run 1:
```
  g++ program_03.cpp lfsr.cpp binary_search_tree.cpp
  ./a.out < data.txt
  generating random numbers...
  printing lfsr numbers
  seed: 221	11011101
  238	11101110
  247	11110111
  251	11111011
  253	11111101
  126	01111110
  191	10111111
  95	01011111
  175	10101111
  87	01010111
  43	00101011
  149	10010101
  74	01001010
  165	10100101
  210	11010010
  105	01101001
  180	10110100
  90	01011010
  173	10101101
  86	01010110

  printing tree:
  43 74 86 87 90 95 105 126 149 165 173 175 180 191 210 221 238 247 251 253
  tree height: 7
  node 251 height: 2
  degree of 251 is 2
  leaves: 253 210 180 173 105 90 86
  root: 221
  deleting 251.
  printing tree:
  43 74 86 87 90 95 105 126 149 165 173 175 180 191 210 221 238 247 253

  Searching for Node 253...
  ================
  Node 253 details:
  Parent: 247
  degree of 253 is 1
  node 253 height: 1
  ================


  Searching for Node 126...
  ================
  Node 126 details:
  Parent: 221
  degree of 126 is 3
  node 126 height: 6
  ================


  Searching for Node 191...
  ================
  Node 191 details:
  Parent: 126
  degree of 191 is 3
  node 191 height: 5
  ================
```


### Sample Run 2:
```
  g++ program_03.cpp lfsr.cpp binary_search_tree.cpp
  ./a.out < data2.txt
  generating random numbers...
  printing lfsr numbers
  seed: 255	11111111
  127	01111111
  63	00111111
  31	00011111
  143	10001111
  199	11000111
  99	01100011
  49	00110001
  24	00011000
  140	10001100
  70	01000110
  163	10100011
  81	01010001
  168	10101000
  84	01010100
  170	10101010
  85	01010101
  42	00101010
  21	00010101
  10	00001010

  printing tree:
  10 21 24 31 42 49 63 70 81 84 85 99 127 140 143 163 168 170 199 255
  tree height: 8
  node 31 height: 4
  degree of 31 is 3
  leaves: 170 140 85 42 10
  root: 255
  deleting 31.
  deleting 42.
  printing tree:
  10 21 24 42 49 63 70 81 84 85 99 127 140 143 163 168 170 199 255

  Searching for Node 143...
  ================
  Node 143 details:
  Parent: 127
  degree of 143 is 3
  node 143 height: 5
  ================


  Searching for Node 199...
  ================
  Node 199 details:
  Parent: 143
  degree of 199 is 2
  node 199 height: 4
  ================


  Searching for Node 99...
  ================
  Node 99 details:
  Parent: 63
  degree of 99 is 2
  node 99 height: 5
  ================
```

### Sample Run 3:
```
  g++ program_03.cpp lfsr.cpp binary_search_tree.cpp
  ./a.out < data3.txt
  generating random numbers...
  printing lfsr numbers
  seed: 1	00000001
  128	10000000
  64	01000000
  32	00100000
  144	10010000
  72	01001000
  164	10100100
  82	01010010
  41	00101001
  148	10010100
  202	11001010
  229	11100101
  242	11110010
  249	11111001
  252	11111100
  254	11111110
  255	11111111
  127	01111111
  63	00111111
  31	00011111

  printing tree:
  1 31 32 41 63 64 72 82 127 128 144 148 164 202 229 242 249 252 254 255
  tree height: 11
  node 32 height: 3
  degree of 32 is 3
  leaves: 255 148 127 63 31
  root: 1
  deleting 32.
  deleting 41.
  printing tree:
  1 31 41 63 64 72 82 127 128 144 148 164 202 229 242 249 252 254 255

  Searching for Node 144...
  ================
  Node 144 details:
  Parent: 128
  degree of 144 is 2
  node 144 height: 9
  ================


  Searching for Node 72...
  ================
  Node 72 details:
  Parent: 64
  degree of 72 is 2
  node 72 height: 3
  ================


  Searching for Node 164...
  ================
  Node 164 details:
  Parent: 144
  degree of 164 is 3
  node 164 height: 8
  ================
```
