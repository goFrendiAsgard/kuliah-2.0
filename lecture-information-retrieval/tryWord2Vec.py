import word2vec

# Training
'''
word2vec.word2phrase('./text8', './text8-phrases', verbose=True)
word2vec.word2vec('./text8-phrases', './text8.bin', size=100, verbose=True)
word2vec.word2clusters('./text8', './text8-clusters.txt', 100, verbose=True)
'''

# Load Model
model = word2vec.load('./text8.bin')

# Show Model
'''
print(model.vocab)
print(model.vectors.shape)
print(model.vectors)
'''

# Show Word representation
'''
print(model['dog'].shape)
print(model['dog'])
print(model.distance("dog", "wolf", "cat", "fish", "chair"))
'''

# Analogies
indexes, metrics = model.analogy(pos=['king', 'woman'], neg=['man'])
print(model.generate_response(indexes, metrics).tolist())
