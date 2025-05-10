# Word Hunt Solver
![wordhunt-2](https://github.com/user-attachments/assets/47fb9e06-28f8-4897-956b-be746cdf8035)

## Description
This project compares two algorithms that solve
the GamePigeon word hunt game. 

### The Game
The game starts with a board like the one pictured
above. The goal of the game is pretty simple, 
find as many words as you can amongst the mix
of random letters. You, however, can only connect
letters next to or diagonal from one another and you
can only use each letter once.

### Algorithm Benchmarking
This project uses three main methods to benchmark 
how successful the algorithms are at solving
the word hunt.
1. \# of words found
2. Speed of execution
3. (For Trie Solver) \# of paths pruned

## Installation & Use
1. Clone the repository by copying the HTTPS link into
   the IDE of your choice & install needed packages.
2. Choose which algorithm you wish to use on line
12 of the main.cpp file: ```TrieSolver``` OR ```BucketSolver```.
3. Run the main.cpp file and input your game board one row a time (no spaces!)

## Bucket Solver
One of the algorithms in this project uses a map
of several buckets. The map is organized by each
letter of the alphabet, and only words that start
with that letter are in its bucket. While this method
is not the most efficient, taking several seconds to fully
execute, it does allow the algorithm skip any words 
which don't have their first letter on the board.

## Trie Solver
![test](https://github.com/user-attachments/assets/c397e33d-1ea8-4371-a189-61583d0114d6)

The other algorithm in this project uses
the Trie structure at its base. As you can see
in the image above, a Trie holds words as a 
tree of letters. This approach allows the search
function to efficiently prune out impossible combos
of letters. For example, if the algorithm were to
run into the letter M, surrounded by several instances
of the letter T, the algorithm would be able to completely
skip any words starting with the letter M, as there
are no words in the English language that start
with an 'MT'. This method of storage, therefore, significantly
increases the speed of execution, taking mere milliseconds 
compared to the seconds the bucket solver takes.

## Resources
[Article discussing the Trie approach I took](https://medium.com/@abhay.khanna_37314/word-hunt-cracking-the-code-9344188b1edb)
[Presentation PDF](https://github.com/user-attachments/files/20126882/Final.Presentation.pdf)

