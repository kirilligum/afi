#!/usr/bin/python

def anagrams(dictionary):
    output = []
    map = {}
    for word in dictionary:
        sorted_words = sortchars(word)
        if sorted_words not in map:
            map[sorted_words] = [word]
        else:
            map[sorted_words].append(word)
    for k in map.keys():
        if len(k)>1:
            output.append(map[k])
    return output

def sortchars(word):
    l = list(word)
    l.sort()
    return ''.join(l)

def main():
    print 'hello there'
    print anagrams(("algorithm","god","logarithm","dog","snute"))
    #f = open('brit-a-z.txt','rU')
    #print anagrams(f)

if __name__ == '__main__':
    main()
