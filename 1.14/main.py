def find_majority(v):
    count=0;
    maj=0;
    for i in v:
        if count == 0:
            maj=i
            count=1
        elif maj==i:
            count+=1
        else:
            count-=1
    return maj

import random

v = [random.randint(0,9) for r in xrange(100)]
print v
print "maj = ", find_majority(v)
