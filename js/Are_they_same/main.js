"use strict";

function comp(array1, array2) {
  if (array1 === null || array2 === null) return false;
  array1 = array1.map((elem) => elem * elem);
  array1.sort();
  array2.sort();
  return array1.toString() === array2.toString();
}

// gptver
// function comp(array1, array2) {
//   return (
//     array1?.length === array2?.length &&
//     array1
//       .map((x) => x * x)
//       .sort()
//       .every((val, i) => val === array2.sort()[i])
//   );
// }

console.log(
  comp(
    [121, 144, 19, 161, 19, 144, 19, 11],
    [121, 14641, 20736, 361, 25921, 361, 20736, 361]
  )
); //true
