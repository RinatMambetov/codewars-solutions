"use strict";

function isPangram(string) {
  return [
    ...new Set(
      string
        .toLowerCase()
        .replace(/[ .,\d]/g, "")
        .split("")
    ),
  ].length === 26
    ? true
    : false;
}
console.log(isPangram("The quick brown fox jumps over the1 lazy dog.")); //true
console.log(isPangram("This is not a pangram.")); //false
