"use strict";

decodeMorse = function (morseCode) {
  morseCode = morseCode.trim();
  const words = morseCode.split("   ");
  let result = [];
  for (const word of words) {
    const letters = word.split(" ");
    let newWord = "";
    for (const letter of letters) {
      newWord += MORSE_CODE[letter];
    }
    result.push(newWord);
  }
  return result.join(" ");
};

// gptver
// const decodeMorse = (morseCode) => {
//   const words = morseCode.trim().split("   ");
//   const result = words.map((word) => word.split(" ").map((letter) => MORSE_CODE[letter]).join(""));
//   return result.join(" ");
// };
