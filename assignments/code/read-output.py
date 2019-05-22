from sys import argv
import matplotlib.pyplot as plt

trials = 10

results = dict()

files = []



with open(argv[1], "r") as f:
    for line in f:
        x = line.split()

        if len(x) < 4:
            continue

        if len(x) == 4:
            file = x[1].replace("./data/", "").replace(".clq", "")
            if file == "lochie":
                continue
            target = int(x[3])
            files.append(file)
            results[file] = {"target": target}
            results[file]["LochieV1"] = {"times": 0, "sizes": 0}
            results[file]["GreedyDegree"] = {"times": 0, "sizes": 0}
            results[file]["GreedyNeighbourhoodDegree"] = {"times": 0, "sizes": 0}
            results[file]["Wayne"] = {"times": 0, "sizes": 0}
            continue

        if file == "lochie":
            continue
        
        algo, size, _, _, time = x
        algo = algo.replace(":", "")

        results[file][algo]["sizes"] += int(size)
        results[file][algo]["times"] += float(time)

for file in files:
    results[file]["LochieV1"]["times"] /= trials
    results[file]["GreedyDegree"]["times"] /= trials
    results[file]["GreedyNeighbourhoodDegree"]["times"] /= trials

    results[file]["LochieV1"]["sizes"] /= trials
    results[file]["GreedyDegree"]["sizes"] /= trials
    results[file]["GreedyNeighbourhoodDegree"]["sizes"] /= trials

# waynes data
results["brock800_1"]["Wayne"]["sizes"] = 10
results["brock800_1"]["Wayne"]["times"] = 0.02 
results["brock800_2"]["Wayne"]["sizes"] = 10
results["brock800_2"]["Wayne"]["times"] = 0.02 
results["brock800_3"]["Wayne"]["sizes"] = 11
results["brock800_3"]["Wayne"]["times"] = 0.43 
results["brock800_4"]["Wayne"]["sizes"] = 10
results["brock800_4"]["Wayne"]["times"] = 0.01
results["C2000.5"]["Wayne"]["sizes"] = 17 
results["C2000.5"]["Wayne"]["times"] = 561.02 
results["C2000.9"]["Wayne"]["sizes"] = 6 
results["C2000.9"]["Wayne"]["times"] = 0.02 
results["MANN_a45"]["Wayne"]["sizes"] = 3 
results["MANN_a45"]["Wayne"]["times"] = 0.05 
results["san1000"]["Wayne"]["sizes"] = 67 
results["san1000"]["Wayne"]["times"] = 0.05 

print("I REMOVED THE LAST DATAPOINT")
files = files[:-1]

greedyD = [results[file]["GreedyDegree"]["sizes"] for file in files]
greedyN = [results[file]["GreedyNeighbourhoodDegree"]["sizes"] for file in files]
lochie = [results[file]["LochieV1"]["sizes"] for file in files]
wayne = [results[file]["Wayne"]["sizes"] for file in files]

greedyT = [results[file]["GreedyDegree"]["times"] for file in files]
greedyT = [results[file]["GreedyNeighbourhoodDegree"]["times"] for file in files]
lochieT = [results[file]["LochieV1"]["times"] for file in files]
wayneT = [results[file]["Wayne"]["times"] for file in files]



plt.figure(1)
plt.style.use('Solarize_Light2')

plt.subplot(2, 2, 1)
plt.title("Average MIS Size")
plt.xlabel("File")
plt.ylabel("Size")
plt.xticks(rotation=45)

plt.plot(files, greedyD, 'o', label="Greedy Node Degree")
plt.plot(files, greedyN, 'o', label="Greedy Neighbourhood Degree")
plt.plot(files, lochie, 'o', label="LochieV1")

plt.legend()

plt.subplot(2, 2, 2)
plt.title("Average Time")
plt.xlabel("File")
plt.ylabel("Time (s)")
plt.xticks(rotation=45)

plt.plot(files, greedyT, 'o', label="Greedy Node Degree")
plt.plot(files, greedyT, 'o', label="Greedy Neighbourhood Degree")
plt.plot(files, lochieT, 'o', label="LochieV1")

plt.legend()

plt.subplot(2, 2, 3)
plt.title("Average Time vs Wayne")
plt.xlabel("File")
plt.ylabel("Time (s)")
plt.xticks(rotation=45)

plt.plot(files, lochieT, 'o', label="LochieV1")
plt.plot(files, wayneT, 'o', label="Wayne")

plt.legend()

plt.subplot(2, 2, 4)
plt.title("Average Size vs Wayne")
plt.xlabel("File")
plt.ylabel("Size")
plt.xticks(rotation=45)

plt.plot(files, lochie, 'o', label="LochieV1")
plt.plot(files, wayne, 'o', label="Wayne")

plt.legend()

plt.show()


