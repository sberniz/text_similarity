def similarity(text1,text2):
  #stop words that are common , does not count in text similarity
  stop_words = ['The','the','to','is','for','on', 'you','your','just','way','with','if','any','You','already','we','we\'ll']
  #Dictionary to count the number of words that are the same between two texts/sentences
  same_words = {}
  #section to convert text to list of words/tokens convert to lowercase and remove punctuation. 
  text1 = text1.lower()
  text2 = text2.lower()
  text1 = text1.replace(",","")
  text2 = text2.replace(",","")
  text1 = text1.replace(".","")
  text2 = text2.replace(".","")  
  text1 = text1.split(" ")
  text2 = text2.split(" ")  
  #goes through text 1 array. 
  for i,item in enumerate(text1):
      #compapres if word on text1 is on text2 and not in 'stop__words' 
    if ((item in text2) and (item not in stop_words)):
       # count the number of times the word appears on each sentence/document
       count1 = text1.count(item)
       count2 = text2.count(item)
       # check if both words are in the same order. and gives a point of 1. 
       if (text2.index(item) == i):
         points = 1
       else:
         points = .5 # else only a .5 point. 
       # if the word count between of the documents is not the same, penalize with a -.5 point. 
       if count1 != count2:
        points -= .5
       if (item not in same_words):
         same_words[item] = points
       else:
         same_words[item] += points
  dic_length = len(same_words)
  if (dic_length == 0):
    score = 0
  else:
    score =  sum(same_words.values()) / dic_length
  return round(score,2)