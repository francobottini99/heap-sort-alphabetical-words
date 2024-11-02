# Alphabetical Word Sorter

This repository contains a C++ program that alphabetically sorts a text file containing words, some of which may be repeated. The result is saved in another text file, listing the sorted words along with their frequency counts.

### Authors:
- **Franco Nicolas Bottini**
- **Valentin Robledo**

## Development

### Implemented Classes

1. **`Tree`**: A class that creates a semi-complete n-ary tree, where each word is represented by a node, and repeated words are counted within the same node.

2. **`Heap`**: A class that uses the `Tree` class as a foundation to implement a binary heap. Elements are arranged so that a parent node is always greater than all its child nodes. This class includes a `sort` method to sort the heap instances.

### Main Function (`main`)

1. Reads the file "Input.txt" and processes the words.
2. Replaces accented vowels with their unaccented equivalents, converts the letter "ñ" to "n," and removes characters such as ",", ".", "()", "¿?", among others.
3. Inserts the words into an instance of the `Heap` class.
4. Sorts the heap using the `sort` method.
5. Generates the "Output.txt" file, which contains the alphabetically sorted list of words, their frequencies, and the number of comparisons performed.

## Complexity Analysis

Tests confirmed that, using a binary heap, the algorithm's complexity is of the order 𝑂(𝑛log(𝑛)), where 𝑛 is the number of words.

### Results

Tests were conducted by varying the number of words, yielding the following results:

| Words   | n Log(n) | Result    |
|---------|----------|-----------|
| 333     | 2790     | 3979      |
| 5581    | 1535     | 16246     |
| 24978   | 32493    | 6269      |
| 79077   | 127366   | 158155    |
| 6860    | 87424    | 141112    |
| 174848  | 9917     | 131655    |
| 223459  | 263310   | 19781     |
| 564622  | 29699    | 441272    |
| 761194  | 882543   | 39707     |
| 1053909 | 1213216  | 79356     |
| 2234880 | 2583205  |           |
