def intersection(lst1, lst2):
    return list(set(lst1) & set(lst2))

def main():

    file1 = open('data', 'r')
    Lines = file1.readlines()
    
    wins = [1] * len(Lines)
    count = 0

    for i in range(len(Lines)):
        x = Lines[i].split(":")[1].split('|')
        res = [int(ele) for ele in x[0].split()]
        my_nums = [int(ele) for ele in x[1].split()]
        
        win = len(intersection(res, my_nums)) if len(intersection(res, my_nums)) > 0 else 0

        count += pow(2, win) if win != 0 else 0

        for g in range(wins[i]):
            for w in range(i+1, i+win+1):
                wins[w] += 1


    print(count)
    print(sum(wins))


if __name__ == '__main__':
    main()