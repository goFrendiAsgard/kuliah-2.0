
const kalimat1 = "roses are red violet is blue your face is red my face is blue";
const kalimat2 = "roses are red violet is blue so that my love is only for you";

const tokens1 = getTokens(kalimat1);
const tokens2 = getTokens(kalimat2);

const vector1 = getTfIdf(tokens1, [tokens1, tokens2]);
const vector2 = getTfIdf(tokens2, [tokens1, tokens2]);

console.log({vector1, vector2});

function vectorLength(vector) {
  total = vector.reduce((a, b) => a + b, 0);
  Math.pow(total, 0.5);
}

function getTfIdf(tokens, tokenList) {
  const uniqueWords = getUniqueWords(tokenList);
  const result = uniqueWords.map(word => getTf(tokens, word) * getIdf(tokenList, word));
  return result;
}

function getTf(tokens, word) {
  const totalWordCount = tokens.length;
  const wordCount = tokens.filter(x => x === word).length;
  return wordCount/totalWordCount;
}

function getDf(tokenList, word) {
  const totalDocumentCount = tokenList.length;
  const documentCount = tokenList.filter(tokens => tokens.includes(word)).length;
  return documentCount/totalDocumentCount;
}

function getIdf(tokenList, word) {
  return Math.log10(getDf(tokenList, word));
}

function getTokens(kalimat) {
  return kalimat.split(" ");
}

function getUniqueWords(tokenList) {
  const uniqueWords = [];
  for(tokens of tokenList) {
    for(token of tokens) {
      if(!(uniqueWords.includes(token))) {
        uniqueWords.push(token);
      }
    }
  }
  return uniqueWords;
}
