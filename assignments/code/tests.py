#!/bin/python3
import subprocess

# runs tests, compares to results, graphs

path_prefix = "./data/"
file_extension = ".clq"

graphs = [("brock800_1", 10, 0.02),
          ("brock800_2", 10, 0.02),
          ("brock800_3", 11, 0.43),
          ("brock800_4", 10, 0.01),
          ("c2000.5",    17, 561.02),
          ("c4000.9",    6, 0.02),
          ("c4000.5",    18, 285,17),
          ("keller6",    63, 0.08),
          ("MANN_a45",   3, 0),
          ("san1000",    67, 0)
          ]

for graph in graphs:
    print("Graph: {}\tTarget: {}\tTime: {}".format(graph[0], graph[1], graph[2]))

    subprocess.call(["./maximum-independent-set", path_prefix + graph[0] + file_extension])

    print()

# subprocess.call(["./maximum-independent-set", "./data/brock800_1.clq"])