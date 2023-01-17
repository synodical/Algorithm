room_number = input()

room_check = {'0': 0, '1':0, '2':0, '3':0, '4':0,
             '5':0, '6':0, '7':0, '8':0}

for i in range(len(room_number)):
    if(room_number[i] in ['6', '9']):
        room_check['6'] += 1
    else:
        room_check[room_number[i]] += 1
        
room_check['6'] = (room_check['6'] // 2) + (room_check['6'] % 2)
print(max(room_check.values()))