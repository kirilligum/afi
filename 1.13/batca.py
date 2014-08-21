import random

def battery_capacity(h):
    b=0
    hmin=h[0]
    for i in h:
        bt = i-hmin
        if b<bt:
            b = bt
        if i<hmin:
            hmin = i
    return b

def main():
    h = random.sample(xrange(-100,100),100)
    print h
    print h[0]
    print "capacity =", battery_capacity(h)

if __name__ == '__main__':
    main()
