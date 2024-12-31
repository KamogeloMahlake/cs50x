height = 0
while True:
    try:
        height = int(input("Height: "))
        if height < 1 or height > 8:
            pass
        else:
            for i in range(1, height + 1):
                spaces = " " * (height - i)
                hashes = f"{'#' * i}  {'#' * i}"
                print(f"{spaces}{hashes}")
            break
    except ValueError:
        pass
