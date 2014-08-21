import random

def addsto(sum,arr):
    ht = set()
    for i in range(len(arr)):
        ht.add(sum-arr[i])
        if arr[i] in ht:
            print arr[i],",",sum-arr[i]

def main():
    arr = random.sample(xrange(-20,80),40)
    addsto(70,arr)

if __name__ == '__main__':
    main()
