# def scope_test(counter=0):
#   print('helos')
#   if(counter == 10):
#     return
#   else:
#     print(counter)
#     scope_test(counter+1)


# def indsider(x):
#   print(x)
# # indsider()

# scope_test()

# def recursion(coin, amount, coinAccumulator):
# # if 100 / 25 - amount divides evenly

#   if(amount / coin > 1):
#   # start dividing it - set division checker
#     divisionCheck = (amount - coinAccumulator) / coin
#     # if accum no longer allows even division, stop
#     if(divisionCheck < 1):
#       print("less than one")
#       return amount
#     else:
#       coinAccumulator += coin
#       print(f"coin accum: {coinAccumulator}")
#       return recursion(coin, amount, coinAccumulator)

# x = recursion(25,100, 25)
# print(x)

# def keyValue(keyCounter, key):
#   if(keyCounter > len(key)-1):
#       keyCounter = 0
#   return keyCounter

# print(keyValue(0,"hello"))

list = ['This site uses cookies to deliver our', 'services and to show you relevant ads', 'and job listings. By using our site,', 'you acknowledge that you have read and understand our Cookie Policy, Privacy Policy, and our Terms of Service. Your use of Stack Overflow’s Products and Services, including the Stack Overflow Network, is subject to these policies and terms.']

# for i in list:
#   print(f"I: {i}")


# f1 = open("./similarities/text1.txt", "r")

# while True :
#     line = f1.readline()
#     print(line)
#     if (line == ""):
#         print("file finished")
#         break;



file = open("./text1.txt", "r")
i = file.read()



# for line in open("./similarities/text1.txt", "r"):
#     print(line)
# else:
#     print('fin')


# with open(i) as lines:
#     try:
#         while True:                 #Just to fake a lot of readlines and hit the end
#             current = next(lines)
#     except StopIteration:
#         print('EOF!')
def getLinesList(file):
    # find last \n

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
    #
    # arr = []
    # for i in  fileList:
    #     if(i != ''):
    #         arr.append(i)
    # print(arr)

    # def removeBlankLines(inputList):
    #     results = []
    #     for i in  inputList:
    #         if(i != ''):
    #             results.append(i)

    # remove all random blank lines from bottom of text file
    removedList = removeBlankLines(fileList)

    # if there were blank lines, use the new    list, else use the origial
    if(removedList != fileList):
        print('reassign')
        fileList = removedList

    return fileList

    # find final \n
    # print(getFinalLine(file))

# print(x)


# if last line does not end in a \n, get that line
def getFinalLine(str):
    # get final \n
    last_n = str.rindex("\n")
    # get all of string at exists after that
    lastLine = str[last_n:len(str)]
    # space is equal to 1, single char equal to 2
    # if len 1, space, means there is already a \n
    print(f"len:{len(lastLine)}")
    if(len(lastLine) <= 1):
        return #returns None if this fires
    else:
        # if greater than one, no \n, needs to be handled
        # strip off all spaces
        return lastLine.strip()

# remove extra \n following the end of the text, they show up as "" in finalList
def removeBlankLines(inputList):
        results = []
        # take all non-blank lines and make a new list
        for i in  inputList:
            if(i != ""):
                # print(i)
                results.append(i)
            # else:
                # print(i)
        return results

print(getLinesList(i))