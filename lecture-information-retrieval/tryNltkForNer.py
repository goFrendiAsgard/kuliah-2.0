import nltk
nltk.download('punkt')
nltk.download('averaged_perceptron_tagger')
sentence = """
Please play any music
Please order a pizza
Cancel please
"""
tokens = nltk.word_tokenize(sentence)
print(tokens)
tagged = nltk.pos_tag(tokens)
print(tagged)
