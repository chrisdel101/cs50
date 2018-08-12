import cs50

# - base case 1 - if coin == amount return change
# - base case 2 - if left == coin return change
# - base case 3 left is less than coin return left and change
# - if amonut left is not less and coin:
# 	- increase accumulator by coin value
# 	- add one to change
# 	- decrease left by coin value
# 	- call function with new values of coin, accumulator, change and left)
# 	- left decreases and is checked against coin value each time

def input_test():

  amount = cs50.get_float("Enter amount:")
  amount = round(amount * 100)
  print(amount)
  # amount of coins
  # change = 0
  # return_left(25,amount,25,0,0)
  x = check_ifDivisible(25,amount, 25, 0, amount)
  # y = check_ifDivisible(10,amount, 10, 0, 0)
  return x


def check_ifDivisible(coin, amount,coinAccumulator, change, left):
  # if equal, return and stop
  # left = amount
  # counter = 0
  # start with coin, add value of coin over and over
  print('top')
  if(amount == coin):
    print('equal off the top')
    change += 1
    print(f"final change: {change}")
    return change
  elif(left == coin):
    print(f"all that's left divides equally:{left}")
    change += 1
    print(f"final change: {change}")
    return change
  # if original amount is divisible by coin
  elif(amount / coin > 1):
    # amount divisible, minus coin val
    # divisible_by_coin = (amount - coinAccumulator) / coin
    # print(f"d_b_c outside:{divisible_by_coin}")
    if(left < coin):
      print(f"less than one")
      print(f"final change: {change}")
      return change, left
    else:
      # increase total for subrtraction
      coinAccumulator += coin
      change += 1
      print(f"change: {change}")
      # print (f"d_b_c:{divisible_by_coin}")
      left -= coin
      print(f"coinAccumulator: {coinAccumulator}")
      print(f"left:{left}")
      print("recurse")
      return check_ifDivisible(coin, amount, coinAccumulator, change, left)
  else:
    print("not divisible")

# def return_left(coin,left,totalDivider,divCheck, totalChange):

#   # amount after each interation left

#   # total being accumulated against amount

#   # if amount is disible by 25, set checker
#   nonlocal amount
#   if(amount == coin):
#     totalChange += 1
#     change = totalChange
#     print(f"change: {change}")
#     return totalChange
#   elif(amount / coin > 1):
#     divQuarterCheck = amount /coin
#   else:
#     print("not divisible by 25")
#     divQuarterCheck = amount /coin
#   while (divQuarterCheck >= 1):
#     # each time divided check more than one
#     # add double adder
#     divQuarterCheck = (amount - totalDivider) / coin
#     # add another value to itself
#     # if still divisible, go on, if not stop
#     totalDivider += coin
#     # print(f"totalDivide: {totalDivider}")
#     # print (divQuarterCheck)
#     totalChange += 1
#     change = totalChange
#     left -= coin
#   return left

y = input_test()
print(y)