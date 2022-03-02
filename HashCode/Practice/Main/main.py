files = ["b_better_start_small.in.txt", "c_collaboration.in.txt", 
         "d_dense_schedule.in.txt", "e_exceptional_skills.in.txt", "f_find_great_mentors.in.txt"]

for file_name in files:
    
    file = open(file_name, "r")

    c,p = map(int, file.readline().split())

    contributers = {}
    projects = {}

    for i in range(c):
        name, skills_num = file.readline().split()
        skills_num = int(skills_num)

        skills = []

        for j in range(skills_num):
            skill, skill_level = file.readline().split()
            skill_level = int(skill_level)
            skills.append([skill, skill_level])

        contributers[name] = skills


    for i in range(p):

        project_name, di, si, bi, ri = file.readline().split()
        di = int(di)
        si = int(si)
        bi = int(bi)
        ri = int(ri)

        skills = []

        for j in range(ri):
            skill_name, skill_level = file.readline().split()
            skill_level = int(skill_level)
            skills.append([skill_name, skill_level])

        projects[project_name] = [di, si, bi, ri, skills]

    project_list = []
    for project in projects:
        project_list.append([project, projects[project][1], projects[project][2]])

    project_list.sort(key=lambda x: [x[2], x[1]])
    project_list.reverse()



    good_projects = []

    contributer_skill_levels = {}

    for contributer in contributers:
        for skill in contributers[contributer]:
            contributer_skill_levels[contributer+skill[0]] = skill[1]


    for project in project_list:
        project = project[0]
        di, si, bi, ri, project_skills = projects[project]
        project_contributers = {}
        talented_contributers_skills = {}
        pc = set()
        backup_skills = {}

        for skill in project_skills:
            # done = False
            for contributer in contributers:
                contributer_skills = [i[0] for i in contributers[contributer]]

                if skill[0] in contributer_skills and contributer_skill_levels[contributer+skill[0]] >= skill[1] and contributer not in pc:
                    project_contributers[skill[0]] = contributer
                    pc.add(contributer)

                    for i in contributer_skills:
                        if i in talented_contributers_skills:
                            talented_contributers_skills[i] = max(talented_contributers_skills[i], contributer_skill_levels[contributer+i])
                        else:
                            talented_contributers_skills[i] = contributer_skill_levels[contributer+i]

                    done = True

                    break
                
            # if not done:
            #     backup_skills[skill[0]] = skill[1]

    

        # for skill in backup_skills:
        #     for contributer in contributers:
        #         contributer_skills = [i[0] for i in contributers[contributer]]

        #         if skill in contributer_skills and contributer_skill_levels[contributer+skill]+1 == backup_skills[skill] and contributer not in pc:
                    
        #             if skill in talented_contributers_skills and talented_contributers_skills[skill] >= contributer_skill_levels[contributer+skill]:
        #                 project_contributers[skill] = contributer
        #                 pc.add(contributer)

        #             break


        project_skills = {i:j for i,j in project_skills}

        if len(project_contributers) >= ri:
            good_projects.append([project, project_contributers])

            for i in project_contributers:
                skill = i
                contributer = project_contributers[i]

                if contributer_skill_levels[contributer+skill] == project_skills[skill]:
                    contributer_skill_levels[contributer+skill] += 1

    #         print(project, " : ", project_contributers, talented_contributers_skills)
    #         print("\n")
    
    # if file_name[0] == "b":
    #     exit()

        





        

    

    output_file_name = "out/" + file_name[:-6] + "out"
    output_file = open(output_file_name, 'w')

    output_file.write(str(len(good_projects)) + "\n")
    for project in good_projects:
        output_file.write(project[0] + "\n")

        for skill in projects[project[0]][4]:
            output_file.write(project[1][skill[0]] + " ")

        output_file.write("\n")

    print("Done with " + file_name)