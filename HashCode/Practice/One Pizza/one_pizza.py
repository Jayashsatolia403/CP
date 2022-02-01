files = ["a_an_example.in.txt", "b_basic.in.txt", "c_coarse.in.txt", "d_difficult.in.txt", "e_elaborate.in.txt"]

for file_name in files:
    file = open(file_name, "r")

    C = int(file.readline())

    likes = []
    dislikes = []

    likes_dict = {}
    dislikes_dict = {}

    result = []


    for _ in range(C):
        
        a = file.readline()
        a = a.split()[1:]
        b = file.readline()
        b = b.split()[1:]

        for i in a:
            if i in likes_dict:
                likes_dict[i] += 1
            else:
                likes_dict[i] = 1

        for i in b:
            if i in dislikes_dict:
                dislikes_dict[i] += 1
            else:
                dislikes_dict[i] = 1


        likes.append(a)
        dislikes.append(b)

    for i in likes_dict:
        if i not in dislikes_dict:
            dislikes_dict[i] = 0
    
    for i in dislikes_dict:
        if i not in likes_dict:
            likes_dict[i] = 0

    
    for i in range(C):
        result.append(False)

    good_ingrediants = set()
    bad_ingrediants = set()

    for i in likes_dict:
        if likes_dict[i] >= dislikes_dict[i]:
            good_ingrediants.add(i)
        else:
            bad_ingrediants.add(i)



    for i in range(C):
        x = likes[i]

        good = True

        for j in x:
            if j in bad_ingrediants:
                good = False
                break

        x = dislikes[i]

        for j in x:
            if j in good_ingrediants:
                good = False
                break

        result[i] = good

    corrects = 0

    for i in result:
        if i:
            corrects += 1
    
    print(corrects)

    # print([i for i in good_ingrediants])