import os
filelist = os.listdir("cknn-dataset/")

for fname in filelist:
    fp = open('cknn-dataset/' + fname, "r")
    bag_dict = {} 
    for line in fp:
        line_split = line.split(",")
        bag_id = line_split[0]
        if bag_id not in bag_dict.keys():
            bag_dict[bag_id] = 1
        else:
            bag_dict[bag_id] += 1

    max_inst_per_bag = sorted(bag_dict.values(), reverse=True)[0]
    print(fname + "\nmax_inst_per_bag: " + str(max_inst_per_bag))
    print(sum(sorted(bag_dict.values(), reverse=True))/len(bag_dict.values()))
    print("---------------------------------")
