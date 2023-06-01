"use strict";

function findMissingLetter(array) {
  let alphabet = "abcdefghijklmnopqrstuvwxyz";
  if (array[0] === array[0].toUpperCase()) alphabet = alphabet.toUpperCase();
  const subAlphabet = alphabet.substring(
    alphabet.indexOf(array[0]),
    alphabet.indexOf(array.slice(-1)) + 1
  );
  for (let i = 0; i < array.length; i++) {
    if (array[i] !== subAlphabet[i]) return subAlphabet[i];
  }
}

// gptver
// function findMissingLetter(array) {
//   const alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
//   const startIndex = alphabet.indexOf(array[0]);
//   const endIndex = alphabet.indexOf(array.slice(-1));
//   const subAlphabet = alphabet.substring(startIndex, endIndex + 1);

//   for (let i = 0; i < array.length; i++) {
//     if (array[i] !== subAlphabet[i]) {
//       return subAlphabet[i];
//     }
//   }
// }

console.log(findMissingLetter(["a", "b", "c", "d", "f"])); //e
console.log(findMissingLetter(["O", "Q", "R", "S"])); //P
