from nltk.tokenize import sent_tokenize


def lines(file1, file2):
    """Return lines in both a and b"""

    result = set()

    def getLinesList(file):

        # storage array
        fileList = []
        # temp storage array
        tempList = []

        # if all lines have \n at the end
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

        finalLine = getFinalLine(file)
        # if return is not None; since if nothing, still returns None
        if(finalLine != None):
            # append final line to the list of lines
            fileList.append(finalLine)

        # call removeBlanklines
        removedList = removeBlankLines(fileList)

        # if there were blank lines, use the new    list, else use the origial
        if(removedList != fileList):
            print('reassign')
            fileList = removedList

        return fileList

    # call getLines
    lines1 = getLinesList(file1)
    lines2 = getLinesList(file2)

    for i in lines1:
        for j in lines2:
            if i == j:
                # add to the set
                result.add(i)

    # make set into a list with this syntax
    result = list(result)
    return result


def getFinalLine(str):
    # get final \n
    last_n = str.rindex("\n")
    # get all of string at exists after that
    lastLine = str[last_n:len(str)]
    # space is equal to 1, single char equal to 2
    # if len 1, space, means there is already a \n
    if(len(lastLine) <= 1):
        return  # returns None if this fires
    else:
        # if greater than one, no \n, needs to be handled
        # strip off all spaces
        return lastLine.strip()

# remove any extra \n following the end of the text, they show up as "" in finalList
def removeBlankLines(inputList):
    results = []
    # take all non-blank lines and make a new list
    for i in inputList:
        if(i != ""):
            results.append(i)
        # else:
    return results


def sentences(a, b):
    """Return sentences in both a and b"""
    result = set()
    list1 = sent_tokenize(a)
    list2 = sent_tokenize(b)

    for i in list1:
        for j in list2:
            if i == j:
                result.add(i)

    result = list(result)
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
