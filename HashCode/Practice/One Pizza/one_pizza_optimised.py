from fileinput import filename


files = ["a_an_example.in.txt", "b_basic.in.txt", "c_coarse.in.txt", "d_difficult.in.txt", "e_elaborate.in.txt"]


def check(a, b):
    likes_a = set(a[0])
    likes_b = set(b[0])
    dislikes_a = set(a[1])
    dislikes_b = set(b[1])

    for i in likes_a:
        if i in dislikes_b:
            return False
    
    for i in likes_b:
        if i in dislikes_a:
            return False

    return True




for file_name in files:
    file = open(file_name, "r")

    C = int(file.readline())

    result = []
    clients = []

    graph = {}


    for _ in range(C):
        
        a = file.readline()
        a = a.split()[1:]
        b = file.readline()
        b = b.split()[1:]

        clients.append([a, b])

    
    for i in range(C):
        for j in range(i+1, C):
            if check(clients[i], clients[j]):
                if i in graph:
                    graph[i].append(j)
                else:
                    graph[i] = [j]

                if j in graph:
                    graph[j].append(i)
                else:
                    graph[j] = [i]
    


