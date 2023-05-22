"use strict";

// function isPrime(num) {
//   if (num < 2) return false;
//   if (num < 4) return true;
//   if (num % 2 === 0 || num % 3 === 0) return false;
//   for (let i = 5; i < Math.sqrt(num); i++) {
//     if (num % i === 0 || num % (i + 2) === 0) {
//       return false;
//     }
//   }
//   return true;
// }

// gptver
function isPrime(num) {
  if (num < 2) return false;
  if (num === 2) return true;
  if (num % 2 === 0) return false;
  const limit = Math.sqrt(num);
  for (let i = 3; i <= limit; i += 2) {
    if (num % i === 0) {
      return false;
    }
  }
  return true;
}

console.log(isPrime(1)); //false
console.log(isPrime(2)); //true
console.log(isPrime(3)); //true
console.log(isPrime(-1)); //false
console.log(isPrime(73)); //true
