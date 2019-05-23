import matplotlib.pyplot as plt

results = dict()


with open("manual.txt", "r") as f:
    for line in f:
        if line[0] == "[":
            continue
        
        if line[0] == "F":
            x = line.split()
            file = x[1].replace("./data/", "").replace(".clq", "")
            target = x[3]

            results[file] = {"target": 0, "targetTime": 0, "L1Time": 0, "L1MIS": 0, "L2Time": 0, "L2MIS": 0, "GNTime": 0, "GNMIS": 0, "GDTime": 0, "GDMIS": 0}

            mis, time = f.readline().split()
            results[file]["L1MIS"] = float(mis)
            results[file]["L1Time"] = float(time)

            mis, time = f.readline().split()
            results[file]["L2MIS"] = float(mis)
            results[file]["L2Time"] = float(time)

            mis, time = f.readline().split()
            results[file]["GNMIS"] = float(mis)
            results[file]["GNTime"] = float(time)

            mis, time = f.readline().split()
            results[file]["GDMIS"] = float(mis)
            results[file]["GDTime"] = float(time)

# manual

results["keller6"] = {"target": 63, "targetTime": 0.8, "L1Time": 1.1899651, "L1MIS": 63, "L2Time": 0.103737123, "L2MIS": 61.4, "GNTime": 0.9005167, "GNMIS": 20, "GDTime": 0.9125780, "GDMIS": 14}


results["brock800_1"]["target"] = 10
results["brock800_1"]["targetTime"] = 0.02 
results["brock800_2"]["target"] = 10
results["brock800_2"]["targetTime"] = 0.02 
results["brock800_3"]["target"] = 11
results["brock800_3"]["targetTime"] = 0.43 
results["brock800_4"]["target"] = 10
results["brock800_4"]["targetTime"] = 0.01
results["C2000.5"]["target"] = 17 
results["C2000.5"]["targetTime"] = 561.02 
results["C2000.9"]["target"] = 6 
results["C2000.9"]["targettime"] = 0.02 
results["C4000.5"]["target"] = 18 
results["C4000.5"]["targettime"] = 285.17
results["MANN_a45"]["target"]= 3 
results["MANN_a45"]["targetTime"] = 0.05 
results["san1000"]["target"] = 67 
results["san1000"]["targetTime"] = 0.05 

# make a table
# print("Graph\tLSV1\tTime\tLSV2\tTime")
for key in results:
    print(key, results[key]["L1MIS"], results[key]["L1Time"], results[key]["L2MIS"], results[key]["L2Time"], sep=",")


files = list(results.keys())

l1mis = [results[file]["L1MIS"] for file in files]
l1times = [results[file]["L1Time"] for file in files]

l2mis = [results[file]["L2MIS"] for file in files]
l2times = [results[file]["L2Time"] for file in files]

gnmis = [results[file]["GNMIS"] for file in files]
gntimes = [results[file]["GNTime"] for file in files]

gdmis = [results[file]["GDMIS"] for file in files]
gdtimes = [results[file]["GDTime"] for file in files]

targetmis = [results[file]["target"] for file in files]
targettimes = [results[file]["targetTime"] for file in files]

plt.figure(1)
plt.style.use('Solarize_Light2')

plt.subplot(2, 2, 1)
plt.title("Average MIS Size")
plt.xlabel("File")
plt.ylabel("Size")
plt.xticks(rotation=45)

plt.plot(files, gdmis, 'o', label="Greedy Node Degree")
plt.plot(files, gnmis, 'o', label="Greedy Neighbourhood Degree")
plt.plot(files, l1mis, 'o', label="LochieV1")
plt.plot(files, l2mis, 'o', label="LochieV2")
plt.plot(files, targetmis, 'o', label="Target")

plt.legend()

plt.subplot(2, 2, 2)
plt.title("Average Time")
plt.xlabel("File")
plt.ylabel("Time (s)")
plt.xticks(rotation=45)

plt.plot(files, gdtimes, 'o', label="Greedy Node Degree")
plt.plot(files, gntimes, 'o', label="Greedy Neighbourhood Degree")
plt.plot(files, l1times, 'o', label="LochieV1")
plt.plot(files, l2times, 'o', label="LochieV2")
plt.plot(files, targettimes, 'o', label="Target")

plt.legend()

plt.subplot(2, 2, 3)
plt.title("Average Size - (excluding san1000, keller6)")
plt.xlabel("File")
plt.ylabel("Size")
plt.xticks(rotation=45)


plt.plot(files[:-2], l1mis[:-2], 'o', label="LochieV1")
plt.plot(files[:-2], l2mis[:-2], 'o', label="LochieV2")
plt.plot(files[:-2], targetmis[:-2], 'o', label="Target")

plt.legend()


plt.subplot(2, 2, 4)
plt.title("Average Time - (excluding C2000.5)")
plt.xlabel("File")
plt.ylabel("Size")
plt.xticks(rotation=45)


files.pop(4)
l1times.pop(4)
l2times.pop(4)
targettimes.pop(4)

plt.plot(files, l1times, 'o', label="LochieV1")
plt.plot(files, l2times, 'o', label="LochieV2")
plt.plot(files, targettimes, 'o', label="Target")

plt.legend()

plt.show()
