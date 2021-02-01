from functions import similarity
text1 = input('Enter First Text:')
text2 = input('Enter Second Text:')
similar = similarity(text1,text2)
print("Similarity is: ",similar)