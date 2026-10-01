# Assignment 4: Array of Structures

ECE 231L Programming Lab, University of New Mexico

## Description
This program stores grocery store items in a dyinamically allocated array of structures. Each item has a name, SKU, category, and price. The program prints all the items, calculates the average price, and searches for an item by SKU using a command line argument.

## Files
- item.h: defines the Item structure
- main.c: contains main and the functions add_item, print_items, average_price, and free_items

## How to compile
gcc -o main main.c

## How to run
./main 14512

The number after ./main is the SKU to search for. If the SKU is not in the list, the program prints "item not found".
