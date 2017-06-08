from sys import stdin
from math import factorial

def main():
    # Python used because it can handle large number :) 
    for line in stdin:
        nr = ""
        n = 0;
        m = 0;
        for c in line:
            if(c == ' '):
                n = int(nr)
                nr = ""
            else:
                nr += c
        m = int(nr)
        n_f = factorial(n);
        if n_f % m == 0:
            print(m,"divides",str(n) + "!")
        else:
            print(m,"does not divide", str(n) + "!")
if __name__ == '__main__':
    main()

