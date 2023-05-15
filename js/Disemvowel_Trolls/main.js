"use strict";

function disemvowel(str) {
  let regexp = /a|e|u|i|o/gi;
  let result = "";
  for (const letter of str) {
    if (letter.match(regexp) === null) result += letter;
  }
  return result;
}

// function disemvowel(str) {
//   return str.replace(/[aeiou]/gi, "");
// }

console.log(disemvowel("This website is for losers LOL!")); //Ths wbst s fr lsrs LL!
