"use strict";

function isUppercase(ch) {
  return ch === ch.toUpperCase();
}

function solution(string) {
  let words = [];
  let index = 0;
  for (let i = 0; i < string.length; i++) {
    if (isUppercase(string[i])) {
      words.push(string.substring(index, i));
      index = i;
    }
  }
  words.push(string.substring(index, string.length));
  return words.join(" ");
}

console.log(solution("camelCasing")); //camel Casing
console.log(solution("identifier")); //identifier
console.log(solution("")); //""
