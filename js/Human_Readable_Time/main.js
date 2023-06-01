"use strict";

// function normilize(num) {
//   if (num - (num % 10) === 0) {
//     return "0" + num;
//   }
//   return num;
// }

// function humanReadable(seconds) {
//   let hours = 0;
//   let minutes = 0;
//   let secs = 0;
//   secs = seconds % 60;
//   seconds -= secs;
//   hours = parseInt(seconds / (60 * 60));
//   minutes = (seconds - hours * 60 * 60) / 60;
//   hours = normilize(hours);
//   minutes = normilize(minutes);
//   secs = normilize(secs);
//   return hours + ":" + minutes + ":" + secs;
// }

// gptver
function normalize(num) {
  return String(num).padStart(2, "0");
}

function humanReadable(seconds) {
  let hours = Math.floor(seconds / (60 * 60));
  seconds = seconds % (60 * 60);
  let minutes = Math.floor(seconds / 60);
  seconds = seconds % 60;

  hours = normalize(hours);
  minutes = normalize(minutes);
  seconds = normalize(seconds);

  return hours + ":" + minutes + ":" + seconds;
}

console.log(humanReadable(0)); //00:00:00
console.log(humanReadable(90)); //00:01:30
console.log(humanReadable(3600)); //01:00:00
console.log(humanReadable(45296)); //12:34:56
