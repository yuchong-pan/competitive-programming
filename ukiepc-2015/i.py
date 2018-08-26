hard_consonants = ['b', 'c', 'd', 'g', 'k', 'n', 'p', 't']

def find_nearest(d, cs):
    d = d.lower()
    mi = None
    for c in cs:
        if mi == None or abs(ord(c) - ord(d)) < abs(ord(mi) - ord(d)):
            mi = c
    return mi

def cast(c1, c2):
    if 'a' <= c2 <= 'z':
        return c1.lower()
    else:
        return c1.upper()

def process(word):
    ans = ''
    syllables = word.split('-')
    ans += cast(find_nearest(syllables[0][0], hard_consonants), syllables[0][0])
    ans += syllables[0][1:]
    for syllable in syllables[1:]:
        for char in syllable:
            if char in hard_consonants:
                ans += cast(ans[0], char)
            else:
                ans += char
    if ans[-1].lower() in hard_consonants:
        ans += find_nearest(ans[-1], ['a', 'o', 'u']) + 'h'
    return ans

words = filter(lambda s: s != '', raw_input().split(' '))
ans = []
for word in words:
    ans.append(process(word))
print ' '.join(ans)
