digits = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']

def main():

    file1 = open('data', 'r')
    Lines = file1.readlines()
    
    count = 0
    for line in Lines:
        line_count = []

        for d in digits:
            line = line.replace(d, d[0] + str(digits.index(d)+1) + d[-1] )

        for letter in line:
            if letter.isnumeric():
                line_count.append(letter)

        # concate and the to number
        count += int(line_count[0] + line_count[-1])

    print('#################################')
    print('SUM')
    print(count)

if __name__ == '__main__':
    main()