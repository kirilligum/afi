import random

def frequent_items(v,k):
    h = {}
    for i in v:
        if i in h:
            h[i]+=1
        else:
            if len(h)==k:
                for k in h.keys():
                    h[k]-=1
                    if h[k]==0:
                        del h[k]
            else:
                h[i]=1
    return h

v = [random.randint(0,4) for r in xrange(10)]
print v
h = frequent_items(v,5)
print h
for i in h:
    h[i]=0
print h
for i in v:
    if i in h:
        h[i]+=1
print h
