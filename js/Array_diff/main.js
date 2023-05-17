"use strict";

// function arrayDiff(a, b) {
//   if (a.length === 0 || b.length === 0) return a;
//   for (let i = 0; i < a.length; i++) {
//     if (b.includes(a[i])) {
//       a.splice(i, 1);
//       i--;
//     }
//   }
//   return a;
// }

//gptver
function arrayDiff(a, b) {
  return a.filter((element) => !b.includes(element));
}

console.log(arrayDiff([1, 2], [1])); //[2]
console.log(arrayDiff([1, 2, 2, 2, 3], [2])); //[1,3]
console.log(arrayDiff([1, 2, 2], [])); //[1,2,2]
console.log(arrayDiff([1, 2, 3], [1, 2])); //[3]
