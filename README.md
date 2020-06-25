# Word Ladder

Lewis Carroll, the infamous author of the novel Alice in Wonderland, invented a game called a word ladder. The goal is to change one word to another by creating a sequence of words that only differ by 1 letter. The sequence of words that allows us to go from one word to another is called a word ladder. 
An example of a valid word ladder from "heart" to "teams" is as follows: 

``` 
heart hears fears tears teams
```

This program uses a dictionary file provided by the user to check that a word ladder exists between a given pair of words. If the ladder exists, it will output the word ladder in the desired .txt file.

# How it Works

I utilized the a WordLadder class which stores a dictionary of available words. The final ladder and intermediate ladders are stored in stacks of strings. I traversed the dictionary to find all possible words to build our ladder. If a word that differs by one letter is found then it is pushed to a stack with the previous found intermediate word ladder. Each possible ladder is pushed onto a queue. This process is repeated until the end word is found, indicating a word ladder has been found, or the queue is empty. If the queue is empty, then all possible ladders from the start have been found but the end has not been found. In this case the word ladder doesnt exist. The resulting stack will only allow output from the end to start, so the stack is flipped, and then the ladder is outputed.

# I/O
Required inputs are a dictionary file, the start and end words, and the name of the output file. In the repository you will find a sample dictionary file and the resulting output for "reads" to "brats".
