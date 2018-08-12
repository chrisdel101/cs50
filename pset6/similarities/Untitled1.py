def lines(file1, file2):
    """Return lines in both a and b"""
    x = []
    result = set()



    def getLinesList(file):
        # storage array
        fileList = []
        # temp storage array
        tempList = []
        for i in file:
            # if not a new line, then all one line
            if not i == "\n":
                # add all to new list on line
                tempList.append(i)
            else:
                # when end of line
                # make a string
                tmp = ''.join(tempList)
                # push string into file list
                fileList.append(tmp)
                # clear the array
                tempList.clear()

        return fileList

    lines1 = getLinesList(file1)
    lines2 = getLinesList(file2)

    # print(lines1)
    for i in lines1:
        for j in lines2:
            if i == j:
                # add to the set
                result.add(i)


    # make set into a list with this syntax
    result = list(result)
    # print(result)
    return result


    def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    result = []
    counter1 = 0
    counter2 = 0
    set1 = set()
    set2 = set()

    for i in a:
        # use counter to increase way through string
        # get chunks of str of length n
        sub1 = a[counter1:n + counter1]
        # if len n and don't have whitespace
        if len(sub1) == n and " " not in sub1:
            # push into set - avoid duplicates
            set1.add(sub1)
        counter1 += 1

    # call same on second string
    for i in b:
        sub2 = b[counter2:n + counter2]
        if len(sub2) == n and " " not in sub2:
            set2.add(sub2)
        counter2 += 1

    # compare each against all in 1 to all in 2
    for i in set1:
        for j in set2:
            if i == j:
                # add to list
                result.append(i)

    return result
