"use strict";

// function descendingOrder(n) {
//   n = n + "";
//   let arr = n.split("");
//   arr = arr.sort();
//   arr = arr.reverse();
//   return +arr.join("");
// }

function descendingOrder(n) {
  n = n + "";
  return +n.split("").sort().reverse().join("");
}

console.log(descendingOrder(0)); //0
console.log(descendingOrder(42145)); //54421
console.log(descendingOrder(123456789)); //987654321
