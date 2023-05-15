"use strict";

// function solution(str) {
//   let result = "";

//   for (let i = str.length - 1; i >= 0; i--) {
//     result += str[i];
//   }

//   return result;
// }

//gptver
function solution(str) {
  return str.split("").reverse().join("");
}

console.log(solution("world")); //dlrow
console.log(solution("word")); //drow
