record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]

user_info = dict()

for i in record:
    record_split = i.split(' ')
    #print(record_split)
    if record_split[0] == "Enter" or record_split[0] == "Change":
        user_info[record_split[1]] = record_split[2]
    #print(user_info)


def enter(nickname):
    return nickname + "님이 들어왔습니다."


def leave(nickname):
    return nickname + "님이 나갔습니다."


answer = list()

for i in record:
    record_split = i.split(' ')
    if record_split[0] == "Enter":
        answer.append(enter(user_info[record_split[1]]))
    elif record_split[0] == "Leave":
        answer.append(leave(user_info[record_split[1]]))

print(answer)
