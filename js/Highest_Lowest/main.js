"use strict";

function highAndLow(numbers) {
  const arr = numbers.split(" ").map(Number);
  const [max, min] = [Math.max(...arr), Math.min(...arr)];
  return max + " " + min;
}

console.log(highAndLow("1 2 3 4 5")); //5 1
console.log(highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4")); //42 -9
