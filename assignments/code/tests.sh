#!/bin/bash

for graph in ./data/*.clq; do
    ./maximum-independent-set $graph
done