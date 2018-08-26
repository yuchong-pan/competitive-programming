from operator import itemgetter
n = input()
names = set()
word_names = dict()
word_count = dict()
for i in range(n):
    msg = filter(lambda s: s != '', raw_input().split(' '))
    name = msg[0]
    names.add(name)
    msg = msg[1:]
    for word in msg:
        if word in word_names:
            word_names[word].add(name)
        else:
            word_names[word] = set()
            word_names[word].add(name)
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
num_names = len(names)
words = []
for key, value in word_names.iteritems():
    if len(value) == num_names:
        words.append((key, -word_count[key]))
sorted_words = sorted(words, key=itemgetter(1, 0))
if len(sorted_words) == 0:
    print "ALL CLEAR"
for pr in sorted_words:
    print pr[0]
