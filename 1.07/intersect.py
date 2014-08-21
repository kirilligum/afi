import random

def try_linear_intersect(n,m,a,b):
    A=[]
    for i in range(n):
        A.append(random.randint(a,b))
    A.sort()
    print A

    B=[]
    for i in range(m):
        B.append(random.randint(a,b))
    B.sort()
    print B

    return linear_intersect(A,B)

def linear_intersect(A,B):
    output = []
    ac = 0
    bc = 0
    last = None
    while ac<len(A) and bc<len(B) :
        if A[ac]==B[bc] and A[ac]!=last:
            last = A[ac]
            output.append(last)
            ac+=1
            bc+=1
        elif A[ac]<B[bc]:
            ac+=1
        else:
            bc+=1
    return output

def main():
    print 'Hello there'
    print try_linear_intersect(30,40,0,50)

if __name__ == '__main__':
    main()
