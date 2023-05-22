"use strict";

function order(words) {
  if (words.length < 2) return words;
  const wordsArr = words.split(" ");
  let result = [];
  for (let index = 1; index < 10; index++) {
    for (const word of wordsArr) {
      if (word.includes(index)) {
        result.push(word);
        break;
      }
    }
  }
  return result.join(" ");
}

console.log(order("is2 Thi1s T4est 3a")); //"Thi1s is2 3a T4est"
console.log(order("4of Fo1r pe6ople g3ood th5e the2")); //"Fo1r the2 g3ood 4of th5e pe6ople"
console.log(order("")); //""
