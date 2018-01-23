# Infix to Postfix

### File:
```
  prog3_Wei.cpp
```

### Compile:
```
  g++ prog3_Wei.cpp -std=c++11
```

### Sample Run
```
Please enter an infix expression:
a + b * c ^ (d / (e + f) )     
a b c d e f + / ^ * +
```

```
Please enter an infix expression:
a ^ b ^ c
a b c ^ ^
```

```
Please enter an infix expression:
a - b - c
a b - c -
```

```
Please enter an infix expression:
!@#$
! is not an operator (+, -, *, /, ^) nor an operand (a single lowercase character)!
```

```
Please enter an infix expression:
1 + a
1 is not an operator (+, -, *, /, ^) nor an operand (a single lowercase character)!
```
