import cs50

# Pseudo
# - divide total by a coin amount
# - keep dividing it by increments of that coin, count each time
# - subtract from total each time, amount left undivided
# - move the amount left from coin to coin


def greedy():
    # GLOBALS
    # get amount
    amount = cs50.get_float("Enter amount:")
    # times by 100 to make easier to work with
    amount = round(amount * 100)
    print(f"amount {amount}")
    # accumation of final change
    change = 0
    # amount left after each while loop
    left = amount

    # coin
    quarter = 25
    # total being accumulated against amount
    totalDivider = quarter
    # value of divider+accum by the coin
    divQuarterCheck = 0
    # if amount is coin, done
    if(amount == quarter):
        change += 1
        print(f"change: {change}")
        return change
        # if amount divides by coin..
    elif(amount / quarter > 1):
        # set divider+accum to start at amount/coin
        divQuarterCheck = amount / quarter
    else:
        print("not divisible by 25")
        # set to value less than 1, loop is skipped
        divQuarterCheck = amount / quarter

    while (divQuarterCheck >= 1):
        # each time divided check more than one
        # add double adder
        divQuarterCheck = (amount - totalDivider) / quarter
        # add another value to itself
        # if still divisible, go on, if not stop
        totalDivider += quarter
        change += 1
        left -= quarter
    print(f"{left} after quarters")

    dime = 10
    totalDivider = dime
    divDimeCheck = 0
    if(left == dime):
        change += 1
        print(f"change: {change}")
        return change
    elif(left / dime > 1):
        divDimeCheck = left / dime
    else:
        print("not divisible by 10")
    while (divDimeCheck >= 1):
        # each time divided check more than one
        # add double adder
        divDimeCheck = (left - totalDivider) / dime
        # add another value to itself
        # if still divisible, go on, if not stop
        totalDivider += dime
        change += 1
        left -= dime
    print(f"{left} after dimes")

    nickel = 5
    totalDivider = nickel
    divNickelCheck = 0
    if(left == nickel):
        change += 1
        print("true")
        print(f"change: {change}")
        return change
    elif(left / nickel > 1):
        divNickelCheck = left / nickel
        print("true")
    else:
        print("not divisible by 5")
    while (divNickelCheck >= 1):
        # each time divided check more than one
        # add double adder
        divNickelCheck = (left - totalDivider) / nickel
        # add another value to itself
        # if still divisible, go on, if not stop
        totalDivider += nickel
        change += 1
        left -= nickel
    print(f"{left} after nickels")

    penny = 1
    divPennyCheck = 0
    totalDivider = penny
    if(left == penny):
        change += 1
        print(f"change: {change}")
        return change
    elif(left / penny > penny):
        divPennyCheck = left / penny
    else:
        print('not divisible by 1')
    while (left):
        # each time divided check more than one
        # add double adder
        divPennyCheck = (left - totalDivider) / penny
        # add another value to itself
        # if still divisible, go on, if not stop
        totalDivider += penny
        # print(f"totalDivide: {totalDivider}")
        print(divPennyCheck)
        change += 1
        left -= penny
    print(f"{left} after > penny")

    print(f"change: {change}")
    return change


greedy()