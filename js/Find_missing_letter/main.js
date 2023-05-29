"use strict";

function findMissingLetter(array) {
  const alphabet = "abcdefghijklmnopqrstuvwxyz";
  const fullAlphabet = alphabet.substring(
    alphabet.indexOf(array[0]),
    alphabet.indexOf(array.slice(-1)) + 1
  );
  console.log(fullAlphabet);
  return " ";
}

console.log(findMissingLetter(["a", "b", "c", "d", "f"])); //e
// console.log(findMissingLetter(["O", "Q", "R", "S"])); //P
