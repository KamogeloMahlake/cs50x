coins = [25, 10, 5, 1]
coins_array_index = 0
change_count = 0

while True:
    try:
        change = (float(input("Change: ")) * 100)

        if change <= 0:
            pass
        else:
            while change > 0:
                if change < coins[coins_array_index]:
                    coins_array_index += 1
                change -= coins[coins_array_index]
                change_count += 1

            print(change_count)
            break
    except ValueError:
        pass
