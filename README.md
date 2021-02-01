### Compare Between Two Text
This github repository has a function to compare the similarities between two different text. 
Although I've tested with cosine similarity, I've decided to go with a point system that adds or substracts points depending on certain conditions. I've added 1 point for every word that are in the same order between two texts. and .5 points if they are on different order. I substracted  -.5 point if the word frequency in one document was more than the other one. Cosine similarity formula has a better performance, but I just wanted to expermient with my own point system and decided to go that route. 
### How to run the program
 This Program has 3 ways of running. The list below explains the difference between them. 

- ```python sampler.py``` From the terminal. runs the code with hard coded sampler text and prints comparison score between 0 and 1
- ```python compare_cli``` From the terminal, prompts the user to type a sentence, after pressing enter, it ask the user to type a second sentence. and then prints the comparison score between 0 and 1
- FastAPI in a docker container.  