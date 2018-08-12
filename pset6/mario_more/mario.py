import cs50

# formula
# (val - (i -1)) * " " /+/ (i + 2) * "#" + 2 * " " + (i + 2) * "#"
# get (highest number - i-1) for spaces, plus (i + 2 x's)

# right alinged
def mario():

  val = cs50.get_int("enter val:");
  # if less and 0 of greater than 24 recurse
  if(val < 0 or val >= 24):
    print('invalid input. Try again')
    mario()
  else:
    for i in range(val):
      rightSideSpaces = val - i-1
      leftSideBlocks = i + 1
      innerSpace = 2
      rightSideBlocks = leftSideBlocks
      # if highest val, no spaces
      if i + 1 == val:
        print(((leftSideBlocks) * "#") + (innerSpace * " ") + (leftSideBlocks * "#"))
        # if any other, add spaces
      else:
        print((rightSideSpaces * " ") + ((leftSideBlocks * "#")) + (innerSpace * " ") + (leftSideBlocks * "#"))


mario()
