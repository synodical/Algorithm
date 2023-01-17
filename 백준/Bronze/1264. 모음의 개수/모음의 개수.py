string = input()
vowel = 'AaEeIiOoUu'

while string != '#':
    answer = 0
    for i in string:
        if i in vowel:
            answer += 1
    print(answer)
    string = input()