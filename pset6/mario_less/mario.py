import cs50

# left alinged example
# val = 4
# # row = 0
# for i in range(val):
#   i = i + 1
#   print(i * "X")
#   # row = i + row
#   # for i in range(row):
#   #   print(row * "X")


# formula
# (val - (i -1)) * " " /+/ (i + 2) * "#"
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
      # if highest val, no spaces
      if i + 1 == val:
        # if any other, add spaces
        print(((i + 2) * "#"))
      else:
        print(((val - i-1) * " ") + (((i + 2) * "#")))


mario()
